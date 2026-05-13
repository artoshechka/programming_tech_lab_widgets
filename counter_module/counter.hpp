/// @file
/// @brief Объявления модуля счетчика
/// @author Artemenko Anton
#ifndef GUID_1b2c8f5a_9b8e_4a7d_8a5c_1f6b9d2e3c41
#define GUID_1b2c8f5a_9b8e_4a7d_8a5c_1f6b9d2e3c41

#include <QtCore/QTextCodec>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

namespace counter_module
{

/// @brief Класс счетчика с сигналом на каждом пятом значении.
class Counter : public QLineEdit
{
    Q_OBJECT

   public:
    /// @brief Конструктор счетчика.
    /// @param[in] contents Начальное значение.
    /// @param[in] parent Родительский виджет.
    explicit Counter(const QString &contents, QWidget *parent = 0);

   signals:
    /// @brief Сигнал при достижении каждого пятого значения.
    void TickSignal();

   public slots:
    /// @brief Увеличивает значение на 1 и генерирует сигнал при каждом пятом значении.
    void AddOne();
};

/// @brief Главное окно модуля счетчика.
class Win : public QWidget
{
    Q_OBJECT

   public:
    /// @brief Конструктор окна.
    /// @param[in] parent Родительский виджет.
    explicit Win(QWidget *parent = 0);

   protected:
    QTextCodec *codecData_;           ///< Кодек UTF-8.
    QLabel *label1Data_;          ///< Метка для счетчика по 1.
    QLabel *label2Data_;          ///< Метка для счетчика по 5.
    Counter *edit1Data_;          ///< Поле счетчика по 1.
    Counter *edit2Data_;          ///< Поле счетчика по 5.
    QPushButton *calcButtonData_; ///< Кнопка увеличения счетчика.
    QPushButton *exitButtonData_; ///< Кнопка выхода.
};

}  // namespace counter_module

#endif  // GUID_1b2c8f5a_9b8e_4a7d_8a5c_1f6b9d2e3c41
