#ifndef BTGS_HPP
#define BTGS_HPP

#include "Item.hpp"
#include "IDiscount.hpp"

#include <unordered_map>
#include <vector>

// Sale where buying two identical products gives a third for free
class BuyTwoGetSame : public IDiscount {

public:
    // Simple constructor
    BuyTwoGetSame(const std::string label);

    // Returns pairs of items with their individual savings
    const std::vector<std::pair<Item, int>> ApplyDiscount(std::vector<Item> items);

};

#endif
