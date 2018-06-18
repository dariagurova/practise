#include <stdio.h>

int	calc(int a, int b, int c, int n)
{
	return(((a*10+b)+(c*10+a))==n);
}
void	equation(int n)
{
	int a = 0;
	int b = 0;
	int c= 0;
	
	while(a <10)
	{
		b=0;
		while(b<10)
		{
			c=0;
			while (c<10)
			{
				if(calc(a,b,c,n))
				printf("A = %d, B = %d, C = %d\n", a,b,c);
				c++;
			}
		b++;
		}
	a++;
	}
}
int	main()
{
	equation(42);
	return (0);
}
			
