#ifndef __TEST_RUNNER_HPP__
#define __TEST_RUNNER_HPP__

#include <vector>
#include "UnitTest.hpp"

class TestRunner {
public:
    void runAllTests();
    void addTest(UnitTest* test);
    static TestRunner* getInstance();
    void sendMessage(std::string message);
private:
    std::vector<UnitTest*> tests;
    TestRunner() {}
    static TestRunner* instance;
};

#endif // __TEST_RUNNER_HPP__