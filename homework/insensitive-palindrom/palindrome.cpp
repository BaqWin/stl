#include "palindrome.hpp"

bool is_palindrome(std::string str) {
    str.erase(std::remove_if(str.begin(), str.end(), [](const auto& ch) {
                  return !std::isalnum(ch);
              }),
              str.end());

    std::transform(str.begin(), str.end(), str.begin(), [](auto& ch) {
        return std::tolower(ch);
    });
    return std::equal(str.begin(), str.end(), str.rbegin(), str.rend());
}