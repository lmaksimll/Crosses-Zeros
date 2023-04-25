#ifndef FIELD_H
#define FIELD_H
#include <prnt_cage.h>
#include <vector>
#include <bot.h>
#include <random>

using namespace std;

class field
{
    public:
        field();

        int get_step();
        void set_step(int new_step);

        void set_cage_field(prnt_cage new_cage);
        void delete_cage();

        bool check_win();

        int analysis_cage();

    private:
        vector <prnt_cage> cage_field;
        int step = 0;

};

#endif // FIELD_H
