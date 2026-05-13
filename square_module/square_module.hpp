/// @file
/// @brief Объявление класса для возведения модуля с отрисовкой Qt Widgets
/// @author Artemenko Anton
#ifndef GUID_4b108220_4ebb_11f1_b4ac_0800200c9a66
#define GUID_4b108220_4ebb_11f1_b4ac_0800200c9a66

#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtGui/QValidator>
#include <QtCore/QTextCodec>

namespace square_module
{

/// @brief Класс окна с интерфейсом вычисления квадрата.
class SquareModule : public QWidget
{
    Q_OBJECT

   public:
    /// @brief Конструктор окна.
    /// @param[in] parent Родительский виджет.
    explicit SquareModule(QWidget *parent = 0);

   public slots:
    /// @brief Метод начальной настройки интерфейса.
    void Begin();

    /// @brief Метод реализации вычислений.
    void Calc();

   protected:
    QTextCodec *codecData_;        ///< Кодек UTF-8.
    QFrame *frameData_;            ///< Рамка.
    QLabel *inputLabelData_;       ///< Метка ввода.
    QLineEdit *inputEditData_;     ///< Строчный редактор ввода.
    QLabel *outputLabelData_;      ///< Метка вывода.
    QLineEdit *outputEditData_;    ///< Строчный редактор вывода.
    QPushButton *nextButtonData_;  ///< Кнопка "Следующее".
    QPushButton *exitButtonData_;  ///< Кнопка "Выход".
};

/// @brief Класс компонента проверки ввода.
class StrValidator : public QValidator
{
   public:
    /// @brief Конструктор валидатора.
    /// @param[in] parent Родительский объект.
    explicit StrValidator(QObject *parent);

    /// @brief Проверяет вводимую строку.
    /// @param[in,out] str Вводимая строка.
    /// @param[in,out] pos Позиция курсора.
    /// @return Состояние валидатора.
    State validate(QString &str, int &pos) const override;
};

}  // namespace square_module

#endif  // GUID_4b108220_4ebb_11f1_b4ac_0800200c9a66
