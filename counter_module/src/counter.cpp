/// @file
/// @brief Реализация модуля счетчика
/// @author Artemenko Anton

#include <counter.hpp>

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

using counter_module::Counter;
using counter_module::Win;

Counter::Counter(const QString &contents, QWidget *parent)
    : QLineEdit(contents, parent)
{
}

void Counter::AddOne()
{
    QString str = text();
    int r = str.toInt();
    if (r != 0 && r % 5 == 0)
        emit TickSignal();
    r++;
    str.setNum(r);
    setText(str);
}

Win::Win(QWidget *parent) : QWidget(parent)
{
    codecData_ = QTextCodec::codecForName("UTF-8");
    setWindowTitle(codecData_->toUnicode("Счетчик"));
    label1Data_ = new QLabel(codecData_->toUnicode("Cчет по 1"), this);
    label2Data_ = new QLabel(codecData_->toUnicode("Cчет по 5"), this);
    edit1Data_ = new Counter("0", this);
    edit2Data_ = new Counter("0", this);
    calcButtonData_ = new QPushButton("+1", this);
    exitButtonData_ = new QPushButton(codecData_->toUnicode("Выход"), this);

    QHBoxLayout *layout1 = new QHBoxLayout();
    layout1->addWidget(label1Data_);
    layout1->addWidget(label2Data_);
    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(edit1Data_);
    layout2->addWidget(edit2Data_);
    QHBoxLayout *layout3 = new QHBoxLayout();
    layout3->addWidget(calcButtonData_);
    layout3->addWidget(exitButtonData_);
    QVBoxLayout *layout4 = new QVBoxLayout(this);
    layout4->addLayout(layout1);
    layout4->addLayout(layout2);
    layout4->addLayout(layout3);
    connect(calcButtonData_, &QPushButton::clicked, edit1Data_, &Counter::AddOne);
    connect(edit1Data_, &Counter::TickSignal, edit2Data_, &Counter::AddOne);
    connect(exitButtonData_, &QPushButton::clicked, this, &QWidget::close);
}
