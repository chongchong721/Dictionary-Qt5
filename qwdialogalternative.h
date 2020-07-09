#ifndef QWDIALOGALTERNATIVE_H
#define QWDIALOGALTERNATIVE_H

#include <QDialog>
#include "DIC.h"
namespace Ui {
class QWDialogAlternative;
}

class QWDialogAlternative : public QDialog
{
    Q_OBJECT

public:
    explicit QWDialogAlternative(QWidget *parent = 0);
    ~QWDialogAlternative();

    QString return_alternative_string();
    void get_EN_Alternative(vector<CHN_Dic_node *> * Find_EN_Alternative);
    void get_CHN_Alternative(vector<EN_Dic_node *> * Find_CHN_Alternative);
    void set_original_text(QString str);
    void set_EN_Alternative();
    void set_CHN_Alternative();
    QString process_meaning_with_wordkind(Meaning *tmp);
private slots:
    void on_comboBox_Order_currentIndexChanged(int index);

    void on_comboBox_Item_currentIndexChanged(const QString &arg1);

private:
    Ui::QWDialogAlternative *ui;
    vector<CHN_Dic_node *> * Find_EN_Alternative;
    vector<EN_Dic_node *> * Find_CHN_Alternative;
    QStringList list;
};

#endif // QWDIALOGALTERNATIVE_H
