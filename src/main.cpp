#include <iostream>
#include "TestRunner.hpp"

int main() {
    TestRunner::getInstance()->runAllTests();
    return 0;
}
