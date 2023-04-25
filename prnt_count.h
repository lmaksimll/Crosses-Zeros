#ifndef PRNT_COUNT_H
#define PRNT_COUNT_H


class prnt_count
{
    public:
        prnt_count();

        int get_count();
        void set_count(int value);

    private:
        int count = 0;
};

#endif // PRNT_COUNT_H
