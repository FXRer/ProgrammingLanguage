#include <stdio.h>

int main()
{
	int gyan[] = { 1,2,3,4,5 };
	int i,*ptr ;
	ptr = gyan;
	for(i = 0; i<=4 ; i++)
	{
		printf("\n %d", *ptr++);
	}
	return 0;
}
