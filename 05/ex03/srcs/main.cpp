
#include "../includes/Intern.hpp"

int main(void)
{
    Intern  formMaker;
    AForm   *f;

    std::cout << std::endl;

    // Try to create invalid Form
    try{
        formMaker.makeForm("change Earth to BluePlanet", "Earth");
    } catch (std::exception & e) {
        std::cout << YELLOW << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;

    // Try to create valid Form
    f = formMaker.makeForm("presidential pardon", "gabe");
    std::cout << *f << std::endl;
    std::cout << "Form's target is " << f->getTarget() << std::endl;

    std::cout << std::endl;
    delete (f);
}
