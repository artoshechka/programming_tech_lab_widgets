// @file
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
class Area : public QWidget
{
    int myTimer; // идентификатор таймера
    float alpha; // угол поворота
  public:
    Area(QWidget *parent = 0);
    ~Area();
    MyLine *myline;
    MyRect *myrect;

  protected:
    // обработчики событий
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
};

} // namespace figure_module

#endif // GUID_5e2b9e70_0f21_4cc3_8f8a_8ef38a7c9b5e