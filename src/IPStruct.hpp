#pragma once
#include<vector>
#include<memory>

/// @brief  Класс для хранения IP адресов
class IPStruct
{
    private:
        std::unique_ptr<short[]> _IP;
    public:
        IPStruct();
        IPStruct(IPStruct&&);
        IPStruct& operator=(IPStruct&&);
        IPStruct(const IPStruct&);
        IPStruct& operator=(const IPStruct&);
        short& operator[](unsigned short) const;
        bool operator==(const IPStruct&) const;
        //P.S из-за использования unique_ptr не тривиальный деструктор не нужен
};

// оператор сравнения для использования в std::sort
bool operator<(const IPStruct& lIP,  const IPStruct& rIP);

// Для удобного вывода IP адресов
std::ostream& operator<<(std::ostream& os, const IPStruct& IP);