
#include "ScalarConverter.hpp"

//class Parent { public: virtual ~Parent(void) {} };
//class Child1 : public Parent {};
//class Child2 : public Parent {};

//int main()
//{
//    Child1 a;
//    Parent *b = &a;
//
//    Child1 *c = dynamic_cast<Child1 *>(b);
//    if (c == NULL)
//        std::cout << "FAIL" << std::endl;
//    else
//        std::cout << "SUCCESS" << std::endl;
//
//    try {
//        Child2 & d = dynamic_cast<Child2 &>(*b);
//        (void)d;
//        std::cout << "SUCCESS" << std::endl;
//    } catch (std::bad_cast &e) {
//        std::cout << "FAIL" << std::endl;
//        std::cout << e.what() << std::endl;
//    }
//}

//int main()
//{
//    float a = 420.042f;
//
//    void *b = &a;
//    int *c = reinterpret_cast<int *>(b);
//    int &d = reinterpret_cast<int &>(b);
//
//    std::cout << *c << std::endl;
//    std::cout << d << std::endl;
//}

//int main()
//{
//    int a = 42;
//
//    int const * b = &a;
//    //int * c = b;  ne compile pas car b est const
//    int * d = const_cast<int *>(b);
//
//    (void)a, (void)b, (void)c, (void)d;
//}

//class Foo
//{
//private:
//    float _v;
//
//public:
//    Foo (float const v) : _v(v) {}
//
//    float getV(void) const { return this->_v; }
//
//    operator float() { return this->_v; }
//    operator int() { return static_cast<int>(this->_v); }
//};
//
//int main()
//{
//    Foo a(420.042f);
//    float b = a;
//    int c = a;
//
//    std::cout << a.getV() << std::endl;
//    std::cout << b << std::endl;
//    std::cout << c << std::endl;
//}
