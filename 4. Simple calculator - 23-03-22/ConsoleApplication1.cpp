// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using db = double;

db getValue()
{
	while (true)
	{
		db value;
		std::cout << "Enter a double value: ";
		std::cin >> value;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "You should enter a double value!\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return value;
		}
	}
}

char getOperator()
{
	while (true)
	{
		char sign;
		std::cout << "Choose one of the following operators (+, -, * or /): ";
		std::cin >> sign;
		std::cin.ignore(32767, '\n');

		if ((sign == '+') || (sign == '-') || (sign == '*') || (sign == '/'))
		{
			return sign;
		}
		else
		{
			std::cout << "Oops, something went wrong.\n";
		}
	}
}

void Calculate(db a, char sign, db b)
{
	switch (sign)
	{
	case '+':
		std::cout << a << " " << sign << " " << b << " = " << a + b << std::endl;
		break;
	case '-':
		std::cout << a << " " << sign << " " << b << " = " << a - b << std::endl;
		break;
	case '*':
		std::cout << a << " " << sign << " " << b << " = " << a * b << std::endl;
		break;
	case '/':
		std::cout << a << " " << sign << " " << b << " = " << a / b << std::endl;
		break;
	default:
		std::cout << "Oops, something went wrong.\n";
		break;
	}
}

int main()
{
	std::cout << "Would you start this calculator: ";
	std::cout << "\n1. Yes";
	std::cout << "\n2. No";
	std::cout << "\nEnter: ";
	int decision;
	std::cin >> decision;

	while (decision == 1)
	{
		db a = getValue();
		char sign = getOperator();
		db b = getValue();

		Calculate(a, sign, b);

		std::cout << "It was calculated.";
		std::cout << "\n\nWould you restart this calculator: ";
		std::cout << "\n1. Yes";
		std::cout << "\n2. No ";
		std::cout << "\nEnter: ";
		int decision;
		std::cin >> decision;

		if (decision == 2)
		{
			break;
		}
	}

	std::cout << "You stopped calculator.";
}
