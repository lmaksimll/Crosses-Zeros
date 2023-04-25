#include "game_message.h"


void game_message::bot_win()
{
    QMessageBox msgBox;
    msgBox.setText("Игра завершена!");
    msgBox.setInformativeText("Увы, искусственный интеллект оказался сильней");
    msgBox.exec();
}

void game_message::player_win()
{
    QMessageBox msgBox;
    msgBox.setText("Игра завершена!");
    msgBox.setInformativeText("Вы победили");
    msgBox.exec();
}

void game_message::draw()
{
    QMessageBox msgBox;
    msgBox.setText("Игра завершена!");
    msgBox.setInformativeText("Силы оказались равны. Ничья");
    msgBox.exec();
}
