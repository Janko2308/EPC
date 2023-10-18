#include <iterator>

template<typename T>
class iterator : public std::iterator<std::forward_iterator_tag, T> {
public:
    iterator(T* ptr) : ptr_(ptr) {}
    iterator operator++() { 
        ptr_++; 
        return *this; 
    }
    iterator operator--() { 
        ptr_--; 
        return *this; 
    }
    bool operator==(const iterator& other) const { 
        return ptr_ == other.ptr_; 
    }
    bool operator!=(const iterator& other) const { 
        return !(*this == other); 
    }
    T& operator*() { 
        return *ptr_; 
    }
private:
    T* ptr_;
};


