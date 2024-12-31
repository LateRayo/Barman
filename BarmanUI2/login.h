#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class login;
}
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();
    void MySQLRequest();
    void normalUser();
    void normalPSS();

    sql::mysql::MySQL_Driver *driver;
    sql::Connection *conn;
    sql::Statement *stmt;
    sql::ResultSet *res;

private slots:
    void on_pushButton_clicked();

    void on_cerrar_clicked();

private:
    Ui::login *ui;


};
#endif // LOGIN_H
