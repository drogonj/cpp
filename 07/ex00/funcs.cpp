
#include "incs.hpp"

void    swap(T * a, T * b)
{
    T   tmp = *a;
    *a = *b;
    *b = tmp;
}

T       max(const T & a, const T & b) const
{
   return (a > b ? a : b);
}

T       min(const T & a, const T & b) const
{
    return (a > b ? b : a);
}
