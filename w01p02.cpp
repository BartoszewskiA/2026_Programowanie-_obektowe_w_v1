#include <iostream>

using namespace std;

class Punkt
{
private:
    int x;
    int y;

public:
    // void setX(int px) { x = px; }
    // void setY(int py) { y = py; }
    void setX(int px)
    {
        if (px >= 0)
            x = px;
        else
            x = 0;
    }
    void setY(int py)
    {
        if (py >= 0)
            y = py;
        else
            y = 0;
    }
    int getX() { return x; }
    int getY() { return y; }
};

int main()
{
    Punkt p1;
    // p1.x = 20; - nie działa
    p1.setX(-100);
    p1.setY(20);
    cout << p1.getX() << ";" << p1.getY();
    return 0;
}