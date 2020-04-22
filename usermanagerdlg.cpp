#include <QDebug>
#include <QMessageBox>

#include "usermanagerdlg.h"
#include "ui_usermanagerdlg.h"
#include "dbinterface.h"
#include "runtimeconfig.h"
#include "userinfodlg.h"

UserManagerDlg::UserManagerDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserManagerDlg)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));
    this->setFixedSize(this->size());//限定窗口大小

    initInfo();
    ui->tableWidgetUserInfo->setFocusPolicy(Qt::NoFocus);//失去焦点
    ui->tableWidgetUserInfo->verticalHeader()->setHidden(true);//去掉每行的行号
    ui->tableWidgetUserInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetUserInfo->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetUserInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(onPushButtonAddClicked()));
    connect(ui->pushButtonEdit, SIGNAL(clicked()), this, SLOT(onPushButtonEditClicked()));
    connect(ui->pushButtonDelete, SIGNAL(clicked()), this, SLOT(onPushButtonDeleteClicked()));
}

UserManagerDlg::~UserManagerDlg()
{
    delete ui;
}

void UserManagerDlg::initInfo()
{
    QStringList users;
    if(!dbInterface.showUser(users))
    {
        qWarning() << "on UserManagerDlg initInfo: " << dbInterface.errorString();
        return;
    }
    for(int i = 0; i < users.count();)
    {
        int row = ui->tableWidgetUserInfo->currentRow() + 1;
        ui->tableWidgetUserInfo->insertRow(row);
        ui->tableWidgetUserInfo->setItem(row, 0, new QTableWidgetItem(users.at(i)));
        ui->tableWidgetUserInfo->setItem(row, 1, new QTableWidgetItem(users.at(i + 1)));
        ui->tableWidgetUserInfo->setItem(row, 2, new QTableWidgetItem(users.at(i + 2)));
        i += 3;
    }
}

void UserManagerDlg::onPushButtonAddClicked()
{
    UserInfoDlg *pUserInfo = new UserInfoDlg(this);
    pUserInfo->setWindowTitle(QStringLiteral("添加用户"));
    connect(pUserInfo, SIGNAL(rejected()), pUserInfo, SLOT(deleteLater()));
    if(QStringLiteral("高级用户") == g_runTimeConfig.getPermission())
    {
        pUserInfo->setComboxPermission(true);
    }
    pUserInfo->open();

    connect(pUserInfo, &UserInfoDlg::userInfoChanged, [&](QStringList infos)
    {
        bool ok = dbInterface.recheckUser(infos.at(0));
        if(!ok && !dbInterface.errorString().isEmpty())
        {
            qDebug() << "on UserManagerDlg edit: " << dbInterface.errorString();
        }
        else if(ok)
        {
            QString text = infos.at(0);
            text.append(QStringLiteral("用户名已存在。"));
            QMessageBox::about(this, QStringLiteral("提示"), text);
        }
        else
        {
            if(!dbInterface.insertUser(infos))
            {
                qDebug() << "on UserManagerDlg add: " << dbInterface.errorString();
                QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("用户添加失败。"));
            }
            else
            {
                int row = ui->tableWidgetUserInfo->rowCount();
                ui->tableWidgetUserInfo->insertRow(row);
                ui->tableWidgetUserInfo->setItem(row, 0, new QTableWidgetItem(infos.at(0)));
                ui->tableWidgetUserInfo->setItem(row, 1, new QTableWidgetItem(infos.at(1)));
                ui->tableWidgetUserInfo->setItem(row, 2, new QTableWidgetItem(infos.at(2)));
            }
        }
    });
}

void UserManagerDlg::onPushButtonEditClicked()
{
    int row = ui->tableWidgetUserInfo->currentRow();
    if(-1 == row)
    {
        QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("请选择用户。"));
        return;
    }
    QStringList userInfos;
    userInfos.append(ui->tableWidgetUserInfo->item(row, 0)->text());
    userInfos.append(ui->tableWidgetUserInfo->item(row, 1)->text());
    userInfos.append(ui->tableWidgetUserInfo->item(row, 2)->text());

    UserInfoDlg *pUserInfo = new UserInfoDlg(this);
    pUserInfo->setWindowTitle(QStringLiteral("编辑用户"));
    connect(pUserInfo, SIGNAL(rejected()), pUserInfo, SLOT(deleteLater()));
    if(QStringLiteral("高级用户") == g_runTimeConfig.getPermission())
    {
        pUserInfo->setComboxPermission(true);
        if(QStringLiteral("超级用户") == ui->tableWidgetUserInfo->item(row, 2)->text())
        {
            QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("操作权限不够。"));
            return;
        }
    }
    if(g_runTimeConfig.getUserName() == ui->tableWidgetUserInfo->item(row, 0)->text())
    {
        pUserInfo->setEditUserInfo(userInfos, false);
    }
    else
    {
        pUserInfo->setEditUserInfo(userInfos, true);
    }
    pUserInfo->open();
    connect(pUserInfo, &UserInfoDlg::userInfoChanged, [&](QStringList infos)
    {
        int rowNum = ui->tableWidgetUserInfo->currentRow();
        if(dbInterface.updataUser(infos))
        {
            ui->tableWidgetUserInfo->item(rowNum, 0)->setText(infos.at(0));
            ui->tableWidgetUserInfo->item(rowNum, 1)->setText(infos.at(1));
            ui->tableWidgetUserInfo->item(rowNum, 2)->setText(infos.at(2));
            QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("编辑成功。"));
        }
        else
        {
            qDebug() << "on UserManagerDlg edit: " << dbInterface.errorString();
            QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("编辑失败。"));
        }
    });
}

void UserManagerDlg::onPushButtonDeleteClicked()
{
    int row = ui->tableWidgetUserInfo->currentRow();
    if(-1 == row)
    {
        QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("请选择用户。"));
        return;
    }
    if(g_runTimeConfig.getUserName() == ui->tableWidgetUserInfo->item(row, 0)->text())
    {
        QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("不能删除自己的账户。"));
        return;
    }
    if(QStringLiteral("高级用户") == g_runTimeConfig.getPermission())
    {
        if(QStringLiteral("超级用户") == ui->tableWidgetUserInfo->item(row, 2)->text())
        {
            QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("操作权限不够。"));
            return;
        }
    }

    if(!dbInterface.deleteUser(ui->tableWidgetUserInfo->item(row, 0)->text()))
    {
        qDebug() << "on UserManagerDlg delete: " << dbInterface.errorString();
        QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("删除失败"));
    }
    else
    {
        ui->tableWidgetUserInfo->removeRow(row);
        QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("删除成功"));
    }
}
