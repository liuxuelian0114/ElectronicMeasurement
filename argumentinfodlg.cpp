#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>

#include "argumentinfodlg.h"
#include "ui_argumentinfodlg.h"
#include "dbinterface.h"

ArgumentInfoDlg::ArgumentInfoDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArgumentInfoDlg)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));

    ui->pushButtonSave->setEnabled(false);
    ui->lineEditIdentifying->setFocusPolicy(Qt::NoFocus);

    //限定输入
    ui->lineEditSweepFStart->setValidator(new QIntValidator(1000,18000,this));
    ui->lineEditSweepFEnd->setValidator(new QIntValidator(1000,18000,this));
    ui->lineEditAtten->setValidator(new QIntValidator(this));
    ui->lineEditSpeedH->setValidator(new QIntValidator(0,999,this));
    ui->lineEditSpeedV->setValidator(new QIntValidator(0,999,this));
    ui->lineEditStartX->setValidator(new QIntValidator(0,5900,this));
    ui->lineEditStartY->setValidator(new QIntValidator(0,6000,this));
    ui->lineEditEndX->setValidator(new QIntValidator(0,5900,this));
    ui->lineEditEndY->setValidator(new QIntValidator(0,6000,this));
    ui->lineEditStepY->setValidator(new QIntValidator(0,1000,this));

    connect(ui->pushButtonSave, SIGNAL(clicked()), this, SLOT(onPushButtonSaveClicked()));
    connect(ui->lineEditTestName, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->comboBoxGather, SIGNAL(currentTextChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->comboBoxSys_init, SIGNAL(currentTextChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->comboBoxReset, SIGNAL(currentTextChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->comboBoxCal, SIGNAL(currentTextChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEditSweepFStart, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEditAtten, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));

    connect(ui->lineEditSpeedH, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEditSpeedV, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEditStartX, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEditStartY, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEditEndX, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEditEndY, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEditStepY, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));

    connect(ui->lineEdit_batch, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEdit_bpXNum, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEdit_bpXSize, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEdit_bpXStartLocation, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEdit_bpYNum, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEdit_bpYSize, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEdit_bpYStartLocation, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEdit_bpZNum, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEdit_bpZSize, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEdit_bpZStartLocation, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEdit_StartFrequency, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->lineEdit_EndFrequenncy, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->textEdit_TestRecord, SIGNAL(textChanged()), this, SLOT(onTextChanged(QString)));

}

ArgumentInfoDlg::~ArgumentInfoDlg()
{
    delete ui;
}

void ArgumentInfoDlg::showTestArgument(QString testName)
{
    m_testName = testName;
    QStringList args;
    if(!dbInterface.getTestArg(args, testName))
    {
        qWarning() << "on ArgumentInfoDlg show: " << dbInterface.errorString();
        return;
    }

    if(!args.isEmpty())
    {

        ui->lineEditIdentifying->setText(args.takeFirst());
        ui->lineEditTestName->setText(args.takeFirst());
        ui->comboBoxGather->setCurrentIndex(args.takeFirst().toInt());
        ui->comboBoxSys_init->setCurrentIndex(args.takeFirst().toInt());
        ui->comboBoxReset->setCurrentIndex(args.takeFirst().toInt());
        ui->comboBoxCal->setCurrentIndex(args.takeFirst().toInt());
        ui->lineEditSweepFStart->setText(args.takeFirst());
        ui->lineEditSweepFEnd->setText(args.takeFirst());
        ui->lineEditAtten->setText(args.takeFirst());

        ui->lineEditSpeedH->setText(args.takeFirst());
        ui->lineEditSpeedV->setText(args.takeFirst());
        ui->lineEditStartX->setText(QString::number((args.takeFirst().toDouble()/* / 100*/)));
        ui->lineEditStartY->setText(QString::number((args.takeFirst().toDouble()/* / 100*/)));
        ui->lineEditEndX->setText(QString::number((args.takeFirst().toDouble()/* / 100*/)));
        ui->lineEditEndY->setText(QString::number((args.takeFirst().toDouble()/* / 100*/)));
        ui->lineEditStepY->setText(QString::number((args.takeFirst().toDouble()/* / 100*/)));

        ui->lineEdit_batch->setText(args.takeFirst());
        ui->lineEdit_bpXNum->setText(args.takeFirst());
        ui->lineEdit_bpXSize->setText(args.takeFirst());
        ui->lineEdit_bpXStartLocation->setText(args.takeFirst());
        ui->lineEdit_bpYNum->setText(args.takeFirst());
        ui->lineEdit_bpYSize->setText(args.takeFirst());
        ui->lineEdit_bpYStartLocation->setText(args.takeFirst());
        ui->lineEdit_bpZNum->setText(args.takeFirst());
        ui->lineEdit_bpZSize->setText(args.takeFirst());
        ui->lineEdit_bpZStartLocation->setText(args.takeFirst());
        ui->lineEdit_StartFrequency->setText(args.takeFirst());
        ui->lineEdit_EndFrequenncy->setText(args.takeFirst());
        ui->textEdit_TestRecord->setText(args.takeFirst());

    }
    else
    {
        qWarning() << "on argument info dlg show test argument, args is empty";
    }
    ui->pushButtonSave->setEnabled(false);
}

void ArgumentInfoDlg::onPushButtonSaveClicked()
{
    int ret = templateArgCheck();
    if(0 == ret)
    {
        return;
    }
    QStringList args;
    args.append(ui->lineEditTestName->text());
    args.append(QString::number(ui->comboBoxGather->currentIndex()));
    args.append(QString::number(ui->comboBoxSys_init->currentIndex()));
    args.append(QString::number(ui->comboBoxReset->currentIndex()));
    args.append(QString::number(ui->comboBoxCal->currentIndex()));
    args.append(ui->lineEditSweepFStart->text());
    args.append(ui->lineEditSweepFEnd->text());
    args.append(ui->lineEditAtten->text());

    args.append(ui->lineEditSpeedH->text());
    args.append(ui->lineEditSpeedV->text());
    args.append(ui->lineEditStartX->text());
    args.append(ui->lineEditStartY->text());
    args.append(ui->lineEditEndX->text());
    args.append(ui->lineEditEndY->text());
    args.append(ui->lineEditStepY->text());

    args.append(ui->lineEdit_batch->text());
    args.append(ui->lineEdit_bpXNum->text());
    args.append(ui->lineEdit_bpXSize->text());
    args.append(ui->lineEdit_bpXStartLocation->text());
    args.append(ui->lineEdit_bpYNum->text());
    args.append(ui->lineEdit_bpYSize->text());
    args.append(ui->lineEdit_bpYStartLocation->text());
    args.append(ui->lineEdit_bpZNum->text());
    args.append(ui->lineEdit_bpZSize->text());
    args.append(ui->lineEdit_bpZStartLocation->text());
    args.append(ui->lineEdit_StartFrequency->text());
    args.append(ui->lineEdit_EndFrequenncy->text());
    args.append(ui->textEdit_TestRecord->toPlainText());

    if(!dbInterface.updateTestArg(args, ui->lineEditIdentifying->text()))
    {
        qWarning() << "on ArgumentInfoDlg save: " << dbInterface.errorString();
        QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("参数保存失败，请核对后再次保存。"));
    }
    else
    {
        if(1 == ret)
        {
            qDebug()<<m_testName<< ui->lineEditTestName->text();
            m_oldTestName = m_testName;
//            emit testArgsChanges(m_oldTestName, ui->lineEditTestName->text());
            emit settingTemplate(m_oldTestName, ui->lineEditTestName->text());
            ui->pushButtonSave->setEnabled(false);
            m_testName = ui->lineEditTestName->text();
            QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("参数保存成功。"));
        }
        else if(2 == ret)
        {
            m_testName = ui->lineEditTestName->text();
            emit addTemplate(m_testName);
            ui->pushButtonSave->setEnabled(false);
            QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("参数保存成功。"));
            this->close();
        }

    }
}

void ArgumentInfoDlg::onTextChanged(QString text)
{
    Q_UNUSED(text);
    ui->pushButtonSave->setEnabled(true);
}

/*检测模板信息参数设置是否正确，添加模板和设置模板操作时参数为空返回0；
  添加模板操作时数据库操作失败返回0；设置模板操作参数正确返回1；添加模
  板操作参数正确且模板num即ID正确设置返回2；
*/
int ArgumentInfoDlg::templateArgCheck()
{
//    参数为空检测
    QStringList args;
    args.append(ui->lineEditTestName->text());
    args.append(QString::number(ui->comboBoxGather->currentIndex()));
    args.append(QString::number(ui->comboBoxSys_init->currentIndex()));
    args.append(QString::number(ui->comboBoxReset->currentIndex()));
    args.append(QString::number(ui->comboBoxCal->currentIndex()));
    args.append(ui->lineEditSweepFStart->text());
    args.append(ui->lineEditSweepFEnd->text());
    args.append(ui->lineEditAtten->text());

    args.append(ui->lineEditSpeedH->text());
    args.append(ui->lineEditSpeedV->text());
    args.append(ui->lineEditStartX->text());
    args.append(ui->lineEditStartY->text());
    args.append(ui->lineEditEndX->text());
    args.append(ui->lineEditEndY->text());
    args.append(ui->lineEditStepY->text());

    args.append(ui->lineEdit_batch->text());
    args.append(ui->lineEdit_bpXNum->text());
    args.append(ui->lineEdit_bpXSize->text());
    args.append(ui->lineEdit_bpXStartLocation->text());
    args.append(ui->lineEdit_bpYNum->text());
    args.append(ui->lineEdit_bpYSize->text());
    args.append(ui->lineEdit_bpYStartLocation->text());
    args.append(ui->lineEdit_bpZNum->text());
    args.append(ui->lineEdit_bpZSize->text());
    args.append(ui->lineEdit_bpZStartLocation->text());
    args.append(ui->lineEdit_StartFrequency->text());
    args.append(ui->lineEdit_EndFrequenncy->text());

    QString varArgs;
    foreach (varArgs, args) {
        if(varArgs.isEmpty())
        {
            QMessageBox::warning(this, QStringLiteral("警告"),
                                 QStringLiteral("参数不能为空!"),
                                 QMessageBox::Ok);
            return 0;
        }
    }

//    检查扫频起点、扫频终点参数是否正确：（1-2或2-6或6-18）且（起点<终点）
    uint sweepFStart = ui->lineEditSweepFStart->text().toUInt();
    uint sweepFEnd = ui->lineEditSweepFEnd->text().toUInt();
    bool one = (sweepFStart >= 1000) && (sweepFStart <= 2000)
               && (sweepFEnd >= 1000) && (sweepFEnd <= 2000)
               && (sweepFStart < sweepFEnd);
    bool two = (sweepFStart >= 2000) && (sweepFStart <= 6000)
            && (sweepFEnd >= 2000) && (sweepFEnd <= 6000)
            && (sweepFStart < sweepFEnd);
    bool three = (sweepFStart >= 6000) && (sweepFStart <=18000)
            && (sweepFEnd >= 6000) && (sweepFEnd <= 18000)
            && (sweepFStart < sweepFEnd);
   if(!(one || two ||three))
   {
       QMessageBox::about(this, QStringLiteral("提示"),
       QStringLiteral("扫频起点为X，扫频终点为Y。X、Y均满足以下两个条件：\n1：X < Y\n2：X、Y ∈[1000,2000] 或者\n      X、Y ∈[2000,6000]或者\n      X、Y ∈[6000,18000]"));
       return 0;
   }


    if(ui->lineEditIdentifying->text() == QString())
    {
//        添加模板时，检测模板名和数据库中已有的模板名是否重复
        QStringList testName;
        if(!dbInterface.getTestName(testName))
        {
            qDebug() << QStringLiteral("不能获取数据库中表Arg_table的testName:") << dbInterface.errorString();
            return 0;
        }
        QString varTestName;
        foreach (varTestName, testName) {
            if(varTestName == ui->lineEditTestName->text())
            {
                QMessageBox::warning(this, QStringLiteral("警告"),
                                     QStringLiteral("此实验名重复，请重新填写实验名!"),
                                     QMessageBox::Ok);
                return 0;
            }
        }

//  添加模板时，检测此模板的标识（数据库中的num）
        QList<int> numId;
        if(!dbInterface.getNumID(numId))
        {
            qDebug() << QStringLiteral("不能获取数据库中表Arg_table的num:") << dbInterface.errorString();
            return 0;
        }
        else
        {

            if(numId.isEmpty())
            {
               if(!dbInterface.insertNumId(1))
               {
                   qDebug() << "3 on ArgumentManagerDlg init: " << dbInterface.errorString();
                   return 0;
               }
               else
               {
                   ui->lineEditIdentifying->setText(QString("1"));
                   return 2;
               }
            }
            else
            {
                int id;
                foreach (id, numId) {
                    int tmp = 0;
                    if(tmp <= id)
                    {
                        tmp = id;
                    }
                    id = tmp + 1;
                }
                QString varStr;
                varStr.setNum(id);
                if(!dbInterface.insertNumId(id))
                {
                    qDebug() << "4 on ArgumentManagerDlg init: " << dbInterface.errorString();
                    return 0;
                }
                else
                {
                    ui->lineEditIdentifying->setText(QString::number(id));
                    return 2;
                }
            }
        }
    }
    return 1;
}
