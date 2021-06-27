#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>
//#include <malloc.h>

typedef enum state{
	pos_out,
	mem_err,
	list_ok,
}list_state_t;

template <class T>
class linkedList
{
	struct node{
	  	T data;
		node* next;
	};
	typedef struct node* point;
	public:
		point head = NULL, tail = NULL, tempList = NULL;
		list_state_t addFirst(T x)
		{
			point r = getNode(x);
			if(r==NULL){
				return mem_err;
			}
			
			if(head == NULL){	//chua co phan tu nao trong danh sach
				head = tail = r;
			}
			else{
				r->next = head;
				head = r;
			}
			return list_ok;
		}
		list_state_t addLast(T x)
		{
			point r = getNode(x);
			if(r==NULL){
				return mem_err;
			}
			if(head == NULL){
				head = tail = r;
			}
			else{
				tail->next = r;
				tail = r;
			}
			return list_ok;
		}
		list_state_t addAt(int pos, T x)
		{
			if((pos == 0) || (head == NULL)){
				return addFirst(x);
			}
			int k = 1;
			point p = head;
			while((p->next!= tail)&&(k<pos)){
				p = p->next;
				k++;
			}
			if(k==pos-1){
				return addLast(x);
			}
			else if(k<pos-1){
				return pos_out;
			}
			return addAfter(p, x);
		}
		void deleteFirst()
		{
			if(head == tail){
				//free(head);
				delete head;
				head = tail = NULL;
			}
			else{
				point temp = head->next;
				delete head;
				//free(head);
				head = temp;
			}
		}
		void deleteLast()
		{
			if(head == tail){
				delete head;
				//free(head);
				head = tail = NULL;
			}
			else{
				point p;
				for(p = head; p->next!=tail; p = p->next);
				delete tail;
				//free(tail);
				tail = p;
				tail->next = NULL;
			}
		}
		list_state_t  deleteAt(int pos)
		{
			if((pos == 0)||(head == NULL)||(head->next == NULL)){
				deleteFirst();
				return list_ok;
			}
			int k = 1;
			point p = head;
			while((p->next != tail)&&(k<pos)){
				p = p->next;
				k++;
			}
			if(k<pos){
				return pos_out;
			}
			delAfter(p);
			return list_ok;
		}
		void deleteList()
		{
			point temp;
			while(head){
				temp = head;
				head = head->next;
				//free(temp);
				delete temp;
			}
		}
	private:
		point getNode(T x)
		{
			point p;
			p = new (struct node);
			//p = (point)malloc(sizeof(struct node));
			if(p!=NULL)
			{
				p->data = x;
				p->next = NULL;
			}
			return p;
		}
		list_state_t addAfter(point q, T x)
		{
			point r = getNode(x);
			if(r==NULL){
				return mem_err;
			}
			r->next = q->next;
			q->next = r;
			return list_ok;
		} 
		void delAfter(point p)
		{
			if(p->next == tail){
				delete tail;
				//free(tail);
				tail = p;
				tail->next = NULL;
			}
			else{
				 point temp = p->next;
				 p->next = p->next->next;
				 //free(temp);
				 delete temp;	
			}
		}
};

#endif
