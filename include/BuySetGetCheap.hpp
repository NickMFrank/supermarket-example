#ifndef BSGC_HPP
#define BSGC_HPP

#include "Item.hpp"
#include "IDiscount.hpp"

#include <unordered_map>
#include <vector>
#include <algorithm>

// Sale where buying two tagged products gives a third for free
class BuySetGetCheap : public IDiscount {

public:
    // Simple constructor
    BuySetGetCheap(const std::string label);

    // Returns pairs of items with their individual savings
    const std::vector<std::pair<Item, int>> ApplyDiscount(std::vector<Item> items);
};

#endif
