#include <iostream>
#include <vector>
#include <algorithm>
#include "Struct_definer.h"
#include "File_conector.h"
#include <iomanip>



namespace get
{
	void getDataShow(std::vector<Shows>& show)
	{
		for (int i = 0; i < show.size(); i++)
		{
			in1 >> show[i].id;
			in1.ignore(32767, ' ');
			in1.get(show[i].name, 200, '|');
			in1.ignore(32767, ' ');
			in1 >> show[i].genre;
		}
	}

	void getDataChannel(std::vector<Channels>& channel)
	{
		for (int i = 0; i < channel.size(); i++)
		{
			in2 >> channel[i].number;
			in2.ignore(32767, ' ');
			in2.get(channel[i].name, 200, '|');
			in2.ignore(32767, ' ');
			in2 >> channel[i].registered;
		}
	}

	void getDataDifuzion(std::vector<Difuzion>& difuzion, std::vector<Channels>& channel)
	{
		for (int i = 0; i < difuzion.size(); i++)
		{
			in3 >> difuzion[i].channel.number;
			in3.ignore(1, ' ');
			in3.get(difuzion[i].show.name, 199, '|');
			in3.ignore(1, '|');
			in3.ignore(1, ' ');
			in3 >> difuzion[i].show.genre;

			in3.ignore(1, ' ');
			in3 >> difuzion[i].time.all;
			difuzion[i].time.h = difuzion[i].time.all[0] * 10 + difuzion[i].time.all[1];
			difuzion[i].time.min = difuzion[i].time.all[4] * 10 + difuzion[i].time.all[5];
			in3 >> difuzion[i].timeDuration;

			in3.ignore(1, ' ');
			in3 >> difuzion[i].lang;

			for (int i = 0; i < channel.size(); i++)
			{
				int num = channel[i].number;

				for (int j = 0; j < difuzion.size(); j++)
				{
					if (num == difuzion[j].channel.number)
					{
						strcpy_s(difuzion[j].channel.name, channel[i].name);
					}
				}
			}
		}
	}
}

namespace show
{
	void showDataShow(const std::vector<Shows>& shows)
	{
		for (const Shows &show : shows)
		{
			std::cout << show.id << " " << show.name << " " << show.genre << "\n";
		}
	}

	void showDataChannel(const std::vector<Channels>& channels)
	{
		for (const Channels &channel : channels)
		{
			std::cout << channel.number << " " << channel.name << " " << channel.registered << "\n";
		}
	}

	void showDataDifuzion(const std::vector<Difuzion>& difuzions)
	{
		for (const Difuzion &difuzion : difuzions)
		{
			std::cout << difuzion.channel.number << " ";
			std::cout << difuzion.show.name << " ";
			std::cout << difuzion.show.genre << " ";
			std::cout << difuzion.time.all << " ";
			std::cout << difuzion.timeDuration << " ";
			std::cout << difuzion.lang << "\n";
		}
	}
}

namespace add
{
	void addDataShow(std::vector<Shows>& show)
	{
		std::cout << "Pe ce loc doriti sa puneti emisiunea: ";
		int index;
		std::cin >> index;
		index--;
		std::cin.ignore(32767, '\n');

		for (int i = show.size() - 1; i > index; i--)
		{
			std::swap(show[i], show[i - 1]);
		}

		while (true)
		{
			std::cout << "Adaugati o emisiune noua:\n";
			std::cin >> show[index].id;
			std::cin.ignore(32767, ' ');
			std::cin.get(show[index].name, 200, '|');
			std::cin.ignore(32767, ' ');
			std::cin >> show[index].genre;

			bool same = false;
			for (int i = 0; i < show.size(); i++)
			{
				if (show[index].id == show[i].id)
				{
					if (i == index)
					{
						continue;
					}
					same = true;
				}
			}

			if (!same)
			{
				break;
			}
			else
			{
				std::cout << "\nEmisiunea sub acest id deja exista!\n";
			}
		}
		std::cin.ignore(32767, '\n');
	}

	void addDataChannel(std::vector<Channels>& channel)
	{
		std::cout << "Pe ce loc doriti sa puneti canalul: ";
		int index;
		std::cin >> index;
		index--;
		std::cin.ignore(32767, '\n');

		for (int i = channel.size() - 1; i > index; i--)
		{
			std::swap(channel[i], channel[i - 1]);
		}
		
		while (true)
		{
			std::cout << "Adaugati un canal nou:\n";
			std::cin >> channel[index].number;
			std::cin.ignore(32767, ' ');
			std::cin.get(channel[index].name, 200, '|');
			std::cin.ignore(32767, ' ');
			std::cin >> channel[index].registered;

			bool same = false;
			for (int i = 0; i < channel.size(); i++)
			{
				if (channel[index].number == channel[i].number)
				{
					if (i == index)
					{
						continue;
					}
					same = true;
				}
			}

			if (!same)
			{
				break;
			}
			else
			{
				std::cout << "\nCanal sub acest numar deja exista!\n";
			}
		}
		std::cin.ignore(32767, '\n');
	}
}

namespace afis
{
	void copyToShowDataShow(const std::vector<Shows>& shows)
	{
		out << "Lista emisiuni:\n";
		for (const Shows& show : shows)
		{
			out << show.id << "\t" << show.name << "\t" << show.genre << "\n";
		}
		out << '\n';
	}

	void copyToShowDataChannel(const std::vector<Channels>& channels)
	{
		out << "Lista canale:\n";
		for (const Channels& channel : channels)
		{
			out << channel.number << "\t" << channel.name << "\t" << channel.registered << "\n";
		}
		out << '\n';
	}

	void copyToShowDataDifuzion(const std::vector<Difuzion>& difuzions)
	{
		out << "Lista difuziuni:\n";
		for (const Difuzion& difuzion : difuzions)
		{
			out << difuzion.channel.number << "\t";
			out << difuzion.show.name << "\t";
			out << difuzion.show.genre << "\t";
			out << difuzion.time.all << "\t";
			out << difuzion.timeDuration << "\t";
			out << difuzion.lang << "\n";
		}
	}
}

namespace del
{
	void delShow(std::vector<Shows>& shows)
	{
		std::cout << "Introduceti denumirea emisiunii care doriti sa eliminati: ";
		char choose[500];  
		std::cin.get(choose, 499);
		std::cin.ignore(32767, '\n');

		for (int i = 0; i < shows.size(); i++)
		{
			if (strstr(shows[i].name, choose))
			{
				for (int j = i; j < shows.size() - 1; j++)
				{
					std::swap(shows[j], shows[j + 1]);
				}
				break;
			}
		}
	}

	void delChannel(std::vector<Channels>& channels)
	{
		std::cout << "Introduceti denumirea canalului care doriti sa eliminati: ";
		char choose[500];
		std::cin.get(choose, 499);
		std::cin.ignore(32767, '\n');

		for (int i = 0; i < channels.size(); i++)
		{
			if (strstr(channels[i].name, choose))
			{
				for (int j = i; j < channels.size() - 1; j++)
				{
					std::swap(channels[j], channels[j + 1]);
				}
				break;
			}
		}
	}
}

namespace refresh
{
	void refreshDataShow(std::vector<Shows>& shows)
	{
		std::cout << "Introduceti id-ul emisiunii pentru a ii edita parametrii: ";
		int choose;
		std::cin >> choose;
		std::cin.ignore(32767, '\n');

		for (Shows &show : shows)
		{
			if (choose == show.id)
			{
				std::cout << "Denumirea: ";
				std::cin.get(show.name, 200);
				std::cout << "Tipul: ";
				std::cin >> show.genre;
				break;
			}
		}
	}


	void refreshDataChannel(std::vector<Channels>& channels)
	{
		std::cout << "Introduceti nr-ul canalului pentru a ii edita parametrii: ";
		int choose;
		std::cin >> choose;
		std::cin.ignore(32767, '\n');

		for (Channels& channel : channels)
		{
			if (choose == channel.number)
			{
				std::cout << "Denumirea: ";
				std::cin.get(channel.name, 200);
				std::cout << "Inregistrarea emisiunilor(Y/N): ";
				std::cin >> channel.registered;
				break;
			}
		}
	}
}

namespace difuzion
{
	void maxTimeDifuzion(const std::vector<Difuzion>& difuzions)
	{
		std::cout << "Emisiuni cu cea mai lunga durata de difuzare:\n";
		
		int max = 0;
		for (const Difuzion &difuzion : difuzions)
		{
			if (difuzion.timeDuration > max)
			{
				max = difuzion.timeDuration;
			}
		}

		for (const Difuzion &difuzion : difuzions)
		{
			if (difuzion.timeDuration == max)
			{
				std::cout << "  " << difuzion.show.name << " " << difuzion.show.genre << " " << difuzion.time.all << " | " << difuzion.timeDuration << " minute\n";
			}
		}
	}

	void minTimeDifuzion(const std::vector<Difuzion>& difuzions)
	{
		std::cout << "Emisiuni cu cea mai scurta durata de difuzare:\n";

		int min = 99999;
		for (const Difuzion &difuzion : difuzions)
		{
			if (difuzion.timeDuration < min)
			{
				min = difuzion.timeDuration;
			}
		}

		for (const Difuzion &difuzion : difuzions)
		{
			if (difuzion.timeDuration == min)
			{
				std::cout << "  " << difuzion.show.name << " " << difuzion.show.genre << " " << difuzion.time.all << " | " << difuzion.timeDuration << " minute\n";
			}
		}
	}

	void numOfShowsPerChannel(std::vector<Difuzion>& difuzions)
	{
		std::cout << "Ce tip de emisiune cautati? ";
		std::string choose;
		std::cin >> choose;

		for (int i = 0; i < difuzions.size(); i++)
		{
			for (int j = 0; j < difuzions.size(); j++)
			{
				if (choose == difuzions[j].show.genre && difuzions[i].channel.number == difuzions[j].channel.number)
				{
					difuzions[i].numByGenre++;
				}
			}
		}

		std::cout << "  Numar emisiuni de tip " << choose << " per canal:\n";
		std::cout << "\n        Nr canal     Nr emisiuni\n";

		bool print = true;
		for (int i = 0; i < difuzions.size(); i++)
		{
			for (int j = i - 1; j > -1; j--)
			{
				if (difuzions[i].channel.number == difuzions[j].channel.number)
				{
					print = false;
				}
			}

			if (print)
			{
				if (difuzions[i].numByGenre)
				{
					std::cout << std::setw(16);
					std::cout << difuzions[i].channel.name;
					std::cout << std::setw(12);
					std::cout << difuzions[i].numByGenre << "\n";
				}
			}
			print = true;
		}
	}

	void mostPopularShow(std::vector<Difuzion>& difuzions)
	{
		std::cout << "Cea mai solicitata emisiune:\n";

		int max = 0;
		for (const Difuzion &difuzion : difuzions)
		{
			if (difuzion.timeDuration > max)
			{
				max = difuzion.timeDuration;
			}
		}

		for (Difuzion difuzion : difuzions)
		{
			if (difuzion.timeDuration == max)
			{
				std::cout << "  " << difuzion.show.name << " " << difuzion.channel.name << "\n";
				break;
			}
		}
	}
}