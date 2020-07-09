#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DIC.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_spinFontSize_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_BtnTranslate_clicked();

    void on_btnAlternative_clicked();

private:
    Ui::MainWindow *ui;

public:
    DIC *my_dic;
    vector<CHN_Dic_node *> * Find_EN_Alternative;
    vector<EN_Dic_node *> * Find_CHN_Alternative;
};

#endif // MAINWINDOW_H
