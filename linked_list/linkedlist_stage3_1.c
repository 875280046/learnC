/*
insert a node to any position of a linked list 
delete a node from any position of a linked list 
creat linked list from tail
get length of a linked list
free all linked list

CSDN
https://www.kancloud.cn/digest/datastructbyc/143032
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
int delete_(pNODE head, int pos);
void freeall(pNODE *head);

int main(){
	pNODE head = creat();
	traverse(head);
	printf("The length of linked list is: %d.\n", getlength(head));
	//insert(head, 5);
	//traverse(head);
	delete_(head, -1);
	traverse(head);
	freeall(&head);
	return 0;
}

pNODE creat(){
	pNODE head = malloc(sizeof(NODE));
	if(head == NULL){
		printf("Failure to memory allocation.\n");
		return NULL;
	}
	head->data = 0;
	head->pNext = NULL;
	pNODE temp = head;
	
	printf("Please input the linked list's length: ");
	int length = 0;
	scanf("%d", &length);
	int i = 0;
	for(i = 0; i < length; i++){
		pNODE new_ = malloc(sizeof(NODE));
		if(new_ == NULL){
			printf("Failure to memory allocation.\n");
			return NULL;
		}
		printf("please input %d node's data: ", i + 1);
		int data = 0;
		scanf("%d", &data);
		new_->data = data;
		new_->pNext = NULL;
		temp->pNext = new_;
		temp = new_;
	}
	return head;
}

void traverse(pNODE head){
	pNODE temp = head->pNext;
	if(temp == NULL){
		printf("The linked list is empty.\n");
	}
	else{
		printf("Print the linked list:\n");
	}
	while(temp != NULL){
		printf("%d\t", temp->data);
		temp = temp->pNext;
	}
	printf("\n");
}

int getlength(pNODE head){
	int length = 0;
	pNODE temp = head->pNext;
	while(temp != NULL){
		length++;
		temp = temp->pNext;
	}
	return length;
}

int insert(pNODE head, int pos){		//insert a node from any position
	if(pos > 0 && pos < getlength(head) + 2){	//eg. three node have four position:     (_POS_) node (_POS_) node (_POS_) node (_POS_)      
		pNODE new_ = malloc(sizeof(NODE));
		if(new_ == NULL){
			printf("Failure to memory allocation.\n");
			return -1;
		}
		printf("Please input the node's data: ");
		int data  = 0;
		scanf("%d", &data);
		new_->data = data;
		new_->pNext = NULL;	
		while(pos != 1){
			pos--;
			head = head->pNext;
		}
		new_->pNext = head->pNext;
		head->pNext = new_;
		return 0;
	}
	else{
		printf("Illegal position.\n");
		return -1;
	}
}

int delete_(pNODE head, int pos){	//delete a node from any position. Attention: if a list have 3 node, there are 4 position to insert, 3 position to delete
	if(pos > 0 && pos < getlength(head) + 1){
		
		while(pos != 1){
			pos--;
			head = head->pNext;
		}
		pNODE temp = head->pNext;		// remember save head->pNext. Always wrong here.
		head->pNext = head->pNext->pNext;
		free(temp);
	}
	else{
		printf("Illegal position.\n");
		return -1;
	}
}

void freeall(pNODE *head){		//parameter is a double pointer. remember free head node.
	pNODE temp = NULL;
	while(*head != NULL){
		temp = (*head)->pNext;
		free(*head);
		*head = temp;
	}
}
