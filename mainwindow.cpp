#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    mFilename = "";
    ui->textEdit->setPlainText("");

}


void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open a file");

    if(!file.isEmpty())
    {
        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text))
        {
            mFilename = file;
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(text);
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    QFile sFile(mFilename);
    if(sFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&sFile);

        out<<ui->textEdit->toPlainText();

        sFile.flush();
        sFile.close();
    }
}


void MainWindow::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "Open a file");

    if(!file.isEmpty())
    {
        mFilename = file;
       on_actionSave_triggered();
    }
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionBold_triggered()
{
    //QTextCharFormat format;
    if(ui->textEdit->fontWeight()!=QFont::Bold)
    {
        ui->textEdit->setFontWeight(QFont::Bold);
    }
    else if(ui->textEdit->fontWeight()==QFont::Bold)
    {
        ui->textEdit->setFontWeight(QFont::Normal);
    }

//    QFont font;
//    QTextCursor cursor = ui->textEdit->textCursor();
//    QTextCharFormat format;


//    if(cursor.hasSelection()){
//        font = cursor.charFormat().font();
//        if(!cursor.charFormat().font().bold()){
//            format.setFontWeight(QFont::Bold);
//            cursor.mergeCharFormat(format);
//        }
//        else{
//            format.setFontWeight(QFont::Normal);
//            cursor.mergeCharFormat(format);
//       }
//       ui->textEdit->setTextCursor(cursor);
//    }
}


void MainWindow::on_actionSubscript_triggered()
{
    //QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat format;
    QTextCursor cursor = ui->textEdit->textCursor();
    if(cursor.hasSelection())
    {
        if(cursor.charFormat().verticalAlignment()!=QTextCharFormat::AlignSubScript)
        {
            format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
            ui->textEdit->textCursor().mergeCharFormat(format);
        }
        else
        {
            format.setVerticalAlignment(QTextCharFormat::AlignNormal);
            ui->textEdit->textCursor().mergeCharFormat(format);
        }
    }

//    if(QEvent::KeyPress)
//    {
//        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
//        ui->textEdit->textCursor().mergeCharFormat(format);
//    }

}

void MainWindow::on_actionSuperscript_triggered()
{
    QTextCharFormat format;
    QTextCursor cursor = ui->textEdit->textCursor();
    if(cursor.hasSelection())
    {
        if(cursor.charFormat().verticalAlignment()!=QTextCharFormat::AlignSuperScript)
        {
            format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
            ui->textEdit->textCursor().mergeCharFormat(format);
        }
        else
        {
            format.setVerticalAlignment(QTextCharFormat::AlignNormal);
            ui->textEdit->textCursor().mergeCharFormat(format);
        }
    }
}

void MainWindow::on_actionSubscript_toggled(bool){};
void MainWindow::on_actionSubscript_hovered(){};
