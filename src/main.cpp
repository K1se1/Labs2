#include <iostream>
#include<algorithm>
#include "Containers/Array/Array.hpp"
#include"Containers/List/OneForwardList.hpp"
#include"Containers/List/TwoForwardList.hpp"
int main(int, char**){
    Containers::Array<int> a = {1, 2, 3 ,4, 5, 6, 7, 8};
    for(int i =0; i < a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << "\n";
    a.insert(7, 10);
    for(int i =0; i < a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << "\n";
    a.erase(0);
    std::for_each(a.begin(), a.end(), [](auto& num){std::cout << num << " ";});
    std::cout << "\n\n";
    Containers::OneForwardList<int> list = {1, 2, 3, 4};
    for(int i = 0; i< list.size(); ++i)
        std::cout << list[i] <<" ";
    std::cout << "\n";
    list.push_back(10);
    list.erase(0);
    for(int i = 0; i< list.size(); ++i)
        std::cout << list[i] <<" ";
    std::cout << "\n";
    std::for_each(list.begin(), list.end(), [](auto& num){std::cout << num << " ";});
    Containers::TwoForwardList<int> listt = {1, 2, 3, 4};
    listt.erase(0);
    std::cout << "\n";
    std::for_each(listt.begin(), listt.end(), [](auto& num){std::cout << num << " ";});
    
}
