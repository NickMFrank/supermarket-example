#include "BuyTwoGetSame.hpp"

BuyTwoGetSame::BuyTwoGetSame(const std::string label) : IDiscount(label) {}

const std::vector<std::pair<Item, int>> BuyTwoGetSame::ApplyDiscount(std::vector<Item> items) {

    std::vector<std::pair<Item, int>> savings;
    for (Item item : items) {
        savings.push_back(std::pair(item, (item.GetQuantity() / 3) * item.GetCost())); // Every third item free
    }

    return savings;
}
