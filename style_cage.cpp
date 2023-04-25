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

QString style_cage::paint_win_cage()
{

}

QString style_cage::paint_default_cage()
{
    return "";
}
