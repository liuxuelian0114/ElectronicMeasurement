#include <QListWidgetItem>
#include <QDebug>
#include <QMessageBox>

#include "argumentmanagerdlg.h"
#include "ui_argumentmanagerdlg.h"
#include "argumentinfodlg.h"
#include "dbinterface.h"

ArgumentManagerDlg::ArgumentManagerDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArgumentManagerDlg)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));
//    ui->listWidget->addItem(QStringLiteral("模板"));
    QStringList testName;
    if(!dbInterface.getTestName(testName))
    {
        qDebug() << "on ArgumentManagerDlg init: " << dbInterface.errorString();
    }
    ui->listWidget->addItems(testName); 
//    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onItemDoubleClicked(QListWidgetItem*)));
    connect(ui->pushButtonAddTemplate,SIGNAL(clicked()),this,SLOT(onPushButtonAddTemplate()));
    connect(ui->pushButtonSetTemplate,SIGNAL(clicked()),this, SLOT(onPushButtonSetTemplate()));
    connect(ui->pushButtonDeleteTemplete, SIGNAL(clicked()),this, SLOT(onPushButtonDaleteTemplate()));
}

ArgumentManagerDlg::~ArgumentManagerDlg()
{
    delete ui;
}

void ArgumentManagerDlg::onSettingTemplate(QString oldName, QString newName)
{
    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        if(ui->listWidget->item(i)->text() == oldName)
        {
            ui->listWidget->item(i)->setText(newName);
        }
    }

    for(int i = 0; i < ui->tabWidget->count(); i++)
    {
        if(ui->tabWidget->tabText(i) == oldName)
        {
            ui->tabWidget->setTabText(i, newName);
            break;
        }
    }
}

void ArgumentManagerDlg::onAddTemplate(QString name)
{
    ui->listWidget->addItem(name);
}

void ArgumentManagerDlg::onPushButtonAddTemplate()
{
    ArgumentInfoDlg *argumentInfo = new ArgumentInfoDlg(this);
    argumentInfo->setAttribute(Qt::WA_DeleteOnClose);
    connect(argumentInfo,SIGNAL(addTemplate(QString)),this, SLOT(onAddTemplate(QString)));
    argumentInfo->exec();
}

void ArgumentManagerDlg::onPushButtonSetTemplate()
{
    if(ui->listWidget->currentItem()->text()== QStringLiteral("模板"))
    {
        QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("请选择需要设置的模板!"));
        return;
    }


// 查找选择设置的模板是否已经打开
    ArgumentInfoDlg *argumentInfo = new ArgumentInfoDlg(this);
    argumentInfo->showTestArgument(ui->listWidget->currentItem()->text());
    bool check = false; //保存当前设置的模板是否已经找到
    for(int i = 0; i < ui->tabWidget->count(); i++)
    {
        if(ui->tabWidget->tabText(i) == ui->listWidget->currentItem()->text())
        {
            check = true;
            ui->tabWidget->setCurrentIndex(i);
            break;
        }
    }

    //1、 当前选择设置的模板没有找到，则将此模板添加进ui->tabWidget
    //2、 并将argumentInfo的信号与此设置连接，在argumentInfo保存参数后，让ui->tabWidget修改为相应的名字
    if(!check)
    {
        connect(argumentInfo, SIGNAL(settingTemplate(QString,QString)), this, SLOT(onSettingTemplate(QString,QString)));
        ui->tabWidget->addTab(argumentInfo, ui->listWidget->currentItem()->text());
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
    }
}

void ArgumentManagerDlg::onPushButtonDaleteTemplate()
{
    if(ui->listWidget->currentItem()->text()== QStringLiteral("模板"))
    {

         QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("请选择需要删除的模板!"));
         return;
    }
    else
    {
        if(QMessageBox::Yes == QMessageBox::question(this,QStringLiteral("提示"),
                              QStringLiteral("确定删除此模板吗？"),QMessageBox::Yes | QMessageBox::No))
        {
            QListWidgetItem *curItem;
            curItem = ui->listWidget->currentItem();

 //从数据库中删除选择的模板
            if(!dbInterface.deleteTemplate(curItem->text()))
            {
                 qDebug() << QStringLiteral("从数据库中删除模板失败：") << dbInterface.errorString();
                 return;
            }

//从模板展示界面删除相关模板的信息
            ui->listWidget->removeItemWidget(curItem);

            for(int i = 0; i < ui->tabWidget->count(); i++)
            {
                if(ui->tabWidget->tabText(i) == ui->listWidget->currentItem()->text())
                {
                    ui->tabWidget->removeTab(i);
                    break;
                }
            }
            delete curItem;
            curItem =nullptr;
        }
        else
        {
            return;
        }
    }
}

