template<typename T>
class UniquePtr {
public:
    // constructors
    UniquePtr() : ptr(nullptr) {}
    UniquePtr(T* p) : ptr(p) {}
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) { other.ptr = nullptr; }
    template<typename U>
    UniquePtr(UniquePtr<U>&& other) noexcept : ptr(other.release()) {}

    // destructor
    ~UniquePtr() { deleter(ptr); }

    // assignment operators
    UniquePtr& operator=(const UniquePtr&) = delete;
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            deleter(ptr);
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    template<typename U>
    UniquePtr& operator=(UniquePtr<U>&& other) noexcept {
        if (this != &other) {
            deleter(ptr);
            ptr = other.release();
        }
        return *this;
    }

    // dereference operators
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    operator bool() const { return ptr != nullptr; }

    // release ownership
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // reset pointer
    void reset() {
        deleter(ptr);
        ptr = nullptr;
    }

    // swap pointers
    void swap(UniquePtr& other) {
        std::swap(ptr, other.ptr);
    }

    using DeleterType = void (*)(T*);

private:
    T* ptr;
    DeleterType deleter = [](T* p) { delete p; };
};

// swap function
template<typename T>
void swap(UniquePtr<T>& a, UniquePtr<T>& b) {
    a.swap(b);
}
