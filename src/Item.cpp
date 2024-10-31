#include "Item.hpp"

Item::Item(std::string name, int quantity, int cost) : name(name), quantity(quantity), cost(cost) {}

Item::~Item() = default;

const std::string Item::GetName() {
    return this->name;
}
const int Item::GetQuantity() {
    return this->quantity;
}
const int Item::GetCost() {
    return this->cost;
}
