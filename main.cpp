/// @file
/// @brief Точка входа в программу
/// @author Artemenko Anton

#include <QtWidgets/QApplication>
#include <Window.hpp>

using figure_module::Window;
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
    Window win;
    win.show();
    return app.exec();
}
