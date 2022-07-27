//Samuel Bryan
//CIS 1202 800
//July 10th, 2022

using namespace std; 

enum PublicationType { BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO }; //Enum to store media types

class Publication
{
private:
	string title; //Stores media title
	string publisher; //Stores media publisher
	float price; //Stores media price
	int year; //Stores media year released
	PublicationType type; //Stores enum value of media
	int stock; //Stores media stock
public:
	void displayType() //Changes enum entry to print type
	{
		switch (type) //Switch statement to match input to entry
		{
		case 0:
			cout << "Type: Book";
			break;
		case 1:
			cout << "Type: Magazine";
			break;
		case 2:
			cout << "Type: Newspaper";
			break;
		case 3:
			cout << "Type: Audio";
			break;
		case 4:
			cout << "Type: Video";
			break;
		default:
			cout << "Invalid Entry";
			break;
		}
	}
	void storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock)
	{
		title = itemTitle; //Saves user input to title
		publisher = itemPublisher; //Saves user input to publisher
		price = itemPrice; //Saves user input to price
		year = itemYear; //Saves user input to year
		type = itemType; //Saves user input to type
		stock = itemStock; //Saves user input to stock
	}
	void displayInfo() //Diplays all info of entry
	{
		cout << "***************************Entry Info**************************" << endl;
		cout << "Title: " << title << endl;
		cout << "Publisher: " << publisher << endl;
		cout << "Price: $" << price << endl;
		cout << "Year Published: " << year << endl;
		displayType();
		cout << "\nTotal in Stock " << stock << endl;
		cout << "***************************************************************" << endl;
	}
	void checkOut() 
	{
		stock--; //Subtracts from stock
	}
	void checkIn()
	{
		stock++; //Adds to stock
	}
	string getTitle()
	{
		cout << "Title: " << title << endl; //Displays title
		return title;
	}
	int getStock()
	{
		cout << "Current Stock: " << stock << endl; //Displays current stock
		return stock;
	}
};
