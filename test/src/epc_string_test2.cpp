#include "technikumSTL/string.h"
#include <gtest/gtest.h>

TEST(StringTests, AppendString) {
    technikum::string str1("Hello, ");
    // technikum::String str2("World!");
    str1.append("World!");
    EXPECT_EQ(str1.length(str1), 13);
    EXPECT_STREQ(str1.c_str(), "Hello, World!");
}