/*
practice linked list: build, print, free pointer 
(pinyin: Cyuyan cong ling dao jingtong. teacher:zhili li.) 
(chapter 15, classhour 78)
*/
#include<stdio.h>
#include<malloc.h>
#include<string.h>
//first method: use struct element
/*typedef struct Book
{
	int price;
	char* name;
	struct Book* next;
}Book;

int main(){
	Book* p;
	Book book1, book2, book3;		//initialize three struct
	book1.price = 10;
	book1.name = "book1";		//you can also do: strcpy(book1.name, "book1");
	book2.price = 20;
	book2.name = "book2";
	book3.price = 30;
	book3.name = "book3";
	
	p = &book1;				//link three struct
	book1.next = &book2;		
	book2.next = &book3;
	book3.next = NULL;
	
	while(p != NULL){
		printf("%d %s\n", p->price, p->name);
		p = p->next;
	}
	return 0;
}*/
//second method: use struct pointer
typedef struct Book
{
	int price;
	char* name;
	struct Book* next;
}Book;

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
	
	while(p != NULL){		//print all 
		printf("%d %s\n", p->price, p->name);
		p = p->next;
	}
	Book* i = p;
	while(i != NULL){		//free all
		free(p->name);
		i = p->next;
		free(p);		
	}
}
