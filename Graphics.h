#pragma once
#include <windows.h>
#include <ctime>
#include <stdlib.h>
//#include <vector>
#include <algorithm>
#include <cmath>
#include "geometry.h"

namespace graphics {

    __declspec(selectany) int height;
    __declspec(selectany) int width;
    __declspec(selectany) HWND hWnd;
    __declspec(selectany) HDC hDC;
    
    //__declspec(selectany) long double M_PI = 3.14159;


    void DefineScreenSize(int& width, int& height);



    /// /////////////////////////////////////////


    class Color {
        unsigned char color_red = 0;
        unsigned char color_green = 0;
        unsigned char color_blue = 0;


    public:
        Color();

        Color(unsigned char color_red, unsigned char color_green, unsigned char color_blue);

        Color(const Color& other);

        void operator = (const Color& other);


        void SetColor(unsigned char color_red, unsigned char color_green, unsigned char color_blue);

        const COLORREF GetColor() const;

        void RandomColor();

        ~Color();
    };

    __declspec(selectany) Color white(255, 255, 255);
    __declspec(selectany) Color black(0, 0, 0);
    __declspec(selectany) Color red(255, 0, 0);
    __declspec(selectany) Color green(0, 255, 0);
    __declspec(selectany) Color blue(0, 0, 255);




    class coordinates {
        friend void DrawLine(coordinates& c1, coordinates& c2, Color& color);
        friend void DrawCircle(coordinates coords, int radius, Color& color);
        friend void DrawTriangle(coordinates c1, coordinates c2, coordinates c3, Color& color);
        friend void TriangleRast(coordinates ñ0, coordinates ñ1, coordinates ñ2, Color& color);
        friend void Swap_c(coordinates& c1, coordinates& c2);


    public:
        int x = 0;
        int y = 0;
    public:
        coordinates();

        coordinates(int x, int y);

        coordinates(const coordinates& other);


        void operator = (const coordinates& other);

        coordinates operator + (coordinates& other);



        coordinates operator - (coordinates& other);

        coordinates operator * (double f);

        //double* Getcoordinates() const;

        void swap();

        void setcoordinates(int x, int y);

        void RandCoordinates();


        ~coordinates();
    };



    void swap(int &a, int &b);

    void Swap_c(coordinates& c1, coordinates& c2);

    void DrawLine(int& x1, int& y1, int& x2, int& y2);

    void Draw_Line(coordinates c1, coordinates c2, Color& color);

    void DrawCircle(int centerX, int centerY, int radius, Color& color);

    void DrawCircle(coordinates coords, int radius, Color& color);

    void DrawTriangle(coordinates c1, coordinates c2, coordinates c3, Color& color);

    void DrawRasTriangle(int x1, int y1, int x2, int y2, int x3, int y3, Color& color);

    void DrawRas_Triangle(coordinates c1, coordinates c2, coordinates c3, Color& color);

    void TriangleRast (coordinates c1, coordinates c2, coordinates c3, Color& color);
}

