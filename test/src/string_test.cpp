#include "technikumSTL/string.h"
#include "technikumSTL/UniquePtr.h"
#include <gtest/gtest.h>
#include <iostream>

namespace technikum{

    TEST(StringTests, InitializeFromString) {
        const char* cstr = "Hello, World!";
        string myString(cstr);
        EXPECT_EQ(myString.length(cstr), 13);
        EXPECT_STREQ(myString.c_str(), cstr);
    }

    TEST(StringTests, AppendString) {
        string str1("Hello, ");
        string str2("World!");
        str1.append("World!");
        size_t test = str1.length(str1.c_str());
        const char* test2 = str1.c_str();
        EXPECT_EQ(test, 13);
        EXPECT_STREQ(test2, "Hello, World!");
    }

    TEST(StringTests, AppendConstChar) {
        string str1("Hello, ");
        const char* cstr = "World!";
        str1.append(cstr);
        EXPECT_EQ(str1.length(str1.c_str()), 13);
        EXPECT_STREQ(str1.c_str(), "Hello, World!");
    }

    TEST(StringTests, EmptyCharInitializer) {
        string str1("");
        EXPECT_EQ(str1.length(str1.c_str()), 0);
        EXPECT_STREQ(str1.c_str(), "");
    }

    TEST(StringTests, AppendEmptyChar) {
        string str1("Hello, ");
        const char* cstr = "";
        str1.append(cstr);
        EXPECT_EQ(str1.length(str1.c_str()), 7);
        EXPECT_STREQ(str1.c_str(), "Hello, ");
    }

    TEST(StringTests, AppendToEmptyChar) {
        string str1("");
        const char* cstr = "Empty";
        str1.append(cstr);
        EXPECT_EQ(str1.length(str1.c_str()), 5);
        EXPECT_STREQ(str1.c_str(), "Empty");
    }


    TEST(StringTests, AppendEmptyCharToEmptyChar) {
        string str1("");
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
    TEST(StringMoveConstructorTest, MoveConstructor) {
        string str1("hello");
        string str2 = std::move(str1);
        //EXPECT_EQ(str1.length(str1.c_str()), 0);
        EXPECT_STREQ(str2.c_str(), "hello");
    }

    TEST(StringMoveAssignmentOperatorTest, MoveAssignmentOperator) {
        string str1("hello");
        string str2 = ("World");
        str2 = std::move(str1);
        //EXPECT_EQ(str1.length(str1.c_str()), 0);
        EXPECT_STREQ(str2.c_str(), "hello");
    }


    TEST(Stringconvert, convertionOfString) {
        string str1("hello");
        const char* converted = str1.convert();
        EXPECT_EQ(converted[0], 'h');
        EXPECT_EQ(converted[1], 'e');
        EXPECT_EQ(converted[2], 'l');
        EXPECT_EQ(converted[3], 'l');
        EXPECT_EQ(converted[4], 'o');
        EXPECT_EQ(converted[5], '\0');
        
    }

    TEST(StringOverloadedPlusOperatorTest, OverloadedPlusOperator) {
        string str1("Hello, ");
        string str2("World!");
        string str3 = str1 + str2;
        EXPECT_EQ(str3.length(str3.c_str()), 13);
        EXPECT_STREQ(str3.c_str(), "Hello, World!");
        EXPECT_STREQ(str1.c_str(), "Hello, ");
        EXPECT_STREQ(str2.c_str(), "World!");
    }

    TEST(StringOverloadedPlusOperatorTest, OverloadedPlusOperatorWithConstChar) {
        string str1("Hello, ");
        const char* cstr = "World!";
        string str3 = str1 + cstr;
        EXPECT_EQ(str3.length(str3.c_str()), 13);
        EXPECT_STREQ(str3.c_str(), "Hello, World!");
        EXPECT_STREQ(str1.c_str(), "Hello, ");
        EXPECT_STREQ(cstr, "World!");
    }

    TEST(StringOverloadedPlusEqualsOperatorTest, OverloadedPlusEqualsOperator) {
        string str1("Hello, ");
        string str2("World!");
        str1 += str2;
        EXPECT_EQ(str1.length(str1.c_str()), 13);
        EXPECT_STREQ(str1.c_str(), "Hello, World!");
    }

    TEST(StringOverloadedPlusEqualsOperatorTest, OverloadedPlusEqualsOperatorWithConstChar) {
        string str1("Hello, ");
        const char* cstr = "World!";
        str1 += cstr;
        EXPECT_EQ(str1.length(str1.c_str()), 13);
        EXPECT_STREQ(str1.c_str(), "Hello, World!");
    }

    TEST(StringNullptrTest, NullptrConstructor) {
        const char* tozero = nullptr;
        string str1(tozero);
        EXPECT_EQ(str1.length(str1.c_str()), 0);
    }

    TEST(StringNullptrTest, NullptrAppend) {
        const char* tozero = nullptr;
        string str1("hello");
        str1.append(tozero);
        EXPECT_EQ(str1.length(str1.c_str()), 5);
        EXPECT_STREQ(str1.c_str(), "hello");
    }

    TEST(StringNullptrTest, NullptrOperatorPlus) {
        const char* tozero = nullptr;
        string str1("Hello");
        string str3 = str1 + tozero;
        EXPECT_EQ(str3.length(str3.c_str()), 5);
        EXPECT_STREQ(str3.c_str(), "Hello");
        EXPECT_STREQ(str1.c_str(), "Hello");
    }

    TEST(StringNullptrTest, NullptrOperatorPlusEqual) {
        const char* tozero = nullptr;
        string str1("Hello");
        str1 += tozero;
        EXPECT_EQ(str1.length(str1.c_str()), 5);
        EXPECT_STREQ(str1.c_str(), "Hello");
    }

    TEST(StringIterator, IteratorTraversal) {
        const char* testStr = "Hello, World!";
        string str(testStr);

        iterator<char> it = str.begin();
        iterator<char> endIt = str.end();

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
        string str(testStr);

        // Use your custom iterator with std::find
        iterator<char> it = str.begin();
        iterator<char> endIt = str.end();
        iterator<char> foundIt = std::find(it, endIt, 'I');

        // Check if the character 'I' was found
        EXPECT_NE(foundIt, endIt);
        EXPECT_EQ(*foundIt, 'I');
    }

    TEST(StringIterator, IteratorEmptyString) {
        string str("");
        iterator<char> it = str.begin();
        iterator<char> endIt = str.end();
        
        // Ensure that begin() and end() are equal for an empty string
        EXPECT_EQ(it, endIt);
    }

    TEST(StringIterator, IteratorIncrement) {
        string str("ABC");
        iterator<char> it = str.begin();
        
        // Iterate through the string and check the values
        EXPECT_EQ(*it, 'A');
        ++it;
        EXPECT_EQ(*it, 'B');
        ++it;
        EXPECT_EQ(*it, 'C');
        ++it;
        
        // Ensure that it is equal to end() after reaching the end
        EXPECT_EQ(it, str.end());
    }

    TEST(StringIterator, IteratorDecrement) {
        string str("XYZ");
        iterator<char> it = str.end();
        
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
        string str1("Hello");
        iterator<char> it1 = str1.begin();
        iterator<char> it2 = str1.begin();
        bool result = (it1 == it2);
        EXPECT_EQ(result, true);    
        ++it2;
        bool result2 = (it2 == it1);
        EXPECT_EQ(result2, false);
    }

    TEST(StringIterator, EqualsNotOperator) {
        string str1("Test");
        iterator<char> it1 = str1.begin();
        iterator<char> it2 = str1.begin();
        bool result = (it1 != it2);
        EXPECT_EQ(result, false); 
        ++it2;
        bool result2 = (it1 != it2);
        EXPECT_EQ(result2, true);
    }

    TEST(StringIterator, IteratorDereference) {
        string str("Dereference");
        iterator<char> it = str.begin();
        
        // Dereference the iterator to check character values
        EXPECT_EQ(*it, 'D');
        ++it;
        EXPECT_EQ(*it, 'e');
        ++it;
        EXPECT_EQ(*it, 'r');
    }

    TEST(StringIterator, IteratorSTLFind) {
        string str("FindTest");
        
        // Use std::find with custom iterator to find a character
        iterator<char> it = std::find(str.begin(), str.end(), 'T');
        
        // Check if the character 'T' was found
        EXPECT_NE(it, str.end());
        EXPECT_EQ(*it, 'T');
    }

    TEST(UniquePtrTest, StringBasicFunctionality) {
        UniquePtr<string> strPointer(new string("Hello World"));
        EXPECT_TRUE(strPointer);
        EXPECT_STREQ(strPointer->c_str(), "Hello World");

        UniquePtr<string> movedStrPointer(std::move(strPointer));
        EXPECT_FALSE(strPointer);
        EXPECT_STREQ(movedStrPointer->c_str(), "Hello World");
        
        *movedStrPointer += "!";
        EXPECT_STREQ(movedStrPointer->c_str(), "Hello World!");
    }

    TEST(UniquePtrTest, StringReleaseAndReset) {
        UniquePtr<string> strPointer(new string("Test"));
        string* rawString = strPointer.Release();
        EXPECT_FALSE(strPointer);
        EXPECT_STREQ(rawString->c_str(), "Test");

        delete rawString;

        strPointer.Reset(new string("ResetTest"));
        EXPECT_STREQ(strPointer->c_str(), "ResetTest");
        strPointer.Reset();
        
    }

    TEST(UniquePtrTest, StringSwapFunctionality) {
        UniquePtr<string> str1(new string("First"));
        UniquePtr<string> str2(new string("Second"));

        str1.Swap(str2);

        EXPECT_STREQ(str1->c_str(), "Second");
        EXPECT_STREQ(str2->c_str(), "First");
    }

    TEST(UniquePtrTest, Entity) {
       struct Entity {
            int id = -1;
        };

        UniquePtr<Entity> entityPointer(new Entity);
        UniquePtr<string> stringPointer(new string("Hello World"));
        EXPECT_EQ(entityPointer->id, -1);
    }

    TEST(UniquePtrTest, MoveOperator) {
        UniquePtr<string> strPointer(new string("Test"));
        UniquePtr<string> strPointer2 = std::move(strPointer);
        EXPECT_FALSE(strPointer);
        EXPECT_STREQ(strPointer2->c_str(), "Test");
        UniquePtr<string> strPointer3(new string("Moved"));
        strPointer3 = std::move(strPointer2);
        EXPECT_FALSE(strPointer2);
        EXPECT_STREQ(strPointer3->c_str(), "Test");
    }

}

/* int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

*/