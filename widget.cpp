#include "widget.h"
#include <QStyle>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
{
   window = new MyWidget();
   setCentralWidget(window);
   IsSave = false;
   FilePath = "";

   connect(window->edit, SIGNAL(textChanged()),
           this, SLOT(on_text_changed()));

   connect(window->edit, SIGNAL(cursorPositionChanged()),
           this, SLOT(on_text_changed()));

   add_menu();
}

void Widget::on_text_changed()
{
   IsSave = false;
}

void Widget::on_open()
{
   FilePath = QFileDialog::getOpenFileName(this,
   "Заголовок окна", "C:\\",
   "Files (*.doc)");

   QFile file(FilePath);
   if (!file.open(QFile::ReadOnly | QFile::Text))
   {
      QMessageBox::information(this, "Error", "Error open file");
      return;
   }
   QTextStream stream(&file);
   QString buffer = stream.readAll();
   window->edit->setText(buffer);
   file.flush();
   file.close();
   IsSave = true;
}

void Widget::on_save()
{
   if (!FilePath.isEmpty())
   {
      QFile file(FilePath);
      if (!file.open(QFile::WriteOnly | QFile::Text))
      {
         QMessageBox::information(this, "Error", "Error open file");
         return;
      }
      QTextStream stream(&file);
      stream << window->edit->toHtml();
      file.flush();
      file.close();
      IsSave = true;
   }
   else
      emit on_save_as();
}

void Widget::on_save_as()
{
   FilePath = QFileDialog::getSaveFileName(this,
   "Заголовок окна", "C:\\",
   "Files (*.doc");

   QFile file(FilePath);
   if (!file.open(QFile::WriteOnly | QFile::Text))
   {
      QMessageBox::information(this, "Error", "Error save file");
      return;
   }
   QTextStream stream(&file);
   stream << window->edit->toHtml();
   file.flush();
   file.close();
   IsSave = true;
}

void Widget::add_menu()
{
   menu = new QMenu("File",this);
   actOpen = new QAction("Open");
   actOpen->setShortcut(QKeySequence::Open);
   actSave = new QAction("Save");
   actSave->setShortcut(QKeySequence::Save);
   actSaveAs = new QAction("Save as");
   actSaveAs->setShortcut(QKeySequence::SaveAs);

   connect(actOpen, SIGNAL(triggered()),
           this, SLOT(on_open()));
   connect(actSave, SIGNAL(triggered()),
           this, SLOT(on_save()));
   connect(actSaveAs, SIGNAL(triggered()),
           this, SLOT(on_save_as()));

   menu->addAction(actOpen);
   menu->addSeparator();
   menu->addAction(actSave);
   menu->addAction(actSaveAs);

   menuBar()->addMenu(menu);
}

void Widget::closeEvent(QCloseEvent *e)
{
   if (!IsSave)
   {
      QMessageBox::StandardButton result;
      result = QMessageBox::question(this, "Подтверждение закрытия окна",
                                     "Вы хотите сохранить изменения в файле?",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                     QMessageBox::Yes);

      if (result == QMessageBox::Yes)
      {
         if (FilePath.isEmpty())
         {
            emit on_save_as();
         }
         else
            emit on_save();

         e->accept();
      }
      else if (result == QMessageBox::No)
         e->accept();
      else if (result == QMessageBox::Cancel)
         e->ignore();
   }
   else
      e->accept();
}

