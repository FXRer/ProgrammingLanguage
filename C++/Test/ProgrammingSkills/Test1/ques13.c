#include <stdio.h>

int main()
{
	int i, j, *ptr, *ptr1;
	i = 10;
	j = 10;
	ptr = &i;
	ptr1 = &j;
	if(ptr == ptr1)
	{
		printf("True");
	}
	else
	{
		printf("False");
	}
	
	return 0;
}
