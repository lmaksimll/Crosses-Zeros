#ifndef PRNT_CAGE_H
#define PRNT_CAGE_H
#include <player.h>
#include <bot.h>

class prnt_cage
{
    public:
        prnt_cage(int number, player &p);
        prnt_cage(int number, bot &b);

        int get_number_cage();
        bool get_crosses_cage();
        bool get_zeros_cage();

    private:
        int number_cage;

        bool crosses_cage;
        bool zeros_cage;
};

#endif // PRNT_CAGE_H
