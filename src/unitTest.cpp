#include "unitTest.hpp"
#include "TestRunner.hpp"

UnitTest::UnitTest(std::string testGroup, std::string testName) : testGroup(testGroup), testName(testName) {
    TestRunner::getInstance()->addTest(this);
}

/**
 * @brief run the test and print the result in the standart output test
 * 
 * @return true 
 * @return false 
 */
bool UnitTest::runTest() {
    bool result = true;
    TestRunner::getInstance()->sendMessage("[ RUN      ] " + testGroup + "." + testName);
    do_runTest(&result);
    if(result) {
        TestRunner::getInstance()->sendMessage("[       OK ] " + testGroup + "." + testName);
    } else {
        TestRunner::getInstance()->sendMessage("[  FAILED  ] " + testGroup + "." + testName);
    }
    return result;
}

/**
 * @brief print the error message and the file and line where the error occured
 * 
 * @param message 
 * @param file 
 * @param line 
 */
void UnitTest::assert_error(std::string message, std::string file, int line) {
    TestRunner::getInstance()->sendMessage("Assertion error in " + file + ":" + std::to_string(line) + " : " + message);
}

