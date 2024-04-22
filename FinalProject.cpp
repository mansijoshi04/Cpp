//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Final Project
//Professor: Mohammad Patory

#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <sstream>
#include "UniformTest.h"
#include "NormalTest.h"

template<typename TestType>
void runTestAndDisplay(nana::form& fm, int samples) {
    TestType test(samples);

    std::stringstream results;
    results << "Min: " << test.getMin() << "\n";
    results << "Max: " << test.getMax() << "\n";
    results << "Mean: " << test.getMean() << "\n";
    results << "Median: " << test.getMedian() << "\n";

    auto histogram = test.getHistogram();
    results << "Histogram:\n";
    for (const auto& bucket : histogram) {
        results << "Bucket starting " << bucket.first * 5 << ": " << bucket.second << "\n";
    }

    // Update GUI with results
    nana::msgbox msg(fm, "Test Results");
    msg << results.str();
    msg.show();
}

int main() {
    using namespace nana;

    // Setup the form
    form fm(API::make_center(400, 200));
    fm.caption("Statistics Analysis");

    label lbl{ fm, rectangle{10, 10, 380, 25} };
    lbl.caption("Enter number of samples:");

    textbox samplesBox{ fm, rectangle{10, 40, 100, 25} };
    samplesBox.tip_string("Samples").multi_lines(false);

    button btnUniform{ fm, rectangle{10, 80, 180, 30} };
    btnUniform.caption("Run Uniform Distribution");

    button btnNormal{ fm, rectangle{210, 80, 180, 30} };
    btnNormal.caption("Run Normal Distribution");

    // Event handling
    btnUniform.events().click([&fm, &samplesBox] {
        int samples = std::stoi(samplesBox.text());
        runTestAndDisplay<UniformTest<double>>(fm, samples);
        });

    btnNormal.events().click([&fm, &samplesBox] {
        int samples = std::stoi(samplesBox.text());
        runTestAndDisplay<NormalTest<double>>(fm, samples);
        });

    fm.show();
    exec();
}
