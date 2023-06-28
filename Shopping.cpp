#include <iostream>
#include "Logic.h"

using namespace std;

int main()
{
	bool check = true;
	int choise;
	cout << "Make a choise " << endl << 
		"1-Add new shop." << endl << 
		"2-Show shops." << endl;
	cin >> choise;
	while (check)
	{
		if (choise == 1)
		{
			Add_f();
			check = false;
		}
		if (choise == 2)
		{
			Print_goods_f();
			check = false;
		}
	}
}
