#ifndef string_h
#define string_h

#include <cstddef>

namespace technikum {
    class string {
    public:
        string();
        string(const char* cstr);
        ~string();
        //Copy Constructor
        string(const string& str);
        //Copy Assignment Operator
        string& operator=(const string& str);
        //Move Constructor
        string(string&& other) noexcept;
        //Move Assignment Operator
        string& operator=(string&& other) noexcept;
        size_t length(char const* cstr) const;
        const char* convert();
        const char* c_str();
        void append(const char* cstr);

        // friend string operator+(const string& str1, const string& str2);
        // friend string operator+(const string& cstr, const char* str2);
        /*friend string operator+(string& str1, string& str2);
        friend string operator+(string& str1, const char* cstr);*/
        string operator+(const string& str2) const;
        string operator+(const char* cstr) const;

        string& operator+=(const string& str2);
        string& operator+=(const char* cstr);
        
        
    private:
        char* m_data;
    };

}

#endif /* string_h */