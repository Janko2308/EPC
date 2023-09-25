#ifndef string_h
#define string_h

namespace technikum {
    class string {
    public:
        string(const char* cstr);
        ~string();
        //Copy Constructor
        //Copy Assignment Operator
        //Move Constructor
        string(string&& other) noexcept;
        //Move Assignment Operator
        string& operator=(string&& other) noexcept;

        int length(char const* cstr) const;
        //int length(string str) const;
        const char* c_str();
        void append(const char* cstr);
        
        
    private:
        char* m_data;
    };

}

#endif /* string_h */