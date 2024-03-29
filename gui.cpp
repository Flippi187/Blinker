#include "gui.h"
#include "config.h"
#include <QDebug>

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_state = false;
    m_timer = new QTimer(this);
    m_gpio = new Gpio(this);
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle);
    wundschuh = 0;
}

void Gui::on_startButton_clicked()
{
    int time = 1000 / horizontalSlider->value();
    m_timer->start(time);
}

void Gui::on_horizontalSlider_valueChanged(int value)
{
    int time = 1000 / value;
    m_timer->setInterval(time);
}

void Gui::toggle()
{
    m_state = !m_state;
    blinklabel->setNum(m_state);
    for(int i = 0; i < 4; i++)
    {
       m_gpio->set(LEDS[i], 0);
    }

    m_gpio->set(LEDS[wundschuh], 1);
    wundschuh++;
    if(wundschuh == 4) wundschuh = 0;
}
