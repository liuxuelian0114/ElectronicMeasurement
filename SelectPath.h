#ifndef SELECTPATH_H
#define SELECTPATH_H

#include <QDialog>

namespace Ui {
class SelectPath;
}

class SelectPath : public QDialog
{
    Q_OBJECT

public:
    explicit SelectPath(QWidget *parent = 0, int model = 0);
    ~SelectPath();

signals:
    void reportExperiment(const int &model, const QString &name);

public slots:
    void onPushButtonDetermine();
private:
    Ui::SelectPath *ui;
    int m_model;
};

#endif // SELECTPATH_H
