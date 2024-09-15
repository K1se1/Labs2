#include <iostream>
#include<algorithm>
#include "Containers/Array/Array.hpp"
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

}
