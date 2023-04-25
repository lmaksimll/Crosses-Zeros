#ifndef PRNT_SYMBOL_H
#define PRNT_SYMBOL_H


class prnt_symbol
{
    public:
        prnt_symbol();

        bool get_crosses();
        bool get_zeros();
        void set_crosses();
        void set_zeros();

    private:
        bool crosses;
        bool zeros;
};

#endif // PRNT_SYMBOL_H
