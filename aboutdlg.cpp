#include "aboutdlg.h"
#include "ui_aboutdlg.h"

AboutDlg::AboutDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDlg)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    setWindowTitle(QStringLiteral("关于"));
    setWindowOpacity(0.9);
    setFixedSize(geometry().width(), geometry().height());

    ui->labelName->setFont(QFont("Timers", 10, QFont::Bold));
    ui->labelSoftName->setFont(QFont("Timers", 10, QFont::Bold));
    ui->labelVersion->setFont(QFont("Timers", 10, QFont::Bold));
    ui->labelSoftVersion->setFont(QFont("Timers", 10, QFont::Bold));
}

AboutDlg::~AboutDlg()
{
    delete ui;
}

/*p2更改2222*/
