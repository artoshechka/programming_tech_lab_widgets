// @file
/// @brief Объявления фигур для модуля обработки событий
/// @author Artemenko Anton
#ifndef GUID_2c8a6d7f_9c01_4b0d_8c3f_1e9b6f5c6a01
#define GUID_2c8a6d7f_9c01_4b0d_8c3f_1e9b6f5c6a01

#include <cmath>

#include <QtGui/QPainter>

namespace figure_module
{
class Figura
{
  protected:
    int x, y, halflen, dx, dy, r;
    virtual void draw(QPainter *Painter) = 0;

  public:
    Figura(int X, int Y, int Halflen) : x(X), y(Y), halflen(Halflen)
    {
    }
    void move(float Alpha, QPainter *Painter);
};
class MyLine : public Figura
{
  protected:
    void draw(QPainter *Painter);

  public:
    MyLine(int x, int y, int halflen) : Figura(x, y, halflen)
    {
    }
};
class MyRect : public Figura
{
  protected:
    void draw(QPainter *Painter);

  public:
    MyRect(int x, int y, int halflen) : Figura(x, y, halflen)
    {
    }
  };
  } // namespace figure_module

  #endif // GUID_2c8a6d7f_9c01_4b0d_8c3f_1e9b6f5c6a01