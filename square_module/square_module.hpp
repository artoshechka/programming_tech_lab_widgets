/// @file
/// @brief Объявление класса для возведения модуля с отрисовкой Qt Widgets
/// @author Artemenko Anton
#ifndef GUID_4b108220_4ebb_11f1_b4ac_0800200c9a66
#define GUID_4b108220_4ebb_11f1_b4ac_0800200c9a66

#include <QtWidgets>
namespace square_module
{

class Win : public QWidget // класс окна
{
  Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
      protected : QTextCodec *codec;
    QFrame *frame;           // рамка
    QLabel *inputLabel;      // метка ввода
    QLineEdit *inputEdit;    // строчный редактор ввода
    QLabel *outputLabel;     // метка вывода
    QLineEdit *outputEdit;   // строчный редактор вывода
    QPushButton *nextButton; // кнопка Следующее
    QPushButton *exitButton; // кнопка Выход
  public:
    Win(QWidget *parent = 0); // конструктор
  public slots:
    void begin(); // метод начальной настройки интерфейса
    void calc();  // метод реализации вычислений
};
class StrValidator : public QValidator // класс компонента проверки ввода
{
  public:
    StrValidator(QObject *parent) : QValidator(parent)
    {
    }
    virtual State validate(QString &str, int &pos) const
    {
        return Acceptable; // метод всегда принимает вводимую строку
    }
};
} // namespace square_module

#endif // GUID_4b108220_4ebb_11f1_b4ac_0800200c9a66
