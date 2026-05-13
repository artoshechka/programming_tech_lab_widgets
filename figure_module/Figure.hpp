/// @file
/// @brief Объявления фигур для модуля обработки событий
/// @author Artemenko Anton
#ifndef GUID_2c8a6d7f_9c01_4b0d_8c3f_1e9b6f5c6a01
#define GUID_2c8a6d7f_9c01_4b0d_8c3f_1e9b6f5c6a01

#include <cmath>

#include <QtGui/QPainter>

namespace figure_module
{

/// @brief Базовый класс фигуры.
class Figura
{
  protected:
    int xData_;
    int yData_;
    int halfLenData_;
    int dxData_;
    int dyData_;
    int rData_;
    virtual void Draw(QPainter *Painter) = 0;

  public:
    /// @brief Конструктор фигуры.
    Figura(int x, int y, int halfLen) : xData_(x), yData_(y), halfLenData_(halfLen)
    {
    }

    /// @brief Выполняет перемещение и отрисовку.
    void Move(float Alpha, QPainter *Painter);
};

/// @brief Линия.
class MyLine : public Figura
{
  protected:
    void Draw(QPainter *Painter);

  public:
    MyLine(int x, int y, int halfLen) : Figura(x, y, halfLen)
    {
    }
};

/// @brief Прямоугольник.
class MyRect : public Figura
{
  protected:
    void Draw(QPainter *Painter);

  public:
    MyRect(int x, int y, int halfLen) : Figura(x, y, halfLen)
    {
    }
};

} // namespace figure_module

#endif // GUID_2c8a6d7f_9c01_4b0d_8c3f_1e9b6f5c6a01