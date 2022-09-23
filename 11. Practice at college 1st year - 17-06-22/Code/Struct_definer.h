#ifndef STRUCT1
#define STRUCT1

#include <string>
#include <iostream>

struct Shows
{
	int id;
	char name[200];
	std::string genre;
};

struct Channels
{
	int number;
	char name[200];
	char registered;
};

struct Time
{
	std::string all;
	int h = 0;
	int min;
};

struct Difuzion
{
	Channels channel; // number
	Shows show; // name, genre
	Time time; // h, min
	int timeDuration = 0;
	std::string lang;
	int numByGenre = 0;
};

#endif // !STRUCT1
