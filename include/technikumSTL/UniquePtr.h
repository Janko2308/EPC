#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <memory>   // Für std::default_delete


template<typename T, typename Deleter = std::default_delete<T>>
class UniquePtr {
public:
    // Konstruktor
    explicit UniquePtr(T* ptr = nullptr) noexcept : m_ptr(ptr), m_deleter(Deleter{}) {}

    // Move Konstruktor
    UniquePtr(UniquePtr&& other) noexcept : m_ptr(other.m_ptr), m_deleter(std::move(other.m_deleter)) {
        other.m_ptr = nullptr;
    }

    // Move Zuweisungsoperator
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            Reset();
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
            m_deleter = std::move(other.m_deleter);
        }
        return *this;
    }

    // Destruktor
    ~UniquePtr() {
        if (m_ptr) {
            m_deleter(m_ptr);
        }
    }

    // Verhindern des Copy-Konstruktors und des Copy-Zuweisungsoperators
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // Dereferenzierung
    T& operator*() const {
        return *m_ptr;
    }

    // Mitglied Zugriffsoperator
    T* operator->() const {
        return m_ptr;
    }

    // Bool Operator
    explicit operator bool() const {
        return m_ptr != nullptr;
    }

    // Release
    T* Release() noexcept {
        T* oldPtr = m_ptr;
        m_ptr = nullptr;
        return oldPtr;
    }

    // Reset
    void Reset(T* ptr = nullptr) noexcept {
        if (m_ptr) {
            m_deleter(m_ptr);
        }
        m_ptr = ptr;
    }

    void Swap(UniquePtr& other) noexcept {
        T* temp = m_ptr;
        m_ptr = other.m_ptr;
        other.m_ptr = temp;
    }

    // Swap
    void Swap(T* other) noexcept {
        T temp = *m_ptr;
        *m_ptr = *other;
        *other = temp;
    }

private:
    T* m_ptr;
    Deleter m_deleter;
};

#endif  // UNIQUE_PTR_H