#pragma once
#include "../Containers.hpp"
#include"TwoForwardList.hpp"



namespace Containers
{
namespace Iters
{
template<typename T>
class TwoForwardListIter
{
    template<typename ValueType>
    friend class ::Containers::TwoForwardList;

    /// Все это нужно для работы функция из std
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = T;
    using pointer = T*;
    using reference = T&;
    
    private:
        TwoForwardListIter(::Containers::Nodes::TwoForwardNode<T>*);
        ::Containers::Nodes::TwoForwardNode<T>* _ptr;
    public:
        TwoForwardListIter(const TwoForwardListIter&);
        bool operator!=(const TwoForwardListIter&) const;
        bool operator==(const TwoForwardListIter&) const;
        TwoForwardListIter::reference operator*() const;
        TwoForwardListIter& operator++();
        TwoForwardListIter& operator--();
};


template<typename T>
TwoForwardListIter<T>::TwoForwardListIter(::Containers::Nodes::TwoForwardNode<T>* ptr) :
    _ptr(ptr)
{

}

template<typename T>
TwoForwardListIter<T>::TwoForwardListIter(const TwoForwardListIter& it) :
    _ptr(it._ptr)
{

}

template<typename T>
bool TwoForwardListIter<T>::operator!=(TwoForwardListIter const& other) const
{
    return _ptr != other._ptr;
}

template<typename T>
bool TwoForwardListIter<T>::operator==(TwoForwardListIter const& other) const
{
    return _ptr == other._ptr;
}

template<typename T>
typename TwoForwardListIter<T>::reference TwoForwardListIter<T>::operator*() const
{
    return _ptr->_data;
}

template<typename T>
TwoForwardListIter<T> &TwoForwardListIter<T>::operator++()
{
    _ptr = _ptr->_next.get();
    return *this;
}

template<typename T>
TwoForwardListIter<T> &TwoForwardListIter<T>::operator--()
{
    _ptr = _ptr->_prev.get();
    return *this;
}

}
}