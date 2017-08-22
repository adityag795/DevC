#include<stdio.h>
float avg (int array[],int size) 
{  
	int  *p, i , sum = 0;  
	p = array;  
	for (i=0; i<size; i++)      
		sum = sum + *(p+i);     
	return ((float) sum / size); 
}
void main() 
{  
	int x[100], k, n;  
	printf("Enter the no. of elements:");
	scanf ("%d", &n);  
	printf("\nNow enter %d elements:",n);
	for (k=0; k<n; k++)     
		scanf ("%d", &x[k]);
	printf ("\nAverage is %f",avg (x, n));
}