/// @file
/// @brief Реализация модуля выбора программы
/// @author Artemenko Anton

#include <launcher.hpp>
#include <square_module.hpp>
#include <counter.hpp>
#include <Window.hpp>

#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>

using launcher_module::Launcher;

Launcher::Launcher()
{
    codecData_ = QTextCodec::codecForName("UTF-8");
    setWindowTitle(codecData_->toUnicode("Выбор программы"));

    selectorData_ = new QComboBox(this);
    selectorData_->addItem(codecData_->toUnicode("Возведение в квадрат"));
    selectorData_->addItem(codecData_->toUnicode("Счетчик"));
    selectorData_->addItem(codecData_->toUnicode("Аниматор фигур"));

    stackData_ = new QStackedWidget(this);
    stackData_->addWidget(new square_module::SquareModule());
    stackData_->addWidget(new counter_module::Win());
    stackData_->addWidget(new figure_module::Window());

    exitButtonData_ = new QPushButton(codecData_->toUnicode("Выход"), this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(selectorData_);
    layout->addWidget(stackData_);
    layout->addWidget(exitButtonData_);

    connect(selectorData_, QOverload<int>::of(&QComboBox::currentIndexChanged),
            stackData_, &QStackedWidget::setCurrentIndex);
    connect(exitButtonData_, &QPushButton::clicked, qApp, &QApplication::quit);
}
