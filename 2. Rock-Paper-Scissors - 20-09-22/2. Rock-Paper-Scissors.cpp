// 2. Rock-Paper-Scissors.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <ctime>
#include <conio.h>
#include <algorithm>

enum class SymbolsEnum
{
    Rock = 1,
    Paper,
    Scissors
};

struct symbols 
{
    SymbolsEnum enumeration;
    std::string text;
};

int setVariant();

int getVariant();

int computersVariant();

symbols* setKeyword(symbols* keywords, int value);

int checkWinner(symbols* usersValue, symbols* computersValue);

void setWinner(symbols* usersValue, symbols* computersValue, int result);

void game(symbols* gameKeywords);

void entryMenu();

void checkValueEntryMenu(int value);

void howToPlay();

void settings();

bool checkYN();

int main()
{
    srand(time(NULL));

    symbols gameKeywords[3]{
        {SymbolsEnum::Rock, "ROCK"},
        {SymbolsEnum::Paper, "PAPER"},
        {SymbolsEnum::Scissors, "SCISSORS"}
    };

    game(gameKeywords);

    std::cout << "\a\n\t\t\t\t\t\tThanks for playing!" << std::endl;

    system("pause");
}

int getVariant() 
{
    int value;
    do
    {
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nValue must be a digit!\n";
            std::cout << "Enter a digit: ";
        }
        else if (value < 1 || value > 3)
        {
            std::cin.ignore(32767, '\n');
            std::cout << "\nEntered value must be less than 4 and more than 0.\n";
            std::cout << "Enter a digit less than 4 and more than 0: ";
        }
        else
        {
            return value;
        }
    } while (true);
}

int setVariant() {

    std::cout << "\t\t\t\t\t\tRock-Paper-Scissors" << std::endl;
    std::cout << "\nSelect one of them: \n";
    std::cout << "1. Rock\n";
    std::cout << "2. Paper\n";
    std::cout << "3. Scissors\n";
    std::cout << "Enter a digit: ";

    int value = getVariant();

    return value;
}

int computersVariant()
{
    return rand() % 3 + 1;
}

symbols* setKeyword(symbols* keywords, int value)
{
    symbols* keywd = new symbols;

    for (int i = 0; i < 3; i++)
    {
        if (static_cast<int>(keywords[i].enumeration) == value)
        {
            keywd->enumeration = keywords[i].enumeration;
            keywd->text = keywords[i].text;
        }
    }

    return keywd;
}

int checkWinner(symbols* usersValue, symbols* computersValue)
{
    int a = static_cast<int>(usersValue->enumeration);
    int b = static_cast<int>(computersValue->enumeration);
    if (abs(a - b) == 1)
    {
        return a > b; // if b more than a, computer win, in another case - user win
    }
    else if (abs(a - b) == 0)
    {
        return 2; // draw
    }
    else
    {
        return !(a > b); // if one of them is rock and another are scissors
    }
}

void setWinner(symbols* usersValue, symbols* computersValue, int result)
{
    if (result == 0)
    {
        std::cout << "\nYou lose...\n";
        std::cout << computersValue->text << " win " << usersValue->text;
    }
    else if (result == 1)
    {
        std::cout << "\nYou win!\n";
        std::cout << usersValue->text << " win " << computersValue->text;
    }
    else
    {
        std::cout << "\nDraw";
    }
}

void entryMenu()
{
    std::cout << "\t\t\t\t\t\tWelcome to Rock-Paper-Scissors" << std::endl;
    std::cout << "\nSelect one of this options:" << std::endl;
    std::cout << "1. Play" << std::endl;
    std::cout << "2. How to play" << std::endl;
    std::cout << "3. Settings" << std::endl;
    std::cout << "Enter a digit: ";

    int value = getVariant();

    system("cls");

    checkValueEntryMenu(value);
}

void howToPlay()
{
    std::cout << "\t\t\t\t\t\tHow to play" << std::endl;
    std::cout << "\nRules to play it are pretty simple. \nThe game is played where players deliver hand signals that will represent the elements of the game; rock, paperand scissors. \nThe outcome of the game is determined by 3 simple rules :" << std::endl;
    std::cout << "Rock wins against scissors." << std::endl;
    std::cout << "Scissors win against paper." << std::endl;
    std::cout << "Paper wins against rock." << std::endl;

    std::cout << "Any value to exit: ";
    _getch();

    system("cls");
}

void settings()
{
    std::cout << "\t\t\t\t\t\tSettings" << std::endl;
    std::cout << "\nSelect one of this options:" << std::endl;
    std::cout << "Color:" << std::endl;
    std::cout << "1. Green" << std::endl;
    std::cout << "2. Red" << std::endl;
    std::cout << "3. White" << std::endl;
    std::cout << "Enter a digit: ";

    int value;
    std::cin >> value;

    if (value == 1)
    {
        system("color 2");
    }
    else if (value == 2)
    {
        system("color 4");
    }
    else
    {
        system("color 7");
    }

    std::cout << "Any value to exit: ";
    _getch();

    system("cls");
}

void checkValueEntryMenu(int value)
{
    if (value == 2)
    {
        howToPlay();
        entryMenu();
    }
    else if (value == 3)
    {
        settings();
        entryMenu();
    }
}

void game(symbols* gameKeywords)
{
    bool answer;
    entryMenu();

    do
    {
        system("cls");

        symbols* usersValue = setKeyword(gameKeywords, setVariant());
        symbols* computersValue = setKeyword(gameKeywords, computersVariant());

        std::cout << "\nUser: " << usersValue->text << std::endl;
        std::cout << "Computer: " << computersValue->text << std::endl;

        setWinner(usersValue, computersValue, checkWinner(usersValue, computersValue));

        std::cout << "\n\nDo you want to play again (Y/N) ? ";
        answer = checkYN();

    } while (answer);
}

bool checkYN()
{
    std::string answer;
    
    do
    {
        std::cin >> answer;
        std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        if (answer == "y" || answer == "yes")
        {
            return true;
        }
        else if (answer == "n" || answer == "no")
        {
            return false;
        }
        else
        {
            std::cout << "Write one of the commands \"yes\" or \"no\": ";
        }
    } while (true);
}