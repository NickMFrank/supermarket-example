# Supermarket Check Out: Nicholas Frank
### Overview
This project, built in C++, prints a receipt based on a series of products and discounts provided via a comma separated value (.csv) file.
### Usage
- Build with `g++ -std=c++23 ./src/*.cpp -I./include -o prog`
- Run with `./prog <filename>`, directing to a .csv file.
- `lists/SimpleGrocery.csv`, `lists/ComplexGrocery.csv`, and `lists/BadGrocery.csv` are provided as example files.
- Future .csv files should hold a line for each product formatted `<name>,<quantity>,<cost in cents>,<deal tag (see deal types)>`.
#### Deal types
- Currently, the only deals implemented are:
  - buy 3 identical items and pay for two (BuyTwoGetSame) : tagged as `btgs`
  - buy 3 (in a set of items) and the cheapest is free (BuySetGetCheap) : tagged as `bsgc`
- Any other inputted tag should lead to no discount on the associated product.
- Future deals should be easy to implement, just requiring a new class that implements the `IDiscount.hpp` interface.
####   Testing
- Run `./prog test` to execute a series of simple tests building a shopping cart.
### Implementation Details
Built in an OOD structure utilized by `main.cpp`. The primary modules are listed below:
#### Item Class
Items represent an individual product, holding their name, quantity, and unit price (aka cost). The Item class simply contains a constructor and simple getters for its private fields.
#### IDiscount Interface
This interface represents potential deals, primarily existing to abstract out functionality for easier extension. The implementing classes, BuyTwoGetSame and BuySetGetCheap, must implement the `ApplyDiscount()` method and return a vector of pairs that match each item to its savings.
#### List Class
A List functions as a metaphorical shopping cart, holding pairs of Items and their optional IDiscount (an empty optional here indicates no discount). These pairs are added with `AddItem()` and then processed with `PrintReceipt`. Calling the latter method sums the cost of all products with their discounts factored in and then prints the information to stdout.
#### Parse Class
The Parse class exists as a utility to create a List from a .csv file formatted as described in the Usage section of this README. This code also handles basic input validation (ensuring positive quantities and reasonable names for example). As such, this program's entry point uses the Parse functionality to build a List before immediately printing its receipt. 
#### Test Class
The Test class exists as some form of automated unit testing, allowing a user to directly run a limited suite that directly checks the total cost of a created List, reporting any unexpected results.
