#ifndef string_h
#define string_h

#include <cstddef>
#include <iterator>


namespace technikum {
    class string {
    public:
        
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

        class iterator : std::iterator<std::forward_iterator_tag,char>{
            public:

                iterator(pointer ptr) : m_ptr(ptr) {}

                reference operator*() const { return *m_ptr; }
                pointer operator->() { return m_ptr; }

                iterator& operator++() { m_ptr++; return *this; }
                iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }

                iterator& operator--() { m_ptr--; return *this; }
                iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }

                bool operator== (const iterator& other) { return m_ptr == other.m_ptr; };
                bool operator!= (const iterator& other) { return m_ptr != other.m_ptr; };
            private:
                pointer m_ptr;
            };

            iterator begin() { return iterator(m_data); }
            iterator end() { return iterator(m_data + length(m_data)); }

        
        
        
    private:
        char* m_data;
    };

}

#endif /* string_h */