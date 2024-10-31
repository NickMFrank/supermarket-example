#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

// Holds most simple information of an item: name, cost (in cents), and quantity
class Item {

private:
    // Base fields
    std::string name;
    int quantity;
    int cost; // in cents

public:
    // Simple constructor for basic properties
    Item(std::string name, int quantity, int cost);

    //Default destructor
    ~Item();

    // Simple getters for accessing private fields
    const std::string GetName();
    const int GetQuantity();
    const int GetCost();

};

#endif
