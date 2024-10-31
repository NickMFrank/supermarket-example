#ifndef DISC_HPP
#define DISC_HPP

#include "Item.hpp"

#include <unordered_map>
#include <vector>

// Interface for all discounts to override
class IDiscount {

public:
    const std::string label; // Name of deal

    // Simple constructor
    IDiscount(std::string label) : label(label) {}

    // Default destructor
    virtual ~IDiscount() = default;

    // Checks equality of two discounts by name; necessary for unordered maps using an IDiscount as a key
    bool operator==(const IDiscount& other) const {
        return label == other.label;
    }

    // Returns pairs of items with their individual savings; varies between particular sales
    const virtual std::vector<std::pair<Item, int>> ApplyDiscount(std::vector<Item> items) = 0;

};

// Adapted from https://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key
// Enables using unordered maps with an IDiscount for the key
namespace std {
    template <>
    struct hash<IDiscount> {
        size_t operator()(const IDiscount& discount) const {
            return hash<string>()(discount.label);
        }
    };
}

#endif
