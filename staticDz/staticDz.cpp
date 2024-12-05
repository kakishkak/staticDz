#include <iostream>
#include <string.h>

using namespace std;

class Student {
	int mark;
public:
	Student() {
		mark = 69;
	}
	Student(int x) {
		this->mark = x;
	}
	void AssingValues(int x) {
		this->mark = x;
	}
	void Printer() {
		cout << "Mark: " << mark << endl;
	}
};

int main()
{

	int amountOfBooks = 4;
	char** bookList = new char* [amountOfBooks];
	for (int i = 0; i < amountOfBooks; i++)
	{
		bookList[i] = new char[10];
		cout << "Write name of book " << i + 1 << ": ";
		cin.getline(bookList[i], 10);
	}
	cout << "Your list: " << endl;
	for (int i = 0; i < amountOfBooks; i++)
	{
		cout << bookList[i] << endl;
	}


	while (true) {
		cout << "1 - Add a book\n2 - Rename book\n3 - Delete book\n4 - Exit application\n5-Show all books\n: ";
		int result;
		cin >> result;
		cin.ignore();




		if (result == 1) {
			char** timeArr = new char* [amountOfBooks]; //временный массив
			for (int i = 0; i < amountOfBooks; i++)
			{
				timeArr[i] = new char[strlen(bookList[i]) + 1];			 //
				//
				//
				for (int j = 0; j < strlen(bookList[i]) + 1; j++)		 //
				{														 //перезаписывание
					timeArr[i][j] = (char)bookList[i][j];				 //
				}														 //
				delete[] bookList[i];									 //
				bookList[i] = nullptr;									 //

			}
			delete[] bookList;
			bookList = nullptr;

			amountOfBooks++;											   //
			bookList = new char* [amountOfBooks];						   //
			for (int i = 0; i < amountOfBooks - 1; i++)					   //
			{															   //
				bookList[i] = new char[strlen(timeArr[i]) + 1];			   //
				//
				//опять перезаписываем
				for (int j = 0; j < strlen(timeArr[i]) + 1; j++)		   //
				{														   //
					bookList[i][j] = (char)timeArr[i][j];				   //
				}														   //
				delete[] timeArr[i];									   //
				timeArr[i] = nullptr;									   //
			}
			delete[] timeArr;
			timeArr = nullptr;

			bookList[amountOfBooks - 1] = new char[10];
			cout << "Write your book: ";
			cin.getline(bookList[amountOfBooks - 1], 10);
			cout << endl;
			cout << "Your list: " << endl;
			for (int i = 0; i < amountOfBooks; i++)
			{
				cout << bookList[i] << endl;	//выводим массив
			}
			cout << endl;
		}


		else if (result == 2) {
			int numberBook;
			char* newName = new char[10];
			cout << "Write the number of book you want to rename: ";
			cin >> numberBook;
			cout << "Write your new name: ";
			cin >> newName;
			delete[] bookList[numberBook - 1];
			bookList[numberBook - 1] = nullptr;									//
			bookList[numberBook - 1] = new char[strlen(newName) + 1];			//перезаписываем новое имя
			bookList[numberBook - 1] = newName;									//
			cout << endl;
			cout << "Your list: " << endl;
			for (int i = 0; i < amountOfBooks; i++)
			{
				cout << bookList[i] << endl;
			}
			cout << endl;
		}


		else if (result == 3) {
			if (amountOfBooks - 1 < 0) {
				cout << "i cant";
				continue;
			}
			else {
				int numberBook;
				cout << "Write the number of book you want to delete: ";
				cin >> numberBook;
				amountOfBooks--;// уменьшаем количество книг
				int time = 0;
				char** timeArr = new char* [amountOfBooks];// временный массив 
				for (int i = 0; i < amountOfBooks + 1; i++)
				{
					if (i == numberBook - 1) {
						continue;
					}
					else {
						timeArr[time] = new char[strlen(bookList[time]) + 1];	   //
						for (int j = 0; j < strlen(bookList[i]) + 1; j++)		   //
						{														   //
							timeArr[time][j] = (char)bookList[i][j];			   //записывем в временный массив
						}														   //
						delete[] bookList[time];								   //
						bookList[time] = nullptr;								   //
						time++;													   //
					}
				}
				delete[] bookList;
				bookList = nullptr;

				bookList = new char* [amountOfBooks];
				for (int i = 0; i < amountOfBooks; i++)
				{
					bookList[i] = new char[strlen(timeArr[i]) + 1];				   //
					for (int j = 0; j < strlen(timeArr[i]) + 1; j++)			   //
					{															   //
						bookList[i][j] = (char)timeArr[i][j];					   //записываем обратно
					}															   //
					delete[] timeArr[i];										   //
					timeArr[i] = nullptr;										   //
				}
				delete[] timeArr;
				timeArr = nullptr;
				cout << endl;
				cout << "Your list: " << endl;
				for (int i = 0; i < amountOfBooks; i++)
				{
					cout << bookList[i] << endl;
				}
			}
			cout << endl;
		}


		else if (result == 4) {
			cout << "goodbye";
			break;
		}


		else if (result == 5) {
			cout << endl;
			cout << "Your list: " << endl;
			for (int i = 0; i < amountOfBooks; i++)
			{
				cout << bookList[i] << endl;
			}
			cout << endl;
		}
	}
} 

 
//#include <iostream>
//
//using namespace std;
//
//class Car {
//	int amountOfDoors;
//	int amountOfWheels;
//	int velocity;
//	int color;
//	static enum Colors {
//		red = 0,
//		green = 1,
//		blue = 2
//	};
//public:
//
//	Car() {
//		amountOfDoors = 4;
//		amountOfWheels = 4;
//		velocity = 69;
//		int colorName = rand() % 3;
//		ChooseColor(colorName);
//	}
//
//	Car(int amountOfDoors, int amountOfWheels, int velocity) {
//		this->amountOfDoors = amountOfDoors;
//		this->amountOfWheels = amountOfWheels;
//		this->velocity = velocity;
//		int colorName = rand() % 3;
//		ChooseColor(colorName);
//	}
//
//	void ChooseColor(int colorName) {
//		if (colorName == 0)
//			color = Colors::red;
//		else if (colorName == 1)
//			color = Colors::green;
//		else if (colorName == 2)
//			color = Colors::blue;
//	}
//
//	int GetDoors() {
//		return this->amountOfDoors;
//	}
//	int GetWheels() {
//		return this->amountOfWheels;
//	}
//	int GetVelocity() {
//		return this->velocity;
//	}
//	void AssingValues(const int amountOfDoors, const int amountOfWheels, int velocity) {
//		this->amountOfDoors = amountOfDoors;
//		this->amountOfWheels = amountOfWheels;
//		this->velocity = velocity;
//	}
//	void Printer() {
//		cout << "Amount of doors: " << amountOfDoors << endl;
//		cout << "Amount of wheels: " << amountOfWheels << endl;
//		cout << "Velocity: " << velocity << endl;
//		if (color == 0) {
//			cout << "Color red";
//		}
//		else if (color == 1) {
//			cout << "Color green";
//		}
//		else if (color == 2) {
//			cout << "Color blue";
//		}
//		cout << color;
//	}
//
//};
//
//class Parking {
//	Car* cars;
//public:
//	Parking() {
//		cars = new Car[amountOfCars];
//	}
//	static int amountOfCars;
//
//	void Adder(Car car) {
//		Car* tempArrOfCars = new Car[amountOfCars];
//
//		for (int i = 0; i < amountOfCars; i++) {
//			tempArrOfCars[i].AssingValues(
//				cars[i].GetDoors(),
//				cars[i].GetWheels(),
//				cars[i].GetVelocity());
//		}
//
//		delete[] cars;
//		cars = nullptr;
//
//		IncrementIncrease(1);
//
//		cars = new Car[amountOfCars];
//
//		for (int i = 0; i < amountOfCars - 1; i++) {
//			cars[i].AssingValues(
//				tempArrOfCars[i].GetDoors(),
//				tempArrOfCars[i].GetWheels(),
//				tempArrOfCars[i].GetVelocity());
//		}
//
//		delete[] tempArrOfCars;
//		tempArrOfCars = nullptr;
//
//		cars[amountOfCars - 1].AssingValues(
//			car.GetDoors(),
//			car.GetWheels(),
//			car.GetVelocity());
//	}
//	void Deleter() {
//		Car* tempArr = new Car[amountOfCars - 1];
//		for (int i = 0; i < amountOfCars-1; i++) {
//			tempArr[i].AssingValues(
//				cars[i].GetDoors(),
//				cars[i].GetWheels(),
//				cars[i].GetVelocity());
//		}
//		delete[] cars;
//		IncrementDecrease(1);
//		cars = new Car[amountOfCars];
//		cars = tempArr;
//	}
//
//	static void IncrementIncrease(int x) {
//		amountOfCars += x;
//	}
//	static void IncrementDecrease(int x) {
//		amountOfCars -= x;
//	}
//};
//
//int Parking::amountOfCars = 1;
//
//int main()
//{
//	srand(time(NULL));
//	int command;
//
//	Car car;
//	Parking park;
//
//	while (true) {
//
//		cout << "Write 1 to add/2 to delete/3 rename: ";
//		cin >> command;
//
//		if (command == 1) {
//			cout << "Amount of cars: " << Parking::amountOfCars << endl;
//			int doors;
//			cout << "Doors: ";
//			cin >> doors;
//			cout << "Wheels: ";
//			int wheels;
//			cin >> wheels;
//			cout << "Velocity: ";
//			int velocity;
//			cin >> velocity;
//			Car newCar = Car(doors, wheels, velocity);
//			park.Adder(newCar);
//			newCar.Printer();
//			cout << endl;
//		}
//		else if (command == 2) {
//			park.Deleter();
//			cout << "Amount of cars: " << Parking::amountOfCars << endl;
//			cout << endl;
//		}
//		else {
//			cout << "Amount of cars: " << Parking::amountOfCars << endl;
//			cout << endl;
//		}
//	}
//
//}