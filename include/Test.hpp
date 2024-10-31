#ifndef TEST_HPP
#define TEST_HPP

#include "Item.hpp"
#include "IDiscount.hpp"
#include "BuyTwoGetSame.hpp"
#include "BuySetGetCheap.hpp"
#include "List.hpp"

// Testing used to measure some expected functionality
class Test {

    private:
        // Checks equivalence of two values and prints result
        bool CheckTest(int id, int expected, int actual);

    public:
        // Default constructor
        Test();

        // Default destructor
        ~Test();

        // Executes all tests
        void RunTests();
};

#endif
