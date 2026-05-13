/// @file
/// @brief Объявление окна модуля обработки событий
/// @author Artemenko Anton
#ifndef GUID_7d8a0f62_ef5a_4a6d_9c89_5a5c2b4a6e6b
#define GUID_7d8a0f62_ef5a_4a6d_9c89_5a5c2b4a6e6b

#include <QtCore/QTextCodec>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include <Area.hpp>

namespace figure_module
{

/// @brief Окно модуля обработки событий.
class Window : public QWidget
{
   public:
    /// @brief Конструктор окна.
    Window();

   protected:
    QTextCodec *codecData_;          ///< Кодек UTF-8.
    Area *areaData_;                 ///< Область отображения рисунка.
    QPushButton *btnData_;           ///< Кнопка завершения.
};

}  // namespace figure_module

#endif  // GUID_7d8a0f62_ef5a_4a6d_9c89_5a5c2b4a6e6b
