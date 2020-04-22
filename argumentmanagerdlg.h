#ifndef ARGUMENTMANAGERDLG_H
#define ARGUMENTMANAGERDLG_H

#include <QDialog>

class QListWidgetItem;

namespace Ui {
class ArgumentManagerDlg;
}

class ArgumentManagerDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ArgumentManagerDlg(QWidget *parent = 0);
    ~ArgumentManagerDlg();

private slots:
    void onSettingTemplate(QString oldName, QString newName);/*界面修改模板名 ListWidget 和tabWidget*/
    void onAddTemplate(QString name);/*界面添加模板名 listWidget*/
    void onPushButtonAddTemplate();/*执行添加模板操作*/
    void onPushButtonSetTemplate();/*执行设置模板操作*/
    void onPushButtonDaleteTemplate();/*执行删除模板操作*/

private:
    Ui::ArgumentManagerDlg *ui;
};

#endif // ARGUMENTMANAGERDLG_H
