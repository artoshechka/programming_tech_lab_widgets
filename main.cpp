/// @file
/// @brief Точка входа в программу
/// @author Artemenko Anton

#include <square_module.hpp>

/// @brief Точка входа в программу.
/// @param[in] argc количество аргументов командной строки
/// @param[in] argv массив аргументов командной строки
/// @return код завершения приложения
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    square_module::Win win(0);
    win.show();
    return app.exec();
}
