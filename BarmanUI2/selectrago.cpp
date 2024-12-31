#include "selectrago.h"
#include "ui_selectrago.h"
#include "login.h"
#include <QTimer>
#include <iostream>

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>



SelecTrago::SelecTrago(QWidget *parent): QDialog(parent), ui(new Ui::SelecTrago)
{
    ui->setupUi(this);



    // this asegura que el modelo se destruirá automáticamente cuando la ventana principal se destruya
    model = new QStandardItemModel(this); // inicializo el modelo

    model->setColumnCount(2); // establece el numero de columnas

    model->setHorizontalHeaderLabels({"USUARIO","bebida"});//establecer los encabezados de las columnas

    //configurar el encabezado en negrita

    QFont font = model->horizontalHeaderItem(0)->font(); // Obtiene la fuente del primer encabezado de columna
    font.setBold(true); // Establece la fuente en negrita
    for (int i = 0; i < model->columnCount(); ++i)
    {
        //Aplica esta fuente en negrita a todos los encabezados de las columnas mediante un bucle.
        model->horizontalHeaderItem(i)->setFont(font);
    }

   ui->tableView->setModel(model);
    /*La función de QTableView es mostrar los datos que le proporciona el modelo.
     * En otras palabras, QTableView no almacena datos por sí mismo; en cambio, muestra
     * los datos que recibe del modelo asociado.
     *
     * Al llamar a setModel(model), estás diciendo a QTableView que use el modelo model
     * para obtener y mostrar los datos. Esto permite que cualquier cambio en el modelo se
     * refleje automáticamente en la vista de tabla.*/

    // Hace que las columnas sean responsivas
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

   //MySQLRequest();
   //Tabla_Refresh();

}

SelecTrago::~SelecTrago()
{
    delete ui;

}

void SelecTrago::Tabla_Refresh()
{
    // Elimina todas las filas del modelo para asegurarse de que los datos antiguos no queden en la vista.
    // limina filas desde la posición 0 hasta el número total de filas (rowCount()).
    model->removeRows(0, model->rowCount());

    // Crear una declaración y ejecutar una consulta
    loginptr->stmt = loginptr->conn->createStatement();
    loginptr->res = loginptr->stmt->executeQuery("SELECT Pedidos.nombre_pedido, Maquina.Nombre_cliente FROM Barman.Pedidos JOIN Barman.Maquina ON  Pedidos.id_usuario = Maquina.id_cliente;");

    while (loginptr->res->next()) // Itera sobre cada fila del ResultSet. La función next() mueve el cursor a la siguiente fila del resultado.
    {
        QStringList Columnas;
        Columnas.append(QString::fromStdString(loginptr->res->getString("Nombre_cliente")));
        Columnas.append(QString::fromStdString(loginptr->res->getString("nombre_pedido")));

        QList<QStandardItem*> rowItems;

        for (const QString &dato : Columnas )
        {
            rowItems << new QStandardItem(dato);
            //se usa para agregar un elemento a la lista rowItems.
            // Es una forma conveniente de insertar elementos en una lista en Qt.
        }

        model->appendRow(rowItems);
        /*
    agrega las nuevas fila al final del QStandardItemModel.
    Después de añadir la fila, la vista (QTableView) automáticamente se
    actualiza para mostrar los nuevos datos.
    */
    }


}




void SelecTrago::trasferirClase(login *login_)
{
    loginptr = login_;
    Tabla_Refresh();
}



void SelecTrago::on_Bebida1_clicked()
{

    try {
        loginptr->stmt = loginptr->conn->createStatement();
         int affectedRows = loginptr->stmt->executeUpdate("INSERT INTO Barman.Pedidos (`id_usuario`, `nombre_pedido`) VALUES ('"+ std::to_string(userID) +"', 'Vodka Con naranja');");
        Tabla_Refresh();
        // Código del evento que podría lanzar una excepción

        if (affectedRows > 0) {
            qDebug() << "Pedido insertado correctamente.";
        } else {
            qDebug() << "No se insertó el pedido.";
        }

    } catch (const std::exception& e) {
        qDebug() << "Error en el evento:" << e.what() << "\n";
    } catch (...) {
        qDebug() << "Error desconocido en el evento.";
    }
}


int SelecTrago::getUserID() const
{
    return userID;
}

void SelecTrago::setUserID(int newUserID)
{
    userID = newUserID;
}


void SelecTrago::on_Bebida2_clicked()
{
    try {
        loginptr->stmt = loginptr->conn->createStatement();
        int affectedRows = loginptr->stmt->executeUpdate("INSERT INTO Barman.Pedidos (`id_usuario`, `nombre_pedido`) VALUES ('"+ std::to_string(userID) +"', 'Ron Con naranja');");
        Tabla_Refresh();
        // Código del evento que podría lanzar una excepción

        if (affectedRows > 0) {
            qDebug() << "Pedido insertado correctamente.";
        } else {
            qDebug() << "No se insertó el pedido.";
        }

    } catch (const std::exception& e) {
        qDebug() << "Error en el evento:" << e.what() << "\n";
    } catch (...) {
        qDebug() << "Error desconocido en el evento.";
    }
}


void SelecTrago::on_Bebida3_clicked()
{
    try {
        loginptr->stmt = loginptr->conn->createStatement();
        int affectedRows = loginptr->stmt->executeUpdate("INSERT INTO Barman.Pedidos (`id_usuario`, `nombre_pedido`) VALUES ('"+ std::to_string(userID) +"', 'Campari Con naranja');");
        Tabla_Refresh();
        // Código del evento que podría lanzar una excepción

        if (affectedRows > 0) {
            qDebug() << "Pedido insertado correctamente.";
        } else {
            qDebug() << "No se insertó el pedido.";
        }

    } catch (const std::exception& e) {
        qDebug() << "Error en el evento:" << e.what() << "\n";
    } catch (...) {
        qDebug() << "Error desconocido en el evento.";
    }
}

