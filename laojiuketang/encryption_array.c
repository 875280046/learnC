/*

encryption array: array[i] + index + key
in the same way dencryption array: newarray[i] - index - key

(pinyin: lingjichuxuebiancheng zhi Cyuyanrumen. teacher:xusong. laojiuxuetang) 
(chapter 13, classhour 67)
*/
#include<stdio.h>
#include<string.h>
#define KEY 3

char* encryption(char*);

int main(){
	char array[] = {"hello"};
	printf("%s\n", encryption(array));
	return 0;
}

char* encryption(char* array){
	int i = 0; 
	int count = strlen(array);
	for(i = 0; i < count; i++){
		array[i] = array[i] + i + KEY;
	} 
	return array;
}
