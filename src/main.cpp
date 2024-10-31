#include <iostream>
#include "Item.hpp"
#include "IDiscount.hpp"
#include "BuyTwoGetSame.hpp"
#include "BuySetGetCheap.hpp"
#include "List.hpp"
#include "Parse.hpp"
#include "Test.hpp"

#include <string>
#include <vector>

// Program entrypoint
int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::string fileName = argv[1];
        if (fileName == "test") {
            Test testing;
            testing.RunTests(); // Simple unit testing mode, could use expansion
        }
        Parse parser = Parse();
        List cart = parser.ProcessFile(fileName); // Load CSV to List for processing
        cart.PrintReceipt();

    } else {
        std::cout << "No csv filepath found! Usage: ./prog <filepath>" << std::endl;
    }
    return 0;
}
