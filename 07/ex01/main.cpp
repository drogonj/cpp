
#include "iter.hpp"

template<typename T>
void inc(T & obj)
{
    obj++;
}

int main(void)
{
    char str[] = "bonjour";
    int  nTab[] = {0, 1, 2, 3, 4, 5, 6};

    iter<char>(str, 7, &inc);
    std::cout << str << std::endl;

    iter<int>(nTab, 7, &inc);
    for (int i = 0; i < 7; i++)
        std::cout << nTab[i];
    std::cout << std::endl;
}
