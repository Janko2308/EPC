#include "technikumSTL/string.h"

#include <iostream>

namespace technikum
{


  string::string(char const* cstr)
  {
    size_t m_length = length(cstr);  
    this->m_data = new char[m_length + 1];  
    for (size_t i = 0; i < m_length; i++)
    {
      this->m_data[i] = cstr[i];
    }
    this->m_data[m_length] = '\0';  
  }
 

  //Move Constructor
  string::string(string&& other)noexcept : m_data(other.m_data){
    if(other.m_data){
      m_data = other.m_data;
      other.m_data = nullptr;
    }
  }
  

  //Move Assignment Operator
  string& string::operator=(string&& other) noexcept {
        if (this != &other) {  
            delete[] m_data;
            m_data = other.m_data;
            other.m_data = nullptr;
        }
        return *this;
    }


  //Copy Constructor
  string::string(const string& str) : m_data(str.m_data) {
    if (str.m_data) {
      m_data = new char[str.length(str.m_data) + 1];
      size_t length = str.length(str.m_data);
      for (size_t i = 0; i <= length; ++i) {
          m_data[i] = str.m_data[i];
      }
    }
  }
  //Copy Assignment Operator
  string& string::operator=(const string& str) {
      if (this != &str) {
        delete[] m_data;
        m_data = new char[str.length(str.m_data) + 1];
        size_t length = str.length(str.m_data);
        for (size_t i = 0; i <= length; ++i){
          m_data[i] = str.m_data[i];
        } 
      }
      return *this;
  }
  

  

  size_t string::length(char const* cstr) const
  {
    size_t length = 0;
    while (cstr[length] != '\0')//kann endlos laufen falls fehler
    {
      length++;
    }
    return length;
  }


  /*int string::length(string str) const
  {
    int length = 0;
    while (str.m_data[length] != '\0')
    {
      length++;
    }
    return length;
  }*/

  void string::append(char const* cstr)
  {
  
    size_t m_length = length(m_data);
    size_t c_length = length(cstr);

    size_t newLength = m_length + c_length;
    char* newString = new char[newLength + 1];

    for (size_t i = 0; i < m_length; i++)
    {
      newString[i] = this->m_data[i];
    }

    for (size_t j = 0; j < c_length; j++)
    {
      newString[m_length + j] = cstr[j];
    }
    newString[newLength] = '\0';

    delete[] this->m_data;
    this->m_data = newString;
    
  }

  // string operator+(const string& str1, const string str2)
  // {
  //   string str1cpy(str1);
  //   string str2cpy(str2);
  //   str1cpy.append(str2cpy.c_str());
  //   return str1cpy;
  // };

  // string operator+(const string& str1, const char* str2)
  // {
  //   string str1cpy(str1);
  //   string str2cpy(str2);

  //   str1cpy.append(str2cpy.c_str());
  //   return str1cpy;
  // }

  string operator+(string& str1, const char* str2)
  {
    str1.append(str2);
    return str1;
  }

  string operator+(string& str1, string& str2)
  {
    str1.append(str2.c_str());
    return str1;
  }

  string& string::operator+=(const string& str2) {
    append(str2.m_data); 
    return *this; 
}

  string& string::operator+=(const char* cstr) {
    append(cstr);
    return *this;
  }
  

  const char* string::c_str()
  {
    return this->m_data;
  }

  string::~string()
  { 
    if(m_data !=  nullptr){
      delete[] this->m_data; 
    }
           
    
  }

} //uint_8 size_t const (string::)? static? /copy constructor