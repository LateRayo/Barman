#ifndef SELECTRAGO_H
#define SELECTRAGO_H

#include <QDialog>
#include "login.h"
#include <QStandardItemModel>

namespace Ui {
class SelecTrago;
}

class SelecTrago : public QDialog
{
    Q_OBJECT

public:
    void trasferirClase(login *login_);
    explicit SelecTrago(QWidget *parent = nullptr);
    ~SelecTrago();
    void Tabla_Refresh();


    QString getUser() const;
    void setUser(const QString &newUser);

    int getUserID() const;
    void setUserID(int newUserID);

private slots:
    void on_Bebida1_clicked();

    void on_Bebida2_clicked();

    void on_Bebida3_clicked();

private:
    Ui::SelecTrago *ui;
    QStandardItemModel *model;
    login *loginptr;
    int userID;

};

#endif // SELECTRAGO_H
