#pragma once
#include <fstream>
using namespace std;

struct Goods
{
	char name[100];
	char shop[100];
	double price;
	double amount;
	char meas[20];
	int code;

	void print()
	{
		cout << "\n\n\tCode: " << code;
		cout << "\n\tName: " << name;
		cout << "\n\tShop: " << shop;
		cout << "\n\tPrice: " << price;
		cout << "\n\tAmount: " << amount;
		cout << "\n\tMeasurement: " << meas;
	}
};

char NameCorrector(char name)//Increases the first letters 
{
	if (name >= 97 && name <= 122)
	{
		name = name - 32;
	}
	return name;
}
Goods* Read_File_f(int& size)// and create array
{
	ifstream in;

	in.open("file.dat", ios::binary);

	in.seekg(0, ios::end);
	size = in.tellg();
	size /= sizeof(Goods);
	in.seekg(0, ios::beg);
	Goods* goods_a = new Goods[size];

	if (!in.read((char*)goods_a, size * sizeof(Goods)))
	{
		cerr << "\n\n\tRead Error!\n\n\n";
	}
	in.close();
	return goods_a;
}
void Write_File_f(Goods* goods_a, int& size)
{
	ofstream out;

	out.open("file.dat", ios::binary);

	if (!out.write((char*)goods_a, size * sizeof(Goods)))
	{
		cerr << "\n\n\tWrite Error!\n\n\n";
	}
	out.close();
}
void Print_arr_f(Goods* goods_a, int& size)
{
	cout << size << endl;
	for (int i = 0; i < size; i++)
	{
		goods_a[i].print();
	}

}
void Add_f()
{
	Goods goods_s;

	cout << "\n\n\tEnter:\n\tName: ";	cin >> goods_s.name;
	goods_s.name[0] = NameCorrector(goods_s.name[0]);

	cout << "\tShop: ";					cin >> goods_s.shop;
	goods_s.shop[0] = NameCorrector(goods_s.shop[0]);

	cout << "\tPrice: ";				cin >> goods_s.price;
	cout << "\tAmount: ";				cin >> goods_s.amount;
	cout << "\tMeasurement: ";			cin >> goods_s.meas;
	goods_s.meas[0] = NameCorrector(goods_s.meas[0]);


	ifstream in;

	in.open("file.dat", ios::binary);

	in.seekg(0, ios::end);
	int size = in.tellg();
	size /= sizeof(Goods);
	in.seekg(0, ios::beg);
	in.close();

	goods_s.code = size + 1;

	ofstream out;

	out.open("file.dat", ios::binary | ios::app);

	if (!out.write((char*)&goods_s, sizeof(Goods)))
	{
		cerr << "\n\n\tWRITE ERROR!\n\n\n";
	}
	out.close();
}
void Sort_By_Name_f()
{
	int size = 0;
	Goods* goods_a = Read_File_f(size);

	bool swaped = false;

	do
	{
		swaped = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (goods_a[i].name[0] > goods_a[i + 1].name[0])
			{
				swap(goods_a[i], goods_a[i + 1]);
				swaped = true;
			}
		}
	} while (swaped);

	Write_File_f(goods_a, size);
	delete[] goods_a;
}
void Print_goods_f()
{
	int size = 0;
	Goods* goods_a = Read_File_f(size);

	Print_arr_f(goods_a, size);

	delete[] goods_a;
}


