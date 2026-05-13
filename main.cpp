/// @file
/// @brief Точка входа в программу
/// @author Artemenko Anton

#include <launcher.hpp>

#include <QtWidgets/QApplication>

/// @brief Точка входа в программу
/// @param argc аргумент командной строки - количество аргументов
/// @param argv аргумент командной строки - массив строк
/// @return код завершения программы
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    launcher_module::Launcher launcher;
    launcher.show();
    return app.exec();
}
