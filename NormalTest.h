//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Final Project
//Professor: Mohammad Patory

#ifndef NORMAL_TEST_H
#define NORMAL_TEST_H

#include "Test.h"
#include <random>
#include <numeric>

template<typename T>
class NormalTest : public Test<T> {
public:
    explicit NormalTest(int samples) : Test<T>(samples) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<T> distribution(0.0, 10.0); // mean = 0, std deviation = 10
        for (int i = 0; i < this->samples; ++i) {
            this->numbers.push_back(distribution(gen));
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
        // Assuming the buckets should also range from min to max of generated numbers
        T minVal = getMin();
        T maxVal = getMax();
        T bucketRange = (maxVal - minVal) / 20.0; // divide the range into 20 buckets

        if (bucketRange == 0) bucketRange = 1; // Avoid division by zero

        for (T num : this->numbers) {
            int bucket = static_cast<int>((num - minVal) / bucketRange);
            histogram[bucket]++;
        }
        return histogram;
    }
};

#endif // NORMAL_TEST_H
