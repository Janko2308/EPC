#include "technikumSTL/string.h"

#include <iostream>
namespace technikum
{

  string::string(char const* cstr)
  {
    int m_length = length(cstr);  
    m_data = new char[m_length + 1];  
    for (int i = 0; i < m_length; i++)
    {
      m_data[i] = cstr[i];
    }
    m_data[m_length] = '\0';  
  }

  int string::length(char const* cstr) const
  {
    int length = 0;
    while (cstr[length] != '\0')
    {
      length++;
    }
    return length;
  }

  int string::length(string str) const
  {
    int length = 0;
    while (str.m_data[length] != '\0')
    {
      length++;
    }
    return length;
  }

  void string::append(char const* cstr)
  {
    int m_length = length(m_data);
    int c_length = length(cstr);

    int newLength = m_length + c_length;
    char* newString = new char[newLength + 1];

    for (int i = 0; i < m_length; i++)
    {
      newString[i] = this->m_data[i];
    }

    for (int j = 0; j < c_length; j++)
    {
      newString[m_length + j] = cstr[j];
    }
    newString[newLength] = '\0';

    delete[] this->m_data;
    this->m_data = newString;
  }

  const char* string::c_str()
  {
    return m_data;
  }

  string::~string()
  {
    if (this->m_data != nullptr)
    {
            //doesnt worrk with the code below (Reason? Unknown)
      //delete[] this->m_data;
            //To whomever is reading this, please help me understand why the code above doesnt work
    }
  }

} 