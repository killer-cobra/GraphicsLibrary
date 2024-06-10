#pragma once
#include <math.h>
#include <algorithm>
//#include <type_traits>
#include <ostream>
#include "Graphics.h"
__declspec(selectany) long double M_PI = 3.14159;


inline long double operator"" _deg(long double deg)
{
    return deg * M_PI / 180;
}

inline long double operator"" _rad(long double rad) {
    return 0;
}

//template <> double transformationT_to_double <double> (double value) {
//    return value;
//}




//namespace geometry {

    //template <typename T> class complex 
    /*template<> */ class complex /*<double>*/ {
    private:
        //friend long float transformationT_to_double( x);
        const char j = -1;


        double x, y, m_re, m_im;


        //static_assert(
        //    std::is_same_v<T, int> ||
        //    std::is_same_v<T, float> ||
        //    std::is_same_v<T, double>,
        //    "MyTemplateClass only supports int, float, and double as template parameters"
        //    );


    public:

        complex() {}

        complex(const double& a, const double& b) {
            this->x = a;
            this->y = b;
            inPolarForm();
        }

        complex(const double& a) {
            this->x = a;
            this->y = 0;
            inPolarForm();
        }

        complex(const complex& ohter) {
            x = ohter.x;
			y = ohter.y;
            m_re = ohter.m_re;
			m_im = ohter.m_im;
        }



        complex operator + (const complex& other) {
            return complex(other.x + this->x, other.y + this->y);
        }

        complex operator - (const complex& other) {
            return complex(other.x - this->x, other.y - this->y);
        }

        complex operator * (const complex& other) {
            return complex(other.m_re * this->m_re, other.m_im + this->m_im);
        }

        complex operator / (const complex& other) {
            return complex(other.m_re / this->m_re, other.m_im - this->m_im);
        }

        complex& operator = (const complex & other) {
            if (&other != this) {
                x = other.x;
                y = other.y;
                m_re = other.m_re;
                m_im = other.m_im;
            }

            return *this;
        }








        const complex GetPolarForm() {
            return complex(this->m_re, this->m_im);
        }

        const complex GetAlgebraicForm() {
            return complex(this->x, this->y);
        }

        complex operator ^ (const int degree) {
            return complex(int(this->m_re) ^ degree, this->m_im * degree);
        }

        complex turn(double m_deg) {
            return complex((x * cos(m_deg) - y * sin(m_deg)) + (y * cos(m_deg) + x * sin(m_deg)));
        }

        // modulo comparison
        const bool operator < (const complex& other) {
            return (this->m_re < other.m_re);
        }

        const bool operator > (const complex& other) {
            return (this->m_re > other.m_re);
        }

        const bool operator >= (const complex& other) {
            return (this->m_re >= other.m_re);
        }

        const bool operator <= (const complex& other) {
            return (this->m_re <= other.m_re);
        }


        //to_numeric_type<float>::type b = 3.14;

        void inPolarForm() {
            this->m_re = sqrt((int(x) ^ 2) + (int(y) ^ 2));       //            ///////////////////////////
            this->m_im = atan(y / x);
        }

        void inAlgebraicForm() {
            this->x = cos(m_re) * m_im;
            this->y = sin(m_re) * m_im;
        }



        ~complex() {}


    };

    /*
    class RenderIn3D{
    public:
        RenderIn3D() {
            
        }


    private:
        struct Point3D { double X; double y; double z; };
        struct Point2D { double x; double y; };
        double rotation = 0.0_deg;  //
        double FOV = 10.0;
        double DeltaTime;



    
    };

    */






    //inline complex <double> operator"" _j(long double y) {
    //    return complex <long double> (0, y);
    //}


//}


    /*
    template <class T> struct Vec2 {
        union {
            struct { t u, v; };
            struct { t x, y; };
            t raw[2];
        };
        Vec2() : u(0), v(0) {}
        Vec2(t _u, t _v) : u(_u), v(_v) {}
        inline Vec2<t> operator +(const Vec2<t>& V) const { return Vec2<t>(u + V.u, v + V.v); }
        inline Vec2<t> operator -(const Vec2<t>& V) const { return Vec2<t>(u - V.u, v - V.v); }
        inline Vec2<t> operator *(float f)          const { return Vec2<t>(u * f, v * f); }
        template <class > friend std::ostream& operator<<(std::ostream& s, Vec2<t>& v);

		////////////////////////////////   - œ≈–≈ƒ≈À¿“¸                           //////////////////////////////////////////////////////////////////////////////////
        inline operator Vec2(graphics::coordinates coords) {
            double numb[2] = coords.Getcoordinates();
            return Vec2(numb[1], numb[2]);
        }

    };
    



    
    template <class t> struct Vec3 {
        union {
            struct { t x, y, z; };
            struct { t ivert, iuv, inorm; };
            t raw[3];
        };
        Vec3() : x(0), y(0), z(0) {}
        Vec3(t _x, t _y, t _z) : x(_x), y(_y), z(_z) {}
        inline Vec3<t> operator ^(const Vec3<t>& v) const { return Vec3<t>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
        inline Vec3<t> operator +(const Vec3<t>& v) const { return Vec3<t>(x + v.x, y + v.y, z + v.z); }
        inline Vec3<t> operator -(const Vec3<t>& v) const { return Vec3<t>(x - v.x, y - v.y, z - v.z); }
        inline Vec3<t> operator *(float f)          const { return Vec3<t>(x * f, y * f, z * f); }
        inline t       operator *(const Vec3<t>& v) const { return x * v.x + y * v.y + z * v.z; }
        float norm() const { return std::sqrt(x * x + y * y + z * z); }
        Vec3<t>& normalize(t l = 1) { *this = (*this) * (l / norm()); return *this; }
        template <class > friend std::ostream& operator<<(std::ostream& s, Vec3<t>& v);
    };



    typedef Vec2<float> Vec2f;
    typedef Vec2<int>   Vec2i;
    typedef Vec3 <float> Vec3f;
    typedef Vec3 <int>   Vec3i;
    
    template <class t> std::ostream& operator<<(std::ostream& s, Vec2<t>& v) {
        s << "(" << v.x << ", " << v.y << ")\n";
        return s;
    }

    template <class t> std::ostream& operator<<(std::ostream& s, Vec3<t>& v) {
        s << "(" << v.x << ", " << v.y << ", " << v.z << ")\n";
        return s;
    }
    */


