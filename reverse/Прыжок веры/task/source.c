#include <stdio.h>
#include <stdlib.h>

void recaman(int *arr, int n)
{
    // First term of the sequence is always 0
    arr[0] = 0;
    //printf("%d, ", arr[0]);
 
    // Fill remaining terms using recursive
    // formula.
    for (int i=1; i< n; i++)
    {
        int curr = arr[i-1] - i;
        int j;
        for (j = 0; j < i; j++)
        {
            // If arr[i-1] - i is negative or
            // already exists.
            if ((arr[j] == curr) || curr < 0)
            {
                curr = arr[i-1] + i;
                break;
            }
        }
 
        arr[i] = curr;
        //printf("%d, ", arr[i]);
    }
}

void main(int argc, char** argv) {
	int k;
	int smth1[35], smth2[35], smth3[35] = {-65, -74, 79, -45, 57, -33, -29, 113, -62, 91, 80, 28, 24, 82, 135, 136, -82, 65, 105, -6, -87, 154, -42, -43, 124, 43, -12, 94, -63, 73, 118, 42, -30, 4, -54};
	srand('O'+'m'+'C'+'T'+'F'+'{'+'t'+'h'+'i'+'s'+' '+'f'+'l'+'a'+'g'+' '+'i'+'s'+' '+'f'+'o'+'r'+' '+'l'+'o'+'s'+'e'+'r'+'s'+')'+'0'+')'+'}');
	printf("I need a number.\n");
	scanf("%d", &k);
	recaman(smth1, 35);
	if(k == 1 && k == 3 && k == 3 && k == 7) {
		for(int i = 0; i < 35; i++) {
			smth2[i] = rand() % 0xFF;
		}
		for(int i = 0; i < 35; i++) {
			printf("%c", (smth1[34-i] ^ smth2[i]) - smth3[i]);
		}
		printf("\n");
	}
}