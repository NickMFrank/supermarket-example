#ifndef LIST_HPP
#define LIST_HPP

#include "Item.hpp"
#include "IDiscount.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <optional>

// Holds collection of items to be tabulated; stores items in a pair with their respective sale
class List {
private:
    std::vector<std::pair<Item, std::optional<IDiscount*>>> items; // Pairs items with sale (empty optional means no sale)

    // Helper that prints individual product information; only includes sale message when savings > 0
    void PrintEntry(Item item, int savings, std::string label);

    // Helper for adding decimal to cents costs
    std::string FormatDollar(int cents);

public:
    // Default constructor
    List();

    // Default destructor
    ~List();

    // Add pair of item with its sale (empty optional means no sale)
    void AddItem(std::pair<Item, std::optional<IDiscount*>>);

    // Prints full tabulation to stdout, applying discounts in the process
    // Returns int total for testing
    int PrintReceipt();

};

#endif
