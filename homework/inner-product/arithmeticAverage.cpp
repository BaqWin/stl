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
    double result;
    std::multimap<int, int> map;
    for (auto i = first.begin(), j = second.begin(); i < first.end() && j < second.end(); ++i, ++j) {
        map.insert({*i, *j});
    }
    std::for_each(map.begin(), map.end(), [&result](auto& pair) {
        result += std::pow((pair.first - pair.second), 2);
    });
    return std::sqrt(result);
}
