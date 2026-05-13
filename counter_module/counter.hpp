/// @file
/// @brief Объявления модуля счетчика
/// @author Artemenko Anton
#ifndef GUID_1b2c8f5a_9b8e_4a7d_8a5c_1f6b9d2e3c41
#define GUID_1b2c8f5a_9b8e_4a7d_8a5c_1f6b9d2e3c41

#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtCore/QTextCodec>

namespace counter_module
{
class Counter : public QLineEdit
{
    Q_OBJECT
  public:
    Counter(const QString &contents, QWidget *parent = 0) : QLineEdit(contents, parent)
    {
    }
  signals:
    void tick_signal();
  public slots:
    void add_one()
    {
        QString str = text();
        int r = str.toInt();
        if (r != 0 && r % 5 == 0)
            emit tick_signal();
        r++;
        str.setNum(r);
        setText(str);
    }
};
class Win : public QWidget
{
    Q_OBJECT
  protected:
    QTextCodec *codec;
    QLabel *label1, *label2;
    Counter *edit1, *edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;

  public:
    Win(QWidget *parent = 0);
};
} // namespace counter_module
#endif // GUID_1b2c8f5a_9b8e_4a7d_8a5c_1f6b9d2e3c41
