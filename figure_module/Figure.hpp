/// @file
/// @brief Объявления фигур для модуля обработки событий
/// @author Artemenko Anton
#ifndef GUID_2c8a6d7f_9c01_4b0d_8c3f_1e9b6f5c6a01
#define GUID_2c8a6d7f_9c01_4b0d_8c3f_1e9b6f5c6a01

#include <QtGui/QPainter>

namespace figure_module
{

/// @brief Базовый класс фигуры.
class Figura
{
   protected:
    int xData_;       ///< X-координата центра.
    int yData_;       ///< Y-координата центра.
    int halfLenData_; ///< Полудлина стороны.
    int dxData_;      ///< Проекция смещения на ось X.
    int dyData_;      ///< Проекция смещения на ось Y.
    int rData_;       ///< Радиус (резервное поле).
    virtual void Draw(QPainter *Painter) = 0;

   public:
    /// @brief Конструктор фигуры.
    Figura(int x, int y, int halfLen);

    /// @brief Выполняет перемещение и отрисовку.
    void Move(float Alpha, QPainter *Painter);
};

/// @brief Линия.
class MyLine : public Figura
{
   protected:
    void Draw(QPainter *Painter);

   public:
    MyLine(int x, int y, int halfLen);
};

/// @brief Прямоугольник.
class MyRect : public Figura
{
   protected:
    void Draw(QPainter *Painter);

   public:
    MyRect(int x, int y, int halfLen);
};

}  // namespace figure_module

#endif  // GUID_2c8a6d7f_9c01_4b0d_8c3f_1e9b6f5c6a01
