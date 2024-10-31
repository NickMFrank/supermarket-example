#include "BuySetGetCheap.hpp"

BuySetGetCheap::BuySetGetCheap(const std::string label) : IDiscount(label) {}

const std::vector<std::pair<Item, int>> BuySetGetCheap::ApplyDiscount(std::vector<Item> items) {

    std::vector<std::pair<Item, int>> savings;
    std::sort(items.begin(), items.end(), [](Item &a, Item &b) {
        return a.GetCost() > b.GetCost();
    });

    // Goes through items sorted by cost to discount the third most expensive repeatedly
    int counter = 0;
    for (Item item : items) {
        int deal = 0;
        counter += item.GetQuantity();
        deal = (counter / 3) * item.GetCost();
        savings.push_back(std::pair(item, deal));
        counter = counter % 3; // Need to reset counter and account for overflow with quantities > 1
    }

    return savings;
}
