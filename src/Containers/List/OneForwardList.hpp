#pragma once
#include "../Containers.hpp"
#include "OneForwardNode.hpp"
#include<memory>
#include<initializer_list>
namespace Containers
{


template<typename T>
class OneForwardList
{
    private:
        std::shared_ptr<Nodes::OneForwardNode<T>> _node;
        size_t _size;
    public:
        OneForwardList();
        OneForwardList(size_t);
        OneForwardList(const std::initializer_list<T>&);
        OneForwardList(const T&);
        OneForwardList(T&&);
        OneForwardList(const OneForwardList<T>&);
        OneForwardList(OneForwardList<T>&&);
        OneForwardList<T>& operator=(const OneForwardList<T>&);
        OneForwardList<T>& operator=(OneForwardList<T>&&);
        inline size_t size() const;
        T& operator[](size_t);
        const T& operator[](size_t) const;
        void push_back(const T&);
        void insert(size_t, const T&);
        void erase(size_t);
};


template<typename T>
OneForwardList<T>::OneForwardList(): _node(std::make_shared<Nodes::OneForwardNode<T>>()), _size(0)
{
}

template<typename T>
OneForwardList<T>::OneForwardList(size_t size)
{
    _node =std::make_shared<Nodes::OneForwardNode<T>>();
    _size = size;
    auto tempNode = _node._next;
    for(size_t i =1; i < _size; ++i)
    {
        tempNode = std::make_shared<Nodes::OneForwardNode<T>>();
        tempNode = tempNode->_next;
    }
}

template<typename T>
OneForwardList<T>::OneForwardList(const std::initializer_list<T>& list)
{
    _node =std::make_shared<Nodes::OneForwardNode<T>>();
    auto listIter = list.begin();
    _size = list.size();
    _node->_data = *listIter;
    auto tempNode = (_node->_next = std::make_shared<Nodes::OneForwardNode<T>>());
    for(size_t i =1; i < _size; ++i)
    {   

        tempNode->_data = *(listIter+i);
        tempNode = (tempNode->_next = std::make_shared<Nodes::OneForwardNode<T>>());
    }
}

template<typename T>
OneForwardList<T>::OneForwardList(const T& value): _size(1), _node(value)
{
}

template<typename T>
OneForwardList<T>::OneForwardList(T&& value): _size(1), _node(std::move(value))
{
}


template<typename T>
OneForwardList<T>& OneForwardList<T>::operator=(const OneForwardList<T>& list)
{
    _size = list._size;
    _node._data = list[0];
    auto tempNode = (_node._next = std::make_shared<Nodes::OneForwardNode<T>>());
    for(size_t i =1; i < _size; ++i)
    {   

        tempNode->_data = list[i];
        tempNode = (tempNode->_next = std::make_shared<Nodes::OneForwardNode<T>>());
    }
    return *this;

}

template<typename T>
OneForwardList<T>& OneForwardList<T>::operator=(OneForwardList<T>&& list)
{
    _size = std::move(list._size);
    _node = std::move(list._node);
    return *this;
}

template<typename T>
OneForwardList<T>::OneForwardList(const OneForwardList<T>& list)
{
    _size = list._size;
    _node._data = list[0];
    auto tempNode = (_node._next = std::make_shared<Nodes::OneForwardNode<T>>());
    for(size_t i =1; i < _size; ++i)
    {   

        tempNode->_data = list[i];
        tempNode = (tempNode->_next = std::make_shared<Nodes::OneForwardNode<T>>());\
    }
}

template<typename T>
OneForwardList<T>::OneForwardList(OneForwardList<T>&& list)
{
    _size = std::move(list._size);
    _node = std::move(list._node);
}


template<typename T>
T& OneForwardList<T>::operator[](size_t i) 
{
    if(i >= _size ) throw std::range_error("List: operator[] Range error");
    if(i == 0) return _node->_data;
    auto tempNode = _node->_next;
    for(int j =1; j < i; ++j)
        tempNode = tempNode->_next;
    return tempNode->_data;

}

template<typename T>
const T& OneForwardList<T>::operator[](size_t i) const
{
    if(i >= _size ) throw std::range_error("List: operator[] Range error");
    if(i == 0) return _node._data;
    auto tempNode = _node._next;
    for(int j =1; j < i; ++j)
        auto tempNode = _node._next;
    return tempNode->_data;

}

template<typename T>
size_t OneForwardList<T>::size() const 
{
    return _size;
}

template<typename T>
void OneForwardList<T>::push_back(const T& elem)
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
    tempNode->_next = std::make_shared<Nodes::OneForwardNode<T>>(elem);
    ++_size;
}


template<typename T>
void OneForwardList<T>::insert(size_t pos, const T& elem)
{
    if(pos >=_size) throw std::range_error("List: operator[] Range error");
    auto newNode = std::make_shared<Nodes::OneForwardNode<T>>(elem);
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
    _size++;
    
    
}

template<typename T>
void OneForwardList<T>::erase(size_t pos)
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
    --_size;
}



}