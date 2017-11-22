/*
insert a node to any loction of a linked list 
delete a node from any loction of a linked list 
creat linked list from head
creat linked list from tail
https://www.kancloud.cn/digest/datastructbyc/143032
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct Data
{
	int num;
	char* name;
}Data;

typedef struct Node		
{
	Data* data;
	struct Node* next;
}Node;

Node* creatLLH();		//creat linked list from head to insert
void show(Node* head);	//print every linked list elements
Node* creatLLT();		//creat linked list from tail to insert
bool isempty(Node* head);	//judge if the linked list is empty
int lengthLL(Node* head);	//the length of linked list
bool insert(Node* head, int index);		//insert in the index position
bool deleteNode(Node* head, int index);	//delete the index node 

int main(){
	Node* nodeT;
	nodeT = creatLLT();
	show(nodeT);
	deleteNode(nodeT, 0);
	//insert(nodeT, 4);
	show(nodeT);
	return 0;
}

Node* creatLLH(){		//creat linked list from head to insert
	Node* head = malloc(sizeof(Node));
	head->data = malloc(sizeof(Data));		
	head->data->name = NULL;
	head->data->num = 0;
	head->next = NULL;		//above are initialize head node. also can do like this way:
							//Node* head = malloc(sizeof(Node));	head->data = NULL;	head->next = NULL;
	printf("Please input the length of linked list: ");
	int length = 0;
	scanf("%d", &length);
	int i = 0;
	for(i = 0; i < length; i++){
		printf("Please fill in the %d node:\n", i + 1);
		Node* node = malloc(sizeof(Node));
		node->data = malloc(sizeof(Data));
		node->data->name = malloc(sizeof(char) * 20);
		printf("Input the num: \n");
		int num = 0;
		scanf("%d", &num);
		printf("Input the name: \n");
		char* name = malloc(sizeof(char) * 20);		//or: char name[20] = {0};
		scanf("%s", name);
		strcpy(node->data->name, name);
		node->data->num = num;
		node->next = head->next;
		head->next = node;
	}
	return head;
}
	
void show(Node* head){		//print every linked list elements
	int i = 1;
	Node* temp = head;
	while(temp->next != NULL){
		printf("The %d node: num is %d, name is %s.\n", i++, temp->next->data->num, temp->next->data->name);
		temp = temp->next;
	}
}	

Node* creatLLT(){		//creat linked list from tail to insert
	Node* head = malloc(sizeof(Node));
	head->data = NULL;
	head->next = NULL;		//above 3 line, initialize head node
	Node* tail = head;		//tail is a pointer, operate tail dose not change head
	printf("Please input the length of linked list: ");
	int length = 0;
	scanf("%d", &length);
	int i = 0;
	for(i = 0; i < length; i++){
		printf("Please fill in the %d node.\n", i + 1);
		Node* temp = malloc(sizeof(Node));		
		temp->next = NULL;
		temp->data = malloc(sizeof(Data));
		printf("Please input the num: ");
		int num = 0;
		scanf("%d", &num);
		temp->data->num = num;
		printf("Please input the name: ");
		temp->data->name = malloc(sizeof(char) * 20);
		char name[20];
		scanf("%s", name);
		strcpy(temp->data->name, name);
		tail->next = temp;
		temp->next = NULL;
		tail = temp;
	}
	return head;
}

bool isempty(Node* head){	//judge if the linked list is empty
	if(NULL == head->next){
		return true;
	}
	else{
		return false;
	}
}	

int lengthLL(Node* head){	//the length of linked list
	int i = 0;
	Node* temp = head->next;
	while(temp != NULL){
		temp = temp->next;
		++i;
	}
	return i;
}

bool insert(Node* head, int index){		//insert in the index position
	Node* p = head;
	int i =0;
	while(i < index && p->next != NULL){
		p = p->next;
		i++;
	}
	if(i > index || (p->next == NULL && i != index)){
		printf("index cross the boundary.\n");
		return false;
	}
	Node* temp = malloc(sizeof(Node));
	temp->data = malloc(sizeof(Data));
	printf("Please input num:");
	int num;
	scanf("%d", &num);
	temp->data->num = num;
	printf("Please input name:");
	temp->data->name = malloc(sizeof(char) * 20);
	char name[20] = {0};
	scanf("%s", name);
	strcpy(temp->data->name, name);
	temp->next = p->next;
	p->next = temp;
	return true;
}

bool deleteNode(Node* head, int index){		//delete the index node 
	int i = 0;
	Node* p = head;
	Node* tmp=NULL;
	while(i < index && p->next != NULL){		
		p = p->next;
		i++;
	}
	if(i > index || p->next == NULL){
		printf("index cross the boundary.\n");
		return false;
	}
	tmp=p->next;
	p->next = tmp->next;
	free(tmp);
	return true;
}
