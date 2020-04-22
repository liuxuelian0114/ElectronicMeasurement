#include "SelectPath.h"
#include "ui_SelectPath.h"
#include <QMessageBox>
#include <QDir>

SelectPath::SelectPath(QWidget *parent,int model) :
    QDialog(parent),
    ui(new Ui::SelectPath)
{
    ui->setupUi(this);
    m_model = model;
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));
    connect(ui->pushButtonDetermine,SIGNAL(clicked()),this,SLOT(onPushButtonDetermine()));
}

SelectPath::~SelectPath()
{
    delete ui;
}

void SelectPath::onPushButtonDetermine()
{
    if(ui->lineEditPath->text().isEmpty())
    {
        QMessageBox::warning(this, QStringLiteral("提示"),
                             QStringLiteral("请选择路径"),QMessageBox::Ok);
        return;
    }
    emit reportExperiment(m_model, QDir::fromNativeSeparators(ui->lineEditPath->text()));
}
