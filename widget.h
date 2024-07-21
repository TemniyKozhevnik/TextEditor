#ifndef WIDGET_H
#define WIDGET_H

#include "mywidget.h"
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QFileDialog>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QCloseEvent>

class Widget : public QMainWindow
{
   Q_OBJECT

   public:
   explicit Widget(QWidget *parent = nullptr);
   private:
      QMenu *menu;
      QMenuBar *menubar;
      QAction *actOpen, *actSave, *actSaveAs;
      QTextEdit *edit;
      QVBoxLayout *vbox;
      MyWidget *window;
      QString FilePath;
      bool IsSave;
      void add_menu();
   private slots:
      void on_open();
      void on_save();
      void on_save_as();
      void on_text_changed();
   protected:
      void closeEvent(QCloseEvent *e);
};
#endif // WIDGET_H
