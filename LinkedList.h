/*
* The declaration of the Node class and the LinkedList class
* Since these two classes have very closed relationship, we declare them in one header file
*
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "bound_err.h"

using namespace std;

class Node
{
public:
	Node() :next(NULL) {};
	Node(char ch, Node* ptr) : data(ch), next(ptr) {};
	char getData() const { return data; }
	Node* getNext() const { return next; }
	friend class LinkedList;  // gives LinkedList access to private data of Node

private:
	char data;
	Node* next;
};


class LinkedList
{
public:
	LinkedList() :head(NULL) {};
	Node* getHead() const;
	void insertAtFront(char ch);
	char deleteAtFront() throw(bound_err);
	void deleteItem(char item);
	void printList() const;
	int size() const;
	~LinkedList();

private:
	Node* head;
};

#endif   /* LINKEDLIST_H */
