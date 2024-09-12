#pragma once
#include<initializer_list>
#include<memory>

namespace Containers
{
template<typename T>
class Array
{
    private:
        std::unique_ptr<T[]> _Arr;
        size_t _size;
        size_t _capacity;
        const double _capRatio = 2;
    public:
        //Basic
        Array();
        Array(size_t);
        Array(std::initializer_list<T>);
        //Copy
        Array(const Array<T>&);
        Array<T>& operator=(const Array<T>&);
        // Move
        Array(Array&&);
        Array<T>& operator=(Array<T>&&);
        inline size_t size() const;
        inline size_t capacity() const;
        T& operator[](size_t) const;
        void pushBack(const T&);
        void pushBack(T&&);
        void insert(size_t, const T&);
        void insert(size_t, T&&);
        void erase(size_t);
};

template<typename T>
Array<T>::Array(size_t size)
{
    _size = size;
    if(_size == 0) _capacity =1;
    else _capacity = _size*_capRatio;
    _Arr = std::make_unique<T[]>(_size);
    for(int i = 0; i < _size; ++i)
        _Arr[i] = 0;
}

template<typename T>
Array<T>::Array(): Array<T>(0) {}

template<typename T>
Array<T>::Array(std::initializer_list<T> data)
{
    size_t i =0;
    _size = data.size();
    if(_size == 0) _capacity =1;
    else _capacity = _size*_capRatio;
    _Arr = std::make_unique<T[]>(_capacity);
    for(const auto& chunk:data)
    {
        _Arr[i] = chunk;
        ++i;
    }
}

template<typename T>
Array<T>::Array(const Array<T>& newArr)
{
    _size = newArr._size;
    _capacity = newArr._capacity;
    _Arr = std::make_unique<T[]>(_capacity);
    for(int i = 0; i < _size; ++i)
        _Arr[i] = newArr._Arr[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& newArr)
{
    _size = newArr._size;
    _capacity = newArr._capacity;
    _Arr = std::make_unique<T[]>(_capacity);
    for(int i = 0; i < _size; ++i)
        _Arr[i] = newArr._Arr[i];
    return *this;
}

template<typename T>
Array<T>::Array(Array&& newArr)
{
    _Arr = std::move(newArr._Arr);
    _size = newArr._size;
    _capacity = newArr._capacity;
    newArr._size = 0;
    newArr._capacity = 0;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& newArr)
{
    _Arr = std::move(newArr._Arr);
    _size = newArr._size;
    _capacity = newArr._capacity;
    newArr._size = 0;
    newArr._capacity = 0;
    return *this;
}

template <typename T>
size_t Array<T>::size() const {return _size;}

template<typename T>
size_t Array<T>::capacity() const {return _capacity;}

template<typename T>
T& Array<T>::operator[](size_t i) const
{
    if(i >= _size) throw std::range_error("Array: operator[] Range error");
    return _Arr[i];
}

template<typename T>
void Array<T>::pushBack(T&& elem)
{
    if(_size == _capacity) // Если размер массива уже равен вместимости, перевыделяем память, умножаем вместимость на коэффицент
    {
        _capacity*=_capRatio;
        auto tempArr = std::move(_Arr);
        _Arr = std::make_unique<T[]>(_capacity);
        for(int i =0; i<_size; ++i)
            _Arr[i] = tempArr[i];
    }
    _Arr[_size] = std::move(elem);
    ++_size;
}

/// @brief Пуш-бэк с копированием, работает так странно(через перемещаемый пуш-бэк), чтобы не было копипаста
/// @tparam T Тип элемента
/// @param elem Элемент, который нужно добавить
template<typename T>
void Array<T>::pushBack(const T& elem)
{
    auto tempElem = elem;
    this->pushBack(std::move(tempElem));
}


template<typename T>
void Array<T>::insert(size_t i, T&& elem)
{
    if(i>= _size) throw std::range_error("Array: insert Range error");
    if(_size == _capacity) _capacity*=_capRatio;
    auto tempArr = std::move(_Arr);
    _Arr = std::make_unique<T[]>(_capacity);
    for(int j =0; j < i; ++j)
        _Arr[j] = tempArr[j];
    _Arr[i] = std::move(elem);
    for(int j = i+1; j < _size+1; ++j)
        _Arr[j] = tempArr[j-1];
    ++_size;

}

template<typename T>
void Array<T>::insert(size_t i, const T& elem)
{
    if(i>= _size) throw std::range_error("Array: insert Range error");
    auto tempElem = std::move(elem);
    this->insert(i, std::move(tempElem));
}

template<typename T>
void Array<T>::erase(size_t i)
{
    if(i>= _size) throw std::range_error("Array: erase Range error");
    for(int j = i; j < _size-1; ++j)
        _Arr[j] = std::move(_Arr[j+1]);
    --_size;
}

}