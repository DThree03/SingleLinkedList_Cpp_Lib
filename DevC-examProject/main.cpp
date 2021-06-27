#include <iostream>
#include <malloc.h>

#include "../linkedlist.h"
using namespace std;


int main() {
	linkedList<float> list1;
	
	list1.addFirst(34);
	list1.addLast(45);
	
	list1.addAt(1, 32);
	if(list1.addAt(3, 46.4) == pos_out){
		cout<<"Pos add out!"<<endl;
	}
	
	if(list1.deleteAt(5) == pos_out){
		cout<<"Pos del out!"<<endl;
	}
	printf("Lenght of list: %d", list1.getLenght());
	cout<<endl;
	list1.tempList = list1.head;
	
	while(list1.tempList!=list1.tail->next){
		printf("Data in list: %0.1f", list1.tempList->data);
		cout<<endl;
		cout<<"in "<<list1.tempList<<endl;
		list1.tempList = list1.tempList->next;	
	}
	
	list1.deleteList();
	
	return 0;
}
