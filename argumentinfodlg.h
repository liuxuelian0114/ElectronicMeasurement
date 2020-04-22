#ifndef ARGUMENTINFODLG_H
#define ARGUMENTINFODLG_H

#include <QDialog>

namespace Ui {
class ArgumentInfoDlg;
}

class ArgumentInfoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ArgumentInfoDlg(QWidget *parent = 0);
    ~ArgumentInfoDlg();

public:
    void showTestArgument(QString testName);/*显示testName实验的所有参数*/

signals:
    void testArgsChanges(QString oldName, QString newName);/*设置模板信号*/
    void settingTemplate(QString oldName, QString newName);/*设置模板信号*/
    void addTemplate(QString testName);/*添加模板信号*/
    void deleteTemplate();/*删除模板信号*/

public slots:
    void onPushButtonSaveClicked();/*保存按钮点击槽函数*/

private slots:
    void onTextChanged(QString text);/*启动保存按钮,保存按钮默认不启动（构造函数中不启动）*/

private:
    int templateArgCheck();

private:
    Ui::ArgumentInfoDlg *ui;
    QString m_testName;
    QString m_oldTestName;
};

#endif // ARGUMENTINFODLG_H
