#include <stdio.h>

void give_flag() {
	printf("Bzzzzzzt! Bzzzbrrrt...\nBeep. Beep. Beep beep beep beep bop!\nBoop beep bop.\n");
	fflush(stdout);
	char flag[100];
	FILE *fptr = fopen("/home/pwn2/flag","r");
	fscanf(fptr,"%s", flag);
	printf("%s\n", flag);
	fflush(stdout);
	fclose(fptr);
}

void impossible() {
	char x[10];
	printf("Bop beep. Beep bop boop! Boop?\nBeep bop: ");
	fflush(stdout);
	scanf("%s", &x);
	return;
}

void main() {
	char need_help;
	fflush(stdout);
	printf("Boop beep bop! Beep beep bop beep.\nBoop bop!\n");
	printf("\nPlease read:\nA personal appeal from task creator.\n\nI won't go into details, but I can't disable ASLR on this machine due to many reasons. (not because I don't know how)\nSo to help you solve this task, I can give you address of the main function. If you know what you are doing, you know how to use it and what I'm talking about.\nIt's up to you if you wanna use it, if you are more skilled, I guess you can do it without my help, but there will be no reward for solving without my hint.\n\n");
	printf("So, do you need main function address? [y/n]\n");
	fflush(stdout);
	scanf("%c", &need_help);
	if(need_help == 'y' || need_help == 'Y') {
		printf("No worries, here it is!\n&main = %X\n", &main);
	} else {
		printf("Ok, you're on your own!\n");
	}
	fflush(stdout);
	impossible();
	printf("Beep bop beep boop...\n Boop beep!\n");
	fflush(stdout);
}