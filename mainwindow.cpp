#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include <qmessagebox.h>
#include "qwdialogalternative.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(ui->spinFontSize,SIGNAL(valueChanged(int)),this,SLOT(on_spinFontSize_valueChanged(int)));
//    connect(ui->BtnTranslate,SIGNAL(clicked()),this,SLOT(on_BtnTranslate_clicked()));
//    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    ui->spinFontSize->setValue(15);
    my_dic=nullptr;
    Find_CHN_Alternative=new vector<EN_Dic_node *>;
    Find_EN_Alternative=new vector<CHN_Dic_node *>;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinFontSize_valueChanged(int arg1)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(arg1);
    ui->plainText_EN->mergeCurrentCharFormat(fmt);
    ui->plainText_CHN->mergeCurrentCharFormat(fmt);
    ui->spinFontSize->setValue(arg1);
}

void MainWindow::on_pushButton_clicked()
{
    QString curPath=QDir::currentPath();
    QString title="选择词典文件";
    QString filter="文本文件(*.txt)";
    QString FileName=QFileDialog::getOpenFileName(this,title,curPath,filter);
    FileName.replace(QString("/"),QString("\\"));
    string str=FileName.toStdString();
    if(!str.empty())
    {
        if(my_dic==nullptr)
        {
            my_dic=new DIC();
            my_dic->initialize(str);
        }
        else
        {
            delete my_dic;
            my_dic=new DIC();
            my_dic->initialize(str);
        }
    }
}

void MainWindow::on_BtnTranslate_clicked()
{
    try
    {
        if(my_dic==nullptr)
        {
            throw -2;
        }
        Find_CHN_Alternative->clear();
        Find_EN_Alternative->clear();
        if(ui->rBtnEN_to_CHN->isChecked())
        {
            QString str1=ui->plainText_EN->toPlainText();
            string str2=str1.toStdString();
            string *result=my_dic->print_EN_to_CHN(str2,Find_CHN_Alternative);
            QString chn=QString::fromStdString(*result);
            ui->plainText_CHN->clear();
            ui->plainText_CHN->appendPlainText(chn);
        }
        else if(ui->rBtnCHN_to_EN->isChecked())
        {
            QString str1=ui->plainText_CHN->toPlainText();
            string str2=str1.toStdString();
            string *result=my_dic->print_CHN_to_EN(str2,Find_EN_Alternative);
            QString en=QString::fromStdString(*result);
            ui->plainText_EN->clear();
            ui->plainText_EN->appendPlainText(en);
        }
    }
    catch(int i)
    {
        if(i==-1)
        {
            QMessageBox::critical(this,"Error!","查询不到相关表达，请重新输入！");
        }
        else if(i==-2)
        {
            QMessageBox::critical(this,"Error!","未选择词典，请先选择词典！");
        }
    }
}

void MainWindow::on_btnAlternative_clicked()
{
    QWDialogAlternative *dlgAlternative=new QWDialogAlternative(this);
    Qt::WindowFlags flags=dlgAlternative->windowFlags();
    dlgAlternative->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
    if(this->ui->rBtnCHN_to_EN->isChecked())
    {
       QString str=ui->plainText_EN->toPlainText();
       dlgAlternative->get_EN_Alternative(this->Find_EN_Alternative);
       dlgAlternative->set_original_text(str);
       dlgAlternative->set_EN_Alternative();
    }
    else if(this->ui->rBtnEN_to_CHN->isChecked())
    {
        QString str=ui->plainText_CHN->toPlainText();
        dlgAlternative->set_original_text(str);
        dlgAlternative->get_CHN_Alternative(this->Find_CHN_Alternative);
        dlgAlternative->set_CHN_Alternative();
    }

    int ret=dlgAlternative->exec();

    if(ret==QDialog::Accepted)
    {
        QString str=dlgAlternative->return_alternative_string();
        if(ui->rBtnCHN_to_EN->isChecked())
        {
            ui->plainText_EN->clear();
            ui->plainText_EN->appendPlainText(str);
        }
        else
        {
            ui->plainText_CHN->clear();
            ui->plainText_CHN->appendPlainText(str);
        }
    }

    delete dlgAlternative;

}
