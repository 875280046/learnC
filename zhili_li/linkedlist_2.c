/*
add an element from (head/tail) of list
add an element to the (behind/front) of an specific element

(pinyin: Cyuyan cong ling dao jingtong. teacher:zhili li.) 
(chapter 15, classhour 80)
*/
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Book
{
	int price;
	char* name;
	struct Book* next;
}Book;

void push_h(Book** head, int price, char* name);	//add an element to head of list
void push_t(Book* head, int price, char* name);		//add an element to tail of list
void push_ts(Book* head, int price, char* name, int sprice);	//add an element to the behind of an specific element
void push_fs(Book* head, int price, char* name, int sprice);	//add an element to the front of an specific element

int main(){
	Book* p;
	Book* book1, * book2, * book3;		//initialize three struct
	book1 = malloc(sizeof(Book));
	book1->price = 10;
	book1->name = malloc(20);
	strcpy(book1->name, "book1");
	
	book2 = malloc(sizeof(Book));
	book2->price = 20;
	book2->name = malloc(20);
	strcpy(book2->name, "book2");
	
	book3 = malloc(sizeof(Book));
	book3->price = 30;
	book3->name = malloc(20);
	strcpy(book3->name, "book3");
	
	p = book1;		//link three struct
	book1->next = book2;
	book2->next = book3;
	book3->next = NULL;
	
	char* hname = "book0";		
	push_h(&p, 00, hname);		//add an element to head of list
	char* tname = "book4";
	push_t(p, 40, tname);		//add an element to tail of list
	
	push_ts(p, 123, "book", 20);	//add an element to the behind of an specific element
	push_fs(p, 223, "wawawa", 40);	//add an element to the front of an specific element
	while(p != NULL){		//print all 
		printf("%2d %s\n", p->price, p->name);
		p = p->next;
	}
	Book* i = p;
	while(i != NULL){		//free all
		free(p->name);
		i = p->next;
		free(p);		
	}
}

void push_h(Book** head, int price, char* name){
	Book* p = malloc(sizeof(Book));
	p->price = price;
	p->name = malloc(20);
	strcpy(p->name, name);
	p->next = *head;
	*head = p;
}

void push_t(Book* head, int price, char* name){
	Book* current = head;
	while(current->next != NULL){		//find the last element
		current = current->next;
	} 
	current->next = malloc(sizeof(Book));
	current->next->price = price;
	current->next->name = malloc(20);
	strcpy(current->next->name, name);
	current->next->next = NULL;
}

void push_ts(Book* head, int price, char* name, int sprice){
	Book* p = head;
	while(p->price != sprice){
		p = p->next;
	}
	Book* pp = p->next;
	p->next = malloc(sizeof(Book));
	p->next->price = price;
	p->next->name = name;
	p->next->next = pp;
}

/*void push_fs(Book* head, int price, char* name, int sprice){
	Book* p = head;
	while(p->next->price != sprice){
		p = p->next; 
	}
	Book* pp = p->next;
	p->next = malloc(sizeof(Book));
	p->next->price = price;
	p->next->name = name;
	p->next->next = pp;
}*/

void push_fs(Book* head, int price, char* name, int sprice){	//pointer head is just a copy of pointer head, if you want to change the value of head, the parameter should use Book** head 
	//Book* p = head;
	while(head->next->price != sprice){
		head = head->next; 
	}
	Book* pp = head->next;
	head->next = malloc(sizeof(Book));
	head->next->price = price;
	head->next->name = name;
	head->next->next = pp;
}
