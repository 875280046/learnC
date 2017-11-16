/*
add an element from (head/tail) of list


(pinyin: Cyuyan cong ling dao jingtong. teacher:zhili li.) 
(chapter 15, classhour 80)
*/
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Data type;	//ADT: "type" represent "struct Data" 

typedef struct Data		//Data
{
	int age;
	int val;
}Data;

typedef struct Node		//Node include Data and pointer next
{
	type data;
	struct Node* next;
}Node;


void add(Node**, int a, int b);		//head insertion
void add_t(Node** head, int a, int b);	//tail insertion
int main(){
	Node* head = NULL;
	add(&head, 1, 2);
	add(&head, 11, 22);
	add(&head, 111, 222);
	Node* current = head;		//don't use head to traversal, use current instead
	while(current != NULL){
		printf("%d %d\n", current->data.age, current->data.val);
		current = current->next;
	}
	printf("\n");
	add_t(&head, 3, 4);
	add_t(&head, 33, 44);
	add_t(&head, 333, 444);
	current = head;
	while(current != NULL){
		printf("%d %d\n", current->data.age, current->data.val);
		current = current->next;
	}
	return 0;
}

void add(Node** head, int a, int b){
	Node* p = malloc(sizeof(Node));
	p->data.age = a;
	p->data.val = b;
	p->next = *head;
	*head = p; 
}
//this function is not good, it is not consider if linked list is empty
/*void add_t(Node* head, int a, int b){
	while(head->next != NULL){		//this is shallow copy, will not change head
		head = head->next;
	}
	head->next = malloc(sizeof(Node));
	head->next->data.age = a;
	head->next->data.val = b;
	head->next->next = NULL;
}*/
	
void add_t(Node** head, int a, int b){
	if(*head == NULL){		//if linked list is empty, regard new Node as head Node
		*head = malloc(sizeof(Node));
		(*head)->data.age = a;
		(*head)->data.val = b;
		(*head)->next = NULL;	
	}
	else{
		Node* p = *head;
		while(p->next != NULL){		//find the last Node
			p = p->next;
		}
		p->next = malloc(sizeof(Node));		//put the new Node behind the last Node
		p->next->data.age = a;
		p->next->data.val = b;
		p->next->next = NULL;
	}
	
}
