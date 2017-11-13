/*
test for all kinds of situations of struct initiallize, struct assigement, struct pointer, deep copy 
(pinyin: lingjichuxuebiancheng zhi Cyuyanrumen. teacher:xusong. laojiuxuetang) 
(chapter 14, classhour 71)
*/
#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct People
{
	int age;
	char pname[200];
	char skill[2][200];
	char* fathername;	
}People;

typedef struct team
{
	int num;
	char name[20];
	char* xinname;
	People p;
}team;

int main(){
//	team hina = {.num = 1, .name = "chinano1", .xinname = "wawawa", {.age = 20, .skill[0] = "paishandaohai", .fathername = "ff"}};	//zhezhong fang fa ke xing
	team* china = malloc(sizeof(team));
	china->num = 1; 
	strcpy(china->name, "chinano1");
	china->xinname = "wawawa";
	//china->p = {.age = 20, .skill[0] = "paishandaohai", .fathername = "ff"};		//buneng zheme fuzhi, zhineng zai chushihua de shihou yong zheyang fuzhi
	china->p.age = 20;
	strcpy(china->p.skill[0], "paishan");
	china->p.fathername = malloc(20);		//deep copy, remember free
	strcpy(china->p.fathername, "ff");
	//china->p.fathername="ff";		//shallow copy, free will cause error
	printf("%d %s %s %d %s %s\n", china->num, china->name, china->xinname, china->p.age, china->p.skill[0], china->p.fathername);
	free(china->p.fathername);
	free(china);
	return 0;
}
