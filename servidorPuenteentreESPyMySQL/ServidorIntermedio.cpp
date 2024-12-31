
//compilar --> g++ ServidorIntermedio.cpp -o servidorEJE -std=c++20 -lmysqlcppconn -lpthread -lssl -lcrypto
//Priemro. Conectarse a wifi --> AT+CWJAP="nicolas","hora14159"
//Segundo --> mandar la solicitud http --> AT+HTTPCLIENT=2,3,"http://192.168.235.121:8080/get?IDT=1234","192.168.0.125","/get",1
//Segundo --> mandar la solicitud de eliminacion http --> AT+HTTPCLIENT=2,3,"http://192.168.235.121:8080/get?IDTDEL=1234","192.168.0.125","/get",1
                                        //  http://192.168.0.125:8080/get?IDT=%5443 === http://192.168.0.125:8080/get?IDT=%35%34%34%33
//para mandar desde el navegar en la misma pc: http://localhost:8080/get?IDT=1234

#include "./cpp-httplib-master/httplib.h"
#include <iostream>
#include <string>
#include <csignal>

#include <arpa/inet.h>
#include <ifaddrs.h>

#include <mysql_driver.h> // Declara las funciones y clases para el controlador MySQL
#include <mysql_connection.h> // Declara la clase sql::Connection que representa una conexión a una base de datos MySQL.
#include <cppconn/statement.h> // Para crear y ejecutar consultas SQL.
#include <cppconn/resultset.h> // Para manejar los resultados de las consultas.

void signal_handler(int signal);
std::string PeticionMySQL(const std::string& idt);
void ModificacionMySQL(const std::string& idt);
void handle_get(const httplib::Request& req, httplib::Response& res);
std::string obtenerIPLocal();
//void handle_post(const httplib::Request& req, httplib::Response& res);

// Globales
sql::mysql::MySQL_Driver *driver;
sql::Connection *conn;
sql::Statement *stmt;
sql::ResultSet *res;

httplib::Server svr; // Definir el servidor a nivel global para acceder desde la señal

std::string ultimaBebida; // varaible para almacenar el siempre el utlimo trago pedido.

int main()
{
    // Configurar el manejador de señales
    signal(SIGINT, signal_handler);

    // Conexión a la base de datos
    driver = sql::mysql::get_mysql_driver_instance();
    conn = driver->connect("tcp://127.0.0.1:3306", "nico", "Bitcoin256@");
    conn->setSchema("Barman");

    std::string ipLocal = obtenerIPLocal();
    std::cout << "Servidor corriendo en http://" << ipLocal << ":8080" << std::endl;

    // Configuración de rutas
    svr.Get("/get", handle_get);
    //svr.Post("/post", handle_post);

    svr.listen("0.0.0.0", 8080);  // Escuchar en el puerto 8080

    // Después de detener el servidor, liberar recursos
    std::cout << "Cerrando conexiones. . ." << std::endl;
    delete res;
    delete stmt;
    delete conn;
    std::cout << "liberando recursos. . ." << std::endl;

    return 0;
}



// Maneja la señal de interrupción (por ejemplo, Ctrl+C)
void signal_handler(int signal)
{
    if (signal == SIGINT)
    {
        std::cout << "\nRecibido SIGINT, cerrando el servidor..." << std::endl;
        svr.stop(); // Detener el servidor de manera segura
    }
}

void handle_get(const httplib::Request& req, httplib::Response& res)
{
    std::string idt = req.get_param_value("IDT"); // IDtargeta
    if (idt.empty())
    {   
        if (!req.get_param_value("msg").empty())
        {   
            std::cout << "msg: " << req.get_param_value("msg") << std::endl;
            return;
        }
        
        if (!req.get_param_value("IDTDEL").empty())
        {
            idt = req.get_param_value("IDTDEL");
            std::cout << "IDTDEL recibido: " << idt << std::endl;
            ModificacionMySQL(idt);

            res.set_content(">del<", "text/plain"); //se se envio el del
            std::cout << "Enviada respuesta: del " << std::endl;
            return;
        }

        std::cout << "ninguna coincidencia" << std::endl;
        return;
    }

    std::cout << "Recibida solicitud GET de ID Tarjeta: " << idt << std::endl;
    std::string peticion = PeticionMySQL(idt);

    res.set_content(peticion, "text/plain"); //enviar respuesta
    std::cout << "Enviada respuesta: " << peticion << std::endl;

}



std::string PeticionMySQL(const std::string& idt)
{
    //std::string name;
    std::string pedido;
    try
    {
        stmt = conn->createStatement();
        res = stmt->executeQuery("SELECT Pedidos.nombre_pedido, Maquina.IDtargeta, Maquina.Nombre_cliente FROM Barman.Pedidos JOIN Barman.Maquina ON  Pedidos.id_usuario = Maquina.id_cliente WHERE IDtargeta = '" + idt + "' LIMIT 1;");

        while (res->next())
        {   
            pedido = res->getString("nombre_pedido");
            //name = res->getString("Nombre_cliente");
        }
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    ultimaBebida = pedido;

    return pedido;
}


void ModificacionMySQL(const std::string& idt)
{
    std::string name;
    std::string pedido;
    try
    {
        stmt = conn->createStatement();
        int filas = stmt->executeUpdate("DELETE FROM Barman.Pedidos WHERE id_usuario IN (SELECT Maquina.id_cliente FROM Barman.Maquina WHERE IDtargeta = '"+idt+"' AND nombre_pedido = '"+ ultimaBebida +"') LIMIT 1;");

        if (filas > 0)
        {
            std::cout << "Filas eliminadas: " << filas << std::endl;
        }
        else
        {
            std::cout << "No se encontró ninguna fila con los criterios especificados." << std::endl;
        }

    }
    catch (sql::SQLException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return;
}

// Función para obtener la IP local
std::string obtenerIPLocal()
{
    struct ifaddrs *ifAddrStruct = nullptr;
    struct ifaddrs *ifa = nullptr;
    void *tmpAddrPtr = nullptr;
    std::string ipLocal;

    getifaddrs(&ifAddrStruct);

    for (ifa = ifAddrStruct; ifa != nullptr; ifa = ifa->ifa_next)
    {
        if (!ifa->ifa_addr)
        {
            continue;
        }

        if (ifa->ifa_addr->sa_family == AF_INET) // Comprobar si es una dirección IPv4
        {
            tmpAddrPtr = &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);

            // Ignorar interfaces de loopback o internas
            if (strcmp(ifa->ifa_name, "lo") != 0)
            {
                ipLocal = addressBuffer;
                break;
            }
        }
    }

    if (ifAddrStruct != nullptr)
        freeifaddrs(ifAddrStruct);

    return ipLocal;
}
