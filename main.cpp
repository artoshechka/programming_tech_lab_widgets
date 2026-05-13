/// @file
/// @brief Точка входа в программу
/// @author Artemenko Anton

#include <counter.hpp>

#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    counter_module::Win win(0);
    win.show();
    return app.exec();
}