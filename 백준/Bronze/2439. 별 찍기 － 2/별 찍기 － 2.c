#include <stdio.h>

int main()
{
	int num, i, j, k;

	scanf("%d", &num);

	for (i = num; i > 0; i--)
	{
		for (j = i - 1; j> 0 ; j--)
		{
			printf(" ");
		}

		for (k = num-i+1; k > 0; k--)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}