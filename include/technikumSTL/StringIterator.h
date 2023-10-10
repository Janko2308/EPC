#ifndef STRINGITERATOR_H
#define STRINGITERATOR_H

#include <iterator>

template <typename T>
class StringIterator : public std::iterator<std::input_iterator_tag, T> {

public:
    StringIterator(T* ptr) : current(ptr) {}

    StringIterator& operator++() {
        ++current;
        return *this;
    }

    StringIterator& operator--() {
        --current;
        return *this;
    }

    bool operator!=(const StringIterator& other) const {
        return current != other.current;
    }

    bool operator==(const StringIterator& other) const {
        return current == other.current;
    }

    T& operator*() {
        return *current;
    }

    T* operator->() {
        return current;
    }
    
private:    
    T* current;
    
};

#endif // STRINGITERATOR_H