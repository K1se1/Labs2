#include <iostream>
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
    for(int i =0; i < a.size(); ++i)
        std::cout << a[i] << " ";

}
