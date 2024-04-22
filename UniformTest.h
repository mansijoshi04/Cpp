//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Final Project
//Professor: Mohammad Patory

#ifndef UNIFORM_TEST_H
#define UNIFORM_TEST_H

#include "Test.h"
#include <random>
#include <numeric>

template<typename T>
class UniformTest : public Test<T> {
public:
    explicit UniformTest(int samples) : Test<T>(samples) {
        std::default_random_engine generator;
        std::uniform_real_distribution<T> distribution(0, 100);
        for (int i = 0; i < this->samples; ++i) {
            this->numbers.push_back(distribution(generator));
        }
    }

    T getMin() const override {
        return *min_element(this->numbers.begin(), this->numbers.end());
    }

    T getMax() const override {
        return *max_element(this->numbers.begin(), this->numbers.end());
    }

    T getMean() const override {
        T sum = std::accumulate(this->numbers.begin(), this->numbers.end(), T(0));
        return sum / this->samples;
    }

    T getMedian() override {
        std::sort(this->numbers.begin(), this->numbers.end());
        if (this->samples % 2 == 0)
            return (this->numbers[this->samples / 2 - 1] + this->numbers[this->samples / 2]) / 2;
        else
            return this->numbers[this->samples / 2];
    }

    std::map<int, int> getHistogram() const override {
        std::map<int, int> histogram;
        for (T num : this->numbers) {
            int bucket = static_cast<int>(num / 5);
            histogram[bucket]++;
        }
        return histogram;
    }
};

#endif // UNIFORM_TEST_H

