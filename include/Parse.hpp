#ifndef PARSE_HPP
#define PARSE_HPP

#include "Item.hpp"
#include "IDiscount.hpp"
#include "BuyTwoGetSame.hpp"
#include "BuySetGetCheap.hpp"
#include "List.hpp"

#include <fstream>

// Utility to read CSV files in format of name,quantity,cost,deal to shopping List
class Parse {

private:
    // Stored each deal so all tagged products get handled together
    std::optional<IDiscount*> none; // Empty optional represents no sale
    std::optional<IDiscount*> btgs; // Buy Two Get Same
    std::optional<IDiscount*> bsgc; // Buy Set get Cheap

    // Ensures name has 1-20 characters
    std::string ValidateName(std::string input);

    // Ensures quantity is positive, valid int
    int ValidateQuantity(std::string input);

    // Ensures cost is positive, valid int
    int ValidateCost(std::string input);

    // Maps string representation of deal to potential deals
    std::optional<IDiscount*> ValidateDeal(std::string input);

public:
    // Simple constructor that intializes deals
    Parse();

    // Default destructor
    ~Parse();

    // Reads provided csv file into List structure
    List ProcessFile(std::string fileName);

};

#endif
