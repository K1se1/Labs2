#pragma once
// Заголовочный файл с объявлением всех классов, для избежания проблем классов отсылающихся друг на друга

namespace Containers
{


template<typename T>
class Array;

template<typename T>
class OneForwardList;


namespace Nodes
{
    template<typename T>
    class OneForwardNode;
}

namespace Iters
{
    template<typename T>
    class ArrayIter;
}

}