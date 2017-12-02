/*
linked list without head
Implement menu operation
add a node to list
print linked list
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	char name[20];
	int age;
	struct Node* next;
}Node;

typedef struct List
{
	Node* head;
}List;

int interface(List* list);
List* initialize();
void add(List* list);
void print(List* list);

int main(){
	List* list = initialize();
	interface(list);	
} 

int interface(List* list){
	while(1){
		system("color 0A");		//change system color:  
		printf("0. quit\n");
		printf("1. add a user\n");
		printf("2. print all user infermations\n");
	
		printf("Please input a number for corresponding operation: ");
		int num = 0;
		scanf("%d", &num);
		switch(num){
			case 0:
				return 0;
			case 1:
				add(list);
				system("pause");
				system("CLS");
				//interface(list);
				break;
			case 2:
				print(list);
				system("pause");
				system("CLS");
				//interface(list);
				break;
			default:
				printf("Wrong number, please reinput again.\n");
				
				system("pause");
				system("CLS");
				//interface(list);
		}
	}

	return 0;
}

List* initialize(){
	List* list = malloc(sizeof(List));
	list->head = NULL; 
	return list;
}

void add(List* list){
	//new node data 
	Node* new_ = malloc(sizeof(Node));
	printf("Please input your name: ");
	char name[20];
	scanf("%s", name);
	strcpy(new_->name, name);
	printf("Please input your age: ");
	int age = 0;
	scanf("%d", &age);
	new_->age = age;
	new_->next = NULL;
	
	
	if(list->head==NULL){
		list->head=new_;
	}
	else{
		Node* temp = list->head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_;
	}	

	printf("Add successful.\n");
}

void print(List* list){
	Node* temp = list->head;
	while(temp != NULL){
		printf("%s %d\n", temp->name, temp->age);
		temp = temp->next;
	}
}
