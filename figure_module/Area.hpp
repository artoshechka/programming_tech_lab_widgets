/// @file
/// @brief Объявление области отображения фигур
/// @author Artemenko Anton
#ifndef GUID_5e2b9e70_0f21_4cc3_8f8a_8ef38a7c9b5e
#define GUID_5e2b9e70_0f21_4cc3_8f8a_8ef38a7c9b5e

#include <QtCore/QTimerEvent>
#include <QtGui/QHideEvent>
#include <QtGui/QPaintEvent>
#include <QtGui/QShowEvent>
#include <QtWidgets/QWidget>

#include <Figure.hpp>

namespace figure_module
{

/// @brief Область отображения фигур.
class Area : public QWidget
{
   public:
    /// @brief Конструктор области.
    Area(QWidget *parent = 0);
    /// @brief Деструктор области.
    ~Area();

   protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

   private:
    int myTimerData_;    ///< Идентификатор таймера.
    float alphaData_;    ///< Угол поворота.
    MyLine *myLineData_; ///< Линия.
    MyRect *myRectData_; ///< Прямоугольник.
};

}  // namespace figure_module

#endif  // GUID_5e2b9e70_0f21_4cc3_8f8a_8ef38a7c9b5e
