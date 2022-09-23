// Guess the number.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int guess, randomNumber, tries=0;
	bool play = true;

	cout << "\t\t\t\tWelcome to Guess My Number";
	srand(time(0));
	randomNumber = (rand() % 100) + 1;

	while (play == true)
	{
		cout << "\n\nEnter a guess: ";
		cin >> guess;
		tries++;
		if (guess == randomNumber)
		{
			cout << "That\'s it! You got it in " << tries << " guesses!";
			play = false;
		}
		else if (guess > randomNumber)
		{
			cout << "Too high!";
			play = true;
		}
		else if (guess < randomNumber)
		{
			cout << "Too low!";
			play = true;
		}
		
	}
}

