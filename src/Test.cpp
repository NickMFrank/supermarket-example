#include "Test.hpp"

Test::Test() {}

Test::~Test() = default;

void Test::RunTests() {
    int passed = 0; // Counter for successes
    std::optional<IDiscount*> none;
    std::optional<IDiscount*> btgs = std::make_optional<IDiscount*>(new BuyTwoGetSame("BuyTwoGetOne"));
    std::optional<IDiscount*> bsgc = std::make_optional<IDiscount*>(new BuySetGetCheap("BuySetGetCheapest"));
    List cart;

    // Add 2 milk, discount for set doesn't apply yet
    cart.AddItem(std::pair(Item("Whole Milk", 2, 399), bsgc));
    passed += (CheckTest(1, 798, cart.PrintReceipt()) ? 1 : 0);

    // Add 8 yogurt, buy 2 get 1 should apply twice
    cart.AddItem(std::pair(Item("Yoplait", 8, 99), btgs));
    passed += (CheckTest(2, 1392, cart.PrintReceipt()) ? 1 : 0);

    // Add 1 bread, no discount so should sum
    cart.AddItem(std::pair(Item("Bread", 1, 400), none));
    passed += (CheckTest(3, 1792, cart.PrintReceipt()) ? 1 : 0);

    // Add 1 cheese, discount for set should discount previous milk
    cart.AddItem(std::pair(Item("Cheese", 1, 449), bsgc));
    passed += (CheckTest(4, 1842, cart.PrintReceipt()) ? 1 : 0);

    // Add 3 crackers, discount for set should make one free
    cart.AddItem(std::pair(Item("Crackers", 3, 229), bsgc));
    passed += (CheckTest(5, 2300, cart.PrintReceipt()) ? 1 : 0);

    // Add 18 brownies, buy 2 get 1 should apply 6 times
    cart.AddItem(std::pair(Item("Brownies", 18, 200), btgs));
    passed += (CheckTest(6, 4700, cart.PrintReceipt()) ? 1 : 0);

    // Add 2 beef, discount for set should cut cheese instead of milk
    cart.AddItem(std::pair(Item("Beef", 2, 600), bsgc));
    passed += (CheckTest(7, 5850, cart.PrintReceipt()) ? 1 : 0);

    // Add 13 bananas, no discount so should sum
    cart.AddItem(std::pair(Item("Bananas", 13, 100), none));
    passed += (CheckTest(8, 7150, cart.PrintReceipt()) ? 1 : 0);

    std::cout << std::endl << passed << "/8 tests passed!" << std::endl;
    exit(0);
}

bool Test::CheckTest(int id, int expected, int actual) {
    std::cout << "---Test " << id;
    if(expected == actual) {
        std::cout << " passed: Got value " << actual << "---" << std::endl;
        return true;
    } else {
        std::cout << " failed: Got value " << actual << " instead of " << expected << "---" << std::endl;
        return false;
    }
}