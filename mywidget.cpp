#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
   //Текстовое поле
   this->setMinimumSize(850,350);
   edit = new QTextEdit();
   FontCombobox = new QFontComboBox();
   SizeCombobox = new QComboBox();
   hbox1 = new QHBoxLayout();
   hbox2 = new QHBoxLayout();
   grid = new QGridLayout();
   spinbox = new QSpinBox();
   ColorBtn = new QPushButton("A");
   ColorBGBtn = new QPushButton("");
   BoldBtn = new QPushButton("Ж");
   ItalicBtn = new QPushButton("К");
   UnderlinedBtn = new QPushButton("Ч");
   leftBtn = new QPushButton("");
   rightBtn = new QPushButton("");
   centerBtn = new QPushButton("");
   FontWeight = edit->fontWeight();

   //format.setLeftMargin(100);
   //format.setRightMargin(50);
   //format.setTopMargin(50);

   FontCombobox->setMinimumSize(100,20);
   FontCombobox->setMaximumSize(100,20);
   FontCombobox->resize(100,20);
   connect(FontCombobox, SIGNAL(currentFontChanged(QFont)),
           this, SLOT(on_currentFontChanged(QFont)));

   edit->setStyleSheet("background-color: white; padding-left:105; padding-right:40; padding-top:50");
   edit->setMinimumWidth(800);
   edit->setMaximumWidth(800);

   SizeCombobox->setMinimumSize(50,20);
   SizeCombobox->setMaximumSize(50,20);
   SizeCombobox->addItem("9");
   SizeCombobox->addItem("10");
   SizeCombobox->addItem("11");
   SizeCombobox->addItem("12");
   SizeCombobox->addItem("14");
   SizeCombobox->addItem("16");
   SizeCombobox->addItem("18");
   SizeCombobox->addItem("20");
   SizeCombobox->addItem("22");
   SizeCombobox->addItem("24");
   SizeCombobox->addItem("26");
   SizeCombobox->addItem("28");
   SizeCombobox->addItem("36");
   SizeCombobox->addItem("48");
   SizeCombobox->addItem("72");
   SizeCombobox->setStyleSheet("background-color: white");
   connect(SizeCombobox, SIGNAL(currentTextChanged(QString)), this, SLOT(on_currentTextChanged(QString)));

   ColorBtn->setMinimumSize(22,25);
   ColorBtn->setMaximumSize(22,25);
   ColorBtn->setStyleSheet("background-color: white");
   connect(ColorBtn, SIGNAL(clicked()),
           this, SLOT(on_ColorClicked()));

   ColorBGBtn->setMinimumSize(22,25);
   ColorBGBtn->setMaximumSize(22,25);
   ColorBGBtn->setStyleSheet("border-image: url(:/colorbg.png) stretch; ");
   connect(ColorBGBtn, SIGNAL(clicked()),
           this, SLOT(on_ColorBGClicked()));

   BoldBtn->setMinimumSize(22,25);
   BoldBtn->setMaximumSize(22,25);
   connect(BoldBtn, SIGNAL(clicked()),
           this, SLOT(on_BoldClicked()));

   ItalicBtn->setMinimumSize(22,25);
   ItalicBtn->setMaximumSize(22,25);
   connect(ItalicBtn, SIGNAL(clicked()),
           this, SLOT(on_ItalicClicked()));

   UnderlinedBtn->setMinimumSize(22,25);
   UnderlinedBtn->setMaximumSize(22,25);
   connect(UnderlinedBtn, SIGNAL(clicked()),
           this, SLOT(on_UnderlinedClicked()));

   leftBtn->setMaximumSize(25,20);
   leftBtn->setMinimumSize(25,20);
   leftBtn->setStyleSheet("border-image: url(:/left.png) stretch; ");
   connect(leftBtn, SIGNAL(clicked()), this, SLOT(on_leftBtn_clicked()));

   rightBtn->setMaximumSize(25,20);
   rightBtn->setMinimumSize(25,20);
   rightBtn->setStyleSheet("border-image: url(:/right.png) stretch; ");
   connect(rightBtn, SIGNAL(clicked()), this, SLOT(on_rightBtn_clicked()));

   centerBtn->setMaximumSize(25,20);
   centerBtn->setMinimumSize(25,20);
   centerBtn->setStyleSheet("border-image: url(:/center.png) stretch; ");
   connect(centerBtn, SIGNAL(clicked()), this, SLOT(on_centerBtn_clicked()));

   hbox1->addWidget(FontCombobox, Qt::AlignLeft | Qt::AlignTop);
   hbox1->addWidget(SizeCombobox, Qt::AlignLeft | Qt::AlignTop);
   hbox1->addSpacing(10);
   hbox1->addWidget(ColorBtn, Qt::AlignLeft | Qt::AlignTop);
   hbox1->addWidget(ColorBGBtn, Qt::AlignLeft | Qt::AlignTop);
   hbox1->addSpacing(10);
   hbox1->addWidget(BoldBtn, Qt::AlignLeft | Qt::AlignTop);
   hbox1->addWidget(ItalicBtn, Qt::AlignLeft | Qt::AlignTop);
   hbox1->addWidget(UnderlinedBtn, Qt::AlignLeft | Qt::AlignTop);
   hbox1->addSpacing(10);
   hbox1->addWidget(leftBtn, Qt::AlignLeft | Qt::AlignTop);
   hbox1->addWidget(centerBtn, Qt::AlignLeft | Qt::AlignTop);
   hbox1->addWidget(rightBtn, Qt::AlignLeft | Qt::AlignTop);

   hbox2->addWidget(edit, Qt::AlignHCenter);

   grid->addLayout(hbox1, 0, 0, Qt::AlignLeft | Qt::AlignTop);
   grid->addLayout(hbox2, 1, 0);

   this->setLayout(grid);

}

void MyWidget::on_ColorBGClicked()
{
   QColor color = QColorDialog::getColor(QColor(255,0,0), this, "Окно выбора цвета фона текста");
   edit->setTextBackgroundColor(color);
}

void MyWidget::on_leftBtn_clicked()
{
   edit->setAlignment(Qt::AlignLeft);
}

void MyWidget::on_rightBtn_clicked()
{
   edit->setAlignment(Qt::AlignRight);
}

void MyWidget::on_centerBtn_clicked()
{
   edit->setAlignment(Qt::AlignCenter);
}

void MyWidget::on_currentFontChanged(const QFont &font)
{
   edit->setCurrentFont(font);
   FontWeight = edit->fontWeight();
}

void MyWidget::on_currentTextChanged(const QString &str)
{
   edit->setFontPointSize(str.toInt());
   qDebug() << "a";
}

void MyWidget::on_ColorClicked()
{
   QColor color = QColorDialog::getColor(QColor(255,0,0), this, "Окно выбора цвета текста");
   edit->setTextColor(color);
}

void MyWidget::on_BoldClicked()
{
   if (edit->fontWeight() == FontWeight)
   {
      edit->setFontWeight(edit->fontWeight() * 1.5);
   }
   else
   {
      edit->setFontWeight(edit->fontWeight() / 1.5);
   }
}

void MyWidget::on_ItalicClicked()
{
   if (edit->fontItalic())
   {
      edit->setFontItalic(false);
   }
   else
   {
      edit->setFontItalic(true);
   }
}

void MyWidget::on_UnderlinedClicked()
{
   if (edit->fontUnderline())
   {
      edit->setFontUnderline(false);
   }

   else
   {
      edit->setFontUnderline(true);
   }
}

MyWidget::~MyWidget() {}
