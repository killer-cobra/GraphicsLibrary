#include "Graphics.h"
#include <iostream>

using namespace graphics;
int main(int argc, char** argv) {



    srand(time(0));

    DefineScreenSize(width, height);


    Color color;
    color.SetColor(255, 0, 255);
    color.RandomColor();

    coordinates c1(400, 400);
    coordinates c2(200, 290);
    coordinates c3(150, 100);


    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            SetPixel(hDC, i, j, color.GetColor());
        }
    }


    color.RandomColor();
    DrawRas_Triangle(c1, c2, c3, color);
    //DrawTriangle(c1, c2, c3, color);

    color.RandomColor();
    c1.RandCoordinates();
    c3.RandCoordinates();

    Draw_Line(c1, c3, color);

    color.RandomColor();
    DrawCircle(500, 259, 70, color);

    c1.RandCoordinates();
    color.RandomColor();
    DrawCircle(c1, 70, color);

    color.RandomColor();
    c1.RandCoordinates();
    c2.RandCoordinates();
    c3.RandCoordinates();
    



    char a = 0;
    std::cin >> a;
    //system("cls");

    return 0;
}
