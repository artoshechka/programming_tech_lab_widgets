/// @file
/// @brief Реализация окна модуля обработки событий
/// @author Artemenko Anton

#include <Window.hpp>

using figure_module::Window;

Window::Window()
{
    codecData_ = QTextCodec::codecForName("UTF-8");
    setWindowTitle(codecData_->toUnicode("Обработка событий"));
    areaData_ = new Area(this);
    btnData_ = new QPushButton(codecData_->toUnicode("Завершить"), this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(areaData_);
    layout->addWidget(btnData_);
    connect(btnData_, &QPushButton::clicked, this, &QWidget::close);
}
