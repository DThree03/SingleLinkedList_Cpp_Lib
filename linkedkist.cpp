#include "linkedlist.h"

point linkedList::getNode(int x)
{
	point p;
	p = (point)malloc(sizeof(node));
	if(p!=NULL)
	{
		p->data = x;
		p->next = NULL;
	}
	return p;
}
void linkedList::addFirst(int x)
{
	point r = getNode(x);
	if(head == NULL){	//chua co phan tu nao trong danh sach
		head = tail = r;
	}
	else{
		r->next = head;
		head = r;
	}
}
void linkedList::addLast(int x)
{
	point r = getNode(x);
	if(head == NULL){
		head = tail = r;
	}
	else{
		tail->next = r;
		tail = r;
	}
}
void linkedList::addAt(int pos, int x)
{
	if((pos == 0) || (head == NULL)){
		addFirst(x);
	}
	else{
		int k = 1;
		point p = head;
		while((p!=NULL)&&(k!=pos)){
			p = p->next;
			k++;
		}
		if(k!=pos){
			addLast(x);
		}
		else{
			point temp = getNode(x);
			temp->next = p->next;
			p->next = temp;
		}
	}
}
void linkedList::deleteFirst()
{
	if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{
		point temp = head->next;
		free(head);
		head = temp;
	}
}
void linkedList::deleteLast()
{
	if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{
		point p = head;
		while(p->next->next != NULL){
			p = p->next;
		}
		free(tail);
		tail = p;
		p->next = NULL;
	}
}
void linkedList::deleteAt(int pos)
{
	if((pos == 0)||(head == NULL)||(head->next == NULL)){
		deleteFirst();
	}
	else{
		int k = 1;
		point p = head;
		while((p->next->next != NULL)&&(k!=pos)){
			p = p->next;
			k++;
		}
		if(k!=pos){
			deleteLast();	
		}
		else{
			point temp = p->next;
			p->next = p->next->next;
			free(temp);
		}
	}
}
void linkedList::deleteList()
{
	point temp = NULL;
	while(head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
