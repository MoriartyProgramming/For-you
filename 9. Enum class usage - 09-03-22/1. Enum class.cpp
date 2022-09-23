// 1. Enum class.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

enum class Arms
{
    SWORD,
    BOW,
    SPEAR,
    HOOK,
    KNIFE,
    NONE
};

enum class Gender
{
    MALE,
    FEMALE
};

enum class Complexity
{
    VERY_EASY,
    EASY,
    NORMAL,
    HARD,
    INSANE,
    EXTREME
};

struct Hero
{
    std::string name;
    Arms arm;
    Gender gender;
    Complexity level;
};

std::string ret_arm(Hero you)
{
    if (you.arm == Arms::SWORD)
    {
        return "Sword";
    }
    if (you.arm == Arms::BOW)
    {
        return "Bow";
    }
    if (you.arm == Arms::SPEAR)
    {
        return "Spear";
    }
    if (you.arm == Arms::HOOK)
    {
        return "Hook";
    }
    if (you.arm == Arms::KNIFE)
    {
        return "Knife";
    }
    if (you.arm == Arms::NONE)
    {
        return "None";
    }
}

std::string ret_gender(Hero you)
{
    if (you.gender == Gender::MALE)
    {
        return "Male";
    }
    if (you.gender == Gender::FEMALE)
    {
        return "Female";
    }
}

std::string ret_complex(Hero you)
{
    if (you.level == Complexity::VERY_EASY)
    {
        return "Very easy";
    }
    if (you.level == Complexity::EASY)
    {
        return "Easy";
    }
    if (you.level == Complexity::NORMAL)
    {
        return "Normal";
    }
    if (you.level == Complexity::HARD)
    {
        return "Hard";
    }
    if (you.level == Complexity::INSANE)
    {
        return "Insane";
    }
    if (you.level == Complexity::EXTREME)
    {
        return "Extreme";
    }
}

void ret_data(Hero you)
{
    std::cout << "\n\aYour set";
    std::cout << "\nYour name: " << you.name;
    std::cout << "\nYour gender: " << ret_gender(you);
    std::cout << "\nYour arm: " << ret_arm(you);
    std::cout << "\nComplexity of the level: " << ret_complex(you);
}

int main()
{
    Hero you;
    std::cout << "Enter your name: ";
    std::cin >> you.name;
    you.arm = Arms::BOW;
    you.gender = Gender::MALE;
    you.level = Complexity::NORMAL;
    ret_data(you);
}
