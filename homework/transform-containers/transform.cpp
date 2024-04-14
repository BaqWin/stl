#include "transform.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& ls,
                                                           std::deque<int>& de) {
    ls.sort();
    auto it = std::unique(ls.begin(), ls.end());
    ls.erase(it, ls.end());

    std::sort(de.begin(), de.end());
    auto itd = std::unique(de.begin(), de.end());
    de.erase(itd, de.end());

    std::map<int, std::string> result;
    std::transform(de.begin(), de.end(), ls.begin(),
                   std::inserter(result, result.end()),
                   [](const int& key, const auto& value) {
                       return std::make_pair(key, value);
                   });
    return result;
}
