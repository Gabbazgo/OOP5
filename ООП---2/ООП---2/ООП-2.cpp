//﻿#include <iostream>
#include <conio.h>
#include "Human.h"
#include <iostream>
#include <Windows.h>
#include "List.h"
#include <conio.h>
#include <stdio.h>
#include <time.h>
//#include "Man.h"
//#include "Baby.h"
//#include "Woman.h"

using namespace std;
void Func1(Human obj) {
	cout <<"Вызвана функция Func1(Human obj)"<< endl;
	cout << "Адрес объекта Func1:" << &obj << endl;
	cout << "Вызов obj.SetW(10)" << endl;
	obj.SetW(10);
}

void Func2(const Human &obj) {
	cout << "Вызвана функция Func2(const Human &obj)" << endl;
	cout << "Адрес объекта Func2:" << &obj << endl;
	cout << "Вызов obj.SetW() невозможен" << endl;
	Human::func(&obj);
}
void Func3(Human *obj) {
	cout << "Вызвана функция Func3(Human *obj)" << endl;
	cout << "Адрес объекта Func3:" << &obj << endl;
	cout << "Вызов obj.SetW(20)" << endl;
	obj -> SetW(20);
}
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "");
	List<Human> linkedList;
	int z;
	for (int i = 0; i < 10; i++)
	{
		z = rand() % 100;
		if (z % 4 == 0)
			linkedList.AddAfter(new Human());
		else if (i % 4 == 1)
			linkedList.AddAfter(new Man());

	}


}