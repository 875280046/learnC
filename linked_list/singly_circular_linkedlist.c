/*
singly circular linked  list:
insert a node to any position 
delete a node from any position 
creat linked list from tail
get length of a linked list
free all linked list

CSDN
http://blog.csdn.net/fisherwan/article/details/19754585

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE, *pNODE;

pNODE creat();
void traverse(pNODE head);
int getlength(pNODE head);
int insert(pNODE head, int pos);
int deletenode(pNODE head, int pos);
void freeall(pNODE *head);

int main(){
	pNODE head = creat();
	traverse(head);
	printf("The length is %d.\n", getlength(head));
//	insert(head, 5);
//	traverse(head);
	deletenode(head, 2);
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
	pNODE temp = head;
	
	printf("Please input the length of the linked list: ");
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
		new_->pNext = head;		//attition not NULL, is point to head.
		temp->pNext = new_;
		temp = new_;
	} 
	return head;
}

void traverse(pNODE head){
	pNODE temp = head;
	if(temp->pNext == head){
		printf("Linked list is empty.\n");
	}
	else{
		printf("Linked list is: \n");
	}
	while(temp->pNext != head){		//boundary conditions is not != NULL.
		printf("%d\t", temp->pNext->data);
		temp = temp->pNext;
	}
	printf("\n");
}

int getlength(pNODE head){
	int length = 0;
	pNODE temp = head;
	while(temp->pNext != head){
		length++;
		temp = temp->pNext;
	}
	return length;
}

int insert(pNODE head, int pos){
	if(pos > 0 && pos < getlength(head) + 2){
		pNODE temp = head;
		pNODE new_ = malloc(sizeof(NODE));
		if(new_ == NULL){
			printf("Failure to allocate memory.\n");
			return -1;
		}
		while(pos != 1){
			pos--;
			temp = temp->pNext;
		}
		printf("Please input new node's data: ");
		int data = 0;
		scanf("%d", &data);
		new_->data = data;
		new_->pNext = temp->pNext;
		temp->pNext = new_;
		return 0;
	}
	else{
		printf("Illegal position.\n");
		return -1;
	}
}

int deletenode(pNODE head, int pos){
	int tempos = pos;
	if(pos > 0 && pos < getlength(head) + 1){
		while(pos != 1){
			pos--;
			head = head->pNext;
		}
		printf("Delete %d node.\n", tempos);
		pNODE temp = head->pNext;
		head->pNext = head->pNext->pNext;
		free(temp);
		return 0;	
	} 
	else{
		printf("Illegal position.\n");
		return -1;
	}
}

void freeall(pNODE *head){
	/*NODE* pCursor=(*head)->pNext;
	while(pCursor!=*head){
		NODE* tmp= pCursor;
		pCursor=pCursor->pNext;
		free(tmp);
	}
	free(*head);
	*head=NULL;*/
	pNODE temhead = (*head)->pNext;
	while(temhead != *head){
		pNODE temp = temhead->pNext;
		free(temhead);
		temhead = temp;
	}
	free(temhead);
	temhead = NULL;
}
