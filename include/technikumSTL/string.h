#ifndef string_h
#define string_h

namespace technikum {
    class string {
    public:
        string(const char* cstr);
        ~string();
        int length(char const* cstr) const;
        //int length(string str) const;
        const char* c_str();
        void append(const char* cstr);
        
        
    private:
        char* m_data;
    };

}

#endif /* string_h */