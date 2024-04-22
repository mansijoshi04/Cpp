//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Final Project
//Professor: Mohammad Patory

#ifndef TEST_H
#define TEST_H

#include <vector>
#include <algorithm>
#include <map>

template<typename T> 
class Test {
public:
    explicit Test(int samples) : samples(samples) {}
    virtual ~Test() = default;

    virtual T getMin() const = 0;
    virtual T getMax() const = 0;
    virtual T getMean() const = 0;
    virtual T getMedian() = 0;
    virtual std::map<int, int> getHistogram() const = 0;
protected:
    std::vector<T> numbers;
    int samples;
};

#endif // TEST_H
