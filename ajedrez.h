#ifndef AJEDREZ_H
#define AJEDREZ_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Ajedrez; }
QT_END_NAMESPACE

class Ajedrez : public QMainWindow
{
    Q_OBJECT

public:
    Ajedrez(QWidget *parent = nullptr);
    ~Ajedrez();
    //djndjcndjiu

private:
    Ui::Ajedrez *ui;
};
#endif // AJEDREZ_H
