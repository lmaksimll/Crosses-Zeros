#ifndef BOT_H
#define BOT_H
#include <prnt_count.h>
#include <prnt_symbol.h>


class bot   : public prnt_count, public prnt_symbol
{
    public:
        bot();

        //void go_step(int number);
};

#endif // BOT_H
