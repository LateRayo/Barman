#include "login.h"
#include "ui_login.h"
#include "selectrago.h"
#include <iostream>




login::login(QWidget *parent): QMainWindow(parent), ui(new Ui::login)
{
    ui->setupUi(this);
    ui->lineEdit_2->setPlaceholderText("usuario");
    ui->lineEdit->setPlaceholderText("contraseña");

    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, &login::normalUser);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &login::normalPSS);

    MySQLRequest();
}

login::~login()
{
    delete ui;
    // Liberar recursos
    delete res;
    delete stmt;
    delete conn;
}

void login::on_pushButton_clicked()
{
    QString usuario = ui->lineEdit_2->text();
    QString password = ui->lineEdit->text();


    stmt = conn->createStatement(); //Crea un objeto Statement a partir de la conexión. Este objeto se utiliza para enviar consultas SQL a la base de datos.

    try
    {
        // Ejecuta la consulta
        res = stmt->executeQuery("SELECT * FROM Barman.Maquina WHERE Nombre_cliente = '" + usuario.toStdString() + "'");

        // Verifica si hay resultados
        if (!res->next())
        {
            std::cout << "No se encontraron resultados para el cliente: " << usuario.toStdString() << std::endl;
            // Aquí podrías mostrar un mensaje en la interfaz o manejar el flujo según sea necesario
            ui->lineEdit_2->setStyleSheet("border: 1px solid red;");
            ui->lineEdit->setStyleSheet("border: 1px solid red;");
        } else
        {
            int id_cliente = res->getInt("Id_cliente");
            if(res->getString("Nombre_cliente") == usuario.toStdString() && res->getString("Password_cliente") == password.toStdString() )
            {
                ui->lineEdit_2->setStyleSheet("border: 1px solid green;");
                ui->lineEdit->setStyleSheet("border: 1px solid green;");

                SelecTrago t;
                t.trasferirClase(this);
                t.setUserID(id_cliente);
                t.exec();
            }
            else
            {
                ui->lineEdit_2->setStyleSheet("border: 1px solid red;");
                ui->lineEdit->setStyleSheet("border: 1px solid red;");
            }
        }

    } catch (sql::SQLException &e) {
        std::cerr << "Error en la consulta SQL: " << e.what() << std::endl;
        // Maneja el error adecuadamente (por ejemplo, mostrando un mensaje de error en la interfaz)
    }

}

void login::MySQLRequest()
{

    try
    {
        driver = sql::mysql::get_mysql_driver_instance();
        conn = driver->connect("tcp://127.0.0.1:3306", "nico", "Bitcoin256@");
        conn->setSchema("Barman");

    } catch (sql::SQLException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void login::normalUser()
{

    ui->lineEdit_2->setStyleSheet("");
}

void login::normalPSS()
{

    ui->lineEdit->setStyleSheet("");
}


void login::on_cerrar_clicked()
{
    this->close();
}

