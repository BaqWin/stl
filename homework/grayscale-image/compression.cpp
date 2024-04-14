#include "compression.hpp"
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    std::for_each(arr.begin(), arr.end(), [&vec](const auto& row) {
        auto start = row.begin();
        while (start != row.end()) {
            auto next = std::adjacent_find(start, row.end(), std::not_equal_to<>());
            if (next != row.end()) {
                ++next;
            }
            int count = std::distance(start, next);
            vec.push_back({*start, count});
            start = next;
        }
    });
    return vec;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, width>, height> arr;
    int indexH = 0;
    int indexW = 0;
    int vecIndex = 0;
    int valCount = vec.at(vecIndex).second;
    while (indexH < height) {
        if (valCount == 0) {
            ++vecIndex;
            valCount = vec.at(vecIndex).second;
        } else {
            arr[indexH][indexW] = vec.at(vecIndex).first;
            --valCount;
            ++indexW;
            if (indexW == width) {
                indexW = 0;
                ++indexH;
            }
        }
    }
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