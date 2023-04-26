#ifndef STYLE_CAGE_H
#define STYLE_CAGE_H
#include <QString>

using namespace std;

//Singleton
class style_cage
{
private:
    style_cage() {}
    style_cage( const style_cage&);
    style_cage& operator=( style_cage& );
public:
    static style_cage& getInstance() {
        static style_cage  instance;
        return instance;
    }

    QString paint_crosses();
    QString paint_zeros();

    QString paint_win_crosses();
    QString paint_win_zeros();

    QString paint_default_cage();
};

#endif // STYLE_CAGE_H
