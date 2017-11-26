/*
double circular linked  list:
insert a node to any position 
delete a node from any position 
creat linked list from tail
get length of a linked list
free all linked list

CSDN
http://blog.csdn.net/fisherwan/article/details/19801993
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
void freeall(pNODE *head);

int main(){
	pNODE head = creat();
	traverse(head);
	printf("The length of the linked list is: %d.\n", getlength(head));
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
		printf("Faliure to allocate memory.\n");
		return NULL;
	}
	head->data = 0;
	head->pNext = head;
	head->pPre = head;
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
		
		/*pNODE tail = head->pPre;
		//pNODE temp_pre = head->pPre;
		tail->pNext=new_;
		new_->pNext = head;
		new_->pPre = tail;		
		head->pPre = new_;*/
		
		new_->pPre = head->pPre;
		new_->pNext = head;
		temp->pNext = new_;
		head->pPre = new_;
		temp = new_;
		
		
	}
	return head;
}

void traverse(pNODE head){
	pNODE temp = head->pNext;
	while(temp != head){
		printf("%d", temp->data);
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
		pNODE new_ = malloc(sizeof(NODE));
		pNODE temp = head;
		if(new_ == NULL){
			printf("Failure to allocate memory.\n");
			return -1;
		}
		printf("Will insert in position %d. Please input the new node's data: ", pos);
		int data = 0;
		scanf("%d", &data);
		new_->data = data;
		while(pos != 1){
			pos--;
			temp = temp->pNext;
		}
		new_->pPre = temp;
		new_->pNext = temp->pNext;
		pNODE ttemp = temp->pNext;
		temp->pNext = new_;
		ttemp->pPre = new_;
		return 0;
		
	}
	else{
		printf("Illegal position.\n");
		return -1;
	}
}

int deletenode(pNODE head, int pos){
	if(pos > 0 && pos <getlength(head) + 1){
		pNODE temp = head;
		while(pos != 1){
			pos--;
			temp = temp->pNext;
		}
		pNODE ttemp = temp->pNext;
		temp->pNext = ttemp->pNext;
		ttemp->pPre = temp;
		free(ttemp);
		return 0;
	}
	else{
		printf("Illegal position.\n");
		return -1;
	}
}

void freeall(pNODE *head){
	pNODE temp = (*head)->pNext;
	while(temp != *head){
		pNODE ttemp = temp->pNext;
		free(temp);
		temp = ttemp;
	}
	free(*head);
}
