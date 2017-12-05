/*
binary tree: creat and print
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	char data;
	struct Node* lchild;
	struct Node* rchild;
}Node, *pNode;

void creattree(pNode *p){		//preorder creat a binary tree
	char c;
	scanf("%c", &c);
	if(c == ' '){		//use space to represent NULL
		(*p) = NULL;
	}	
	else{
		(*p) = malloc(sizeof(Node));
		(*p)->data = c;
		creattree(&(*p)->lchild);
		creattree(&(*p)->rchild);
	}
}

show(char c, int level){
	printf("%c is in %d level.\n", c, level);
}

void traverse(pNode p, int level){		//preorder traverse a tree
	if(p != NULL){
		show(p->data, level);
		traves(p->lchild, level + 1);
		traves(p->rchild, level + 1);
	}
}

int main(){
	pNode t = NULL;
	int level = 1; 
	creattree(&t);
	traves(t, level);
	return 0;
}
