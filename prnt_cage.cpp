#include "prnt_cage.h"

prnt_cage::prnt_cage(int number, player &p)
{
    number_cage = number;

    crosses_cage = p.get_crosses();
    zeros_cage = p.get_zeros();
}

prnt_cage::prnt_cage(int number, bot &b)
{
    number_cage = number;

    crosses_cage = b.get_crosses();
    zeros_cage = b.get_zeros();
}

int prnt_cage::get_number_cage()
{
    return number_cage;
}
