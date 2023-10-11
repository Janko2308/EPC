#ifndef string_h
#define string_h

#include <cstddef>
#include <iterator>

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

        template<typename T>
        class iterator;

        template<typename T>
        iterator<T> begin();

        template<typename T>
        iterator<T> end();
        
    private:
        char* m_data;
    };

    template<typename T>
        class iterator : public std::iterator<std::forward_iterator_tag, T> {
        public:
            iterator(T* ptr) : ptr_(ptr) {}
            iterator operator++() { ptr_++; return *this; }
            iterator operator--() { ptr_--; return *this; }
            bool operator==(const iterator& other) const { return ptr_ == other.ptr_; }
            bool operator!=(const iterator& other) const { return !(*this == other); }
            T& operator*() { return *ptr_; }
        private:
            T* ptr_;
        };

}

#endif /* string_h */