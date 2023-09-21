#ifndef string_h
#define string_h

namespace technikum {
    class string {
    public:
        //String();
        string(const char* cstr);
        ~string();
        int length(char const* cstr) const;
        int length(string str) const;
        const char* c_str();
        string append(const char* cstr);

    private:
        char const* m_data;
        //int m_length;
    };

}

#endif /* string_h */