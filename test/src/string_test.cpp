#include "technikumSTL/string.h"
#include <gtest/gtest.h>
#include <iostream>

namespace technikum{

    TEST(StringTests, InitializeFromString) {
        const char* cstr = "Hello, World!";
        technikum::string myString(cstr);
        EXPECT_EQ(myString.length(cstr), 13);
        EXPECT_STREQ(myString.c_str(), cstr);
    }

    TEST(StringTests, AppendString) {
        technikum::string str1("Hello, ");
        technikum::string str2("World!");
        str1.append("World!");
        size_t test = str1.length(str1.c_str());
        const char* test2 = str1.c_str();
        EXPECT_EQ(test, 13);
        EXPECT_STREQ(test2, "Hello, World!");
    }

    TEST(StringTests, AppendConstChar) {
        technikum::string str1("Hello, ");
        const char* cstr = "World!";
        str1.append(cstr);
        EXPECT_EQ(str1.length(str1.c_str()), 13);
        EXPECT_STREQ(str1.c_str(), "Hello, World!");
    }

    TEST(StringTests, EmptyCharInitializer) {
        technikum::string str1("");
        EXPECT_EQ(str1.length(str1.c_str()), 0);
        EXPECT_STREQ(str1.c_str(), "");
    }

    TEST(StringTests, AppendEmptyChar) {
        technikum::string str1("Hello, ");
        const char* cstr = "";
        str1.append(cstr);
        EXPECT_EQ(str1.length(str1.c_str()), 7);
        EXPECT_STREQ(str1.c_str(), "Hello, ");
    }

    TEST(StringTests, AppendToEmptyChar) {
        technikum::string str1("");
        const char* cstr = "Empty";
        str1.append(cstr);
        EXPECT_EQ(str1.length(str1.c_str()), 5);
        EXPECT_STREQ(str1.c_str(), "Empty");
    }

    TEST(StringTests, AppendEmptyCharToEmptyChar) {
        technikum::string str1("");
        const char* cstr = "";
        str1.append(cstr);
        EXPECT_EQ(str1.length(str1.c_str()), 0);
        EXPECT_STREQ(str1.c_str(), "");
    }

    TEST(StringCopyConstructorTest, CopyConstructor) {
        string original("Hello, World!");
        string copy(original); // Copy constructor
        EXPECT_EQ(original.length(original.c_str()), copy.length(copy.c_str()));
        EXPECT_STREQ(original.c_str(), copy.c_str());
    }

    TEST(StringCopyAssignmentTest, CopyAssignmentOperator) {
        string str1("Hello, World!");
        string str2("Copy Assignment Test");
        
        str2 = str1; // Copy assignment operator
        
        EXPECT_EQ(str1.length(str1.c_str()), str2.length(str2.c_str()));
        EXPECT_STREQ(str1.c_str(), str2.c_str());
    }
}

/*TEST(StringTests, LetsSee) {
    technikum::string str1("Hello");
    technikum::string str2(str1);
    std::cout << "working" << std::endl;
    EXPECT_EQ(str2.length(str2.c_str()), 5);
    std::cout << "working" << std::endl;
    EXPECT_STREQ(str2.c_str(), "Hello");
    std::cout << "working" << std::endl;
}*/

/* int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
*/