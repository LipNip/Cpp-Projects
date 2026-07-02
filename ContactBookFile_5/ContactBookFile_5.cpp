#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio> // FILE, fopen, fprintf, fclose
using namespace std;

struct Contact {
	char surname[50], phone[20];
};

void set_Contact(Contact* book, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "\nContact #" << i + 1 << "\n";

		cout << "Surname: ";
		gets_s(book[i].surname);

		cout << "Phone: ";
		gets_s(book[i].phone);
	}
}

int main()
{
	int size;

	cout << "Enter number contact: ";
	cin >> size;
	cin.ignore();

	Contact* book = new Contact[size];
	set_Contact(book, size);

	char path[] = "contactbook.txt";
	FILE* file = fopen(path, "w");

	if (!file) {
		cout << "Error path!!!\n";
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		fprintf(file, "Surname: %16s | Phone: %16s\n", book[i].surname, book[i].phone);
	}
	
	fclose(file);

	cout << "Data saved to contactbook.txt";

	delete[] book;
	cout << "\n\n";
	return 0;
}
