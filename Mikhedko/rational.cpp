#include <iostream>
 
struct RatioNum
{
    int a;
    int b;
    RatioNum() {};
    RatioNum(int a, int b)
    {
        if (b != 0)
        {
            if ((a < 0) && (b < 0))
            {
                a = -1 * a;
                b = -1 * b;
            }
            else if ((a > 0) && (b < 0))
            {
                a = -1 * a;
                b = -1 * b;
            }
            int a1 = a; //НОД (для того, чтобы дробь была правильная)
            int b1 = b;
            if (a1 < 0)
            {
                a1 = -1 * a;
            }
 
            if (b1 < 0)
            {
                b1 = -1 * b;
            }
 
            while (a1 != b1)
            {
                if (a1 > b1)
                {
                    a1 -= b1;
                }
                else
                {
                    b1 -= a1;
                }
            }
 
            this->a = (int)a / a1;
            this->b = (int)b / a1;
 
 
 
        }
        else
        {
            while (b == 0)
            {
                std::cin >> b;
 
            }
 
            this->a = a;
            this->b = b;
 
        }
    }
 
 
};
 
 
RatioNum operator+(RatioNum num1, RatioNum num2)
{
    int a, b;
    if (num1.b != num2.b)
    {
        a = num1.a + num1.b;
        b = num1.b;
 
        a = num1.a * num2.b + num2.a * num1.b;
        b = num1.b * num2.b;
    }
    else
    {
        a = num1.a + num1.b;
        b = num1.b;
    }
 
    return RatioNum(a, b);
}
 
 
RatioNum operator += (RatioNum num1, RatioNum num2)
{
    int a, b;
    if (num1.b != num2.b)
    {
        a = num1.a * num2.b + num2.a * num1.b;
        b = num1.b * num2.b;
    }
    else
    {
        a = num1.a + num1.b;
        b = num1.b;
    }
 
    return RatioNum(a, b);
}
 
RatioNum operator-(RatioNum num1, RatioNum num2)
{
    int a, b;
    if (num1.b != num2.b)
    {
        a = num1.a * num2.b - num2.a * num1.b;
        b = num1.b * num2.b;
    }
    else
    {
        a = num1.a - num1.b;
        b = num1.b;
    }
 
    return RatioNum(a, b);
}
 
RatioNum operator-=(RatioNum num1, RatioNum num2)
{
    int a, b;
    if (num1.b != num2.b)
    {
        a = num1.a * num2.b - num2.a * num1.b;
        b = num1.b * num2.b;
    }
    else
    {
        a = num1.a - num1.b;
        b = num1.b;
    }
 
    return RatioNum(a, b);
}
 
bool operator>(RatioNum num1, RatioNum num2)
{
    if (num1.b = num2.b)
    {
        return num1.a > num2.a;
    }
    else
    {
        int a1, a2;
        a1 = num1.a * num2.b;
        a2 = num2.a * num1.b;
 
        return  a1 > a2;
    }
}
 
 
bool operator<(RatioNum num1, RatioNum num2)
{
    if (num1.b = num2.b)
    {
        return num1.a < num2.a;
    }
    else
    {
        int a1, a2;
        a1 = num1.a * num2.b;
        a2 = num2.a * num1.b;
 
        return  a1 < a2;
    }
}
 
bool operator>=(RatioNum num1, RatioNum num2)
{
    if (num1.b = num2.b)
    {
        return num1.a >= num2.a;
    }
    else
    {
        int a1, a2;
        a1 = num1.a * num2.b;
        a2 = num2.a * num1.b;
 
        return  a1 >= a2;
    }
}
 
bool operator<=(RatioNum num1, RatioNum num2)
{
    if (num1.b = num2.b)
    {
        return num1.a <= num2.a;
    }
    else
    {
        int a1, a2;
        a1 = num1.a * num2.b;
        a2 = num2.a * num1.b;
 
        return  a1 <= a2;
    }
}
 
RatioNum operator*(RatioNum num1, RatioNum num2)
{
    int a, b;
    a = num1.a * num2.a;
    b = num1.b * num2.b;
    return RatioNum(a, b);
}
 
RatioNum operator*(RatioNum num1, int c)
{
    int a, b;
    a = num1.a * c;
    b = num1.b;
    return RatioNum(a, b);
}
inline std::ostream& operator << (std::ostream& os, RatioNum& num)
{
    os << "(" << num.a << "," << num.b << ")" << std::endl;
    return os;
}
 
inline std::istream& operator >> (std::istream& is, RatioNum& num)
{
    is >> num.a >> num.b;
 
    if (num.b != 0)
    {
        if ((num.a < 0) && (num.b < 0))
        {
            num.a = -1 * num.a;
            num.b = -1 * num.b;
        }
        else if ((num.a > 0) && (num.b < 0))
        {
            num.a = -1 * num.a;
            num.b = -1 * num.b;
        }
        int a1 = num.a; //НОД (для того, чтобы дробь была правильная)
        int b1 = num.b;
        if (a1 < 0)
        {
            a1 = -1 * num.a;
        }
 
        if (b1 < 0)
        {
            b1 = -1 * num.b;
        }
 
        while (a1 != b1)
        {
            if (a1 > b1)
            {
                a1 -= b1;
            }
            else
            {
                b1 -= a1;
            }
        }
 
        num.a = num.a / a1;
        num.b = (int)num.b / a1;
 
 
 
    }
    else
    {
        while (num.b == 0)
        {
            std::cin >> num.b;
 
        }
 
    }
 
 
    return is;
}
 
 
 
 
 
 
int main()
{
    RatioNum b;
 
    std::cin >> b;
 
    std::cout << b;
 
    RatioNum c;
 
    std::cin >> c;
 
    std::cout << c;
 
    RatioNum t =  c + b;
 
    std::cout << t;
 
    return 0;
}
