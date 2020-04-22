#include <QDebug>
#include <QListWidgetItem>

#include "choosetestdlg.h"
#include "ui_choosetestdlg.h"
#include "dbinterface.h"

ChooseTestDlg::ChooseTestDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseTestDlg)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));
//    this->layout()->setSizeConstraint(QLayout::SetFixedSize);//限定窗口大小
    this->setFixedSize(this->size());//限定窗口大小

    QStringList testName;
    if(!dbInterface.getTestName(testName))
    {
        qDebug() << "on ChooseTestDlg init: " << dbInterface.errorString();
    }
    ui->listWidget->addItems(testName);

    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onLWitemDoubleClicked(QListWidgetItem*)));
}

ChooseTestDlg::~ChooseTestDlg()
{
    delete ui;
}

void ChooseTestDlg::onLWitemDoubleClicked(QListWidgetItem *item)
{
    emit testNameChanged(item->text());
    accept();
}
