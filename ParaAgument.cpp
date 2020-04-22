#include "ParaAgument.h"
#include "ui_ParaAgument.h"

#include <QStandardItemModel>
#include <QStringList>
#include <QDebug>
#include <QStandardItem>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QResizeEvent>
#include "dbinterface.h"

ParaAgument::ParaAgument(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParaAgument),
    m_pDataModel(Q_NULLPTR),
    m_pSelectModel(Q_NULLPTR)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));

    m_uneditTestArgs.append(QStringLiteral("载频"));
    m_uneditTestArgs.append(QStringLiteral("带宽"));
    m_uneditTestArgs.append(QStringLiteral("BP成像X方向网格数"));
    m_uneditTestArgs.append(QStringLiteral("BP成像Y方向网格数"));
    m_uneditTestArgs.append(QStringLiteral("BP成像Z方向网格数"));
    m_uneditTestArgs.append(QStringLiteral("每个batch元素个数"));
    m_uneditTestArgs.append(QStringLiteral("BP成像X方向起始位置"));
    m_uneditTestArgs.append(QStringLiteral("BP成像Y方向起始位置"));
    m_uneditTestArgs.append(QStringLiteral("BP成像Z方向起始位置"));
    m_uneditTestArgs.append(QStringLiteral("BP成像X方向网格大小"));
    m_uneditTestArgs.append(QStringLiteral("BP成像Y方向网格大小"));
    m_uneditTestArgs.append(QStringLiteral("BP成像Z方向网格大小"));
    m_uneditTestArgs.append(QStringLiteral("X方向运动速度"));
    m_uneditTestArgs.append(QStringLiteral("X方向运动位置"));
    m_uneditTestArgs.append(QStringLiteral("Y方向起始位置"));
    m_uneditTestArgs.append(QStringLiteral("X方向运动距离"));
    m_uneditTestArgs.append(QStringLiteral("Y方向运动距离"));
    m_uneditTestArgs.append(QStringLiteral("起始频率"));
    m_uneditTestArgs.append(QStringLiteral("终止频率"));
    m_uneditTestArgs.append(QStringLiteral("保留字段1"));

    initModel();
    connect(ui->pushButtonAdd,SIGNAL(clicked()), this, SLOT(onPushButtonAdd()));
    connect(ui->pushButtonDelete,SIGNAL(clicked()), this, SLOT(onPushButtonDelete()));
    connect(ui->pushButtonDeleteAll,SIGNAL(clicked()), this, SLOT(onPushButtonDeleteAll()));
    connect(ui->pushButtonSave,SIGNAL(clicked()), this, SLOT(onPushButtonSave()));
}

ParaAgument::~ParaAgument()
{
    delete ui;
    if(m_pDataModel != Q_NULLPTR)
    {
        delete m_pDataModel;
    }
    if(m_pSelectModel != Q_NULLPTR)
    {
        delete m_pSelectModel;
    }
}

void ParaAgument::initModel()
{
    m_pDataModel = new QStandardItemModel(this);
    m_pDataModel->setColumnCount(2);
    QStringList headerLabels;
    headerLabels << QStringLiteral("参数名称") << QStringLiteral("参数值");
    m_pDataModel->setHorizontalHeaderLabels(headerLabels);


    //将数据库中的内容呈现在界面上
    QStringList field;
    dbInterface.getTableField(field, QString("para_arg"));
    field.takeFirst();

    QStringList rows;
    dbInterface.getTablePara(rows, QString("para_arg"));
    rows.takeFirst();

    for(int i = 0; (i < field.count()) && (i < rows.count()); i++)
    {
        QStandardItem* pItem0 = new QStandardItem(field.at(i).section("field",-1, -1));
        m_pDataModel->setItem(i,0, pItem0);
        QStandardItem* pItem1 = new QStandardItem(rows.at(i));
        m_pDataModel->setItem(i,1, pItem1);

        if(m_uneditTestArgs.contains(field.at(i).section("field",-1, -1)))
        {
            pItem0->setEditable(false);
            pItem1->setEditable(false);
        }
    }

    ui->tableView->setModel(m_pDataModel);
    m_pSelectModel = new QItemSelectionModel(m_pDataModel,this);
    ui->tableView->setSelectionModel(m_pSelectModel);

}

void ParaAgument::resizeEvent(QResizeEvent *event)
{

    this->ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    event->accept();
}

void ParaAgument::onPushButtonAdd()
{
    int totalRow = m_pDataModel->rowCount();
    int currentRow = m_pSelectModel->currentIndex().row();
    if(-1 == currentRow)
    {
        QStandardItem* pItem0 = new QStandardItem;
        m_pDataModel->setItem(totalRow,0, pItem0);
        QStandardItem* pItem1 = new QStandardItem;
        m_pDataModel->setItem(totalRow,1, pItem1);
    }
    else
    {
        QList<QStandardItem *>  items;
        QStandardItem * item0 = new QStandardItem;
        QStandardItem * item1 = new QStandardItem;
        items.append(item0);
        items.append(item1);
        m_pDataModel->insertRow(currentRow,items);
    }
}

void ParaAgument::onPushButtonDelete()
{
    int currentRow = m_pSelectModel->currentIndex().row();
    if(-1 == currentRow)
    {
        QMessageBox::about(this,QStringLiteral("提示"),QStringLiteral("请选择你要删除的行"));
    }
    else
    {
        m_pDataModel->removeRow(currentRow);
    }
}

void ParaAgument::onPushButtonDeleteAll()
{
    int totalRow = m_pDataModel->rowCount();
    if(QMessageBox::Ok == QMessageBox::question(this,QStringLiteral("提示"),QStringLiteral("删除所有数据？"),QMessageBox::Ok,QMessageBox::No))
    {
       m_pDataModel->removeRows(0,totalRow);
    }
    else
    {
        return;
    }

}

void ParaAgument::onPushButtonSave()
{
    QStringList field;
    QStringList value;
    int totalRow = m_pDataModel->rowCount();

   /*参数名称在数据库中存储为字段名，因为SQlite数据库的的字段名不能是数字，为避免用户
    *将参数名称设置为数字时，数据库报错不能使用，故均在参数名称前加prefix
   */
    QString prefix("field");

    for(int i = 0; i < totalRow; i++)
    {
        if((m_pDataModel->item(i,0) != Q_NULLPTR) && (m_pDataModel->item(i,1) != Q_NULLPTR))
        {
            QString fieldTmp = m_pDataModel->item(i,0)->text().remove(QRegExp("\\s"));
            QString valueTmp = m_pDataModel->item(i,1)->text().remove(QRegExp("\\s"));
//            qDebug() << fieldTmp.toInt();


            if(fieldTmp.isNull() || valueTmp.isNull())
            {
                QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("数据值不能为空"));
                return;
            }
            else
            {
                if(field.contains(prefix + fieldTmp))
                {
                    QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("请修改重复参数名称：")+fieldTmp);
                    return;
                }
                else
                {
                    field.append(prefix + fieldTmp);
                    value.append(valueTmp);
                }
            }
         }
        else
        {
            qDebug() << QStringLiteral("item指针为空");
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("数据值不能为空"));
            return;
        }
    }

//    QString fieldTmp ;
//    QString valueTmp ;
//    foreach (fieldTmp, field) {
//        qDebug() << fieldTmp;
//    }

//    foreach (valueTmp, value) {
//        qDebug() << valueTmp;
//    }

    if(field.count() == value.count())
    {
        dbInterface.addTable(field, value,QString("para_arg"));
    }
    else
    {
        return;
    }

}
