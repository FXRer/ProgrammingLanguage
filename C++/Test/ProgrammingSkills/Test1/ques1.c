#include <stdio.h>

int main()
{
	int x=20, y=35;
	x=y++ + x++;
	printf("%d %d\n", x, y);
	y=++y + ++ x;
	printf("%d %d\n", x, y);	
	
	return 0;
}
