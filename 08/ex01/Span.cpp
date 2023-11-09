
#include "Span.hpp"

Span::Span(void) : _N(5) { }
Span::Span(const unsigned int n) : _N(n) { }
Span::Span(const Span &src) : _N(src._N), _V(src._V){ }
Span::~Span(void) { }

int Span::getN(void) const {
    return (this->_N);
}

const std::vector<int> & Span::getV(void){
    return (this->_V);
}

void Span::displayV(void) {
    std::cout << '[';
    for (std::vector<int>::iterator it = this->_V.begin(); it != this->_V.end(); it++) {
        std::cout << *it;
        it == this->_V.end() - 1 ? std::cout << ']' << std::endl : std::cout << ", ";
    }
}

void Span::addNumber(const int n) {
    if (this->_V.size() >= this->_N)
        throw maximumReached();
    this->_V.push_back(n);
}

void Span::addNumbers(const int *args, int length) {
    for (int i = 0; i < length; i++) {
        if (this->_V.size() >= this->_N)
            throw maximumReached();
        this->_V.push_back(args[i]);
    }
}

int Span::shortestSpan(void) {
    if (this->_V.size() <= 1)
        throw tooFewElements();
    std::vector<int> cpy(this->_V);
    std::sort(cpy.begin(), cpy.end());
    std::vector<int>::iterator it = cpy.begin();
    int shortest = *(it + 1) - *it;
    for ( ; std::distance(it, cpy.end()) > 1; ++it) {
            *(it + 1) - *it < shortest ? shortest = *(it + 1) - *it : 0 ;
    }
    return (shortest);
}

int Span::longestSpan(void) {
    if (this->_V.size() <= 1)
        throw tooFewElements();
    std::vector<int>::iterator max = std::max_element(this->_V.begin(), this->_V.end());
    std::vector<int>::iterator min = std::min_element(this->_V.begin(), this->_V.end());
    return (*max - *min);
}

Span & Span::operator=(const Span &src){
    if (&src != this) {
        this->_N = src._N;
        this->_V = src._V;
    }
    return (*this);
}
