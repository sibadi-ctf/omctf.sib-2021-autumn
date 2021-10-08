#include <stdio.h>

void main() {
	int pincode;
	printf("pincode\n> ");
	scanf("%d", &pincode);
	if(pincode / 100000 == 0)
		if(pincode % 100 / 10 == 5)
			if((pincode % 10000 / 1000) + (pincode % 10) == 18)
				if((pincode ^ 0x4A15) == (0xA4E2 & pincode))
					if(pincode < 60000 && pincode > 20000)
						printf("Good!\n");
	return;
}