#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>
#include <malloc.h>

typedef struct node* point;
struct node{
	int data;
	point next;
};

class linkedList
{
	public:
		point head = NULL, tail = NULL;
		void addFirst(int x);
		void addLast(int x);
		void addAt(int pos, int x);
		void deleteFirst();
		void deleteLast();
		void deleteAt(int pos);
		void deleteList();
	private:
		point getNode(int x);		
};

#endif
