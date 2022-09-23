// Colector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Randomize.h"
#include <conio.h>

bool looseCheck(char polygon[20][30]);

int main()
{
    char polygon[20][30];
	int score = 0;
	char fruit = 'o';

	// Polygon generation
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (((i == 0) || (i == 19)) || ((j == 0) || (j == 29)))
			{
				polygon[i][j] = '#';
			}
			else
			{
				polygon[i][j] = ' ';
			}
		}
	}

	// Hero generation
	int placeY = randomize(16);
	int placeX = randomize(26);
	polygon[placeY][placeX] = '%';

	// Iterator for first fruit generation
	bool b = true;

	// Game stop
	bool game = true;

	while (game)
	{
		// Initial fruit generation
		while (b)
		{
			int posFruitX = randomize(26);
			int posFruitY = randomize(16);

			if (polygon[posFruitX][posFruitY] == ' ')
			{
				polygon[posFruitX][posFruitY] = fruit;
				b = false;
				break;
			}
		}

		// Polygon display
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				std::cout << polygon[i][j];
			}
			std::cout << std::endl;
		}

		// Statistics
		{
			std::cout << "Score: " << score;
			char step = _getch();

			if (step == 'w')
			{
				polygon[placeY--][placeX] = ' ';
				polygon[placeY][placeX] = '%';
				//mode--;
			}
			else if (step == 'a')
			{
				polygon[placeY][placeX--] = ' ';
				polygon[placeY][placeX] = '%';
				//mode--;
			}
			else if (step == 's')
			{
				polygon[placeY++][placeX] = ' ';
				polygon[placeY][placeX] = '%';
				//mode--;
			}
			else if (step == 'd')
			{
				polygon[placeY][placeX++] = ' ';
				polygon[placeY][placeX] = '%';
				//mode--;
			}
		}

		// Score checking
		{
			bool fruitAbsent = true;
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					// Check presention of the fruit
					if (polygon[i][j] == fruit)
					{
						fruitAbsent = false;
					}
				}
			}
			if (fruitAbsent)
			{
				score++;
			}
		}

		// Fruit REgeneration
		{
			bool fruitPresention = false;
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					// Check presention of the fruit
					if (polygon[i][j] == fruit)
					{
						fruitPresention = true;
					}
				}
			}

			// Fruit regeneration
			if (!(fruitPresention))
			{
				while (true)
				{
					int posFruitX = randomize(26);
					int posFruitY = randomize(16);

					if (polygon[posFruitX][posFruitY] == ' ')
					{
						polygon[posFruitX][posFruitY] = fruit;
						break;
					}
				}
			}
		}

		system("cls");

		// Condition to stop principal while
		game = looseCheck(polygon);
	}

	if (!(game))
	{
		std::cout << "You losed!\n";
		std::cout << "You scored " << score << " points!\n";
	}
}


bool looseCheck(char polygon[20][30])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (((i == 0) || (i == 19)) || ((j == 0) || (j == 29)))
			{
				if (!(polygon[i][j] == '#'))
				{
					return false;
				}
			}
		}
	}
}
