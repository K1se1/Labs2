#pragma once
#include<string>
#include<vector>
#include<fstream>

/// @brief Класс для парсинга IP адресов
class IPParser
{
    public:
        /// @brief Функция, для парсинга IP адресов
        /// @tparam IPStruct Структура, хранящая в себе IP адрес(обязана иметь оператор []) 
        /// @param filePath Путь до файла, который нужно спарсить
        /// @param IPBuffer Контейнер, в который нужно поместить IP адрес
        template<typename IPStruct>
        static void parseFile(const std::string& filePath, std::vector<IPStruct>& IPBuffer);
};

template<typename IPStruct>
void IPParser::parseFile(const std::string& filePath, std::vector<IPStruct>& IPBuffer)
{
    std::vector<IPStruct> tempBuffer; // Временный буффер IP
    std::ifstream IPFile(filePath); // Файл, с IP
    std::string line; // Строка, которую мы парсим
    std::string IPNum; // Строка, с одной октетой IP адреса
    int i = 0; // Счетчик октет
    if(!IPFile.is_open()) throw std::runtime_error("Couldn't open file");
    while(std::getline(IPFile, line))
    {
        IPStruct ip; // Инициализируем ip, который мы будем заполнять
        IPNum = ""; 
        for(const auto& c: line)
        {
            if(std::isdigit(c))
                IPNum += c;
            else if(c == '.')
                {
                    ip[i] = std::stoi(IPNum); // записываем октет в структуру
                    IPNum = ""; // Очищаем строчку октета
                    i++; // Переходим к следующему октету
                }
            else // Если символ и не число, и не точка, то IP адрес закончен
            {                
                ip[i] = std::stoi(IPNum); // записываем октет в структуру
                break;
            }

        }
        i =0;
        tempBuffer.push_back(std::move(ip)); // Перемещаем IP адрес во временный буффер
    }
    IPBuffer = std::move(tempBuffer); // Перемещаем временный буффер в основной
}

