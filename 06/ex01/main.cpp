
#include "Serializer.hpp"
#include "Data.hpp"

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

int main(void)
{
    std::cout << std::endl;

    {
        // Serializer && Data creation
        Serializer      s;
        Data            d("lorem ipsum dolor sit amet");

        // Display Data
        std::cout << "-- Showing Data --" << std::endl;
        std::cout << GREEN << "d.str: " << BLUE << d.str << RESET << std::endl;
        std::cout << GREEN << "&d: " << BLUE << &d << RESET << std::endl;

        std::cout << std::endl;

        // Serializing data
        std::cout << "-- Serializing Data --" << std::endl;
        uintptr_t       r = s.serialize(&d);
        std::cout << GREEN << "&d: " << BLUE << &d << RESET << std::endl;

        std::cout << std::endl;

        // Deserializing data
        std::cout << "-- Deserializing Data --" << std::endl;
        Data            *d2 = s.deserialize(r);
        std::cout << GREEN << "d2.str: " << BLUE << d2->str << RESET << std::endl;
        std::cout << GREEN << "&2d: " << BLUE << &d2 << RESET << std::endl;
    }


    std::cout << std::endl;
}