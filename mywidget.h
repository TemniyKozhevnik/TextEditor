#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFontComboBox>
#include <QColorDialog>
#include <QPushButton>
#include <QResizeEvent>
#include <QSpinBox>
#include <QTextBlockFormat>

class MyWidget : public QWidget
{
   Q_OBJECT

public:
   explicit MyWidget(QWidget *parent = nullptr);
   ~MyWidget();
      QTextEdit *edit;
private:
      QHBoxLayout *hbox1;
      QHBoxLayout *hbox2;
      QGridLayout *grid;
      QSpinBox *spinbox;
      QPushButton *ColorBtn;
      QPushButton *ColorBGBtn;
      QPushButton *BoldBtn;
      int FontWeight;
      QPushButton *ItalicBtn;
      QPushButton *UnderlinedBtn;
      QFontComboBox *FontCombobox;
      QComboBox *SizeCombobox;
      QColorDialog *window_of_color;
      QTextBlockFormat format;
      QPushButton *leftBtn;
      QPushButton *rightBtn;
      QPushButton *centerBtn;
private slots:
      void on_currentFontChanged(const QFont&);
      void on_currentTextChanged(const QString&);
      void on_ColorClicked();
      void on_ColorBGClicked();
      void on_BoldClicked();
      void on_ItalicClicked();
      void on_UnderlinedClicked();
      void on_leftBtn_clicked();
      void on_rightBtn_clicked();
      void on_centerBtn_clicked();
};
#endif // WIDGET_H
