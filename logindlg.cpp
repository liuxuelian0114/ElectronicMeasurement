#include <QDebug>
#include <QMessageBox>

#include "logindlg.h"
#include "ui_logindlg.h"
#include "dbinterface.h"
#include "runtimeconfig.h"

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));
//    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    this->setFixedSize(this->size());//限定窗口大小

    ui->lineEditUser->setFocus();
    connect(ui->pushButtonQuit, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(pushButtonOkClicked()));
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::pushButtonOkClicked()
{
    QString userName = ui->lineEditUser->text();
    QString password = ui->lineEditPassword->text();
    if(userName.isEmpty())
    {
        QMessageBox::warning(this, QStringLiteral("警告"),QStringLiteral("用户名不能为空。"));
        return;
    }
    if(password.isEmpty())
    {
        QMessageBox::warning(this, QStringLiteral("警告"),QStringLiteral("密码不能为空。"));
        return;
    }
    QString permission = QString("");
    bool ok = dbInterface.checkUser(userName, password, permission);
    if(ok)
    {
        g_runTimeConfig.setUserInfo(userName, permission);
        accept();
    }
    else if(!ok && !dbInterface.errorString().isEmpty())
    {
        QMessageBox::warning(this, QStringLiteral("警告"), dbInterface.errorString());
        qDebug() << "on LoginDlg ok: " << dbInterface.errorString();
    }
    else
    {
        QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("用户不存在或密码错误。"));
        return;
    }
}
