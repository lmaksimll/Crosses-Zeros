#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //------------Выбор x/0------------
    clicked_button_x();     //Значения по умолчанию
    connect(ui->radioButton_x,SIGNAL(clicked()),this,SLOT(clicked_button_x()));
    connect(ui->radioButton_0,SIGNAL(clicked()),this,SLOT(clicked_button_0()));

    //------Кнопки сброс и отчистка-----
    connect(ui->pushButton_clear,SIGNAL(clicked()),this,SLOT(clicked_button_clear()));
    connect(ui->pushButton_reset,SIGNAL(clicked()),this,SLOT(clicked_button_reset()));

    //-----------Кнопки поля------------

    connect(ui->pushButton_00,SIGNAL(clicked(bool)),this,SLOT(paint_cage_00(bool)));
    connect(ui->pushButton_01,SIGNAL(clicked(bool)),this,SLOT(paint_cage_01(bool)));
    connect(ui->pushButton_02,SIGNAL(clicked(bool)),this,SLOT(paint_cage_02(bool)));

    connect(ui->pushButton_10,SIGNAL(clicked(bool)),this,SLOT(paint_cage_10(bool)));
    connect(ui->pushButton_11,SIGNAL(clicked(bool)),this,SLOT(paint_cage_11(bool)));
    connect(ui->pushButton_12,SIGNAL(clicked(bool)),this,SLOT(paint_cage_12(bool)));

    connect(ui->pushButton_20,SIGNAL(clicked(bool)),this,SLOT(paint_cage_20(bool)));
    connect(ui->pushButton_21,SIGNAL(clicked(bool)),this,SLOT(paint_cage_21(bool)));
    connect(ui->pushButton_22,SIGNAL(clicked(bool)),this,SLOT(paint_cage_22(bool)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::game_enabled(bool game_start)
{
    this->game_start = game_start;
    ui->radioButton_x->setEnabled(!game_start);
    ui->radioButton_0->setEnabled(!game_start);
}

void MainWindow::selection_cage(int number)
{
    switch (number) {
    case 1:
        paint_cage_00(1);
        break;
    case 2: 
        paint_cage_01(1);
        break;
    case 3:
        paint_cage_02(1);
        break;
    case 4:
        paint_cage_10(1);
        break;
    case 5:
        paint_cage_11(1);
        break;
    case 6:
        paint_cage_12(1);
        break;
    case 7:
        paint_cage_20(1);
        break;
    case 8:
        paint_cage_21(1);
        break;
    case 9:
        paint_cage_22(1);
        break;
    default:
        break;
    }
}

void MainWindow::create_cage(bool bot, prnt_cage &new_cage)
{
    if(!game_start)             //Проверили что игра начата и заблокировали выбор символов
    {
        game_enabled(true);
    }

    if(!bot)                    //Создали клетку
    {
        f.set_cage_field(new_cage);
    }
    else
    {
        f.set_cage_field(new_cage);
    }

    int tmp = f.get_step();
    tmp++;
    f.set_step(tmp);                  //сделали 1 ход

    if(f.get_step() >= 5)
    {
        //f.check_win();          //Проверить на победу
        //game_win();             //Если победа вызвать функцию победы
    }

    if(!bot && f.get_step() < 9)
    {
        int number = f.analysis_cage();                //Сказали боту что нужно ходить если кнопка нажата пользователем
        selection_cage(number);                        //Бот сделал выбор
    }

    if(f.get_step() == 9)
    {
        game_message::getInstance().draw();          //Сказать что ничья сообщением
        game_enabled(false);
        //clicked_button_clear();
    }
}

void MainWindow::clicked_button_x()
{
    qDebug("Выбран Х");

    p.set_crosses();
    b.set_zeros();
}

void MainWindow::clicked_button_0()
{
    qDebug("Выбран 0");

    p.set_zeros();
    b.set_crosses();
}

void MainWindow::clicked_button_clear()
{
    f.delete_cage();
    f.set_step(0);

    game_enabled(false);             //Разблокировать выбор символа для нажати

    ui->pushButton_00->setEnabled(1);   //Разблокировать поле для нажати
    ui->pushButton_01->setEnabled(1);
    ui->pushButton_02->setEnabled(1);
    ui->pushButton_10->setEnabled(1);
    ui->pushButton_11->setEnabled(1);
    ui->pushButton_12->setEnabled(1);
    ui->pushButton_20->setEnabled(1);
    ui->pushButton_21->setEnabled(1);
    ui->pushButton_22->setEnabled(1);

    ui->pushButton_00->setStyleSheet(style_cage::getInstance().paint_default_cage());        //Вернуть стили кнопкам
    ui->pushButton_01->setStyleSheet(style_cage::getInstance().paint_default_cage());
    ui->pushButton_02->setStyleSheet(style_cage::getInstance().paint_default_cage());
    ui->pushButton_10->setStyleSheet(style_cage::getInstance().paint_default_cage());
    ui->pushButton_11->setStyleSheet(style_cage::getInstance().paint_default_cage());
    ui->pushButton_12->setStyleSheet(style_cage::getInstance().paint_default_cage());
    ui->pushButton_20->setStyleSheet(style_cage::getInstance().paint_default_cage());
    ui->pushButton_21->setStyleSheet(style_cage::getInstance().paint_default_cage());
    ui->pushButton_22->setStyleSheet(style_cage::getInstance().paint_default_cage());

    qDebug() << "клеток сейчас- " << f.get_step();
}

void MainWindow::clicked_button_reset()
{
    p.set_count(0);
    b.set_count(0);

    ui->spinBox_player->setValue(p.get_count());
    ui->spinBox_bot->setValue(p.get_count());
}

void MainWindow::paint_cage_00(bool bot)
{
    if(!bot)
    {
        prnt_cage c00(1,p);
        create_cage(bot,c00);

        if(p.get_crosses())
        {
            //крестик
            ui->pushButton_00->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_00->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }
    else
    {
        prnt_cage c00(1,b);
        create_cage(bot,c00);

        if(b.get_crosses())
        {
            //крестик
            ui->pushButton_00->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_00->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }

    ui->pushButton_00->setEnabled(0);
}

void MainWindow::paint_cage_01(bool bot)
{
    if(!bot)
    {
        prnt_cage c01(2,p);
        create_cage(bot,c01);

        if(p.get_crosses())
        {
            //крестик
            ui->pushButton_01->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_01->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }
    else
    {
        prnt_cage c01(2,b);
        create_cage(bot,c01);

        if(b.get_crosses())
        {
            //крестик
            ui->pushButton_01->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_01->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }

    ui->pushButton_01->setEnabled(0);
}

void MainWindow::paint_cage_02(bool bot)
{
    if(!bot)
    {
        prnt_cage c02(3,p);
        create_cage(bot,c02);

        if(p.get_crosses())
        {
            //крестик
            ui->pushButton_02->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_02->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }
    else
    {
        prnt_cage c02(3,b);
        create_cage(bot,c02);

        if(b.get_crosses())
        {
            //крестик
            ui->pushButton_02->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_02->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }

    ui->pushButton_02->setEnabled(0);
}

void MainWindow::paint_cage_10(bool bot)
{
    if(!bot)
    {
        prnt_cage c10(4,p);
        create_cage(bot,c10);

        if(p.get_crosses())
        {
            //крестик
            ui->pushButton_10->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_10->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }
    else
    {
        prnt_cage c10(4,b);
        create_cage(bot,c10);

        if(b.get_crosses())
        {
            //крестик
            ui->pushButton_10->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_10->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }

    ui->pushButton_10->setEnabled(0);
}

void MainWindow::paint_cage_11(bool bot)
{
    if(!bot)
    {
        prnt_cage c11(5,p);
        create_cage(bot,c11);

        if(p.get_crosses())
        {
            //крестик
            ui->pushButton_11->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_11->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }
    else
    {
        prnt_cage c11(5,b);
        create_cage(bot,c11);

        if(b.get_crosses())
        {
            //крестик
            ui->pushButton_11->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_11->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }

    ui->pushButton_11->setEnabled(0);
}

void MainWindow::paint_cage_12(bool bot)
{
    if(!bot)
    {
        prnt_cage c12(6,p);
        create_cage(bot,c12);

        if(p.get_crosses())
        {
            //крестик
            ui->pushButton_12->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_12->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }
    else
    {
        prnt_cage c12(6,b);
        create_cage(bot,c12);

        if(b.get_crosses())
        {
            //крестик
            ui->pushButton_12->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_12->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }

    ui->pushButton_12->setEnabled(0);
}

void MainWindow::paint_cage_20(bool bot)
{
    if(!bot)
    {
        prnt_cage c20(7,p);
        create_cage(bot,c20);

        if(p.get_crosses())
        {
            //крестик
            ui->pushButton_20->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_20->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }
    else
    {
        prnt_cage c20(7,b);
        create_cage(bot,c20);

        if(b.get_crosses())
        {
            //крестик
            ui->pushButton_20->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_20->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }

    ui->pushButton_20->setEnabled(0);
}

void MainWindow::paint_cage_21(bool bot)
{
    if(!bot)
    {
        prnt_cage c21(8,p);
        create_cage(bot,c21);

        if(p.get_crosses())
        {
            //крестик
            ui->pushButton_21->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_21->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }
    else
    {
        prnt_cage c21(8,b);
        create_cage(bot,c21);

        if(b.get_crosses())
        {
            //крестик
            ui->pushButton_21->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_21->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }

    ui->pushButton_21->setEnabled(0);
}

void MainWindow::paint_cage_22(bool bot)
{
    if(!bot)
    {
        prnt_cage c22(9,p);
        create_cage(bot,c22);

        if(p.get_crosses())
        {
            //крестик
            ui->pushButton_22->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_22->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }
    else
    {
        prnt_cage c22(9,b);
        create_cage(bot,c22);

        if(b.get_crosses())
        {
            //крестик
            ui->pushButton_22->setStyleSheet(style_cage::getInstance().paint_crosses());
        }
        else
        {
            //нолик
            ui->pushButton_22->setStyleSheet(style_cage::getInstance().paint_zeros());
        }
    }

    ui->pushButton_22->setEnabled(0);
}


