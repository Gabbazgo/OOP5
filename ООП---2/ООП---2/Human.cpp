#include "human.h"
#include <iostream>


using namespace std;

Human::Human() { 
	age = 0;
	weight = 0;
	height = 0;

	cout << "Вызов конструктора по умолчанию класса Human : Human()" << endl;
}

Human::Human(int a, int w, int h) {
	age = a;
	weight = w;
	height = h;

	cout << "Вызов конструктора с параметром класса Human : Human(" << age << "," << weight << ","<<height<<")" << endl;
}

Human::Human(Human& black) {
	age = black.age;
	weight = black.weight;
	height = black.height;

	cout << "Вызов конструктора копирования класса Human : Human(Human& gay)" << endl;
}

void Human::Up(int aH, int wH, int hH)
{
	age = age + aH;
	weight = weight + wH;
	height = height + hH;
	cout << "Вызван метод Up класса Human" << endl;
}

 const string Human::className()
{
	return "Human";
}

void Human::func(const Human* const human)
{
	cout << "human->age = " << human->age << endl;
	cout << "human->weight = " << human->weight << endl;
	cout << "human->height = " << human->height << endl;
}
bool Human::IsA(string className)
{

	if (className.compare("Human") == 0)
		return true;

	return false;
}
void Human::SetW(int w) {
	weight = w;
	cout << "Вызов метода Run (" << weight << ")" << endl;
}

void Human::Print() {
	cout << "Значение age: " << age << " // Значение weight: " << weight << " // Значение height: " << height;
}

int Human::GetAge() {
	return age;
}

int Human::GetWeight() {
	return weight;
}

int Human::GetHeight() {
	return height;
	
}

const char* Human::GetType() {
	return "Human";
}

void Human::Mode() {
	cout << "Рост = " << endl;
	cin >> height;

	cout <<"Вес = "<< endl;
	cin >> weight;

	cout << "Возраст = " << endl;
	cin >> age;
} 

Human :: ~Human() {
	cout << "Вызов деструктора ~Human()" << endl;
}

/* */

Man::Man() : Human(),power(0) {
	
	cout << "Вызов конструктора по умолчанию Man :: Man()" << endl;
}

Man::Man(int a, int w, int h, int p) : Human(a, w, h), power(p) {

	cout << "Вызов конструктора с параметрами Man :: Man(" << age << "," << weight << "," << height << "," << power << ")" << endl;
}

void Man::Print() {
	Human::Print();
	cout << " // Значение силы: " << " " << power;
}

Man::Man(Man& man) :Human(man) {
	power = man.power;
}

void Man::SetPower(int p) {
	power = p;
}

const char* Man::GetType() {
	return "Man";
}
void Man::Mode() {
	Human::Mode();
	cout << "Сила = " << endl;
	cin >> power;
}

const string Man::className()
{
	return "Man";
}
bool Man::IsA(string className)
{

	
	if (className.compare("Man") == 0)
		return true;

	return Human::IsA(className);
}

Man :: ~Man() {
	cout << "Вызов деструктора класса Man" << endl;
}

/* */

Baby::Baby() :Man() {
	dex = 0;
	cout << "Вызов конструктора по умолчанию Baby :: Baby()" << endl;
}

Baby::Baby(int a, int w, int h, int p, int d) : Man(a, w, h, p) {
	dex = d;
	cout << "Вызов конструктора с параметрами Baby :: Baby(" << age << "," << weight << "," << height << "," << power << "," << dex << ")" << endl;
}
void Baby::Mode() {
	Man::Mode();
	cout << "Сила = " << endl;
	cin >> power;
}

const string Baby::className()
{
	return "Baby";
}
bool Baby::IsA(string className)
{


	if (className.compare("Baby") == 0)
		return true;

	return Man::IsA(className);
}

void Baby::Print() {
	Man::Print();
	cout << "Значение ловкости" << " " << dex << endl;
}

Baby::Baby(Baby& baby) :Man(baby) {
	dex = baby.dex;
}

void Baby::SetDex(int d) {
	dex = d;
}

Baby :: ~Baby() {
	cout << "Вызов деструктора класса Baby" << endl;
}

/* */

Woman::Woman() {
	
	cout << "Вызов конструктора по умолчанию класса Woman: Woman()" << endl;
}

Woman::Woman(Woman& woman) {

	cout << " Вызов конструктора копирования класса Woman: Woman(Woman& woman)" << endl;
}

Woman::~Woman() {
	cout << "Вызов деструктора класса Woman" << endl;
}