#include "technikumSTL/string.h"

namespace technikum
{

  string::string(char const* cstr)
  {
    //m_data = new char[length(cstr + 1)];
    m_data = cstr;
  }

  // write the append function here

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

  string string::append(char const* cstr)
  {
    int m_length = this->length(this->m_data);
    int c_length = this->length(cstr);

    int newLength = m_length + c_length;
    char* newString = new char[newLength + 1];
    int i = 0;
    for (i = 0; i < m_length; i++)
    {
      newString[i] = this->m_data[i];
    }
    // schau ob es richtig speichert
    for (int j = 0; j < c_length; j++)
    {
      newString[i + j] = cstr[j];
    }

    this->m_data = newString;

    return newString;
  }

  const char* string::c_str()
  {
    return m_data;
  }

  string::~string()
  {
    delete this->m_data;
  }

}  // namespace technikum