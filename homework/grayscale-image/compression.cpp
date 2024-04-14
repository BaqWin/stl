#include "compression.hpp"
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    std::for_each(arr.begin(), arr.end(), [&vec](auto &row){
        uint8_t tmpVal = row.at(0);
        int indexPair = 1;
        std::for_each(row.begin() + 1, row.end(), [&vec, &indexPair, &tmpVal](auto &val){
            if (val != tmpVal) {
                vec.push_back({tmpVal, indexPair});
                tmpVal = val;
                indexPair = 1;
            } else {
                ++indexPair;
            }
        });
        vec.push_back({tmpVal, indexPair});
    });
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, width>, height> arr;
    auto itArr = arr.begin();
    auto innerItArr = arr.begin()->begin();
    std::for_each(vec.begin(), vec.end(), [&itArr, &innerItArr](auto &val){
        if(innerItArr == itArr->end()){
            ++itArr;
            innerItArr = itArr->begin();
        }
        std::fill_n(innerItArr, val.second, val.first);
        innerItArr = innerItArr + val.second;
    });
    return arr;
}

void printMap(const std::array<std::array<uint8_t, 32>, 32>& arr) {
    std::for_each(arr.begin(), arr.end(), [](const auto &row){
        std::for_each(row.begin(), row.end(), [](const auto &v){
            if (unsigned(v) == 0) {
                std::cout << " ";
            } else if (unsigned(v) > 0 && unsigned(v) < 33) {
                std::cout << " ";
            } else {
                std::cout << v;
            }
        });
        std::cout << std::endl;
    });
}