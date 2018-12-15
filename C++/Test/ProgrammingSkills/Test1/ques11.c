#include <stdio.h>

int main()
{
	int i, j;
	i = 10;
	j = 30;
	if(i == 20 || (j++))
	{
		printf("True, %d", j);
	}
	else
	{
		printf("False %d", j);
	}	
	return 0;
}

