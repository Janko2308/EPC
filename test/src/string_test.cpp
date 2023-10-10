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
    
    TEST(StringDefaultConstructorTest, DefaultConstructor) {
        technikum::string str1;
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
    TEST(StringMoveConstructorTest, MoveConstructor) {
        technikum::string str1("hello");
        technikum::string str2 = std::move(str1);
        //EXPECT_EQ(str1.length(str1.c_str()), 0);
        EXPECT_STREQ(str2.c_str(), "hello");
    }

    TEST(StringMoveAssignmentOperatorTest, MoveAssignmentOperator) {
        technikum::string str1("hello");
        technikum::string str2 = ("World");
        str2 = std::move(str1);
        //EXPECT_EQ(str1.length(str1.c_str()), 0);
        EXPECT_STREQ(str2.c_str(), "hello");
    }


    TEST(Stringconvert, convertionOfString) {
        technikum::string str1("hello");
        const char* converted = str1.convert();
        EXPECT_EQ(converted[0], 'h');
        EXPECT_EQ(converted[1], 'e');
        EXPECT_EQ(converted[2], 'l');
        EXPECT_EQ(converted[3], 'l');
        EXPECT_EQ(converted[4], 'o');
        EXPECT_EQ(converted[5], '\0');
        
    }

    TEST(Stringconvert, convertionOfEmpty) {
        technikum::string str1;
        const char* converted = str1.convert();
        EXPECT_EQ(converted[0], '\0');
    }

    TEST(StringOverloadedPlusOperatorTest, OverloadedPlusOperator) {
        technikum::string str1("Hello, ");
        technikum::string str2("World!");
        technikum::string str3 = str1 + str2;
        EXPECT_EQ(str3.length(str3.c_str()), 13);
        EXPECT_STREQ(str3.c_str(), "Hello, World!");
        EXPECT_STREQ(str1.c_str(), "Hello, ");
        EXPECT_STREQ(str2.c_str(), "World!");
    }

    TEST(StringOverloadedPlusOperatorTest, OverloadedPlusOperatorWithConstChar) {
        technikum::string str1("Hello, ");
        const char* cstr = "World!";
        technikum::string str3 = str1 + cstr;
        EXPECT_EQ(str3.length(str3.c_str()), 13);
        EXPECT_STREQ(str3.c_str(), "Hello, World!");
        EXPECT_STREQ(str1.c_str(), "Hello, ");
        EXPECT_STREQ(cstr, "World!");
    }

    TEST(StringOverloadedPlusEqualsOperatorTest, OverloadedPlusEqualsOperator) {
        technikum::string str1("Hello, ");
        technikum::string str2("World!");
        str1 += str2;
        EXPECT_EQ(str1.length(str1.c_str()), 13);
        EXPECT_STREQ(str1.c_str(), "Hello, World!");
    }

    TEST(StringOverloadedPlusEqualsOperatorTest, OverloadedPlusEqualsOperatorWithConstChar) {
        technikum::string str1("Hello, ");
        const char* cstr = "World!";
        str1 += cstr;
        EXPECT_EQ(str1.length(str1.c_str()), 13);
        EXPECT_STREQ(str1.c_str(), "Hello, World!");
    }

    TEST(StringNullptrTest, NullptrConstructor) {
        const char* tozero = nullptr;
        technikum::string str1(tozero);
        EXPECT_EQ(str1.length(str1.c_str()), 0);
        EXPECT_STREQ(str1.c_str(), "");
    }

    TEST(StringNullptrTest, NullptrAppend) {
        const char* tozero = nullptr;
        technikum::string str1("hello");
        str1.append(tozero);
        EXPECT_EQ(str1.length(str1.c_str()), 5);
        EXPECT_STREQ(str1.c_str(), "hello");
    }

    TEST(StringNullptrTest, NullptrOperatorPlus) {
        const char* tozero = nullptr;
        technikum::string str1("Hello");
        technikum::string str3 = str1 + tozero;
        EXPECT_EQ(str3.length(str3.c_str()), 5);
        EXPECT_STREQ(str3.c_str(), "Hello");
        EXPECT_STREQ(str1.c_str(), "Hello");
    }

    TEST(StringNullptrTest, NullptrOperatorPlusEqual) {
        const char* tozero = nullptr;
        technikum::string str1("Hello");
        str1 += tozero;
        EXPECT_EQ(str1.length(str1.c_str()), 5);
        EXPECT_STREQ(str1.c_str(), "Hello");
    }

    TEST(StringIterator, IteratorTraversal) {
        const char* testStr = "Hello, World!";
        String str(testStr);

        StringIterator<char> it = str.begin();
        StringIterator<char> endIt = str.end();

        // Traverse the string and build a new string from the characters
        std::string result;
        while (it != endIt) {
            result += *it;
            ++it;
        }

        // Check if the result matches the original string
        EXPECT_EQ(result, testStr);
    }

    TEST(StringIterator, IteratorFind) {
        const char* testStr = "Testing Iterator Functionality";
        String str(testStr);

        // Use your custom iterator with std::find
        StringIterator<char> it = str.begin();
        StringIterator<char> endIt = str.end();
        StringIterator<char> foundIt = std::find(it, endIt, 'I');

        // Check if the character 'I' was found
        EXPECT_NE(foundIt, endIt);
        EXPECT_EQ(*foundIt, 'I');
    }

    TEST(StringIterator, IteratorEmptyString) {
        String str("");
        StringIterator<char> it = str.begin();
        StringIterator<char> endIt = str.end();
        
        // Ensure that begin() and end() are equal for an empty string
        EXPECT_EQ(it, endIt);
    }

    TEST(StringIterator, IteratorIncrement) {
        String str("ABC");
        StringIterator<char> it = str.begin();
        
        // Iterate through the string and check the values
        EXPECT_EQ(*it, 'A');
        ++it;
        EXPECT_EQ(*it, 'B');
        ++it;
        EXPECT_EQ(*it, 'C');
        ++it;
        
        // Ensure that it is equal to end() after reaching the end
        EXPECT_EQ(it, str.end());
        ++it;
        EXPECT_EQ(*it, '\0');
        ++it;
        EXPECT_EQ(*it, nullptr);
    }

    TEST(StringIterator, IteratorDecrement) {
        String str("XYZ");
        StringIterator<char> it = str.end();
        
        // Iterate backwards through the string and check the values
        --it;
        EXPECT_EQ(*it, 'Z');
        --it;
        EXPECT_EQ(*it, 'Y');
        --it;
        EXPECT_EQ(*it, 'X');
        
        // Ensure that it is equal to begin() after reaching the beginning
        EXPECT_EQ(it, str.begin());
    }

    TEST(StringIterator, EqualsOperator) {
        String str1("Hello");
        String str2("Hello");
        String str3("World");
        bool result = (str1 == str2);
        EXPECT_EQ(result, true);    

        bool result2 = (str2 == str3);
        EXPECT_EQ(result2, false);
    }

    TEST(StringIterator, EqualsNotOperator) {
        String str1("Test");
        String str2("String");
        String str3("Test");
        bool result = (str1 != str2);
        EXPECT_EQ(result, true); 
        bool result2 = (str1 != str3);
        EXPECT_EQ(result2, false);
    }

    TEST(StringIterator, IteratorDereference) {
        String str("Dereference");
        StringIterator<char> it = str.begin();
        
        // Dereference the iterator to check character values
        EXPECT_EQ(*it, 'D');
        ++it;
        EXPECT_EQ(*it, 'e');
        ++it;
        EXPECT_EQ(*it, 'r');
    }

    TEST(StringIterator, IteratorSTLFind) {
        String str("FindTest");
        
        // Use std::find with custom iterator to find a character
        StringIterator<char> it = std::find(str.begin(), str.end(), 'T');
        
        // Check if the character 'T' was found
        EXPECT_NE(it, str.end());
        EXPECT_EQ(*it, 'T');
    }

}

/* int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

*/