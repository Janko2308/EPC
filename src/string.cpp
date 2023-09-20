#include "technikumSTL/string.h"

technikum::String::String(char const* cstr) {
    m_data = cstr;
}

//write the append function here

int technikum::String::length(char const* cstr) const {
    int length = 0;
    while (cstr[length] != '\0') {
        length++;
    }
    return length;
}

int technikum::String::length(String str) const {
    int length = 0;
    while (str.m_data[length] != '\0') {
        length++;
    }
    return length;
}

technikum::String technikum::String::append(char const* cstr) {
    int m_length = this->length(this->m_data);
    int c_length = this->length(cstr);

    int newLength = m_length + c_length;
    char* newString = new char[newLength + 1];
    int i = 0;
    for (i = 0; i < m_length; i++) {
        newString[i] = this->m_data[i];
    }
    //schau ob es richtig speichert
    for (int j = 0; j < c_length; j++) {
        newString[i + j] = cstr[j];
    }

    this->m_data = newString;

    return newString;
}

const char* technikum::String::c_str() {
    return m_data;
}

// technikum::String::~String() {
//     delete[] m_data;
// }