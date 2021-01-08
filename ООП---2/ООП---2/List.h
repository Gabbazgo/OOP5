#pragma once

#include "Node.h"

using namespace std;
template <typename T>

class List {
private:
	Node <T>* current;
	int len;
	Node <T>* first;
	void SetLen(int _len);
	Node <T> *GetLast();
public:
	List(); 
	void Set();
	void AddAfter(T* value); // добавление после текущего элемента
	void AddBefore(T* value); // добавление перед текущим элементом
	void Delete(); // удаляет текущий элемент из списка
	void MoveNext(); // переход к следующему
	void MovePrev(); // переход к предыдущему
	void MoveFirst(); // переход к первому
	bool GetEnd(); //проверка на конец списка
	int GetLen(); //получение длины списка
	T* GetValue(); // получение значения текущего элемента
	Node <T>* GetCurrent(); // получение ссылки на текущий элемент
	void SetCurrent(Node <T>* current); // установить значение текушего элемента
	~List();
};
template <typename T>
List <T> ::List() {
	len = 0;
	current = NULL;
}
template <typename T>
void List <T>::SetLen(int _len) { 
	/*защита, т.к. мб >0*/
	if (_len >= 0)
		len = _len;
	else {
		cout << "Ошибка!";
		len = 0;
	}
}
template <typename T>
Node<T>* List <T> ::GetLast() {

	return first->GetPrev();
}
template <typename T>
bool List <T> ::GetEnd() {

	if (len == 0)
		return true;
	return current->GetNext() == first;// если следующий элемент после текущего - первый, то текущий элемент последний, и вернется true
}
template <typename T>
void List <T> ::AddAfter(T* obj) {

	if (len == 0) { // если список пуст, то меняем значение текущего эл-а
		current = new Node <T>();//создаем новый узел

		first = current;//первый элемент становится текущим
		current->SetNext(current);//направляем указатель на самого себя для корректности алгоритма
		current->SetPrev(current);//направялем указатель на самого себя
		current->SetValue(obj);//записываем в текущий элемент значение
		SetLen(len + 1);//увеличиваем список на 1
		return;
	}
	Node<T>* oldNext = current->GetNext(); // сохраняем адрес следующего элемента
	Node<T>* addNode = new Node <T>(current, obj, oldNext);
	current->SetNext(addNode);
	oldNext->SetPrev(addNode);
	SetLen(len + 1);
	current = addNode;
}
template <typename T>
void List <T> ::AddBefore(T* obj) {

	if (len == 0) {
		AddAfter(obj);
		return;

	}
	Node <T>* oldPrev = current->GetPrev();
	Node<T>* addNode = new Node <T>(oldPrev, obj, current);
	current->SetPrev(addNode);
	oldPrev->SetNext(addNode);
	SetLen(len + 1);
	if (current == first)
	first = addNode;
	current = addNode;
	}
template <typename T>
void List <T> ::Delete() {
	int k = 0;
	if (len == 0)
		return;
	Node <T>* prev = current->GetPrev();
	Node<T>* newnext = current->GetNext();
	prev->SetNext(newnext);
	newnext->SetPrev(prev);

	if (first == current) {
		first = current->GetNext();
		k = 1;
	}
	delete current;
	if (k == 1)
		current = first;
	else current = prev;
	SetLen(len - 1);
	}
template<typename T>
void List<T>::MoveFirst() {
	current = first;
}
template<typename T>
void List<T>::MoveNext() {
	if (len == 0)
		return;
	current = current->GetNext();
}

template<typename T>
void List<T>::MovePrev() {
	if (len == 0)
		return;
	current = current->GetPrev();
}
template<typename T>
T* List<T>::GetValue() {
	return current->GetValue();
}
template<typename T>
Node <T>* List<T>::GetCurrent() {
	return current;
}
template<typename T>
int List<T>::GetLen() {
	return len;
}
template<typename T>
void List<T>::Set() {
	if (len == 0)
		return;
	current->GetValue()->Mode();
}
template<typename T>
void List<T>::SetCurrent(Node <T>* _current) {
	current = _current;
}


template<typename T>
List <T>::~List() {
	cout << "Вызов деструктора класса List"<<endl;

	if (len == 0)
		return;
	int tmp = len;
	for (int i = 0; i < tmp; i++)
		Delete();

}






