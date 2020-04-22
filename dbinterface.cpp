#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QApplication>
#include <QFileInfo>
#include <QDir>
#include "dbinterface.h"

DBInterface dbInterface;

DBInterface::DBInterface(QObject *parent) :
    QObject(parent)
{


}

bool DBInterface::openDatabase()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");

    QFileInfo info(QDir(QApplication::applicationDirPath()), "EMsys.db");
    if (!info.exists()) {
        return false;
    }

    m_database.setDatabaseName(info.absoluteFilePath());
    if(!m_database.open())
    {
        qWarning() << m_database.lastError().text();
    }

    return true;
}

bool DBInterface::getTableField(QStringList &args, QString tableName)
{
    QSqlQuery query(m_database);
    QString select_sql = QString("PRAGMA table_info('%1')").arg(tableName);
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    while(query.next())
    {
        args.append(query.value(1).toString());
    }
    return true;
}

bool DBInterface::getTablePara(QStringList &args, QString tableName)
{
    QSqlQuery query(m_database);
    QString select_sql = QString("select * from %1 where ID= 1").arg(tableName);
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    if(query.first())
    {
        for(int i = 0; i < query.record().count(); i++)
        {
            args.append(query.value(i).toString());
        }
    }

    return true;
}

//QStringList &field, QStringList &value, QString tableName

bool DBInterface::addTable(QStringList &field, QStringList &value,QString tableName)
{
//    qDebug() << "tableName:" << tableName;
//    for(int i = 0; i < field.size(); i++)
//    {
//        qDebug() << "field:" << field.at(i);
//    }

//    for(int i = 0; i < field.size(); i++)
//    {
//        qDebug() << "value:" << value.at(i);
//    }

    QStringList testName;
    QSqlQuery query(m_database);
    //查询数据库中的所有表名字
    QString select_sql = QString("select name from sqlite_master where type='table' order by name");
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        qDebug() << QStringLiteral("数据库查询所有表名字失败");
        return false;
    }

    while(query.next())
    {
        testName.append(query.value(0).toString());
    }

    //删除和将要创建的表同名的表
    for(int i = 0; i < testName.count(); i++)
    {
       if(testName.at(i) == tableName)
       {
           select_sql = QString("DROP TABLE %1").arg(tableName);
           if(!query.exec(select_sql))
           {
               m_errStr = query.lastError().text();
               qDebug() << QStringLiteral("数据库删除表失败");
               return false;
           }
       }
    }

    //创建新表，ID字段赋值
    select_sql.clear();
    select_sql = QString("CREATE TABLE %1 (ID INTEGER(1) PRIMARY KEY NOT NULL DEFAULT 1)").arg(tableName);
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        qDebug() << QStringLiteral("数据库添加表失败");
        return false;
    }
    select_sql.clear();
    select_sql = QString("insert into %1(ID) values(1)").arg(tableName);
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        qDebug() << QStringLiteral("数据库添加值失败");
        return false;
    }


    for(int i = 0; i < field.size(); i++)
    {
        upTable(tableName,field.at(i), value.at(i));
    }
//    for(int i = 0; i < field.count(); i++)
//    {
//        select_sql.clear();
//        select_sql = QString("ALTER TABLE '%1' ADD '%2' TEXT(32) DEFAULT '0' NOT NULL").arg(tableName).arg(field.at(i));
//        if(!query.exec(select_sql))
//        {
//            m_errStr = query.lastError().text();
//            qDebug() << QStringLiteral("数据库循环添加字段失败");
//            return false;
//        }
//        select_sql.clear();
//        select_sql = QString("update %1 set %2='%3' where ID=1").arg(tableName).arg(field.at(i)).arg(value.at(i));
//        qDebug() << select_sql;
//        if(!query.exec(select_sql))
//        {
//            m_errStr = query.lastError().text();
//            qDebug() << QStringLiteral("数据库循环添加值失败");
//            return false;
//        }
//    }
    return true;
}

bool DBInterface::upTable(QString tableName, QString field, QString value)
{
//    qDebug()<< "tableName:" << tableName <<"field" << field << "value" << value;
    QStringList totalField;
    bool whether = false;//保存是否有与field相同的字段
    QSqlQuery query(m_database);
    QString select_sql = QString("PRAGMA table_info('%1')").arg(tableName);
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    while(query.next())
    {
        totalField.append(query.value(1).toString());
        if(query.value(1).toString() == field)
        {
//            qDebug() << query.value(1).toString();

            whether = true;
        }
    }

    //如果字段不存在则添加字段
    if(!whether)
    {
        select_sql.clear();
        select_sql = QString("ALTER TABLE '%1' ADD '%2' TEXT(32)").arg(tableName).arg(field);
//        qDebug() << select_sql;
        if(!query.exec(select_sql))
        {
            m_errStr = query.lastError().text();
            qDebug() << QStringLiteral("数据库循环添加字段失败") << m_errStr;
            return false;
        }
    }

    select_sql.clear();
    select_sql = QString("update %1 set %2='%3' where ID = 1").arg(tableName).arg(field).arg(value);
//    qDebug() << select_sql;
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        qDebug() << QStringLiteral("数据库循环添加值失败") << m_errStr;
        return false;
    }
    return true;
}


bool DBInterface::getTestName(QStringList &testName)
{
    QSqlQuery query(m_database);
    QString select_sql = "select testName from Arg_table";
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    while(query.next())
    {
        testName.append(query.value(0).toString());
    }
    return true;
}

bool DBInterface::getTestArg(QStringList &args, QString name)
{
    QSqlQuery query(m_database);
    QString select_sql = QString("select * from Arg_table where testName='%1'").arg(name);
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    if(query.first())
    {
        for(int i = 0; i < query.record().count(); i++)
        {
            args.append(query.value(i).toString());
        }
    }
    return true;
}

bool DBInterface::getNumID(QList<int> &args)
{
    QSqlQuery query(m_database);
    QString select_sql = "select num from Arg_table";
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    while(query.next())
    {
        args.append(query.value(0).toInt());
    }
    return true;
}

bool DBInterface::insertNumId(int var)
{
    QSqlQuery query(m_database);
    QString insert_sql = QString("insert into Arg_table(num,testName,gather,Sys_init,Reset,Calibration,SweepFStart,"
                                 "SweepFEnd,Atten_Set,speedH,speedV,startX,startY,endX,endY,stepY)values('%1','','',"
                                 "'','','','','','','','','','','','','')").arg(QString::number(var));
    if(!query.exec(insert_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    return true;
}

bool DBInterface::updateTestArg(const QStringList &args, const QString &id)
{
    QSqlQuery query(m_database);
    QStringList list = args;

    QString update_sql = QString("update Arg_table set testName ='%1' where num ='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set gather ='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set Sys_init='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    update_sql = QString("update Arg_table set Reset='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    update_sql = QString("update Arg_table set Calibration='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    update_sql = QString("update Arg_table set SweepFStart='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    update_sql = QString("update Arg_table set SweepFEnd='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    update_sql = QString("update Arg_table set Atten_Set='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set speedH='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    update_sql = QString("update Arg_table set speedV='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    update_sql = QString("update Arg_table set startX='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    update_sql = QString("update Arg_table set startY='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    update_sql = QString("update Arg_table set endX='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    update_sql = QString("update Arg_table set endY='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    update_sql = QString("update Arg_table set stepY='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set batch='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set bpXNum='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set bpXSize='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set bpXStartLocation='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set bpYNum='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set bpYSize='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set bpYStartLocation='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set bpZNum='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set bpZSize='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set bpZStartLocation='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set StartFrequency='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set EndFrequenncy='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }

    update_sql = QString("update Arg_table set TestRecord='%1' where num='%2'").arg(list.takeFirst()).arg(id);
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    return true;
}

bool DBInterface::deleteTemplate(QString name)
{
    QSqlQuery query(m_database);
    QString select_sql = QString("delete from Arg_table where testName='%1'").arg(name);
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    return true;
}
bool DBInterface::checkUser(const QString &username, const QString &password, QString &permission)
{
    QSqlQuery query(m_database);
    QString select_sql = QString("select * from user_table where userName='%1'").arg(username);
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    if(query.first())
    {
        if(password == query.value(2).toString())
        {
            permission = query.value(3).toString();
            return true;
        }
    }
    m_errStr = query.lastError().text();
    return false;
}

bool DBInterface::showUser(QStringList &users)
{
    QSqlQuery query(m_database);
    QString select_sql = QString("select * from user_table");
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    while(query.next())
    {
        users.append(query.value(1).toString());
        users.append(query.value(2).toString());
        users.append(query.value(3).toString());
    }
    return true;
}

bool DBInterface::deleteUser(const QString &userName)
{
    QSqlQuery query(m_database);
    QString delete_sql = QString("delete from user_table where userName='%1'").arg(userName);
    if(!query.exec(delete_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    return true;
}

bool DBInterface::recheckUser(const QString &userName)
{
    QSqlQuery query(m_database);
    QString select_sql = QString("select * from user_table where userName='%1'").arg(userName);
    if(!query.exec(select_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    if(query.first())
    {
        return true;
    }
    return false;
}

bool DBInterface::updataUser(const QStringList &infos)
{
    QSqlQuery query(m_database);
    QString update_sql = QString("update user_table set password='%1',permission='%2' where userName='%3'")
            .arg(infos.at(1)).arg(infos.at(2)).arg(infos.at(0));
    if(!query.exec(update_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    return true;
}

bool DBInterface::insertUser(const QStringList &infos)
{
    QSqlQuery query(m_database);
    QString insert_sql = QString("insert into user_table(userName,password,permission)values('%1','%2','%3')")
            .arg(infos.at(0)).arg(infos.at(1)).arg(infos.at(2));
    if(!query.exec(insert_sql))
    {
        m_errStr = query.lastError().text();
        return false;
    }
    return true;
}
