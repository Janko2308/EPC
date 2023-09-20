#ifndef string_h
#define string_h

namespace technikum {
    class String {
    public:
        //String();
        String(const char* cstr);
        //~String();
        int length(char const* cstr) const;
        int length(String str) const;
        const char* c_str();
        String append(const char* cstr);

    private:
        char const* m_data;
        //int m_length;
    };

}

#endif /* string_h */