
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) { }
PmergeMe::PmergeMe(const PmergeMe & src) { (void)src; }
PmergeMe::~PmergeMe(void) { }

///// VECTOR SORT /////

void PmergeMe::vecInsertion(std::vector<int> & vec, int left, int right) {
    for (int i = left; i < right; i++) {
        int tmp = vec[i + 1];
        int j = i + 1;
        while (j > left && vec[j - 1] > tmp) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = tmp;
    }
}

void PmergeMe::vecMerge(std::vector<int> & vec, int left, int middle, int right) {
    int firstSize = middle - left + 1;
    int secondSize = right - middle;
    std::vector<int> firstTab(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<int> secondTab(vec.begin() + middle + 1, vec.begin() + right + 1);
    int firstI = 0;
    int secondI = 0;

    for (int i = left; i <= right; i++) {
        if (firstI < firstSize && (secondI >= secondSize || firstTab[firstI] <= secondTab[secondI])) {
            vec[i] = firstTab[firstI];
            firstI++;
        } else {
            vec[i] = secondTab[secondI];
            secondI++;
        }
    }
}

void PmergeMe::vecSort(std::vector<int> & vec, int left, int right) {
    int packages = 5;
    if (vec.size() > 10)
        packages = vec.size() / 2;
    if (right - left > packages ) {
        int middle = (left + right) / 2;
        this->vecSort(vec, left, middle);
        this->vecSort(vec, middle + 1, right);
        this->vecMerge(vec, left, middle, right);
    } else {
        this->vecInsertion(vec, left, right);
    }
}

////// LIST SORT //////

void PmergeMe::lstInsertion(std::list<int>::iterator left, std::list<int>::iterator right) {
    for (std::list<int>::iterator i = left; i != right; i++) {
        std::list<int>::iterator j = i; j++;
        int tmp = *j;
        std::list<int>::iterator prevj = j; prevj--;
        while (j != left && *prevj > tmp) {
            *j = *prevj;
            j--; prevj--;
        }
        *j = tmp;
    }
}

void PmergeMe::lstMerge(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right) {
    std::list<int>::iterator nmiddle = middle; nmiddle++;
    std::list<int> firstTab(left, nmiddle);
    std::list<int>::iterator nright = right; nright++;
    std::list<int> secondTab(nmiddle, nright);

    std::list<int>::iterator firstI = firstTab.begin();
    std::list<int>::iterator secondI = secondTab.begin();

    std::list<int>::iterator end = right; end++;
    for (std::list<int>::iterator i = left; i != end; ++i) {
        if (firstI != firstTab.end() && (secondI == secondTab.end() || *firstI <= *secondI)) {
            *i = *firstI;
            ++firstI;
        } else {
            *i = *secondI;
            ++secondI;
        }
    }
}

void PmergeMe::lstSort(std::list<int> & lst, std::list<int>::iterator left, std::list<int>::iterator right) {
    int packages = 5;
    if (lst.size() > 10)
        packages = lst.size() / 2;
    if (std::distance(left, right) > packages) {
        std::list<int>::iterator middle = left;
        std::advance(middle, std::distance(left, right) / 2);
        this->lstSort(lst, left, middle);
        std::list<int>::iterator nextMiddle = middle;
        this->lstSort(lst, ++nextMiddle, right);
        this->lstMerge(left, middle, right);
    } else {
        this->lstInsertion(left, right);
    }
}

void PmergeMe::sort(std::vector<int> & vec) {
    this->vecSort(vec, 0, vec.size() - 1);
}
void PmergeMe::sort(std::list<int> & lst) {
    std::list<int>::iterator end = lst.end();
    end--;
    this->lstSort(lst, lst.begin(), end);
}

PmergeMe & PmergeMe::operator=(const PmergeMe & src) {
    (void)src;
    return (*this);
}




