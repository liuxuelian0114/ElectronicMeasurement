#include <QDebug>
#include <QDir>

#include "configmanagerdlg.h"
#include "ui_configmanagerdlg.h"
#include "localconfig.h"

ConfigManagerDlg::ConfigManagerDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigManagerDlg)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));
//    this->layout()->setSizeConstraint(QLayout::SetFixedSize);//限定窗口大小
    this->setFixedSize(this->size());//限定窗口大小

    ui->lineEditCollect->setText(localConfig.getCollectIp());
    ui->lineEditForword->setText(localConfig.getForwordIp());
    ui->lineEditNAS->setText(localConfig.getNASIp());
    ui->lineEditAccount->setText(localConfig.getNASAccount());
    ui->lineEditPassward->setText(localConfig.getNASPassword());
    ui->lineEditBatFolder->setText(QDir::toNativeSeparators(localConfig.getBatFolderAddress()));

    connect(ui->pushButtonSave, SIGNAL(clicked()), this, SLOT(onPushButtonSaveClicked()));
}

ConfigManagerDlg::~ConfigManagerDlg()
{
    delete ui;
}

void ConfigManagerDlg::onPushButtonSaveClicked()
{
    localConfig.setCollectIp(ui->lineEditCollect->text());
    localConfig.setForwordIp(ui->lineEditForword->text());
    localConfig.setNASIp(ui->lineEditNAS->text());
    localConfig.setNASAccount(ui->lineEditAccount->text());
    localConfig.setNASPassword(ui->lineEditPassward->text());
    localConfig.setBatFolderAddress(QDir::fromNativeSeparators(ui->lineEditBatFolder->text()));
    emit configChanged();
    accept();
}
