#pragma once
#include <math.h>
#include <algorithm>
//#include <type_traits>

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


    //inline complex <double> operator"" _j(long double y) {
    //    return complex <long double> (0, y);
    //}


//}

