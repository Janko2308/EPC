#include "technikumSTL/string.h"
#include <gtest/gtest.h>

TEST(StringTests, AppendString) {
    technikum::string str1("Hello, ");
    // technikum::String str2("World!");
    //str1.append("World!");
    //int test = str1.length(str1);
    //const char* test2 = str1.c_str();
    EXPECT_EQ(test, 13);
    EXPECT_STREQ(test2, "Hello, World!");
}