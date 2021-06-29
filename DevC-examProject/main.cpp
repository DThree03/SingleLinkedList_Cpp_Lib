#include <iostream>
#include <malloc.h>

#include "../linkedlist.h"
using namespace std;


int main() {
	linkedList<float> list1;
	
	list1.addFirst(34);
	list1.addLast(45);
	
	list1.addAt(2, 32);
	if(list1.addAt(1, 46.4) == pos_out){
		cout<<"Pos add out!"<<endl;
	}
	
	if(list1.deleteAt(5) == pos_out){
		cout<<"Pos del out!"<<endl;
	}
	printf("Lenght of list: %d", list1.getLenght());
	cout<<endl;
	
	list1.tempList = list1.head;
	while(list1.tempList!=list1.tail->next){
		printf("Data: %0.1f ", list1.tempList->data);
		cout<<"in addr "<<list1.tempList<<endl;
		list1.tempList = list1.tempList->next;	
	}
	
	float buff[3];
	list1.getBuffer(1, buff, 3);
	for(int i = 0; i<3;i++){
		printf("Data in buff[%d]: %0.2f", i, buff[i]);
		cout<<endl;	
	}
	printf("Data in pos %d: %0.1f", 2, list1.getData(2));
	cout<<endl;
	list1.deleteList();
	
	return 0;
}
