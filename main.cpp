#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Widget w;
   w.resize(600,300);
   w.setWindowTitle("Text Editor");
   w.show();
   return a.exec();
}
