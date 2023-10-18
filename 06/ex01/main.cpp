
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    std::cout << std::endl;

    {
        Serializer      s;
        Data            d("lorem ipsum dolor sit amet");

        std::cout << "d.str: " << d.str<< std::endl;
        std::cout << "&d: " << &d << std::endl;

        std::cout << std::endl;

        std::cout << "-- Serializing Data --" << std::endl;
        uintptr_t       r = s.serialize(&d);
        std::cout << "&d: " << &d << std::endl;

        std::cout << std::endl;

        std::cout << "-- Deserializing Data --" << std::endl;
        Data            *d2 = s.deserialize(r);
        std::cout << "d2.str: " << d2->str << std::endl;
        std::cout << "&2d: " << &d2 << std::endl;
    }


    std::cout << std::endl;
}