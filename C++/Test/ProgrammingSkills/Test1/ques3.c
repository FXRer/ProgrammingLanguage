#include <stdio.h>

int main()
{
	int i, j, k;
	
	i=3;
	j=2*(i++);
	k=2*(++i);
	
	printf("%d %d %d\n", i, j, k);
	return 0;
}
