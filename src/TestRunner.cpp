#include "TestRunner.hpp"
#include <iostream>
#include <algorithm>


TestRunner* TestRunner::instance = nullptr;

/**
 * @brief run all the tests
 * 
 */
void TestRunner::runAllTests() {
    sendMessage("[==========] Running " + std::to_string(tests.size()) + " tests");
    int numberTestsPassed = 0;
    for(int i = 0; i < tests.size(); i++) {
        if(tests[i]->runTest()) {
            numberTestsPassed++;
        }
    }
    sendMessage("[==========] " + std::to_string(tests.size()) + " tests ran");
    sendMessage("[  PASSED  ] " + std::to_string(numberTestsPassed) + " tests");
    sendMessage("[  FAILED  ] " + std::to_string(tests.size() - numberTestsPassed) + " tests");
    sendMessage("[==========] " + std::to_string(tests.size()) + " tests ran");
    if(tests.size() == numberTestsPassed) {
        sendMessage("[  PASSED  ] All tests passed");
    } else {
        sendMessage("[  FAILED  ] Some tests failed");
    }

}

/**
 * @brief add a test to the list of tests
 * 
 * @param test 
 */
void TestRunner::addTest(UnitTest* test) {
    tests.push_back(test);
}

/**
 * @brief get the instance of the TestRunner
 * 
 * @return TestRunner* 
 */
TestRunner* TestRunner::getInstance() {
    if(instance == nullptr) {
        instance = new TestRunner();
    }
    return instance;
}

/**
 * @brief send a message to the standart output
 * 
 * @param message 
 */
void TestRunner::sendMessage(std::string message) {
    std::cout << message << std::endl;
}
