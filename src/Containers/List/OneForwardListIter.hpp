#pragma once
#include "../Containers.hpp"
#include"OneForwardList.hpp"



namespace Containers
{
namespace Iters
{
template<typename T>
class OneForwardListIter
{
    template<typename ValueType>
    friend class ::Containers::OneForwardList;

    /// Все это нужно для работы функция из std
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = T;
    using pointer = T*;
    using reference = T&;
    
    private:
        OneForwardListIter(::Containers::Nodes::OneForwardNode<T>*);
        ::Containers::Nodes::OneForwardNode<T>* _ptr;
    public:
        OneForwardListIter(const OneForwardListIter&);
        bool operator!=(const OneForwardListIter&) const;
        bool operator==(const OneForwardListIter&) const;
        OneForwardListIter::reference operator*() const;
        OneForwardListIter& operator++();
};


template<typename T>
OneForwardListIter<T>::OneForwardListIter(::Containers::Nodes::OneForwardNode<T>* ptr) :
    _ptr(ptr)
{

}

template<typename T>
OneForwardListIter<T>::OneForwardListIter(const OneForwardListIter& it) :
    _ptr(it._ptr)
{

}

template<typename T>
bool OneForwardListIter<T>::operator!=(OneForwardListIter const& other) const
{
    return _ptr != other._ptr;
}

template<typename T>
bool OneForwardListIter<T>::operator==(OneForwardListIter const& other) const
{
    return _ptr == other._ptr;
}

template<typename T>
typename OneForwardListIter<T>::reference OneForwardListIter<T>::operator*() const
{
    return _ptr->_data;
}

template<typename T>
OneForwardListIter<T> &OneForwardListIter<T>::operator++()
{
    _ptr = _ptr->_next.get();
    return *this;
}

}
}