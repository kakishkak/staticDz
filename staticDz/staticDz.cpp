#include <iostream>
#include <string.h>

using namespace std;

class Student {
	string name;
public:
	Student() {
		name = "Lolik";
	}
	Student(string x) {
		this->name = x;
	}
	void AssingValues(string x) {
		this->name = x;
	}
	void Printer() {
		cout << "Name: " << name << endl;
	}
	string getName() {
		return this->name;
	}
	void setMark(string x) {
		this->name = x;
	}
};

class Group {
	Student* slaves;
public:
	static int amountOfSlaves;
	Group() {
		slaves = new Student[amountOfSlaves];
	}
	void Adder(Student slave) {
		IncrementIncrease(1);
		Student* temporaryArr = new Student[amountOfSlaves];
		for (int i = 0; i < amountOfSlaves - 1; i++)
		{
			temporaryArr[i].AssingValues(slaves[i].getName());
		}
		temporaryArr[amountOfSlaves - 1].AssingValues(slave.getName());
		delete[]slaves;
		slaves = new Student[amountOfSlaves];
		slaves = temporaryArr;
	}
	void Deleter(int index) {
		IncrementDecrease(1);
		Student* temporaryArr = new Student[amountOfSlaves];
		int tempIndex = 0;
		for (int i = 0; i < amountOfSlaves+1; i++)
		{
			if (i + 1 == index) {
				continue;
			}
			else {
				temporaryArr[tempIndex].AssingValues(slaves[i].getName());
				tempIndex++;
			}
		}
		delete[] slaves;
		slaves = new Student[amountOfSlaves];
		slaves = temporaryArr;
	}

	void Renamer(int index, string name) {
		slaves[index - 1].AssingValues(name);
	}
	void Writer() {
		for (int i = 0; i < amountOfSlaves; i++)
		{
			cout << "Name of student " << i + 1 << " is: " << slaves[i].getName() << endl;
		}
	}
	static void IncrementIncrease(int x) {
		amountOfSlaves += x;
	}
	static void IncrementDecrease(int x) {
		amountOfSlaves -= x;
	}
};
int Group::amountOfSlaves = 0;
int main()
{
	cout << Group::amountOfSlaves << endl;
	Group obj;
	while (true) {
		cout << "1 - Add a student\n2 - Rename student\n3 - Delete student\n: ";
		int result;
		cin >> result;
		cin.ignore();

		if (result == 1) {
			string name;
			cout << "Write name: ";
			cin >> name;
			Student slave = Student(name);
			obj.Adder(slave);
			cout << endl;
			cout << "Amount of students: " << Group::amountOfSlaves << endl << "List of students: " << endl;
			obj.Writer();
		}


		else if (result == 2) {
			if (Group::amountOfSlaves < 1) {
				cout << "Here is nobody to rename.\n";
			}
			else {
				int renamerIndex;
				cout << "White which slave you want to rename: ";
				cin >> renamerIndex;
				if (renamerIndex<1 || renamerIndex>Group::amountOfSlaves) {
					cout << "Invalid number.\n";
				}
				else {
					string name;
					cout << "Write name: ";
					cin >> name;
					obj.Renamer(renamerIndex, name);
					obj.Writer();
				}
			}
		}


		else if (result == 3) {
			if (Group::amountOfSlaves<1) {
				cout << "Here is nobody to fire.\n";
			}
			else {
				int deleter;
				cout << "White which slave you want to fire: ";
				cin >> deleter;
				if (deleter<1 || deleter>Group::amountOfSlaves) {
					cout << "Invalid number.\n";
				}
				else {
					obj.Deleter(deleter);
					cout << endl;
					cout << "Amount of students: " << Group::amountOfSlaves << endl << "List of students: " << endl;
					obj.Writer();
				}
			}
		}
	}
}