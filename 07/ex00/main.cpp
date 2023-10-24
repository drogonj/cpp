
#include "incs.hpp"

int main(void)
{
    int a = 42;
    int b = 21;
    std::cout << BLUE << "Base: " << std::endl << GREEN << "a = " << a << "; b = " << b << RESET << std::endl;

    swap<int>(a, b);
    std::cout << BLUE << "Swap: " << std::endl << GREEN << "a = " << a << "; b = " << b << RESET << std::endl;

    std::cout << BLUE << "Min: " << std::endl << GREEN << min<int>(a, b) << RESET << std::endl;

    std::cout << BLUE << "Max: " << std::endl << GREEN << max<int>(a, b) << RESET << std::endl;
}

//int main( void ) {
//    int a = 2;
//    int b = 3;
//    ::swap( a, b );
//    std::cout << "a = " << a << ", b = " << b << std::endl;
//    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//    std::string c = "chaine1";
//    std::string d = "chaine2";
//    ::swap(c, d);
//    std::cout << "c = " << c << ", d = " << d << std::endl;
//    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
//    return 0;
//}