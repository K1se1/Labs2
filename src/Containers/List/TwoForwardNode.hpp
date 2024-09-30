#pragma once
#include "../Containers.hpp"
#include<memory>

namespace Containers
{
namespace Nodes
{


template<typename T>
class TwoForwardNode
{
    public:
        TwoForwardNode();
        TwoForwardNode(const T&);
        TwoForwardNode(T&&);
        TwoForwardNode(const TwoForwardNode&) = delete; // Конструктор и оператор копирования создадут очень много проблем здесь
        TwoForwardNode(TwoForwardNode&&);
        TwoForwardNode& operator=(const TwoForwardNode&) = delete;
        TwoForwardNode& operator=(TwoForwardNode&&);
    public:
        std::shared_ptr<TwoForwardNode> _prev;
        std::shared_ptr<TwoForwardNode> _next;
        T _data;
        

};

template<typename T>
TwoForwardNode<T>::TwoForwardNode(): _next(nullptr), _prev(nullptr), _data() 
{
}

template<typename T>
TwoForwardNode<T>::TwoForwardNode(const T& data): _next(nullptr), _prev(nullptr), _data(data)
{
}

template<typename T>
TwoForwardNode<T>::TwoForwardNode(T&& data): _next(nullptr), _prev(nullptr), _data(std::move(data))
{
}


template<typename T>
TwoForwardNode<T>::TwoForwardNode(TwoForwardNode<T>&& Node)
{
    _data = std::move(Node._data);
    _next = std::move(Node._next);
    _prev = std::move(Node._prev);
}

template<typename T>
TwoForwardNode<T>& TwoForwardNode<T>::operator=(TwoForwardNode<T>&& Node)
{
    _data = std::move(Node._data);
    _next = std::move(Node._next);
    _prev = std::move(Node._prev);
    return *this;
}

}


}