#include "technikumSTL/string.h"
#include <gtest/gtest.h>

TEST(StringTests, InitializeFromString) {
    const char* cstr = "Hello, World!";
    technikum::string myString(cstr);
    EXPECT_EQ(myString.length(cstr), 13);
    EXPECT_STREQ(myString.c_str(), cstr);
}






/*int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/