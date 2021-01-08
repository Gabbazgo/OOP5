#pragma once
#include <string>
using std::string;

class Human { //класс Human
protected:
	int age, weight, height;

public:
	Human();
	Human(int a, int w, int h);
	Human(Human& Black);
	void GetOlder(int a);
	virtual void SetW(int w);
	virtual void Print();
	void Up(int a, int w, int h);
	int GetAge();
	int GetWeight();
	int GetHeight();
	virtual const char* GetType();
	virtual void Mode();
	virtual const string className();
	virtual bool IsA(string className);
	static void func(const Human* const human);


	virtual ~Human();

};

class Man : public Human { // наследник Human
protected:
	int power;
public:
	Man();
	Man(int a, int w, int h, int p);
	Man(Man& Black);
	virtual const string className();
	virtual bool IsA(string className);
	void Print();
	void SetPower(int p);
	 virtual const char* GetType();
	 virtual void Mode();
	 int GetParam();
	 
	~Man();

};

class Baby : public Man { // наследник Man
protected:
	int dex;
public:
	Baby();
	Baby(int a, int w, int h, int p, int d);
	Baby(Baby& Black);
	virtual const string className();
	virtual bool IsA(string className);
	virtual void Mode();
	int GetParam();

	
	void Print();
	void SetDex(int d);

	~Baby() override;

};

class Woman : public Human { // отдельный класс Woman для композиции классов

private:
	int z;

public:
	Woman();
	Woman(int a,int w,int h, int z);
	Woman(Woman& woman);

	int GetZ();
	void SetZ(int z);
	virtual const char* GetType();
	virtual void Mode();
	void Print();
	virtual const string className();
	virtual bool IsA(string className);

	~Woman();
};
