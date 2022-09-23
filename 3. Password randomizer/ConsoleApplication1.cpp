// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>

int main()
{
    std::random_device random;
    std::mt19937 rand(random());

    int length;
    length = rand() % 13 + 8;
    char* pass = new char[length];

    char allSymbols[]{ "1234567890qwertyuiopasdfghjklzxcvbnmMNBVCXZLKJHGFDSAPOIUYTREWQ1234567890qwertyuiopasdfghjklzxcvbnmMNBVCXZLKJHGFDSAPOIUYTREWQ._.!@#$%^&*()_/-+={[}]|:;" };

    for (int i = 0; i < length - 1; i++)
    {
        int randomSymbol = rand() % 150;
        pass[i] = allSymbols[randomSymbol];
    }

    pass[length - 1] = '\0';

    std::cout << pass;
}
