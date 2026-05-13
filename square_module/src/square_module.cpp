/// @file
/// @brief Объявление класса для возведения модуля с отрисовкой Qt Widgets
/// @author Artemenko Anton

#include <square_module.hpp>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>

using square_module::SquareModule;

SquareModule::SquareModule(QWidget *parent)
    : QWidget(parent)
{
    codecData_ = QTextCodec::codecForName("UTF-8");
    setWindowTitle(codecData_->toUnicode("Возведение в квадрат"));
    frameData_ = new QFrame(this);
    frameData_->setFrameShadow(QFrame::Raised);
    frameData_->setFrameShape(QFrame::Panel);
    inputLabelData_ = new QLabel(codecData_->toUnicode("Введите число:"), this);
    inputEditData_ = new QLineEdit("", this);
    StrValidator *v = new StrValidator(inputEditData_);
    inputEditData_->setValidator(v);
    outputLabelData_ = new QLabel(codecData_->toUnicode("Результат:"), this);
    outputEditData_ = new QLineEdit("", this);
    nextButtonData_ = new QPushButton(codecData_->toUnicode("Следующее"), this);
    exitButtonData_ = new QPushButton(codecData_->toUnicode("Выход"), this);
    // компоновка приложения выполняется согласно рисунку 2.
    QVBoxLayout *vLayout1 = new QVBoxLayout(frameData_);
    vLayout1->addWidget(inputLabelData_);
    vLayout1->addWidget(inputEditData_);
    vLayout1->addWidget(outputLabelData_);
    vLayout1->addWidget(outputEditData_);
    vLayout1->addStretch();
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButtonData_);
    vLayout2->addWidget(exitButtonData_);
    vLayout2->addStretch();
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frameData_);
    hLayout->addLayout(vLayout2);
    Begin();
    connect(exitButtonData_, &QPushButton::clicked, this, &QWidget::close);
    connect(nextButtonData_, &QPushButton::clicked, this, &SquareModule::Begin);
    connect(inputEditData_, &QLineEdit::returnPressed, this, &SquareModule::Calc);
}

void SquareModule::Begin()
{
    inputEditData_->clear();
    nextButtonData_->setEnabled(false);
    nextButtonData_->setDefault(false);
    inputEditData_->setEnabled(true);
    outputLabelData_->setVisible(false);
    outputEditData_->setVisible(false);
    outputEditData_->setEnabled(false);
    inputEditData_->setFocus();
}

void SquareModule::Calc()
{
    bool Ok = true;
    float r, a;
    QString str = inputEditData_->text();
    a = str.toDouble(&Ok);
    if (Ok)
    {
        r = a * a;
        str.setNum(r);
        outputEditData_->setText(str);
        inputEditData_->setEnabled(false);
        outputLabelData_->setVisible(true);
        outputEditData_->setVisible(true);
        nextButtonData_->setDefault(true);
        nextButtonData_->setEnabled(true);
        nextButtonData_->setFocus();
    }
    else if (!str.isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Information, codecData_->toUnicode("Возведение в квадрат."),
                           codecData_->toUnicode("Введено неверное значение."), QMessageBox::Ok);
        msgBox.exec();
    }
}