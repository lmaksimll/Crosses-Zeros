#ifndef GAME_MESSAGE_H
#define GAME_MESSAGE_H
#include <QMessageBox>

//Singleton
class game_message
{
private:
    game_message() {}
    game_message( const game_message&);
    game_message& operator=( game_message& );
public:
    static game_message& getInstance() {
        static game_message  instance;
        return instance;
    }

    void bot_win();
    void player_win();
    void draw();
};

#endif // GAME_MESSAGE_H
