#pragma once
#include "../Containers.hpp"
#include"Array.hpp"



namespace Containers
{
namespace Iters
{
template<typename T>
class ArrayIter
{
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;
    using difference_type = int;
    using pointer = int*;
    using reference = int&;
    template<typename Value>
    friend class ::Containers::Array;
    private:
        ArrayIter(T*);
        T* _ptr;
    public:
        ArrayIter(const ArrayIter&);
        bool operator!=(const ArrayIter&) const;
        bool operator==(const ArrayIter&) const;
        ArrayIter::reference operator*() const;
        ArrayIter& operator++();
};


template<typename T>
ArrayIter<T>::ArrayIter(T *ptr) :
    _ptr(ptr)
{

}

template<typename T>
ArrayIter<T>::ArrayIter(const ArrayIter& it) :
    _ptr(it._ptr)
{

}

template<typename T>
bool ArrayIter<T>::operator!=(ArrayIter const& other) const
{
    return _ptr != other._ptr;
}

template<typename T>
bool ArrayIter<T>::operator==(ArrayIter const& other) const
{
    return _ptr == other._ptr;
}

template<typename T>
typename ArrayIter<T>::reference ArrayIter<T>::operator*() const
{
    return *_ptr;
}

template<typename T>
ArrayIter<T> &ArrayIter<T>::operator++()
{
    ++_ptr;
    return *this;
}

}
}