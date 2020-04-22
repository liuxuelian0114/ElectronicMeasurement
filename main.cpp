#include "mainwindow.h"
#include "logindlg.h"

#include <QApplication>
#include <QMessageBox>
#include "Packet.h"
#include <QDir>
#include "dbinterface.h"
#include "localconfig.h"


Q_DECLARE_METATYPE(D3Para)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dbInterface.openDatabase();
    localConfig.readConfig();

    qRegisterMetaType<D3Para>();
    LoginDlg m_loginDlg;//建立登录窗口的类对象dlg
    //利用Accepted返回值判断按钮是否被按下


    if(QDialog::Accepted == m_loginDlg.exec())
    {
        MainWindow w;
        w.show();//如果按下，显示主窗口
        return a.exec();//执行程序，直到主窗口关闭
    }
}
