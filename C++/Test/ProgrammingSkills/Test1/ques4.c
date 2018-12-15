#include <stdio.h>

int main()
{
	int i;
	i=0;
	do
	{
		--i;
		printf("%d\n", i);
		i++;
	}while (i>=0);
	
	return 0;
}
