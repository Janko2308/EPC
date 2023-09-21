#include "technikumSTL/string.h"
#include <gtest/gtest.h>

TEST(StringTests, AppendConstChar) {
    technikum::string str1("Hello, ");
    const char* cstr = "World!";
    str1.append(cstr);
    EXPECT_EQ(str1.length(str1), 13);
    EXPECT_STREQ(str1.c_str(), "Hello, World!");
}