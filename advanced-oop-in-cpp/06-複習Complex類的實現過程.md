## 複習 Complex 類的實現過程

```cpp
#ifndef __COMPLEX__
#define __COMPLEX__

class complex {
public:
    complex(double r = 0, double i = 0) : re(r), im(i) {}
    complex& operator+=(const complex&);
    double real() const { return re; }
    double imag() const { return im; }

private:
    double re, im;
    friend complex& __doapl(complex*, const complex&);
};

inline complex& __doapl(complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex& complex::operator+=(const complex& r)
{
    return __doapl(this, r);
}

inline complex operator+(const complex& x, const complex& y)
{
    return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex operator+(const complex& x, double y)
{
    return complex(real(x) + y, imag(x));
}

inline complex operator+(double x, const complex& y)
{
    return complex(x + real(y), imag(y));
}

#include <iostream>
ostream& operator<<(ostream& os, const complex& x)
{
    return os << '(' << real(x) << ',' << imag(x) << ')';
}

#endif
```
