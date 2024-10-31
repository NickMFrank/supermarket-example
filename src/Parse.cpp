#include "Parse.hpp"

Parse::Parse() {
    this->btgs = std::make_optional<IDiscount*>(new BuyTwoGetSame("BuyTwoGetOne"));
    this->bsgc = std::make_optional<IDiscount*>(new BuySetGetCheap("BuySetGetCheapest"));
}

Parse::~Parse() = default;

List Parse::ProcessFile(std::string fileName) {
    List cart;
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Could not access file!" << std::endl;
        exit(0);
    }
    std::cout << "Successfully loaded " << fileName <<  std::endl << std::endl;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            continue; // Skip comments and empty lines
        }
        std::stringstream ss(line);
        std::string nameStr, quantityStr, costStr, dealStr;
        // Get values separated by commas
        if (std::getline(ss, nameStr, ',') && std::getline(ss, quantityStr, ',') && std::getline(ss, costStr, ',') && std::getline(ss, dealStr, ',')) {
            try {
                cart.AddItem(std::pair(Item(ValidateName(nameStr), ValidateQuantity(quantityStr), ValidateCost(costStr)), ValidateDeal(dealStr)));
            } catch(const std::exception& e) { // Cleanly exit from invalid arguments
                std::cerr << "Error processing line: " << line << std::endl << e.what() << std::endl;
                file.close();
                exit(0);
            }
        }
    }
    file.close();
    return cart;
}

std::string Parse::ValidateName(std::string input) {
    if (input.empty()) {
        throw std::invalid_argument("Invalid name, not present!");
    }
    if (input.length() > 20) {
        throw std::invalid_argument("Invalid name, too long!");
    }
    return input;
}

int Parse::ValidateQuantity(std::string input) {
    try {
        int quantity = std::stoi(input);
        if (quantity < 0) {
            throw std::invalid_argument("Invalid quantity, negative value!");
        }
        return quantity;
    }
    catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Invalid quantity, not a positive integer!");
    } 
    catch (const std::out_of_range& e) {
        throw std::invalid_argument("Invalid quantity, too large!");
    }
}

int Parse::ValidateCost(std::string input) {
    try {
        int cost = std::stoi(input);
        if (cost < 0) {
            throw std::invalid_argument("Invalid cost, negative value!");
        }
        return cost;
    }
    catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Invalid cost, not a positive integer!");
    } 
    catch (const std::out_of_range& e) {
        throw std::invalid_argument("Invalid cost, too large!");
    }
}

std::optional<IDiscount*> Parse::ValidateDeal(std::string input) {
    if (input == "btgs") {
        return btgs;
    } else if (input == "bsgc") {
        return bsgc;
    } else {
        return none;
    }
}