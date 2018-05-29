#include <stdio.h>

void	init(int *arr, int *i, int *sum_l, int *sum_r, int n)
{
	
	*i=0;
	*sum_l = 0;
	*sum_r = 0;
	n--;
	while (n>=1)
{
	*sum_r = *sum_r + arr[n];
	n--;
}
 return;
}
void	next(int *arr, int *i, int *sum_l, int *sum_r)
{	
	*sum_l += arr[*i];
	*sum_r -= arr[*i + 1];
	*i+=1;
return;
}
	
int find_pivot(int *arr, int n)
{
	int i;
	int sum_r;
	int sum_l;
	if ((n<2)||(!arr))
		return(-1);	
	init(arr, &i, &sum_l,&sum_r,n);
	while(i < n-1)
	{
		if (sum_l == sum_r)
			return (i);
		next(arr, &i, &sum_l,&sum_r);
	}
	if (sum_l == sum_r)
		return (i);
	
	return (-1);
}
int main ()
{
	//int arr[21] = {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1};
	int arr[4] = { -5, 10, 2, 5 };


	printf("%d\n", find_pivot(arr, 4));

	return(0);
}
	
