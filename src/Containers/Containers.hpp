#pragma once
// Заголовочный файл с объявлением всех классов, для избежания проблем классов отсылающихся друг на друга

namespace Containers
{


template<typename T>
class Array;

template<typename T>
class OneForwardList;

template<typename T>
class TwoForwardList;


namespace Nodes
{
    template<typename T>
    class OneForwardNode;
    template<typename T>
    class TwoForwardNode;
}

namespace Iters
{
    template<typename T>
    class ArrayIter;
    template<typename T>
    class OneForwardListIter;
    template<typename T>
    class TwoForwardListIter;
}

}