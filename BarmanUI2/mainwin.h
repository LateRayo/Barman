#ifndef MAINWIN_H
#define MAINWIN_H

#include <QDialog>

namespace Ui {
class MainWin;
}

class MainWin : public QDialog
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = nullptr);
    ~MainWin();

private:
    Ui::MainWin *ui;
};

#endif // MAINWIN_H
