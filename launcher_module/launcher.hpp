/// @file
/// @brief Объявление модуля выбора программы
/// @author Artemenko Anton
#ifndef GUID_a3f5c2d1_8b7e_4f9a_b6c3_2e1d0f8a7b4c
#define GUID_a3f5c2d1_8b7e_4f9a_b6c3_2e1d0f8a7b4c

#include <QtCore/QTextCodec>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

namespace launcher_module
{

/// @brief Окно с выбором и встроенным отображением модуля.
class Launcher : public QWidget
{
    Q_OBJECT

   public:
    /// @brief Конструктор окна.
    Launcher();

   private:
    QTextCodec *codecData_;      ///< Кодек UTF-8.
    QComboBox *selectorData_;    ///< Выпадающий список модулей.
    QStackedWidget *stackData_;  ///< Контейнер встроенных виджетов.
    QPushButton *exitButtonData_; ///< Кнопка выхода из приложения.
};

}  // namespace launcher_module

#endif  // GUID_a3f5c2d1_8b7e_4f9a_b6c3_2e1d0f8a7b4c
