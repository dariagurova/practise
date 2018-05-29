
#include <stdio.h>
#include <stdlib.h>

int	*hist(char *s,int * histo)
{
	int i = 0;
	while (i < 255)
	{
		char ch = (char)i;
		int j = 0;
		histo[i]=0;
		while (s[j] != '\0')
		{
			if(ch == s[j])
				histo[i] += 1;
		j++;
		}
	i++;
	}
return (histo);
}
int	compare(int *a, int *b)
{
	int i = 0;
	while (i < 255)
	{
	printf("i=%d a[i]=%d b[i]=%d\n",i,a[i],b[i]);
		if (a[i] != b[i]){
	printf("jkhcf\n");
			return(0);}
	i++;
	}
	return (1);
}
 
int main ()
{
	char *a = "rabbit";
	char *b = "bitrcb";
	
	int *ah = malloc(256*sizeof(int));
	ah= hist(a,ah);
	int *bh = malloc(256*sizeof(int));
	bh = hist(b,bh);
	if (compare(ah,bh))
		printf("Anagram\n");
	else
		printf("Not anagram\n");
	return (0);
}
	
	
	
