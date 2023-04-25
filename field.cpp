#include "field.h"

field::field()
{

}

int field::get_step()
{
    return step;
}

void field::set_step(int new_step)
{
    step = new_step;
}

void field::set_cage_field(prnt_cage new_cage)
{
    cage_field.push_back(new_cage);
}

void field::delete_cage()
{
    cage_field.clear();
}

int field::analysis_cage()
{
    while (1)
    {
        random_device rd;                           // non-deterministic generator
        mt19937 gen(rd());                          // to seed mersenne twister.
        uniform_int_distribution<> dist(1,9);       // distribute results between 1 and 9 inclusive.

        int number = dist(gen);

        bool flag = true;

        auto iter = cage_field.begin();
        while (iter != cage_field.end())
        {
           if(iter->get_number_cage() == number)
           {
               flag = false;
               break;
           }
           iter++;
        }
        if(flag)
        {
            return number;
        }
    }
}
