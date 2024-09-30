#pragma once
#include "../Containers.hpp"
#include<memory>

namespace Containers
{
namespace Nodes
{


template<typename T>
class OneForwardNode
{
    public:
        OneForwardNode();
        OneForwardNode(const T&);
        OneForwardNode(T&&);
        OneForwardNode(const OneForwardNode&) = delete; // Конструктор и оператор копирования создадут очень много проблем здесь
        OneForwardNode(OneForwardNode&&);
        OneForwardNode& operator=(const OneForwardNode&) = delete;
        OneForwardNode& operator=(OneForwardNode&&);
    public:
        std::shared_ptr<OneForwardNode> _next;
        T _data;
        

};

template<typename T>
OneForwardNode<T>::OneForwardNode(): _next(nullptr), _data() 
{
}

template<typename T>
OneForwardNode<T>::OneForwardNode(const T& data): _next(nullptr), _data(data)
{
}

template<typename T>
OneForwardNode<T>::OneForwardNode(T&& data): _next(nullptr), _data(std::move(data))
{
}


template<typename T>
OneForwardNode<T>::OneForwardNode(OneForwardNode<T>&& Node)
{
    _data = std::move(Node._data);
    _next = std::move(Node._next);
}

template<typename T>
OneForwardNode<T>& OneForwardNode<T>::operator=(OneForwardNode<T>&& Node)
{
    _data = std::move(Node._data);
    _next = std::move(Node._next);
    return *this;
}

}


}