/// @file
/// @brief Реализация фигур для модуля обработки событий
/// @author Artemenko Anton

#include <Figure.hpp>

using figure_module::Figura;
using figure_module::MyLine;
using figure_module::MyRect;

void Figura::Move(float Alpha, QPainter *Painter)
{
    dxData_ = halfLenData_ * cos(Alpha);
    dyData_ = halfLenData_ * sin(Alpha);
    Draw(Painter);
}
void MyLine::Draw(QPainter *Painter)
{
    Painter->drawLine(xData_ + dxData_, yData_ + dyData_, xData_ - dxData_, yData_ - dyData_);
}
void MyRect::Draw(QPainter *Painter)
{
    Painter->drawLine(xData_ + dxData_, yData_ + dyData_, xData_ + dyData_, yData_ - dxData_);
    Painter->drawLine(xData_ + dyData_, yData_ - dxData_, xData_ - dxData_, yData_ - dyData_);
    Painter->drawLine(xData_ - dxData_, yData_ - dyData_, xData_ - dyData_, yData_ + dxData_);
    Painter->drawLine(xData_ - dyData_, yData_ + dxData_, xData_ + dxData_, yData_ + dyData_);
}
