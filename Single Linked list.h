#pragma once
#include <iostream>
#include <cassert>
using namespace std;

class Node
{
public:
	string data;
	Node* next;

	Node() :data(), next() {}
	Node(const string& _data) : data(_data), next() {}

};
class SingleLinkedList
{
	Node* head;
public:

	// default cons
	SingleLinkedList() : head() {}

	// addBegin(node)
	void addBegin(Node*& item);

	// addBegin(string)
	void addBegin(string& item);

	// addEnd(node)
	void addEnd(Node*& item);

	// addEnd(string)
	void addEnd(string& item);

	// AddBefore(node)
	// AddBefore(string)

	// DeleteBegin
	void deleteBegin();

	// DeleteEnd
	void deleteEnd();
	// Delete by value(stirng)
	void deleteByValue(string& item);
	// Delete by value(node)
	void deleteByValue(Node*& item);
	// Search by Value(node)
	Node*& searchValue(Node*& item);

	// Display => cout overlodaing
	void Display();





};

void SingleLinkedList::addBegin(Node*& item)
{
	auto newNode = new Node(item->data);

	if (head == NULL) { head = newNode; return; }

	Node* temp = head;
	head = newNode;
	head->next = temp;
}
void SingleLinkedList::addBegin(string& item)
{
	auto newNode = new Node(item);
	if (head == NULL) { head = newNode; return; }
	Node* temp = head;
	head = newNode;
	head->next = temp;
}

void SingleLinkedList::addEnd(Node*& item)
{
	auto newNode = new Node(item->data);

	if (head == NULL) { head = newNode; return; }

	Node* temp = head;

	while (temp->next != nullptr)
		temp = temp->next;
	temp->next = newNode;
}
void SingleLinkedList::addEnd(string& item)
{
	auto newNode = new Node(item);

	if (head == NULL) { head = newNode; return; }

	Node* temp = head;
	while (temp->next != nullptr)
		temp = temp->next;

	temp->next = newNode;
}

void SingleLinkedList::deleteBegin()
{
	if (head == NULL) { assert(!"LIST IS EMPTY!"); }

	Node* temp = head;
	head = head->next;
	delete temp;
	temp = nullptr;
}
void SingleLinkedList::deleteEnd()
{
	if (head == NULL) { assert(!"LIST IS EMPTY!"); }
	Node* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
}




void SingleLinkedList::deleteByValue(Node*& item) {
	Node* newNode = new Node(*item);
	if (head == NULL)
		assert(!"List is empty");

	Node* temp = head;

	if (head->data == item->data) {
		if (head->next == NULL)
			head = NULL;
		else
			head = head->next;
		return;
	}

	while (temp->next != NULL) {
		if (temp->next->data == item->data)
			break;
		temp = temp->next;
	}

	temp->next = temp->next->next;
}
void SingleLinkedList::deleteByValue(string& item) {
	Node* newNode = new Node(item);
	deleteByValue(newNode);
}



Node*& SingleLinkedList::searchValue(Node*& item) {
	if (head == NULL) {
		assert(!"List is empty");
	}
	Node* temp = head;
	while (temp->next != NULL) {
		if (temp->data == item->data) {
			return temp;
		}
		temp = temp->next;
	}
	if (temp->data == item->data) return temp;
	assert(!"Not found");
}


void SingleLinkedList::Display()
{
	auto temp = head;
	cout << "[";
	while (temp->next != NULL)
	{
		cout << temp->data << ", ";
		temp = temp->next;
	}
	cout << temp->data << "]\n";

}

