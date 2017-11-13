/*
dynamic creat hero file
attention: malloc free, scanf string, provide optional choices

(pinyin: lingjichuxuebiancheng zhi Cyuyanrumen. teacher:xusong. laojiuxuetang) 
(chapter 13, classhour 71)
*/
#include"hero.h"

int main(){
	creatHero();
	return 0;
}
/*		for convenience
typedef struct Skill
{
	int num;
	char* name;	
}Skill;

typedef struct Hero
{
	int num;
	char* name
	Skill skill;
}Hero;
*/
void creatHero(){
	Skill skill[3] = {		//struct array
		{1, "paishang"},
		{2, "daohai"},
		{3, "bashu"}
	};
	Hero* hero = malloc(sizeof(Hero));		//hero type is pointer, remember malloc
	printf("Please input hero's num: ");
	scanf("%d", &hero->num);		//remember &
	printf("Please input hero's name: ");
	hero->name = malloc(20);
	scanf("%s", hero->name);		//hero->name is already address, with no need for &
	printf("choice a skill: \n");
	int i = 0;
	for(i = 0; i < 3; i++){
		printf("%d %s\n", i + 1, skill[i].name);	//combine with below "choice", obtain dynamic selection skill
	}
	int choice = 0;
	scanf("%d", &choice);
	printf("%d %s %s", hero->num, hero->name, skill[choice - 1].name); 
	free(hero->name);
	free(hero);
}


