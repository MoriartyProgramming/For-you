#include <iostream>
#include <string>
#include <conio.h>

void colorSetting()
{
	system("cls");
	char command;
	
	do
	{
		int indexToExecute = 0;
		const int allARR = 15;
		std::string arr[allARR] = {
		"o 1. Dark blue\n",
		"  2. Green\n",
		"  3. Blue\n",
		"  4. Red\n",
		"  5. Pink\n",
		"  6. Yellow\n",
		"  7. White\n",
		"  8. Grey\n",
		"  9. Violet\n",
		"  10. Light green\n",
		"  11. Cyan\n",
		"  12. Light red\n",
		"  13. Light pink\n",
		"  14. Ligth yellow\n",
		"  15. Light white\n",
		};

		do
		{
			std::cout << "\nSet color:\n\n";
			for (int i = 0; i < allARR; i++)
			{
				std::cout << arr[i];
			}

			std::cout << "\n\nTips:\n";
			std::cout << "  w - up\n";
			std::cout << "  s - down\n";
			std::cout << "  c - confirm\n";
			std::cout << "  r - return to menu\n";

			do
			{
				command = _getch();
				if (command == 'w' || command == 's' || command == 'c')
				{
					break;
				}
				else if (command == 'r')
				{
					return;
				}

			} while (true);

			for (int i = 0; i < allARR; i++)
			{
				if (arr[i].at(0) == 'o')
				{
					if (arr[i].at(2) == '1' and arr[i].at(3) == '.' and command == 'w')
					{
						break;
					}
					else if (arr[i].at(3) == '5' and command == 's')
					{
						break;
					}

					arr[i].at(0) = ' ';
					if (command == 'w')
					{
						arr[i - 1].at(0) = 'o';
						indexToExecute = i - 1;
						break;
					}
					else if (command == 's')
					{
						arr[i + 1].at(0) = 'o';
						indexToExecute = i + 1;
						break;
					}
				}
			}

			system("cls");

		} while (command != 'c');

		std::string executable = arr[indexToExecute];

		switch (executable.at(2))
		{
		case '1':
			if (executable.at(3) == '.')
			{
				system("color 1");
			}
			else if (executable.at(3) == '0')
			{
				system("color A");
			}
			else if (executable.at(3) == '1')
			{
				system("color B");
			}
			else if (executable.at(3) == '2')
			{
				system("color C");
			}
			else if (executable.at(3) == '3')
			{
				system("color D");
			}
			else if (executable.at(3) == '4')
			{
				system("color E");
			}
			else if (executable.at(3) == '5')
			{
				system("color F");
			}
			break;
		case '2':
			system("color 2");
			break;
		case '3':
			system("color 3");
			break;
		case '4':
			system("color 4");
			break;
		case '5':
			system("color 5");
			break;
		case '6':
			system("color 6");
			break;
		case '7':
			system("color 7");
			break;
		case '8':
			system("color 8");
			break;
		case '9':
			system("color 9");
			break;
		}
	} while (command == 'c');
} 