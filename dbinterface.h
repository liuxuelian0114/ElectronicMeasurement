#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include <QObject>
#include <QSqlDatabase>

class DBInterface : public QObject
{
    Q_OBJECT
public:
    explicit DBInterface(QObject *parent = 0);

public:
    /*
     *@brief 错误信息
     */
    QString errorString() const {return m_errStr;}

    bool openDatabase();

    //获取某张表的所有字段名
    bool getTableField(QStringList &args, QString tableName);

    //获取指定表的记录
    bool getTablePara(QStringList &args, QString tableName);

    //删除旧表，增加新表
    bool addTable(QStringList &field, QStringList &value, QString tableName);

    //更新表数据
    bool upTable(QString tableName, QString field, QString value);

    bool getTestName(QStringList &testName);

    bool getTestArg(QStringList &args, QString name);

    bool getNumID(QList<int> &args);

    bool insertNumId(int var);

    bool updateTestArg(const QStringList &args, const QString &id);

    bool deleteTemplate(QString name);

    bool checkUser(const QString &username, const QString &password, QString &permission);

    bool showUser(QStringList &users);

    bool deleteUser(const QString &userName);

    bool recheckUser(const QString &userName);

    bool updataUser(const QStringList &infos);

    bool insertUser(const QStringList &infos);

signals:

public slots:

private:
    QString m_errStr;
    QSqlDatabase m_database;
};

extern DBInterface dbInterface;

#endif // DBINTERFACE_H
