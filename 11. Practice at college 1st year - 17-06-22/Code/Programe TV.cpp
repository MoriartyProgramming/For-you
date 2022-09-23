// Programe TV.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <vector>
#include "Struct_definer.h"
#include <conio.h>
#include <iomanip>
#include "GetData.h"
#include "ShowData.h"
#include "AddData.h"
#include "DelAndRefresh.h"
#include "Difuzion_Parameters.h"

//int getNum();
void colorSetting();
std::string menu(std::vector<Channels>& channels, std::vector<Shows>& shows, std::vector<Difuzion>& difuzions, int& lengthShows, int& lengthChannels, int& lengthDifuzions);
void execute(std::vector<Channels>& channels, std::vector<Shows>& shows, std::vector<Difuzion>& difuzions, int& lengthShows, int& lengthChannels, int& lengthDifuzions, std::string executable);

int main()
{
	std::cout << "Nr emisiuni: ";
	int lengthShows = 50;
	std::vector <Shows> show;
	   
	std::cout << "Nr canale: ";
	int lengthChannels = 50;
	std::vector <Channels> channel;

	std::cout << "Nr difuziuni: ";
	int lengthDifuzions = 50;
	std::vector <Difuzion> difuzion;

	show.resize(lengthShows);
	channel.resize(lengthChannels);
	difuzion.resize(lengthDifuzions);

	get::getDataShow(show);
	get::getDataChannel(channel);
	get::getDataDifuzion(difuzion, channel);


	std::cout << menu(channel, show, difuzion, lengthChannels, lengthShows, lengthDifuzions);

	system("pause");
}

//int getNum()
//{
//	int num;
//	do
//	{
//		std::cin >> num;
//		if (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(32767, '\n');
//			std::cout << "Fail: character instead of number!";
//			std::cout << "\nEnter a number: ";
//		}
//		else
//		{
//			std::cin.ignore(32767, '\n');
//			std::cout << "\n";
//			return num;
//		}
//	} while (true);
//}

std::string menu(std::vector<Channels>& channels, std::vector<Shows>& shows, std::vector<Difuzion>& difuzions, int& lengthShows, int& lengthChannels, int& lengthDifuzions)
{
	char command = 'r';

	do
	{
		system("cls");
		int indexToExecute = 0;
		const int allARR = 16;
		std::string arr[allARR] = {
		"o 1. Afiseaza la eran informatia din fisierul \"Emisiuni.txt\"\n",
		"  2. Afiseaza la eran informatia din fisierul \"Canal.txt\"\n",
		"  3. Inregistreaza o emisiune noua\n",
		"  4. Inregistreaza un canal nou\n",
		"  5. Afiseaza Emisiunile in fisierul \"Afisare.txt\"\n",
		"  6. Afiseaza Canalurile in fisierul \"Afisare.txt\"\n",
		"  7. Exclude o emisiune\n",
		"  8. Exclude un canal\n",
		"  9. Actualizeaza datele unei emisiuni\n",
		"  10. Actualizeaza datele unui canal\n",
		"  11. Afiseaza la eran informatia din fisierul \"Difuziune.txt\"\n",
		"  12. Afiseaza Difuzarile in fisierul \"Afisare.txt\"\n",
		"  13. Afiseaza emisiunile cu durata maxima de difuzare\n",
		"  14. Afiseaza emisiunile cu durata minima de difuzare\n",
		"  15. Afiseaza numarul emisiunilor per canal dupa tipul emisiunii\n",
		"  16. Afiseaza cea mai solicitata emisiune\n"
		};

		do
		{
			std::cout << "\nMENU:\n\n";
			for (int i = 0; i < allARR; i++)
			{
				std::cout << arr[i];
			}

			std::cout << "\n\nTips:\n";
			std::cout << "  w - up\n";
			std::cout << "  s - down\n";
			std::cout << "  c - confirm\n";
			std::cout << "  e - exit\n";
			std::cout << "  # - set color system\n";

			do
			{
				command = _getch();
				if (command == 'r' || command == 'w' || command == 's' || command == 'c' || command == '#')
				{
					break;
				}
				else if (command == 'e')
				{
					return "\nProcess terminated\n\n";
				}

			} while (true);

			if (command == '#')
			{
				colorSetting();
				continue;
			}

			for (int i = 0; i < allARR; i++)
			{
				if (arr[i].at(0) == 'o')
				{
					if (arr[i].at(2) == '1' and arr[i].at(3) == '.' and command == 'w')
					{
						break;
					}
					else if (arr[i].at(3) == '6' and command == 's')
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
		std::cout << executable;

		execute(channels, shows, difuzions, lengthChannels, lengthShows, lengthDifuzions, executable);

		std::cout << "\n\ne - exit\n";
		std::cout << "r - return to menu\n";
		do
		{
			command = _getch();

			if (command == 'r')
			{
				break;
			}
			else if (command == 'e')
			{
				break;
			}
		} while (true);

		if (command == 'e')
		{
			return "\nProcess terminated\n\n";
		}

	} while (command == 'r');
	
}

void execute(std::vector<Channels>& channels, std::vector<Shows>& shows, std::vector<Difuzion>& difuzions, int& lengthShows, int& lengthChannels, int& lengthDifuzions, std::string executable)
{
	switch (executable.at(2))
	{
	case '1':
		if (executable.at(3) == '.')
		{
			shows.resize(lengthShows);
			show::showDataShow(shows);
		}
		else if (executable.at(3) == '0')
		{
			refresh::refreshDataChannel(channels);
			channels.resize(lengthChannels);
			std::cout << "\nData was refreshed\n";
			show::showDataChannel(channels);
		}
		else if (executable.at(3) == '1')
		{
			show::showDataDifuzion(difuzions);
		}
		else if (executable.at(3) == '2')
		{
			afis::copyToShowDataDifuzion(difuzions);
			std::cout << "\nSuccesful operation, data will be imported to file\n";
		}
		else if (executable.at(3) == '3')
		{
			difuzion::maxTimeDifuzion(difuzions);
		}
		else if (executable.at(3) == '4')
		{
			difuzion::minTimeDifuzion(difuzions);
		}
		else if (executable.at(3) == '5')
		{
			difuzion::numOfShowsPerChannel(difuzions);
		}
		else if (executable.at(3) == '6')
		{
			difuzion::mostPopularShow(difuzions);
		}
		break;
	case '2':
		channels.resize(lengthChannels);
		show::showDataChannel(channels);
		break;
	case '3':
		shows.resize(++lengthShows);
		add::addDataShow(shows);
		std::wcout << "\nElement succesful added\n";
		show::showDataShow(shows);
		break;
	case '4':
		channels.resize(++lengthChannels);
		add::addDataChannel(channels);
		std::wcout << "\nElement succesful added\n";
		show::showDataChannel(channels);
		break;
	case '5':
		shows.resize(lengthShows);
		afis::copyToShowDataShow(shows);
		std::cout << "\nSuccesful operation, data will be imported to file\n";
		break;
	case '6':
		channels.resize(lengthChannels);
		afis::copyToShowDataChannel(channels);
		std::cout << "\nSuccesful operation, data will be imported to file\n";
		break;
	case '7':
		del::delShow(shows);
		shows.resize(--lengthShows);
		std::cout << "\nSuccesful excluded one element from \"Emisiuni.txt\"\n";
		show::showDataShow(shows);
		break;
	case '8':
		del::delChannel(channels);
		channels.resize(--lengthChannels);
		std::cout << "\nSuccesful excluded one element from \"Canal.txt\"\n";
		show::showDataChannel(channels);
		break;
	case '9':
		refresh::refreshDataShow(shows);
		shows.resize(lengthShows);
		std::cout << "\nData was refreshed\n";
		show::showDataShow(shows);
		break;
	}
}