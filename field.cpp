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

int field::check_status_game(vector<int> &index_cage)
{
    //-1 это ничья
    //0 это победа ноликов
    //1 это победа крестиков
    //2 это игра продолжается

    vector<int> tmp_crosses;        //Поля с крестиками
    vector<int> tmp_zeros;          //Поля с ноликами

    auto iter = cage_field.begin();
    while (iter != cage_field.end())
    {
       if(iter->get_crosses_cage())
       {
           tmp_crosses.push_back(iter->get_number_cage());
       }
       else
       {
           tmp_zeros.push_back(iter->get_number_cage());
       }
       iter++;
    }

    if(step >= 5)
    {
        //---------Линии------------
        index_cage[0] = 1;
        index_cage[1] = 2;
        index_cage[2] = 3;
        //int index_cage[3] = {1,2,3};
        int res;
        res = analysis_line(tmp_crosses,tmp_zeros,index_cage);
        if(res == 0)
            return 0;

        else if(res == 1)
            return 1;

        //----------------------
        index_cage[0] = 4;
        index_cage[1] = 5;
        index_cage[2] = 6;

        res = analysis_line(tmp_crosses,tmp_zeros,index_cage);
        if(res == 0)
            return 0;

        else if(res == 1)
            return 1;

        //----------------------
        index_cage[0] = 7;
        index_cage[1] = 8;
        index_cage[2] = 9;

        res = analysis_line(tmp_crosses,tmp_zeros,index_cage);
        if(res == 0)
            return 0;

        else if(res == 1)
            return 1;

        //---------Столбцы------------
        index_cage[0] = 1;
        index_cage[1] = 4;
        index_cage[2] = 7;

        res = analysis_line(tmp_crosses,tmp_zeros,index_cage);
        if(res == 0)
            return 0;

        else if(res == 1)
            return 1;

        //----------------------
        index_cage[0] = 2;
        index_cage[1] = 5;
        index_cage[2] = 8;

        res = analysis_line(tmp_crosses,tmp_zeros,index_cage);
        if(res == 0)
            return 0;

        else if(res == 1)
            return 1;

        //----------------------
        index_cage[0] = 3;
        index_cage[1] = 6;
        index_cage[2] = 9;

        res = analysis_line(tmp_crosses,tmp_zeros,index_cage);
        if(res == 0)
            return 0;

        else if(res == 1)
            return 1;

        //---------Диагонали------------
        index_cage[0] = 1;
        index_cage[1] = 5;
        index_cage[2] = 9;

        res = analysis_line(tmp_crosses,tmp_zeros,index_cage);
        if(res == 0)
            return 0;

        else if(res == 1)
            return 1;

        //----------------------
        index_cage[0] = 3;
        index_cage[1] = 5;
        index_cage[2] = 7;

        res = analysis_line(tmp_crosses,tmp_zeros,index_cage);
        if(res == 0)
            return 0;

        else if(res == 1)
            return 1;

    }
    if(step == 9)
    {
        return -1;
    }

    return 2;
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

int field::analysis_line(vector<int> &tmp_crosses, vector<int> &tmp_zeros, vector<int> &index_cage)
{
    bool cage1 = false;
    bool cage2 = false;
    bool cage3 = false;

    auto iter = tmp_crosses.begin();
    while(iter != tmp_crosses.end())
    {
        if(*iter == index_cage[0])
        {
            cage1 = true;
        }
        else if(*iter == index_cage[1])
        {
            cage2 = true;
        }
        else if(*iter == index_cage[2])
        {
            cage3 = true;
        }
        iter++;
    }

    if(cage1 && cage2 && cage3)
    {
        return 1;
    }
    else
    {
        cage1 = false;
        cage2 = false;
        cage3 = false;

        auto iter = tmp_zeros.begin();
        while(iter != tmp_zeros.end())
        {
            if(*iter == index_cage[0])
            {
                cage1 = true;
            }
            else if(*iter == index_cage[1])
            {
                cage2 = true;
            }
            else if(*iter == index_cage[2])
            {
                cage3 = true;
            }
            iter++;
        }

        if(cage1 && cage2 && cage3)
        {
            return 0;
        }
        else
        {
            return 2;
        }
    }
}


