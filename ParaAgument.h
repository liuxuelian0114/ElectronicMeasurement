#ifndef PARAAGUMENT_H
#define PARAAGUMENT_H

#include <QDialog>
class QStandardItemModel;
class QItemSelectionModel;
class QResizeEvent;
class QStringList;

namespace Ui {
class ParaAgument;
}

class ParaAgument : public QDialog
{
    Q_OBJECT

public:
    explicit ParaAgument(QWidget *parent = 0);
    ~ParaAgument();

private:
    void initModel();
    virtual void resizeEvent(QResizeEvent * event);

private slots:
    void onPushButtonAdd();
    void onPushButtonDelete();
    void onPushButtonDeleteAll();
    void onPushButtonSave();

private:
    Ui::ParaAgument *ui;
    QStandardItemModel* m_pDataModel;
    QItemSelectionModel* m_pSelectModel;
    //检查成像参数是否是软件写入的，如果是则不能修改
    QStringList m_uneditTestArgs;
};

#endif // PARAAGUMENT_H
