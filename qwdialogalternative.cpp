#include "qwdialogalternative.h"
#include "ui_qwdialogalternative.h"
#include <QVector>
#include <QDebug>
QWDialogAlternative::QWDialogAlternative(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogAlternative)
{
    ui->setupUi(this);
    Find_EN_Alternative=nullptr;
    Find_CHN_Alternative=nullptr;
}


QWDialogAlternative::~QWDialogAlternative()
{
    qDebug()<<"destroyed";
    list.clear();
    delete ui;
}

QString QWDialogAlternative::process_meaning_with_wordkind(Meaning *tmp)
{
    QString str;
    switch(tmp->word_kind)
    {
    case noun:
        str+="n.";
        break;
    case verb:
        str+="v.";
        break;
    case pron:
        str+="pron.";
        break;
    case prep:
        str+="prep.";
        break;
    case intj:
        str+="intj.";
        break;
    case adj:
        str+="adj.";
        break;
    case adv:
        str+="adv.";
        break;
    case conj:
        str+="conj.";
        break;
    case abbr:
        str+="abbr.";
        break;
    case art:
        str+="art.";
        break;
    case num:
        str+="num.";
        break;
    default:
        str+="unkonwn.";
        break;
    }
    str+=QString::fromStdString(tmp->meaning);
    return str;
}

void QWDialogAlternative::set_original_text(QString str)
{
    ui->textBrowser_Original->clear();
    ui->textBrowser_Original->setText(str);
    if(Find_EN_Alternative!=nullptr)
    {
        list=str.split(" ");
    }
    else
    {

    }
}

void QWDialogAlternative::set_EN_Alternative()
{
    int word_num=this->Find_EN_Alternative->size();
    for(int i=1;i<=word_num;i++)
    {
        ui->comboBox_Order->addItem(QString::asprintf("选项%d",i));
    }
    ui->comboBox_Order->setCurrentIndex(0);
    ui->comboBox_Item->clear();
    auto it=Find_EN_Alternative->begin();
    for(auto it_tmp=(*it)->node_content->meanings->begin();it_tmp!=(*it)->node_content->meanings->end();it_tmp++)
    {
        //ui->comboBox_Item->addItem(QString::fromStdString((*it_tmp)->meaning));
        ui->comboBox_Item->addItem(process_meaning_with_wordkind(*it_tmp));
    }
}

void QWDialogAlternative::set_CHN_Alternative()
{
    int word_num=this->Find_CHN_Alternative->size();
    for(int i=0;i<word_num;i++)
    {
        list.append(" ");
    }
    for(int i=1;i<=word_num;i++)
    {
        ui->comboBox_Order->addItem(QString::asprintf("选项%d",i));
    }
    ui->comboBox_Order->setCurrentIndex(0);
    ui->comboBox_Item->clear();
    auto it=Find_CHN_Alternative->begin();
    for(auto it_tmp=(*it)->node_content->meanings->begin();it_tmp!=(*it)->node_content->meanings->end();it_tmp++)
    {
        //ui->comboBox_Item->addItem(QString::fromStdString((*it_tmp)->meaning));
        ui->comboBox_Item->addItem(process_meaning_with_wordkind(*it_tmp));
    }
}

void QWDialogAlternative::get_EN_Alternative(vector<CHN_Dic_node *> *Find_EN_Alternative)
{
    this->Find_EN_Alternative=Find_EN_Alternative;
}

void QWDialogAlternative::get_CHN_Alternative(vector<EN_Dic_node *> *Find_CHN_Alternative)
{
    this->Find_CHN_Alternative=Find_CHN_Alternative;
}

void QWDialogAlternative::on_comboBox_Order_currentIndexChanged(int index)
{
    if(Find_EN_Alternative!=nullptr)
    {
        auto it=Find_EN_Alternative->begin();
        it+=index;
        ui->comboBox_Item->clear();
        for(auto it_tmp=(*it)->node_content->meanings->begin();it_tmp!=(*it)->node_content->meanings->end();it_tmp++)
        {
            //ui->comboBox_Item->addItem(QString::fromStdString((*it_tmp)->meaning));
            ui->comboBox_Item->addItem(process_meaning_with_wordkind(*it_tmp));
        }
    }
    else
    {
        auto it=Find_CHN_Alternative->begin();
        it+=index;
        ui->comboBox_Item->clear();
        for(auto it_tmp=(*it)->node_content->meanings->begin();it_tmp!=(*it)->node_content->meanings->end();it_tmp++)
        {
            //ui->comboBox_Item->addItem(QString::fromStdString((*it_tmp)->meaning));
            ui->comboBox_Item->addItem(process_meaning_with_wordkind(*it_tmp));
        }
    }

}

void QWDialogAlternative::on_comboBox_Item_currentIndexChanged(const QString &arg1)
{
        int num=ui->comboBox_Order->currentIndex();
        int cut=arg1.indexOf(".");
        QString arg2=arg1.mid(cut+1);
 //       qDebug()<<arg1<<" "<<num<<" "<<cut<<" "<<arg2;
        list.replace(num,arg2);
        ui->plainTextEdit_Alternative->clear();
        if(Find_EN_Alternative!=nullptr)
        {
            ui->plainTextEdit_Alternative->appendPlainText(list.join(" "));
        }
        else
        {
            ui->plainTextEdit_Alternative->appendPlainText(list.join(""));
        }
}


QString QWDialogAlternative::return_alternative_string()
{
    QString str=ui->plainTextEdit_Alternative->toPlainText();
    return str;
}
