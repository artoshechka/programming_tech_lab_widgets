/// @file
/// @brief Точка входа в программу
/// @author Artemenko Anton

#include <square_module.hpp>
#include <counter.hpp>
#include <Window.hpp>

#include <QtWidgets/QApplication>

/// @brief Точка входа в программу
/// @param argc аргумент командной строки - количество аргументов
/// @param argv аргумент командной строки - массив строк
/// @return код завершения программы
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    square_module::SquareModule squareWin(nullptr);
    squareWin.show();

    counter_module::Win counterWin(nullptr);
    counterWin.show();

    figure_module::Window figureWin;
    figureWin.show();

    return app.exec();
}
