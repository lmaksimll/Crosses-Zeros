#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <player.h>
#include <bot.h>
#include <field.h>
#include <prnt_cage.h>
#include <style_cage.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    player p;       //Игрок
    bot b;          //Бот
    field f;        //Поле
    bool game_start = false;

    void game_win(int res,vector<int> &tmp_index_cage);                 //Вызов ui функции конца игры
    void pain_win_cage(int res, vector<int> &tmp_index_cage);           //Закрашиваем клетки победителя игры
    void game_enabled(bool game_start);                                 //Вкл или выкл возможность выбирать символ и установка статуса игры
    void selection_cage(int number);                                    //Выбрать клетку
    void create_cage(bool bot, prnt_cage &new_cage);                    //Создание клетки в памяти

private slots:
    void clicked_button_x();
    void clicked_button_0();

    void clicked_button_clear();
    void clicked_button_reset();

    void paint_cage_00(bool bot);
    void paint_cage_01(bool bot);
    void paint_cage_02(bool bot);

    void paint_cage_10(bool bot);
    void paint_cage_11(bool bot);
    void paint_cage_12(bool bot);

    void paint_cage_20(bool bot);
    void paint_cage_21(bool bot);
    void paint_cage_22(bool bot);

};
#endif // MAINWINDOW_H
