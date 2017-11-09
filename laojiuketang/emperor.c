/*
practice one dimensional array, two dimensional array.
litter game: you are an emperor, live for 10 days to win, don't let the favorability reduce to 50.

(pinyin: lingjichuxuebiancheng zhi Cyuyanrumen. teacher:xusong. laojiuxuetang) 
*/

#include<stdio.h>
#include<string.h>
#define MAXNUM 6

char name[MAXNUM][20] = {"Snow_White", "Litter_Red", "Cinderella", "Beyonce", "Stone",};
char level[5][20] = {"maid", "concubine", "girlfriend", "wife", "queen"};		//girl's level combine with level_num when useing eg.level
int level_num[MAXNUM] = {0, 0, 0, 0, 0, -1,};
int favorability[MAXNUM] = {100, 100, 100, 100, 100, -100,};
int i;
int count = 5;		//current number of girls
char ename[20] = {" "};		//emperor's name
int choice = 0;		//switch choice
char tempname[20];
int flag = 0;
int tempi = 0;
int day = 0;		//days of survival
int live = 0;	//0 is alive -1 is gameover

void add();
void interface();
void show();

int main(){	
	//interface
	printf("you are an emperor, live for 10 days to win, don't let the favorability reduce to 50.\n");
	printf("Please input an emperor's name: ");
	scanf("%s", ename);
	interface();
	return 0;
} 

void show(){		//show current status
	printf("\n*********************************************\n");
	printf("%-15s%-12s%-12s\n", "Name", "Level", "Favorability");		//-15 means: - left justify  15 show 15byte space
	for(i = 0; i < count; i++){
		printf("%-15s%-12s%-12d\n", name[i], level[level_num[i]], favorability[i]);
	} 
}

void add(){		//add a girl
	printf("Please input a girl's name: ");
	scanf("%s", name[count]);
	level_num[count] = 0;
	favorability[count] = 100;
	count++;
	printf("\n\n");
}

void interface(){
	printf("********************************************************\n");
	printf("Day %d\n", day++);		//days of survival
	if(day == 10){
		printf("Today is 10 day, you insist 10 days, you win!\n");
		live = -1;
	}
	else{
		for(i = 0; i < count; i++){
			if(favorability[i] <= 50){
				live = -1;
				printf("%s's favoriability is lower than 50, game over.\n", name[i]);
				break;
			}
		}
	}
	
	printf("The emperor is: %s\n", ename);
	printf("1. Add a girl\n");
	printf("2. Give a gilr a prize\n");
	printf("3. Banish a gile\n");
	printf("4. Show current status\n");
	printf("********************************************************\n");
	printf("Choice a number you want: ");
	scanf("%d", &choice);
	//printf("\n\n");
	if(live == 0){
		switch(choice){
			case 1:		//add: 1.judge whether there is enough space or not before add. 2 add array elements(name, level_num, favorability)
				if(count < MAXNUM){
					add();
					interface();
				}
				else{
					printf("Already reached the maximum number of girls, fail to add\n\n\n");
					interface();
				}
				break;
			case 2:		//search a girl and modify her status(jibie -1, haogandu +10, ruguo zuigao ji ze bubian), modify other girl's status(haogandu -10)
				for(i = 0; i < count; i++){
					printf("%s,  ", name[i]);
				}
				printf("\nWho do you want to give a prize, enter her name: ");
				scanf("%s", tempname);
				for(i = 0; i < count; i++){
					if(strcmp(tempname, name[i]) == 0){		//strcmp: compare two strings, return 0 when two strings are the same
						tempi = i;
						flag = 1;
					}
				}
				if(flag == 1){		//search a girl and modify her status(jibie -1, haogandu +10, ruguo zuigao ji ze bubian), modify other girl's status(haogandu -10)
					for(i = 0; i < count; i++){
						favorability[i] -= 10;
					}
					level_num[tempi] = (level_num[tempi] ==4 ? 4: level_num[tempi]+1);
					favorability[tempi] += 20;
					interface();
				}
				else{
					printf("Sorry, there is no one here by that name.\n\n\n");
					interface();
				}
				break;
			case 3:		//delete a girl: 1 search a girl name. 2 back element move forward. 3 count-- 4 other girl's favorability -20
				for(i = 0; i < count; i++){
					printf("%s,  ", name[i]);
				}
				printf("\nWhich girl you want to banish? Enter her name: ");
				scanf("%s", tempname);
				for(i= 0; i < count; i++){
					if(strcmp(tempname, name[i]) == 0){
						flag = 1;
						tempi = i;
					}
				}
				if(flag == 1){		//don't forget level_num, favorability, count--
					for(i = tempi; i < count - 1; i++){
						strcpy(name[i], name[i + 1]);
						level_num[i] = level_num[i + 1];
						favorability[i] = favorability[i + 1];
					}
					count--;
					for(i = 0; i < count; i++){
						favorability[i] -= 20;
					}
					interface();
				}
				else{
					printf("No such a person.");
					interface();
				}
				break;
			case 4:
				show();
				interface();
				break;
			default:
				printf("Wrong input, please reinput again.\n");
				interface();
		}	
	}
	
}
