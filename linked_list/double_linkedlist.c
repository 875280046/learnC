/*
double linked  list:
insert a node to any position 
delete a node from any position 
creat linked list from tail
get length of a linked list
free all linked list

CSDN
http://blog.csdn.net/fisherwan/article/details/19760681
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
	struct Node* pPre;
}NODE, *pNODE;

pNODE creat();
void traverse(pNODE head);
int getlength(pNODE head);
int insert(pNODE head, int pos);
int deletenode(pNODE head, int pos);
void freeall(pNODE* head);

int main(){
	pNODE head = creat();
	traverse(head);
	printf("The length of linked list is %d.\n", getlength(head));
	//insert(head, 5);
	//traverse(head);
	deletenode(head, 4);
	traverse(head);
	freeall(&head);
	return 0;
} 

pNODE creat(){
	pNODE head = malloc(sizeof(NODE));
	if(head == NULL){
		printf("Failure to allocate memory.\n");
		return NULL;
	}
	head->data = 0;
	head->pNext = NULL;
	head->pPre = NULL;
	pNODE temp = head;
	
	printf("Please input the length of linked list: ");
	int length = 0;
	scanf("%d", &length);
	int i = 0;
	for(i = 0; i < length; i++){
		pNODE new_ = malloc(sizeof(NODE));
		if(new_ == NULL){
			printf("Failure to allocate memory.\n");
			return NULL;
		}
		printf("Please input %d node's data: ", i + 1);
		int data = 0;
		scanf("%d", &data);
		new_->data = data;
		new_->pPre = temp->pNext;
		temp->pNext = new_;
		new_->pNext = NULL;
		temp = new_;
	}
	return head;
}

void traverse(pNODE head){
	pNODE temp = head;
	while(temp->pNext != NULL){
		printf("%d\t", temp->pNext->data);
		temp = temp->pNext;		
	}
	printf("\n");
}

int getlength(pNODE head){
	int length = 0;
	while(head->pNext != NULL){
		length++;
		head = head->pNext;
	}
	return length;
}

int insert(pNODE head, int pos){
	if(pos > 0 && pos < getlength(head) + 2){
		pNODE new_ = malloc(sizeof(NODE));
		if(new_ == NULL){
			printf("Failure to allocate memory.\n");
			return -1;
		}
		printf("Will insert node in position %d. Please input new node's data: ", pos);
		int data = 0;
		scanf("%d", &data);
		new_->data = data;
		new_->pNext = NULL;
		new_->pPre = NULL;
		
		while(pos != 1){
			pos--;
			head = head->pNext;
		}
		pNODE temp = head->pNext;
		new_->pNext = temp;
		new_->pPre = head;
		head->pNext = new_;
		if(temp != NULL){		//remember this: when next node is NULL, NULL have not pPre
			temp->pPre = new_;
		}
		return 0;
	}
	else{
		printf("Illegal position.\n");
		return -1;
	}
}

int deletenode(pNODE head, int pos){
	if(pos > 0 && pos < getlength(head) + 1){
		while(pos != 1){
			pos--;
			head = head->pNext;
		}
		pNODE temp = head->pNext->pNext;
		free(head->pNext);
		head->pNext = temp;
		if(temp != NULL){
			temp->pPre = head;
		}
		return 0;
	}
	else{
		printf("Illegal position.\n");
		return -1;
	}
}

void freeall(pNODE* head){
	while(*head != NULL){
		pNODE temp = (*head)->pNext;
		free(*head);
		*head = temp;
	}
}
