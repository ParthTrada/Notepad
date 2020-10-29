#include "my_notepad.h"
#include "ui_notepad.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QLabel>



Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

Notepad::~Notepad()
{
    delete ui;
}


void Notepad::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(file_name);
    file_path_ = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","file note open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
}

void Notepad::on_actionSave_triggered()
{

    QFile file(file_path_);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","file note open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void Notepad::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open the file");
    QFile file(file_name);
    file_path_ = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","file note open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void Notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void Notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void Notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void Notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void Notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void Notepad::on_actionNew_triggered()
{
    file_path_ = "";
    ui->textEdit->setText("");
}

void Notepad::on_actionAbout_Me_triggered()
{
    QString text ="<P><b><font color='#000000', font size=35 >";
    text .append("PARTH TRADA\n");
    text .append("</font></b></P></br>");

    text .append("<font-size=10> Email : parth.s.trada@gmail.com</font></P>");
    text .append("<P>-------------------------------------------------------------------------------------------------</P>");
    text .append("<P><b><font-size=20>◦ EDUCATION \n</font></b></P>");
    text .append("<font-size=10> Dharmsinh Desai University </font>");
    text .append("<P><i><font-size=10> Electronics and Communications Enginnering(2017-2021) </font></i></P>");
    text .append("<P>-------------------------------------------------------------------------------------------------</P>");
    text .append("<P><b><font-size=20>◦ EXPERIENCE </font></b></P>");
    text .append("<P><font-size=10><b>1.</b> Softsensor.ai <i>(Deep Learning Intern)</i> </font></P>");
    text .append("<P><font-size=10>◦ Subject: Write a research paper on CAMELYON 17 grand challenge problem and build automated methods for tissue and micro environment analytics. </font></P>");
    text .append("<P><font-size=10><b>2.</b> Technocolabs <i>(Computer Vision Intern)</i></font></P>");
    text .append("<P><font-size=10>◦ Goal: I have worked on COVID 19 face mask detection android application.</font></P>");
    text .append("<P>-------------------------------------------------------------------------------------------------</P>");
    text .append("<P><b><font-size=20>◦ TRAINING </font></b></P>");
    text .append("<P><font-size=10><b>1.</b> Machine Learning </font></P>");
    text .append("<P><font-size=10>This course provides me a broad introduction to machine learning, datamining, and statistical pattern recognition.I completed this course on coursera.</font></P>");
    text .append("<P>-------------------------------------------------------------------------------------------------</P>");
    text .append("<P><b><font-size=20>◦ PROJECTS </font></b></P>");
    text .append("<P><font-size=10><b>1.</b> Stock Prediction Forecasting </font></P>");
    text .append("<P><font-size=10>Build Stock Price Forecasting Machine learning model on historical data from yahoo finance, FRED, and some financial site.</font></P>");
    text .append("<P><font-size=10><b>2.</b> Breast Cancer Image Classification </font></P>");
    text .append("<P><font-size=10>Build CNN classifier to identify breast cancer from images.</font></P>");
    text .append("<P>-------------------------------------------------------------------------------------------------</P>");
    text .append("<P><b><font-size=20>◦ PUBLICATIONS </font></b></P>");
    text .append("<P><font-size=10><b>1.</b> Lunar Crater Detection Walkthrough - A Review <i>(IRJET)</i> </font></P>");
    text .append("<P><font-size=10><b>2.</b> Machine Learning based Analysis of Industry Finances Subjected to Bankruptcy <i>(IRJET)</i></font></P>");

    QMessageBox::about(this,"Resume",text);

}
