//﻿#include <iostream>
#include <conio.h>
#include "Human.h"
#include <iostream>
#include <Windows.h>
#include "List.h"
#include <conio.h>
#include <stdio.h>
//#include "Man.h"
//#include "Baby.h"
//#include "Woman.h"

using namespace std;
void SetClr(int clr) {
    HANDLE consolehandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consolehandle, (WORD)(0 | clr));
}
template<typename T>
void PrintList(List<T>*List)
{

    cout << "Длина :  " << List->GetLen() << endl << endl;

    //номер отрисовываемого элемента
    int i = 1;

    Node<T>* init = List->GetCurrent();

    List->MoveFirst();

    for (int i = 1; i <= List->GetLen(); i++)
    {

        if (List->GetCurrent() == init)
            SetClr(10);

        cout << "[" << i << "] : " << List->GetValue()->GetType() << "{";
        List->GetValue()->Print();
        cout << "}" << endl;



        List->MoveNext();

        SetClr(15);
    }

    List->SetCurrent(init);

    SetClr(15);
}
int main()
{
    setlocale(LC_ALL, "");
    List <Human> List;
    bool cont = true;
    while (cont) {
        cout << "\nТекущий список: " << endl;
        PrintList(&List);
        cout << "Выберите действие:" << endl;
        if (List.GetLen() == 0)
        {
            cout << "1 - Добавить элемент" << endl;
            SetClr(0);
        }
        else
            cout << "1 - Добавить после текущего" << endl;
            cout << "2 - Добавить перед текущим элементом" << endl;
            cout << "3 - Удалить текущий" << endl;

            if (List.GetLen() == 1)
                SetClr(0);
            cout << "4 - Перейти к следующему элементу" << endl;
            cout << "5 - Перейти к предыдущему элементу" << endl;

            if (List.GetLen() == 1)
                SetClr(15);
            cout << "6 - Изменить параметры текущего" << endl;
                SetClr(15);
                cout << "7 - Выход" << endl;

                int input = 1;
                cin >> input;
                Human* newObj;
                if(input >= 1 && input <= 2 && !(List.GetLen() == 0 && input == 2))
                {
                    cout << "Выберите тип:\n1 - Human\n2 - Man " << endl;
                    int objType = 1;
                    cin >> objType;
                    switch (objType) {
                    case 1:
                        newObj = new Human();
                        break;
                    case 2:
                        newObj = new Man();
                        break;
                    default:
                        newObj = new Human();
                        break;
                    }
                    newObj->Mode();
                    switch (input) {
                    case 1:
                        List.AddAfter(newObj);
                        break;
                    case 2:
                        if (List.GetLen() != 0)
                            List.AddBefore(newObj);
                        break;
                    }
                }
                switch (input) {
                case 3:
                    List.Delete();
                    break;
                case 4:
                    List.MoveNext();
                    break;
                case 5:
                    List.MovePrev();
                    break;
                case 6:
                    if (List.GetLen() != 0)
                        List.GetCurrent()->GetValue()->Mode();
                    break;
                case 7:
                    cont = false;
                    break;
                default:
                    cout << "Попробуйте еще раз!" << endl;
                    break;
                }
                system("cls");

    }

}    
//cout << "Создание класса Human: " << endl;
    //Human human;

    //cout << "human.Print :" << endl;

    //human.Print();
    //cout << endl;

    //// cout << "Вызов конструктора с параметром Human(16, 50)" << endl;

    //Human* kek = new Human(16, 50, 186);
    //kek->Print();

    //cout << "Вызван метод kek->Run(3)" << endl;

    //kek->Run(3);
    //kek->Print();

    //cout << "Вызван метод kek->GetAge()" << endl;
    //cout << kek->GetAge() << endl;

    //cout << "Вызван метод kek->GetWeight()" << endl;
    //cout << kek->GetWeight() << endl;

    //cout << "Удаление kek" << endl;
    //delete(kek);


    //cout << "Создание объекта класса Man:" << endl;
    //Man huh;
    //cout << "Вызов Man.Print" << endl;
    //huh.Print();
    //cout << "Вызов метода SetPower(7)" << endl;

    //huh.SetPower(7);
    //huh.Print();

    //Man* lol = new Man(18, 60, 186, 5);
    //lol->Print();

    //Human* pew = new Man(); //
    //pew->Run(4);
    //pew->Print();
    //cout << "______________________" << endl;

    //cout << "Приведение типов" << endl;
    //cout << "Вызов Print с помощью приведения типов:((Man*)pew)->Print()" << endl;
    //((Man*)pew)->Print();

    //cout << "Удаляем объект по адресу pew : delete pew" << endl;
    //delete pew;

    //cout << "______________________" << endl;

    //cout << "Динамическое создание класса Human с помощью конструктора с параметрами: Human* humanDynamic = new Human(36,65,170) " << endl;
    //Human* humanDynamic = new Human(36, 65, 170);
    //cout << "Динамическое создание класса Baby с помощью конструктора с параметрами: Baby* babyDynamic = new Baby(36,65,170,3,9) " << endl;
    //Baby* babyDynamic = new Baby(36, 65, 170, 3, 9);

    //cout << "Значение humanDynamic: " << endl;
    //humanDynamic->Print();

    //cout << "Значение babyDynamic: " << endl;
    //babyDynamic->Print();

    //cout << "______________________" << endl;
    //cout << "Композиция классов: " << endl;
    //cout << "Создание объекта класса Woman* wom= new Woman()" << endl;

    //Woman* wom = new Woman();

    //cout << "Вызовем wom -> GetParam() -> GetAge()" << endl;
    //wom->GetParam()->GetAge();

    //cout << "Вызовем wom -> GetParam() -> GetWeight()" << endl;
    //wom->GetParam()->GetWeight();

    //cout << "Вызовем wom -> GetParam() -> GetHeight()" << endl;
    //wom->GetParam()->GetHeight();

    //cout << "Значение human: " << endl;
    //human.Print();

    //cout << "Вызовем wom->SetParam()" << endl;
    //wom->SetParam(human);

    //cout << "Вызовем wom -> GetParam() -> GetAge()" << endl;
    //cout << wom->GetParam()->GetAge() << endl;

    //cout << "Вызовем wom -> GetParam() -> GetWeight()" << endl;
    //cout << wom->GetParam()->GetWeight() << endl;

    //cout << "Вызовем wom -> GetParam() -> GetHeight()" << endl;
    //cout << wom->GetParam()->GetHeight() << endl;

    //human.Run(2);
    //wom->SetParam(human);

    //cout << "Вызовем wom -> GetParam() -> GetAge()" << endl;
    //cout << wom->GetParam()->GetAge() << endl;

    //cout << "Вызовем wom -> GetParam() -> GetWeight()" << endl;
    //cout << wom->GetParam()->GetWeight() << endl;

    //cout << "Вызовем wom -> GetParam() -> GetHeight()" << endl;
    //cout << wom->GetParam()->GetHeight() << endl;

    //wom->GetVozr();
    //delete wom;



