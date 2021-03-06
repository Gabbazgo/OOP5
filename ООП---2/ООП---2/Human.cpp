#include "Human.h"
#include <iostream>



using namespace std;

Human::Human() { 
	age = 0;
	weight = 0;
	height = 0;

	cout << "����� ������������ �� ��������� ������ Human : Human()" << endl;
}

Human::Human(int a, int w, int h) {
	age = a;
	weight = w;
	height = h;

	cout << "����� ������������ � ���������� ������ Human : Human(" << age << "," << weight << ","<<height<<")" << endl;
}

Human::Human(Human& black) {
	age = black.age;
	weight = black.weight;
	height = black.height;

	cout << "����� ������������ ����������� ������ Human : Human(Human& g)" << endl;
}

void Human::Up(int aH, int wH, int hH)
{
	age = age + aH;
	weight = weight + wH;
	height = height + hH;
	cout << "������ ����� Up ������ Human" << endl;
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
	//cout << "����� ������ Run (" << weight << ")" << endl;
}

void Human::Print() {
	cout << "�������� age: " << age << " // �������� weight: " << weight << " // �������� height: " << height;
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
	cout << "���� = " << endl;
	cin >> height;

	cout <<"��� = "<< endl;
	cin >> weight;

	cout << "������� = " << endl;
	cin >> age;
} 
void Human::GetOlder(int a) {
	age = age + a;
}
Human :: ~Human() {
	cout << "����� ����������� ~Human()" << endl;
}

/* */

Man::Man() : Human(),power(0) {
	
	cout << "����� ������������ �� ��������� Man :: Man()" << endl;
}

Man::Man(int a, int w, int h, int p) : Human(a, w, h), power(p) {

	cout << "����� ������������ � ����������� Man :: Man(" << age << "," << weight << "," << height << "," << power << ")" << endl;
}

void Man::Print() {
	Human::Print();
	cout << " // �������� ����: " << " " << power;
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
	cout << "���� = " << endl;
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
int Man::GetParam() {
	return age + weight + height;
}

Man :: ~Man() {
	cout << "����� ����������� ������ Man" << endl;
}

/* */

Baby::Baby() :Man() {
	dex = 0;
	cout << "����� ������������ �� ��������� Baby :: Baby()" << endl;
}

Baby::Baby(int a, int w, int h, int p, int d) : Man(a, w, h, p) {
	dex = d;
	cout << "����� ������������ � ����������� Baby :: Baby(" << age << "," << weight << "," << height << "," << power << "," << dex << ")" << endl;
}
void Baby::Mode() {
	Man::Mode();
	cout << "���� = " << endl;
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
	cout << " �������� ��������" << " " << dex << endl;
}

Baby::Baby(Baby& baby) :Man(baby) {
	dex = baby.dex;
}

void Baby::SetDex(int d) {
	dex = d;
}
int Baby::GetParam() {
	return age + weight + height - dex;
}

Baby :: ~Baby() {
	cout << "����� ����������� ������ Baby" << endl;
}

/* */

Woman::Woman() {
	

	cout << "����� ������������ �� ��������� ������ Woman: Woman()" << endl;
}

Woman::Woman(int a, int w, int h, int z) : Human(age, weight, height), z(z) {
	cout << "����� ������������ � ����������� Woman()" << endl;
}
Woman::Woman(Woman& woman) : Human(woman), z(woman.z)
{
	cout << " ����� ������������ ����������� ������ Woman: Woman(Woman& woman)" << endl;
}
void Woman::Print(){
	Human::Print();
	cout << "// �������� z: "<< z << endl;
}
int Woman::GetZ() {
	return z;
}
void Woman::SetZ(int ze) {
	z = ze;
}
const string Woman::className() {
	return "Woman";
}
bool Woman::IsA(string className) {
	if (className.compare("Woman") == 0)
		return true;
	return Human::IsA(className);
}
void Woman::Mode() {
	Human::Mode();
	cout << "z = ";
	cin >> z;
}
const char* Woman::GetType() {
	return "Woman";
}
Woman::~Woman() {
	cout << "����� ����������� ������ Woman" << endl;
}