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

        int check_status_game(vector<int> &index_cage);

        int analysis_cage();

    private:
        vector <prnt_cage> cage_field;
        int step = 0;

        int analysis_line(vector<int> &tmp_crosses,vector<int> &tmp_zeros,vector<int> &index_cage);

};

#endif // FIELD_H
