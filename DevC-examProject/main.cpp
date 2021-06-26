#include <iostream>
#include <malloc.h>

#include "../linkedlist.h"
using namespace std;


int main() {
	linkedList list1;
	
	list1.addFirst(34);
	list1.addLast(45);
	list1.addAt(1, 32);
	list1.addAt(2, 46);
	//list1.deleteAt(2);
	
	point temp = list1.head;
	while(temp){
		printf("Data in list: %d", temp->data);
		cout<<endl;
		cout<<"in "<<temp<<endl;
		temp = temp->next;	
	}
	list1.deleteList();
	
	return 0;
}
