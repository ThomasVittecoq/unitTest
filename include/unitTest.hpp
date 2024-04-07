#ifndef __UNIT_TEST_HPP__
#define __UNIT_TEST_HPP__

#include <string>
#include <vector>

/**
 * @brief fonction macro pour définir un test unitaire
 * 
 */
#define TEST(testGroup, testName) \
    class testGroup##testName : public UnitTest { \
    public: \
        testGroup##testName() : UnitTest(#testGroup, #testName) {} \
    private: \
        void do_runTest(bool *result) override; \
    }; \
    testGroup##testName testGroup##testName##Instance; \
    void testGroup##testName::do_runTest(bool *result)

#define ASSERT_TRUE(condition) if(!(condition)) { assert_error("expected true", __FILE__, __LINE__); *result = false; return; }
#define ASSERT_FALSE(condition) if((condition)) { assert_error("expected false", __FILE__, __LINE__); *result = false; return; }
#define ASSERT_EQUAL(expected, actual) if((expected) != (actual)) { assert_error("expected " + std::to_string(expected) + " but got " + std::to_string(actual), __FILE__, __LINE__); *result = false; return; }
#define ASSERT_NOT_EQUAL(notExpected, actual) if((notExpected) == (actual)) { assert_error("expected " + std::to_string(notExpected) + " but got " + std::to_string(actual), __FILE__, __LINE__); *result = false; return; }
#define ASSERT_NULL(pointer) if((pointer) != nullptr) { assert_error("expected null pointer", __FILE__, __LINE__); *result = false; return; }
#define ASSERT_NOT_NULL(pointer) if((pointer) == nullptr) { assert_error("expected not null pointer", __FILE__, __LINE__); *result = false; return; }


/**
 * @brief Classe de base pour les tests unitaires
 * 
 */
class UnitTest {
public:
    UnitTest(std::string testGroup, std::string testName);
    bool runTest();
    void assert_error(std::string message, std::string file, int line);
    std::string getTestGroup() { return testGroup; }
    std::string getTestName() { return testName; }
private:
    std::string testGroup;
    std::string testName;
    virtual void do_runTest(bool *result) = 0;
};

class testGroup {
public:
    static void runAllTests();
    static void addTest(UnitTest* test);
    static void sendMessage(std::string message);
private:
    static std::vector<UnitTest*> tests;
    testGroup() {}
};

#endif // __UNIT_TEST_HPP__