
#include "MutantStack.hpp"
#include <iostream>
#include <vector>

// Fonctions dispo dans std::stack
// operator=
// top()
// size()
// empty()
// pop()
//push()

int main(void) {
    MutantStack<int>            s;
    MutantStack<int>::iterator  it;

    s.push(21);
    s.push(42);
    s.push(84);

    std::cout << s.top() << std::endl;

    return (0);
}