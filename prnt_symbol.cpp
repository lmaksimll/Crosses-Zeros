#include "prnt_symbol.h"

prnt_symbol::prnt_symbol()
{

}

bool prnt_symbol::get_crosses()
{
    return crosses;
}

bool prnt_symbol::get_zeros()
{
    return zeros;
}

void prnt_symbol::set_crosses()
{
    crosses = true;
    zeros = false;
}

void prnt_symbol::set_zeros()
{
    crosses = false;
    zeros = true;
}
