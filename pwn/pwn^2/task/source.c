#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
	char input[100];
	char something_interesting[100];
	printf("ENTER THE KEY: ");
	fflush(stdout);
	scanf("%99s", input);
	//system("echo -n $(md5sum /home/pwn3/keyholder) | cut -d\" \" -f1 > /home/pwn3/secret");
	system("bash /home/pwn3/magic.sh");
	FILE *fptr = fopen("/home/pwn3/secret","r");
	fscanf(fptr,"%s", something_interesting);
	//printf("%s\n", something_interesting);
	fflush(stdout);
	fclose(fptr);
	if(!strcmp(input, something_interesting)) {
		FILE *fptr = fopen("/home/pwn3/flag","r");
		fscanf(fptr,"%s", something_interesting);
		printf("RIGHT...\n%s\n", something_interesting);
		fflush(stdout);
		fclose(fptr);
	} else {
		printf("WRONG...");
	}
}