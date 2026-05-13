/// @file
/// @brief Реализация области отображения фигур
/// @author Artemenko Anton

#include <Area.hpp>

using figure_module::Area;

Area::Area(QWidget *parent) : QWidget(parent)
{
    setFixedSize(QSize(300, 200));
    myLineData_ = new MyLine(80, 100, 50);
    myRectData_ = new MyRect(220, 100, 50);
    alphaData_ = 0;
}
void Area::showEvent(QShowEvent *)
{
    myTimerData_ = startTimer(50); // создать таймер
}
void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    myLineData_->Move(alphaData_, &painter);
    myRectData_->Move(alphaData_ * (-0.5), &painter);
}
void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimerData_) // если наш таймер
    {
        alphaData_ = alphaData_ + 0.2;
        update(); // обновить внешний вид
    }
    else
        QWidget::timerEvent(event); // иначе передать для стандартной
                                    // обработки
}
void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimerData_); // уничтожить таймер
}
Area::~Area()
{
    delete myLineData_;
    delete myRectData_;
}