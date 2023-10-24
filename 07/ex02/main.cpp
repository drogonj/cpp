
#include "Array.hpp"

int main(void)
{
    // Testing char array
    {
        std::cout << BLUE << "Testing char array: " << RESET << std::endl;
        Array<char>   arr(2);
        arr[0] = 'h';
        arr[1] = 'i';
        std::cout << GREEN << arr[0] << arr[1] << RESET << std::endl;
    }

    // Testing std::string array
    {
        std::cout << BLUE << "Testing std::string array: " << RESET << std::endl;
        Array<std::string>  arr(3);
        arr[0] = "Bonjour";
        arr[1] = " a ";
        arr[2] = "tous";
        std::cout << GREEN << arr[0] << arr[1] << arr[2] << RESET << std::endl;
    }

    // Testing int array
    {
        std::cout << BLUE << "Testing int array: " << RESET << std::endl;
        Array<int>  arr(10);
        for (int i = 0; i < 10; i++)
            arr[i] = i;
        for (int i = 0; i < 10; i++)
            std::cout << GREEN << arr[i] << ' ' << RESET;
        std::cout << std::endl;

        std::cout << GREEN << "Size: " << arr.size() << RESET << std::endl;

        // Testing exception
        std::cout << BLUE << "Testing exception: " << RESET << std::endl;
        try {
            std::cout << arr[13] << std::endl;
        } catch (std::exception &e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }
    }
}
