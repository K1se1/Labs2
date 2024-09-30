#pragma once
#include "../Containers.hpp"
#include "TwoForwardNode.hpp"
#include<memory>
#include<initializer_list>
#include "TwoForwardListIter.hpp"
namespace Containers
{


template<typename T>
class TwoForwardList
{
    template<typename ValueType>
    friend class Iters::TwoForwardListIter;
    private:
        std::shared_ptr<Nodes::TwoForwardNode<T>> _node;
        size_t _size;
    public:
        typedef Iters::TwoForwardListIter<T> iter;
        typedef Iters::TwoForwardListIter<const T> const_iter;
        TwoForwardList();
        TwoForwardList(size_t);
        TwoForwardList(const std::initializer_list<T>&);
        TwoForwardList(const T&);
        TwoForwardList(T&&);
        TwoForwardList(const TwoForwardList<T>&);
        TwoForwardList(TwoForwardList<T>&&);
        TwoForwardList<T>& operator=(const TwoForwardList<T>&);
        TwoForwardList<T>& operator=(TwoForwardList<T>&&);
        inline size_t size() const;
        T& operator[](size_t);
        const T& operator[](size_t) const;
        void push_back(const T&);
        void insert(size_t, const T&);
        void erase(size_t);
        iter begin();
        iter end();
        iter begin() const;
        iter end() const;
};


template<typename T>
TwoForwardList<T>::TwoForwardList(): _node(std::make_shared<Nodes::TwoForwardNode<T>>()), _size(0)
{
}

template<typename T>
TwoForwardList<T>::TwoForwardList(size_t size)
{
    _node =std::make_shared<Nodes::TwoForwardNode<T>>();
    _size = size;
    auto prevNode = _node;
    auto tempNode = (_node->_next = std::make_shared<Nodes::TwoForwardNode<T>>());
    for(size_t i =1; i < _size; ++i)
    {
        tempNode->_prev = prevNode;
        prevNode = tempNode;
        tempNode = (tempNode->_next  = std::make_shared<Nodes::TwoForwardNode<T>>());
    }
}

template<typename T>
TwoForwardList<T>::TwoForwardList(const std::initializer_list<T>& list)
{
    _node =std::make_shared<Nodes::TwoForwardNode<T>>();
    auto listIter = list.begin();
    _size = list.size();
    _node->_data = *listIter;
    auto prevNode = _node;
    auto tempNode = (_node->_next = std::make_shared<Nodes::TwoForwardNode<T>>());
    for(size_t i =1; i < _size; ++i)
    {   
        tempNode->_prev = prevNode;
        tempNode->_data = *(listIter+i);
        tempNode = (tempNode->_next = std::make_shared<Nodes::TwoForwardNode<T>>());
    }
}

template<typename T>
TwoForwardList<T>::TwoForwardList(const T& value): _size(1), _node(value)
{
}

template<typename T>
TwoForwardList<T>::TwoForwardList(T&& value): _size(1), _node(std::move(value))
{
}


template<typename T>
TwoForwardList<T>& TwoForwardList<T>::operator=(const TwoForwardList<T>& list)
{
    _size = list._size;
    _node._data = list[0];
    auto prevNode= _node;
    auto tempNode = (_node._next = std::make_shared<Nodes::TwoForwardNode<T>>());
    for(size_t i =1; i < _size; ++i)
    {   
        tempNode->_prev = prevNode;
        tempNode->_data = list[i];
        tempNode = (tempNode->_next = std::make_shared<Nodes::TwoForwardNode<T>>());
    }
    return *this;

}

template<typename T>
TwoForwardList<T>& TwoForwardList<T>::operator=(TwoForwardList<T>&& list)
{
    _size = std::move(list._size);
    _node = std::move(list._node);
    return *this;
}

template<typename T>
TwoForwardList<T>::TwoForwardList(const TwoForwardList<T>& list)
{
    _size = list._size;
    _node._data = list[0];
    auto prevNode = _node;
    auto tempNode = (_node._next = std::make_shared<Nodes::TwoForwardNode<T>>());
    for(size_t i =1; i < _size; ++i)
    {   
        tempNode->_prev = prevNode;
        tempNode->_data = list[i];
        tempNode = (tempNode->_next = std::make_shared<Nodes::TwoForwardNode<T>>());
    }
}

template<typename T>
TwoForwardList<T>::TwoForwardList(TwoForwardList<T>&& list)
{
    _size = std::move(list._size);
    _node = std::move(list._node);
}


template<typename T>
T& TwoForwardList<T>::operator[](size_t i) 
{
    if(i >= _size ) throw std::range_error("List: operator[] Range error");
    if(i == 0) return _node->_data;
    auto tempNode = _node->_next;
    for(int j =1; j < i; ++j)
        tempNode = tempNode->_next;
    return tempNode->_data;

}

template<typename T>
const T& TwoForwardList<T>::operator[](size_t i) const
{
    if(i >= _size ) throw std::range_error("List: operator[] Range error");
    if(i == 0) return _node._data;
    auto tempNode = _node._next;
    for(int j =1; j < i; ++j)
        auto tempNode = _node._next;
    return tempNode->_data;

}

template<typename T>
size_t TwoForwardList<T>::size() const 
{
    return _size;
}

template<typename T>
void TwoForwardList<T>::push_back(const T& elem)
{
    if(_size == 0)
    { 
        _node->_data = elem;
        ++_size;
        return;
    }
    auto tempNode = _node->_next;
    for(int i  =1; i <_size-1; ++i)
    {
        tempNode = tempNode->_next;
    }
    tempNode->_next = std::make_shared<Nodes::TwoForwardNode<T>>(elem);
    auto prevNode = tempNode;
    tempNode = tempNode->next;
    tempNode->_prev = prevNode; 

    ++_size;
}


template<typename T>
void TwoForwardList<T>::insert(size_t pos, const T& elem)
{
    if(pos >=_size) throw std::range_error("List: operator[] Range error");
    auto newNode = std::make_shared<Nodes::TwoForwardNode<T>>(elem);
    if(pos == 0) 
    {
        newNode->_next = _node;
        _node = newNode;
        ++_size;
        return;
    }
    auto tempNode = _node;
    for(int i =1; i < pos; ++i)
    {
        tempNode = tempNode->_next;
    }
    newNode->_next = tempNode->_next;
    tempNode->_next = newNode;
    newNode->_prev = tempNode;
    tempNode->_next = newNode;
    _size++;
    
    
}

template<typename T>
void TwoForwardList<T>::erase(size_t pos)
{
    if(pos == 0)
    {
        _node = _node->_next;
        --_size;
        return;
    }
    auto tempNode = _node;
    for(int i = 1; i < pos; ++i)
        tempNode = tempNode->_next;
    tempNode->_next = tempNode->_next->_next;
    tempNode->_prev = tempNode;
    --_size;
}


template<typename T>
typename TwoForwardList<T>::iter TwoForwardList<T>::begin()
{
    return iter(_node.get());
}

template<typename T>
typename TwoForwardList<T>::iter TwoForwardList<T>::end()
{
    auto tempNode = _node;
    for(int i = 0; i < _size;++i)
        tempNode = tempNode->_next;
    return iter(tempNode.get());
}


}