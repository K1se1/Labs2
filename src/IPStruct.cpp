#include "IPStruct.hpp"
#include<iostream>


// Правило пяти

IPStruct::IPStruct()
{
    _IP = std::make_unique<short[]>(4);
    for(int i = 0; i < 4; ++i)
        _IP[i] = -1;
}

IPStruct::IPStruct(IPStruct&& IP)
{
    if(this == &IP) return; // проверка на самоприсвоение
    this->_IP = std::move(IP._IP);
    IP._IP = nullptr;
}

IPStruct& IPStruct::operator=(IPStruct&& IP)
{    
    if(this == &IP) return *this; // проверка на самоприсвоение
    this->_IP = std::move(IP._IP);
    IP._IP = nullptr;
    return *this;
}

IPStruct::IPStruct(const IPStruct& IP)
{
    _IP = std::make_unique<short[]>(4);
    for(int i =0; i < 4; ++i)
        _IP[i] = IP._IP[i];
}

IPStruct& IPStruct::operator=(const IPStruct& IP)
{
    for(int i =0; i < 4; ++i)
        _IP[i] = IP._IP[i];
    return *this; 
}

// Так как используется unique_ptr - дополнительное удаление не нужно

short& IPStruct::operator[](unsigned short i) const
{
    return _IP[i];
}

bool operator<(const IPStruct& lIP,  const IPStruct& rIP)
{
    for(int i =0; i< 4; ++i)
    {
        if(lIP[i] < rIP[i]) return true;
        else if(lIP[i] > rIP[i]) return false;
    }
    return false;
}



bool IPStruct::operator==(const IPStruct& rIP) const
{
    for(int i = 0; i <4; ++i)
        if(_IP[i] != rIP[i]) return false;
    return true; 
}

std::ostream& operator<<(std::ostream& os, const IPStruct& IP) 
{
    return (os << IP[0] << "." << IP[1] << "." << IP[2] << "." << IP[3]); 
}