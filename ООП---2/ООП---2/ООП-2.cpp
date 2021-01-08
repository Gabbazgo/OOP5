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
		else if (i % 4 == 2)
			linkedList.AddAfter(new Woman());
		else linkedList.AddAfter(new Baby());
	}

	linkedList.MoveFirst();
	cout << endl << endl;
	for (int i = 0; i < linkedList.GetLen(); i++)
	{
		cout << i << ")" << linkedList.GetValue()->className().c_str() << "\t IsA(Human)";
		if (linkedList.GetValue()->IsA("Human") == true)
			cout << "true";
		else cout << "false";

		cout <<"||"<< linkedList.GetValue()->className().c_str() << "\t IsA(Man)";
		if (linkedList.GetValue()->IsA("Man") == true)
			cout << "true";
		else cout << "false";

		cout << "||" << linkedList.GetValue()->className().c_str() << "\t IsA(Baby)";
		if (linkedList.GetValue()->IsA("Baby") == true)
			cout << "true";
		else cout << "false";

		cout << "||" << linkedList.GetValue()->className().c_str() << "\t IsA(Woman)";
		if (linkedList.GetValue()->IsA("Woman") == true)
			cout << "true";
		else cout << "false";

		cout << endl << endl;
		linkedList.MoveNext();
	}
	 
	cout << endl << "----------------------------------" << endl << endl;
	cout << "Проверка передачи параметров в функцию: " << endl << endl;
	cout << "Создание объекта класса Human" << endl << endl;

	Human human;
	human.Print();
	cout << endl << "Адрес объекта в Main: " << &human << endl << endl;
	Func1(human);
	cout << endl << "После вызова Func1:" << endl;
	human.Print();
	cout << endl << endl;

	Func2(human);
	cout << endl << "После вызова Func2:" << endl;
	human.Print();
	cout << endl << endl;

	Func3(&human);
	cout << endl << "После вызова Func3:" << endl;
	human.Print();
	cout << endl << endl;

	cout << "Создание объектов класса Man наследника Human" << endl << endl;
	Man nuggets;
	cout << endl << endl;

	Func1(nuggets);
	cout << endl << "После вызова Func1:" << endl;
	nuggets.Print();
	cout << endl << endl;

	Func2(nuggets);
	cout << endl << "После вызова Func2:" << endl;
	nuggets.Print();
	cout << endl << endl;

	Func3(&nuggets);
	cout << endl << "После вызова Func3:" << endl;
	nuggets.Print();
	cout << endl << endl;

	cout << "----------------------------------" << endl << endl;

	cout <<"Перекрытие методов:"<<endl << endl;

	Man* mana = new Man(26, 60, 170, 6);
	Baby* biba = new Baby(8, 30, 130, 2, 9);
	cout << "Вызов метода GetParam у объекта Man (26+60+170+6): "<< mana->GetParam() << endl << endl;
	cout << "Вызов метода GetParam у объекта Baby (8+30+130+2-9): " << biba->GetParam() << endl << endl;

	cout << "----------------------------------" << endl << endl;

	cout << "Вызов наследуемого метода: " << endl << endl;
	cout << "Текущее значение Man" << endl;
	mana->Print();
	cout << endl << endl;
	cout << "Вызов метода GetOlder(50), который наследуется от класса родителя Human" << endl;
	mana->GetOlder(50);
	cout << endl;
	cout << "Измененное значение Man: " << endl;
	mana->Print();

	cout << "----------------------------------" << endl << endl;
	cout << "Безопасное приведение типов " << endl << endl;
	cout << "c помощью dynamic_cast: " << endl << endl;
	linkedList.MoveFirst();
	for (int i = 0; i < linkedList.GetLen(); i++) {
		Baby* biba = dynamic_cast<Baby*>(linkedList.GetValue());
		if (biba != NULL)
		{
			cout << i << ")";
			biba->Print();
			cout << endl;
			cout << "buba->SetPower(10)" << endl;
			biba->SetPower(10);
			biba->Print();
			cout << endl << endl;
		}
		linkedList.MoveNext();
	}
	cout << endl << endl;
	cout << "Безопасное приведение типов вручную" << endl << endl;
	linkedList.MoveFirst();
	for (int i = 0; i < linkedList.GetLen(); i++)
	{
		if (linkedList.GetValue()->IsA("Baby"))
		{
			cout << i << ")";
			Baby* biba = (Baby*)(linkedList.GetValue());
			biba->Print();
			cout << endl;
			cout << "bobs->SetPower(20)" << endl;
			biba->SetPower(10);
			biba->Print();
			cout << endl << endl;
		}
		linkedList.MoveNext();
	}
	cout << "----------------------------------" << endl << endl;
	delete mana;
	delete biba;
}