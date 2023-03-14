#include <iostream>
using namespace std;

struct Rect
{
    double x, y, w, h;
};
Rect merge(Rect &a, Rect &b)
{
    Rect c;
    c.x = min(a.x, b.x);
    c.y = max(a.y, b.y);
    c.w = max(a.x + a.w, b.x + b.w) - c.x;
    c.h = c.y - min(a.y - a.h, b.y - b.h);
    return c;
};

int main()
{
    Rect R1,R2,R3,R4,R5,R6,R7;
cout << "Please input Rect 1 (x y w h): ";
cin >> R1.x >> R1.y >> R1.w >> R1.h;
cout << "Please input Rect 2 (x y w h): ";
cin >> R2.x >> R2.y >> R2.w >> R2.h;
cout << "Please input Rect 3 (x y w h): ";
cin >> R3.x >> R3.y >> R3.w >> R3.h;
cout << "Please input Rect 4 (x y w h): ";
cin >> R4.x >> R4.y >> R4.w >> R4.h;
R5 = merge(R1, R2);
R6 = merge(R3, R4);
R7 = merge(R5, R6);
cout << "Merged Rect = ";
cout << R7.x << " " << R7.y << " " << R7.w << " " << R7.h << " ";
return 0;
}