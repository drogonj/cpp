
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
    for (int i = left; i < right - left + 1; i++) {
        if (firstI == secondSize) {
            vec[i] = firstTab[secondI];
            secondI++;
        } else if (secondI == firstSize) {
            vec[i] = secondTab[firstI];
            firstI++;
        } else if (secondTab[firstI] > firstTab[secondI]) {
            vec[i] = firstTab[secondI];
            secondI++;
        } else {
            vec[i] = secondTab[firstI];
            firstI++;
        }
    }
}


void PmergeMe::vecSort(std::vector<int> & vec, int left, int right) {
    int packages = vec.size() / 2;
    if (right - left > packages) {
        int middle = (left + right) / 2;
        this->vecSort(vec, left, middle);
        this->vecSort(vec, middle + 1, right);
        this->vecMerge(vec, left, middle, right);
    } else {
        this->vecInsertion(vec, left, right);
    }
}

////// LIST SORT //////

void PmergeMe::lstInsertion(std::list<int> &lst, std::list<int>::iterator left, std::list<int>::iterator right) {
    ++right;
    for (std::list<int>::iterator it = left; it != right; ++it) {
        std::list<int>::iterator nextIt = it;
        ++nextIt;
        int tmp = *nextIt;
        std::list<int>::iterator j = nextIt;
        std::list<int>::iterator previousJ = it;
        while (j != lst.begin() && *previousJ > tmp) {
            *j = *previousJ;
            --previousJ;
            --j;
        }
        *j = tmp;
    }
}

void PmergeMe::lstMerge(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right) {
    std::list<int> firstTab(left, middle);
    std::list<int> secondTab(middle, right);

    std::list<int>::iterator firstI = firstTab.begin();
    std::list<int>::iterator secondI = secondTab.begin();

    for (std::list<int>::iterator i = left; i != right; ++i) {
        if (firstI == firstTab.end()) {
            *i = *secondI;
            ++secondI;
        } else if (secondI == secondTab.end()) {
            *i = *firstI;
            ++firstI;
        } else if (*secondI > *firstI) {
            *i = *firstI;
            ++firstI;
        } else {
            *i = *secondI;
            ++secondI;
        }
    }
}

void PmergeMe::lstSort(std::list<int> & lst, std::list<int>::iterator left, std::list<int>::iterator right) {
    int packages = lst.size() / 2;

    if (std::distance(left, right) > packages) {
        std::list<int>::iterator middle = left;
        std::advance(middle, std::distance(left, right) / 2);
        this->lstSort(lst, left, middle);
        std::list<int>::iterator nextMiddle = middle;
        this->lstSort(lst, ++nextMiddle, right);
        this->lstMerge(left, middle, right);
    } else {
        this->lstInsertion(lst, left, right);
    }
}

void PmergeMe::sort(std::vector<int> & vec) {
    this->vecSort(vec, 0, vec.size() - 1);
}
void PmergeMe::sort(std::list<int> & lst) {
    this->lstSort(lst, lst.begin(), lst.end());
}

PmergeMe & PmergeMe::operator=(const PmergeMe & src) {
    (void)src;
    return (*this);
}
