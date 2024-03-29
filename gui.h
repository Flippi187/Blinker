#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include "gpio.h"
#include <QTimer>

class Gui : public QWidget, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);
private slots:
    void on_startButton_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void toggle();
private:
    QTimer* m_timer;
    bool m_state;
    Gpio* m_gpio;
    int wundschuh;
};

#endif // GUI_H
