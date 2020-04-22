#include <QMessageBox>

#include "userinfodlg.h"
#include "ui_userinfodlg.h"

UserInfoDlg::UserInfoDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInfoDlg)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));
//    this->layout()->setSizeConstraint(QLayout::SetFixedSize);//限定窗口大小
    this->setFixedSize(this->size());//限定窗口大小

    connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(onPushButtonOkClicked()));
}

UserInfoDlg::~UserInfoDlg()
{
    delete ui;
}

void UserInfoDlg::setEditUserInfo(const QStringList &infos, const bool &ok)
{
    ui->lineEditUserName->setText(infos.at(0));
    ui->lineEditPassword->setText(infos.at(1));
    ui->comboBoxPermission->setCurrentText(infos.at(2));
    ui->comboBoxPermission->setEnabled(ok);
    ui->lineEditUserName->setEnabled(false);
}

void UserInfoDlg::setComboxPermission(const bool &ok)
{
    if(ok)
    {
        ui->comboBoxPermission->removeItem(2);
    }
}

void UserInfoDlg::onPushButtonOkClicked()
{
    if(ui->lineEditUserName->text().isEmpty() || ui->lineEditPassword->text().isEmpty())
    {
        QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("信息不能为空。"));
        return;
    }
    QStringList infos;
    infos.append(ui->lineEditUserName->text());
    infos.append(ui->lineEditPassword->text());
    infos.append(ui->comboBoxPermission->currentText());
    emit userInfoChanged(infos);
    accept();
}
