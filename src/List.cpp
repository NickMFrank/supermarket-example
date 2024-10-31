#include "List.hpp"

List::List() {}

List::~List() = default;

void List::AddItem(std::pair<Item, std::optional<IDiscount*>> item) {
    items.push_back(item);
}

int List::PrintReceipt() {
    std::cout << std::left;
    int total = 0;
    std::unordered_map<IDiscount*, std::vector<Item>> discounts;

    // Go through each item
    for (std::pair<Item, std::optional<IDiscount*>> item : items) {
        if (item.second.has_value()) {
            discounts[item.second.value()].push_back(item.first); // If on sale, map items to their discount
        } else {
            total += (item.first.GetCost() * item.first.GetQuantity()); // Item has no sale and gets added
            PrintEntry(item.first, 0, "");
        }
    }

    // Apply each discount to all items with the same discount
    for (const std::pair<IDiscount*, std::vector<Item>>& mapPair : discounts) {
        IDiscount& deal = *mapPair.first;
        const std::vector<Item> onSaleItems = mapPair.second;
        std::vector<std::pair<Item, int>> savings = deal.ApplyDiscount(onSaleItems);
        // Iterate through savings per item and add
        for(std::pair<Item, int> salesPair : savings) {
            total += (salesPair.first.GetCost() * salesPair.first.GetQuantity() - salesPair.second);
            PrintEntry(salesPair.first, salesPair.second, deal.label);
        }
    }
    std::cout << std::endl << "Total: " << FormatDollar(total) << std::endl;
    return total;
}

void List::PrintEntry(Item item, int savings, std::string label) {
    std::cout << "Product: " << std::setw(25) << item.GetName() << "Quantity: " << std::setw(10) << item.GetQuantity() << "Cost: " << std::setw(15) << FormatDollar(item.GetCost() * item.GetQuantity() - savings);
    if (savings > 0) {
        std::cout << std::setw(25) << label + " deal!" << "Saved: " << FormatDollar(savings); // Only show savings > 0
    }
    std::cout << std::endl;
}

std::string List::FormatDollar(int cents) {
    return ("$" + std::to_string(cents / 100) + "." + (cents % 100 < 10 ? "0" : "") + std::to_string(cents % 100));
}