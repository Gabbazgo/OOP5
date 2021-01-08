#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
	Node* prev; T* value; Node* next; 
public:
	Node(); 
	Node(Node* _prev, T* _value, Node* _next);
	Node(Node& node);
	Node* GetPrev();
	T* GetValue();
	Node* GetNext();
	void SetValue(T* _value);
	void SetPrev(Node* _prev);
	void SetNext(Node* _next);

	~Node();
};

template <typename T>
Node<T>::Node() {
	prev = NULL;
	value = NULL;
	next = NULL;
}

template <typename T>
Node<T>::Node(Node* _prev, T* _value, Node* _next) {
	prev = _prev;
	value = _value;
	next = _next;
}

template <typename T>
Node<T>::Node(Node<T> &node) {
	value = node.value;
	next = node.next;
	prev = node.prev;
}

template <typename T>
T* Node<T>::GetValue() {
	return value;
}

template <typename T>
Node <T>* Node<T>::GetPrev() {
	return prev;
}

template <typename T>
Node <T>* Node<T>::GetNext() {
	return next;
}

template <typename T>
void Node <T>::SetValue(T* _value) {
	value = _value;
}

template <typename T>
void Node <T>::SetNext(Node <T>* _next) {
	next = _next;
}

template <typename T>
void Node<T>::SetPrev(Node <T>* _prev) {
	prev = _prev;
}

template <typename T>
Node<T>::~Node<T>() {
	cout << "Вызван деструктор класса Node";
}


