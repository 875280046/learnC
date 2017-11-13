#ifndef HERO_H
#define HERO_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Skill
{
	int num;
	char* name;	
}Skill;

typedef struct Hero
{
	int num;
	char* name;
	Skill skill;
}Hero;

void creatHero();
#endif
