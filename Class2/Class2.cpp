//Samuel Bryan
//CIS 1202 800
//July 27th, 2022

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include "Publication.h"
#include <string.h>

using namespace std;

void getPublicationInfo(Publication[]);
void showTitles(Publication[]);
void findPublication(Publication[], string);
int getMenuChoice(Publication[], string);
int binarySearch(Publication[], string);
void selectionsort(Publication[]);
void swapS(Publication&, Publication&);

int main()
{
	const int SIZE = 6;
	int input = 0;
	string entry;
	Publication list[SIZE];
	cout << "Weclome to the Pop Culture Database" << endl;
	getPublicationInfo(list);
	cout << "Enter a choice from the menu below" << endl;
	getMenuChoice(list, entry);
	system("pause");
	return 0;
}

void getPublicationInfo(Publication list[])
{
	string fileTitle;
	string filePublisher;
	float filePrice = 0;
	int fileYear = 0;
	int fileEntry = 0; //Collects int from user input to be converted to enum type
	PublicationType fileType = BOOK; //Enum type
	float fileStock = 0;
	fstream dataFile;
	dataFile.open("data.txt", ios::in);
	if (dataFile)
	{
		for (int i = 0; i < 6; i++)
		{
			dataFile >> fileTitle >> filePublisher >> filePrice >> fileYear >> fileEntry >> fileStock;
			list[i].displayType();
			list[i].storePublication(fileTitle, filePublisher, filePrice, fileYear, fileType, fileStock); //Saves all user input to storePublication function
		}
	}
	else
	{
		cout << "Cannot open file" << endl;
	}
	dataFile.close();
}


int getMenuChoice(Publication list[], string entry)
{
	int input;
	int i = 0;
	do
	{
		cout << "1. Display everything" << endl;
		cout << "2. Show Titles" << endl;
		cout << "3. Find Publication" << endl;
		cout << "4. Check Publication In" << endl;
		cout << "5. Check Publication Out" << endl;
		cout << "6. Exit Program" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
		{
			for (int i = 0; i < 6; i++)
			{
				list[i].displayInfo();
			}
			break;
		}
		case 2:
		{
			showTitles(list);
			break;
		}
		case 3:
		{
			findPublication(list, entry);
			break;
		}
		case 4:
		{
			findPublication(list, entry);
			list[i].checkIn();
			list[i].getStock();
			break;
		}
		case 5:
		{
			findPublication(list, entry);
			list[i].checkOut();
			list[i].getStock();
			break;
		}
		case 6:
		{
			cout << "Thank you for using our program.  Goodbye\n\n";
			break;
		}
		default:
		{
			cout << "Invalid Entry, please try again" << endl;
			break;
		}
		}
	} while (input != 6);
	return input;
}

void showTitles(Publication list[])
{
	for (int i = 0; i < 6; i++)
	{
		list[i].getTitle();
	}
}

void findPublication(Publication list[], string entry)
{
	selectionsort(list);
	cout << "Enter the name of the publication you want to find: ";
	getline(cin, entry);
	int position = binarySearch(list, entry);
	if (position == -1)
	{
		cout << "Invalid entry, please try again" << endl;
	}
	else
	{
		list[position].displayInfo();
	}
}

void selectionsort(Publication list[])
{
	int minIndex;
	Publication minValue;
	for (int start = 0; start < 6; start++)
	{
		minIndex = start;
		minValue = list[start];
		for (int i = start + 1; i < 6; i++)
		{
			if (list[i].printTitle() < minValue.printTitle())
			{
				minValue = list[i];
				minIndex = i;
			}
		}
		swapS(list[minIndex], list[start]);
	}
}

void swapS(Publication& a, Publication& b)
{
	Publication temp = a;
	a = b;
	b = temp;
}

int binarySearch(Publication list[], string entry)
{
	const int SIZE = 6;
	int first = 0;
	int last = SIZE - 1;
	int middle;
	int position = -1;
	bool found = false;
	while (!found && first <= last)
	{
		middle = (first + last / 2);
		if (list[middle].getTitle() == entry)
		{
			found = true;
			position = middle;
		}
		else if (list[middle].getTitle() > entry)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}
