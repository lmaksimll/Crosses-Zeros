#include "style_cage.h"

QString style_cage::paint_crosses()
{
    return "QPushButton{"
        "background-image: url(:/resourses/img_x_100.png) ;"
        "background-repeat: no-repeat ;"
        "background-position: center center;"
        "border: 1px solid #222;"
        "}";
}

QString style_cage::paint_zeros()
{
    return "QPushButton{"
        "background-image: url(:/resourses/img_o_100.png) ;"
        "background-repeat: no-repeat ;"
        "background-position: center center;"
        "border: 1px solid #222;"
           "}";
}

QString style_cage::paint_win_crosses()
{
    return "QPushButton{"
        "background-color: rgb(78, 154, 6);"
        "background-image: url(:/resourses/img_x_100.png) ;"
        "background-repeat: no-repeat ;"
        "background-position: center center;"
        "border: 1px solid #222;"
        "}";
}

QString style_cage::paint_win_zeros()
{
    return "QPushButton{"
        "background-color: rgb(78, 154, 6);"
        "background-image: url(:/resourses/img_o_100.png) ;"
        "background-repeat: no-repeat ;"
        "background-position: center center;"
        "border: 1px solid #222;"
        "}";
}

QString style_cage::paint_default_cage()
{
    return "";
}
