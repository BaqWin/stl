#include "arithmeticAverage.hpp"

double ArithmeticAverage(std::vector<int>& first, std::vector<int>& second) {
    double result;
    std::for_each(first.begin(), first.end(), [&result](auto& val) {
        result += val;
    });
    std::for_each(second.begin(), second.end(), [&result](auto& val) {
        result += val;
    });
    return result / (first.size() + second.size());
}

double Distance(std::vector<int>& first, std::vector<int>& second) {
    double result = 0.0;
    for (size_t i = 0; i < first.size(); ++i) {
        result += std::pow(static_cast<double>(first[i] - second[i]), 2);
    }
    return std::sqrt(result);
}
