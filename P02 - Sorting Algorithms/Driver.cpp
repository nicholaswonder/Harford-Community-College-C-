#include "Sort Class.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main() {
	string fileName;
	ifstream file;

	file.open("TestNumbers500.txt");
	Sort* Bubble = new Sort (file);
	Sort* Insert = new Sort (file);
	Sort* Select = new Sort (file);

	Bubble->bubbleSort();
	Insert->insertSort();
	Select->selectSort();

	delete Bubble;
	delete Insert;
	delete Select;
	file.close();

	cout << endl;

	file.open("TestNumbers5k.txt");
	Sort* BubbleTwo = new Sort(file);
	Sort* InsertTwo = new Sort(file);
	Sort* SelectTwo = new Sort(file);

	BubbleTwo->bubbleSort();
	InsertTwo->insertSort();
	SelectTwo->selectSort();

	delete BubbleTwo;
	delete InsertTwo;
	delete SelectTwo;
	file.close();

	cout << endl;

	file.open("TestNumbers25k.txt");
	Sort* BubbleThree = new Sort(file);
	Sort* InsertThree = new Sort(file);
	Sort* SelectThree = new Sort(file);

	BubbleThree->bubbleSort();
	InsertThree->insertSort();
	SelectThree->selectSort();

	delete BubbleThree;
	delete InsertThree;
	delete SelectThree;
	file.close();

	cout << endl;

	file.open("TestNumber100k.txt");
	Sort* BubbleFour = new Sort(file);
	Sort* InsertFour = new Sort(file);
	Sort* SelectFour = new Sort(file);

	BubbleFour->bubbleSort();
	InsertFour->insertSort();
	SelectFour->selectSort();

	delete BubbleFour;
	delete InsertFour;
	delete SelectFour;
	file.close();

	cout << endl;


	return 0;
}
