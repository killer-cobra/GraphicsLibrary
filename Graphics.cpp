#define _WIN32_WINNT 0x0500

#include "Graphics.h"



void graphics::DefineScreenSize(int& width, int& height) {
    graphics::hWnd= GetConsoleWindow();
    RECT rect = { 0 };
    GetWindowRect(GetConsoleWindow(), &rect);
    width = rect.right;
    height = rect.right;
    graphics::hDC = GetDC(hWnd);
}


///////////////////////////////////////////////////////



//----------------------------------------------------------------
    graphics::coordinates::coordinates() {}

    graphics::coordinates::coordinates(int x, int y) {
        this->x = x;
        this->y = y;
    }

    graphics::coordinates::coordinates(const coordinates& other) {
        this->x = other.x;
        this->y = other.y;
    }

    void graphics::coordinates::operator = (const coordinates& other) {
        this->x = other.x;
        this->y = other.y;
    }

    graphics::coordinates graphics::coordinates::operator - (coordinates& other) {
        return coordinates(x - other.x, y - other.y);
    }

    graphics::coordinates graphics::coordinates::operator + (coordinates& other) {

        return coordinates(x + other.x, y + other.y);
    }

    graphics::coordinates graphics::coordinates::operator * (double f) {
        return coordinates(x * f, y * f);
    }

    //double* graphics::coordinates::Getcoordinates() const {
    //    double coords[2] = { this->x, this->y };
    //    return coords;
    //}




    void graphics::coordinates::swap() {
        int temp = x;
        x = y;
        y = temp;

    }


    void graphics::coordinates::setcoordinates(int x=0, int y=0) {
        this->x = x;
        this->y = y;
    }

    void graphics::coordinates::RandCoordinates() {
        this->x = rand() % width + 0;
        this->y = rand() % height + 0;
    }

    graphics::coordinates::~coordinates() {}

	//----------------------------------------------------------------


    graphics::Color::Color() {}

    graphics::Color::Color(unsigned char color_red, unsigned char color_green, unsigned char color_blue) {
            this->color_red = color_red;
            this->color_green = color_green;
            this->color_blue = color_blue;
        }

    graphics::Color::Color(const Color& other) {
            this->color_red = other.color_red;
            this->color_green = other.color_green;
            this->color_blue = other.color_blue;
        }

    void graphics::Color::operator = (const Color& other) {
        this->color_red = other.color_red;
        this->color_green = other.color_green;
        this->color_blue = other.color_blue;
    }


    void graphics::Color::SetColor(unsigned char color_red, unsigned char color_green, unsigned char color_blue) {

        this->color_red = color_red;
        this->color_green = color_green;
        this->color_blue = color_blue;
    }

    const COLORREF graphics::Color::GetColor()const {
        return RGB(color_red, color_green, color_blue);
    }

    void graphics::Color::RandomColor() {
         color_red = rand() % 255 + 0;
         color_green = rand() % 255 + 0;
         color_blue = rand() % 255 + 0;
    }


    graphics::Color::~Color() {}

	//----------------------------------------------------------------





    void graphics::swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }


    void graphics::Swap_c(coordinates& c1, coordinates& c2) {
        coordinates temp(c1.x, c1.y);
        c1.x = c2.x;
        c1.y = c2.y;
        c2.x = temp.x;
        c2.y = temp.y;
    }


    void graphics::DrawLine(int &x1, int &y1, int &x2, int &y2) {
        int deltaX = std::abs(x2 - x1);
        int deltaY = std::abs(y2 - y1);
        int signX = x1 < x2 ? 1 : -1;
        int signY = y1 < y2 ? 1 : -1;

        int error = deltaX - deltaY;

        SetPixel(hDC, x2, y2, white.GetColor());
        while (x1 != x2 || y1 != y2) {
            SetPixel(hDC, x1, y1, white.GetColor());
            int error2 = error * 2;
            if (error2 > -deltaY) {
                error -= deltaY;
                x1 += signX;
            }
            if (error2 < deltaX) {
                error += deltaX;
                y1 += signY;
            }
        }
    }


    void graphics::DrawCircle(int centerX, int centerY, int radius, Color& color) {
        int x = radius;
        int y = 0;
        int radiusError = 1 - x;

        while (x >= y) {
            // Рисуем пиксели октантов
            SetPixel(hDC, x, y, color.GetColor());
            SetPixel(hDC, x + centerX, y + centerY, color.GetColor());
            SetPixel(hDC, y + centerX, x + centerY, color.GetColor());
            SetPixel(hDC, -x + centerX, y + centerY, color.GetColor());
            SetPixel(hDC, -y + centerX, x + centerY, color.GetColor());
            SetPixel(hDC, -x + centerX, -y + centerY, color.GetColor());
            SetPixel(hDC, -y + centerX, -x + centerY, color.GetColor());
            SetPixel(hDC, x + centerX, -y + centerY, color.GetColor());
            SetPixel(hDC, y + centerX, -x + centerY, color.GetColor());
            y++;

            if (radiusError < 0) {
                radiusError += 2 * y + 1;
            }
            else {
                x--;
                radiusError += 2 * (y - x + 1);
            }
        }
    }


    void graphics::DrawCircle(coordinates coords, int radius, Color& color) {
        int x = radius;
        int y = 0;
        int radiusError = 1 - x;

        while (x >= y) {
            // Рисуем пиксели октантов
            SetPixel(hDC, x, y, color.GetColor());
            SetPixel(hDC, x + coords.x, y + coords.y, color.GetColor());
            SetPixel(hDC, y + coords.x, x + coords.y, color.GetColor());
            SetPixel(hDC, -x + coords.x, y + coords.y, color.GetColor());
            SetPixel(hDC, -y + coords.x, x + coords.y, color.GetColor());
            SetPixel(hDC, -x + coords.x, -y + coords.y, color.GetColor());
            SetPixel(hDC, -y + coords.x, -x + coords.y, color.GetColor());
            SetPixel(hDC, x + coords.x, -y + coords.y, color.GetColor());
            SetPixel(hDC, y + coords.x, -x + coords.y, color.GetColor());
            y++;

            if (radiusError < 0) {
                radiusError += 2 * y + 1;
            }
            else {
                x--;
                radiusError += 2 * (y - x + 1);
            }
        }
    }

    void graphics::Draw_Line(coordinates c1, coordinates c2, Color& color) {
        int deltaX = std::abs(c2.x - c1.x);
        int deltaY = std::abs(c2.y - c1.y);
        int signX = c1.x < c2.x ? 1 : -1;
        int signY = c1.y < c2.y ? 1 : -1;

        int error = deltaX - deltaY;

        SetPixel(hDC, c2.x, c2.y, color.GetColor());
        while (c1.x != c2.x || c1.y != c2.y) {
            SetPixel(hDC, c1.x, c1.y, color.GetColor());
            int error2 = error * 2;
            if (error2 > -deltaY) {
                error -= deltaY;
                c1.x += signX;
            }
            if (error2 < deltaX) {
                error += deltaX;
                c1.y += signY;
            }
        }
    }



    void graphics::DrawTriangle(coordinates c1, coordinates c2, coordinates c3, Color& color) {
        Draw_Line(c1, c2, color);
        Draw_Line(c2, c3, color);
        Draw_Line(c3, c1, color);
    }

    

    void graphics::DrawRasTriangle(int x1, int y1, int x2, int y2, int x3, int y3, Color& color) {
        auto edgeFunction = [](int x0, int y0, int x1, int y1, int x2, int y2) {
            return (y2 - y0) * (x1 - x0) - (x2 - x0) * (y1 - y0);
            };

        // Получение границ треугольника
        int minX = min(x1, x2, x3);
        int minY = min(y1, y2, y3);
        int maxX = max(x1, x2, x3);
        int maxY = max(y1, y2, y3);

        // Построчный обход пикселей в ограничивающем прямоугольнике
        for (int y = minY; y <= maxY; ++y) {
            for (int x = minX; x <= maxX; ++x) {
                // Вычисление весов для точки относительно краев треугольника
                int w0 = edgeFunction(x2, y2, x3, y3, x, y);
                int w1 = edgeFunction(x3, y3, x1, y1, x, y);
                int w2 = edgeFunction(x1, y1, x2, y2, x, y);

                // Проверка, находится ли точка (x, y) внутри треугольника
                if (w0 >= 0 && w1 >= 0 && w2 >= 0) {
                    SetPixel(hDC, x, y, color.GetColor()); // Закрашиваем пиксель
                }
            }
        }
    }





    void graphics::DrawRas_Triangle(coordinates c1, coordinates c2, coordinates c3, Color& color) {



        auto edgeFunction = [](int x0, int y0, int x1, int y1, int x2, int y2) {
            return (y2 - y0) * (x1 - x0) - (x2 - x0) * (y1 - y0);
            };

        // Получение границ треугольника
        int minX = min(c1.x, c2.x, c3.x);
        int minY = min(c1.y, c2.y, c3.y);
        int maxX = max(c1.x, c2.x, c3.x);
        int maxY = max(c1.y, c2.y, c3.y);

        // Построчный обход пикселей в ограничивающем прямоугольнике
        for (int y = minY; y <= maxY; ++y) {
            for (int x = minX; x <= maxX; ++x) {
                // Вычисление весов для точки относительно краев треугольника
                int w0 = edgeFunction(c2.x, c2.y, c3.x, c3.y, x, y);
                int w1 = edgeFunction(c3.x, c3.y, c1.x, c1.y, x, y);
                int w2 = edgeFunction(c1.x, c1.y, c2.x, c2.y, x, y);

                // Проверка, находится ли точка (x, y) внутри треугольника
                if (w0 >= 0 && w1 >= 0 && w2 >= 0) {
                    SetPixel(hDC, x, y, color.GetColor()); // Закрашиваем пиксель
                }
            }
        }
    }



    //void graphics::triangle21(coordinates c1, coordinates c2, coordinates c3, Color& color) {
    //    if (c1.y == c2.y && c1.y == c3.y) return; // i dont care about degenerate triangles
    //    // sort the vertices, t0, t1, t2 lower-to-upper (bubblesort yay!)
    //    if (c1.y > c2.y) Swap_c(c1, c2);
    //    if (c1.y > c3.y) Swap_c(c1, c3);
    //    if (c2.y > c3.y) Swap_c(c2, c3);
    //    int total_height = c3.y - c1.y;
    //    for (int i = 0; i < total_height; i++) {
    //        bool second_half = i > c2.y - c1.y || c2.y == c1.y;
    //        int segment_height = second_half ? c3.y - c2.y : c2.y - c1.y;
    //        float alpha = (float)i / total_height;
    //        float beta = (float)(i - (second_half ? c2.y - c1.y : 0)) / segment_height; // be careful: with above conditions no division by zero here
    //        coordinates Aa = c2 - c1;
    //        coordinates Aaa = Aa * alpha;
    //        coordinates A = c1 + Aaa;
    //        coordinates Bb = (c3 - c2) * beta

    //            coordinates B = second_half ? c2 + coordinates((c3 - c2) * beta) : c1 + coordinates((c2 - c1) * beta);
    //        if (A.x > B.x) Swap_c(A, B);
    //        for (int j = A.x; j <= B.x; j++) {
    //            SetPixel(hDC, j, c1.y + i, color.GetColor()); // attention, due to int casts t0.y+i != A.y
    //        }
    //    }
    //}



    void graphics::TriangleRast (coordinates c1, coordinates c2, coordinates c3, Color &color) {
        if (c1.y == c2.y && c1.y == c3.y) return;
        // sort the vertices, c1, c2 lower-to-upper (bubblesort yay!)
        if (c1.y > c2.y) Swap_c(c1, c2);
        if (c1.y > c3.y) Swap_c(c1, c3);
        if (c2.y > c3.y) Swap_c(c2, c3);
        int total_height = c3.y - c1.y;
        for (int i = 0; i < total_height; i++) {
            bool second_half = i > c2.y - c1.y || c2.y == c1.y;
            int segment_height = second_half ? c3.y - c2.y : c2.y - c1.y;
            float alpha = (float)i / total_height;
            float beta = (float)(i - (second_half ? c2.y - c1.y : 0)) / segment_height;
            coordinates Aa = c3 - c1;
            coordinates Aaa = Aa * alpha;
            coordinates A = c1 + Aaa;
            coordinates Bb = (c3 - c2)  * beta;
            coordinates Bbb = Bb + c2;

            coordinates Cc = (c2 - c1) * beta;
            coordinates Ccc = c1 + Cc;

            coordinates B = second_half ? Bbb: Ccc;

            if (A.x > B.x) Swap_c(A, B);
            for (int j = A.x; j <= B.x; j++) {
                SetPixel(hDC,j, c1.y + i, color.GetColor()); // attention, due to int casts t0.y+i != A.y
            }
        }
    }


