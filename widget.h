 #ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "scene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:



private slots:
    void on_startGameButton_clicked();
    void on_easyButton_clicked();
    void on_normalButton_clicked();
    void on_hardButton_clicked();


private:
    Ui::Widget *ui;

    // add scene
    Scene* scene;
};
#endif // WIDGET_H
