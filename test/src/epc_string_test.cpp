#include "technikumSTL/string.h"
#include <gtest/gtest.h>

TEST(StringTests, InitializeFromString) {
    const char* cstr = "Hello, World!";
    technikum::String myString(cstr);
    EXPECT_EQ(myString.length(cstr), 13);
    EXPECT_STREQ(myString.c_str(), cstr);
}

TEST(StringTests, AppendString) {
    technikum::String str1("Hello, ");
    // technikum::String str2("World!");
    str1.append("World!");
    EXPECT_EQ(str1.length(str1), 13);
    EXPECT_STREQ(str1.c_str(), "Hello, World!");
}

TEST(StringTests, AppendConstChar) {
    technikum::String str1("Hello, ");
    const char* cstr = "World!";
    str1.append(cstr);
    EXPECT_EQ(str1.length(str1), 13);
    EXPECT_STREQ(str1.c_str(), "Hello, World!");
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}