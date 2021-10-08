#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	unsigned short flag[] = {79, 109, 67, 84, 70, 123, 103, 48, 84, 95, 102, 76, 52, 103, 95, 98, 49, 116, 95, 66, 121, 95, 66, 105, 55, 125};
	//OEIS A062993
	unsigned short seq[] = {1, 1, 1, 2, 1, 1, 5, 3, 1, 1, 14, 12, 4, 1, 1, 42, 55, 22, 5, 1, 1, 132, 273, 140, 35, 6, 1};
	int i;
	for(i = 0; i < 26; i++) {
		flag[i] ^= ~seq[i];
		flag[i] += 0xb;
		flag[i] <<= 3;
		flag[i] -= 0xda;
		flag[i] ^= seq[i];
		printf("%X ", flag[i]);
	}
	for(i = 0; i < 26; i++) {
		flag[i] ^= seq[i];
		flag[i] += 0xda;
		flag[i] >>= 3;
		flag[i] -= 0xb;
		flag[i] ^= ~seq[i];
		printf("%c", flag[i]);
	}
}