#include <iterator>

template<typename T>
class StringIterator : public std::iterator<std::forward_iterator_tag, T> {
public:
    StringIterator(T* ptr) : ptr_(ptr) {}
    StringIterator operator++() { ptr_++; return *this; }
    StringIterator operator--() { ptr--; return *this; }
    bool operator==(const StringIterator& other) const { return ptr_ == other.ptr_; }
    bool operator!=(const StringIterator& other) const { return !(*this == other); }
    T& operator*() { return *ptr_; }
private:
    T* ptr_;
};


