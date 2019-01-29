#include<stdio.h>
#include <stdlib.h>

void set_array_rand(int x[], int n);
void Sorting(int x[], int n);
void MERGE(int a[], int na, int b[], int nb, int c[], int nc);
void PRINT_ARRAY(char* name, int x[], int nx);

int main(int argv, char **argc)
{
	int a[50], b[70], c[120];
	set_array_rand(a, 50);
	set_array_rand(b, 70);
	Sorting(a, 50);
	Sorting(b, 70);
	MERGE(a, 50, b, 70, c, 120);
	PRINT_ARRAY("Array c", c, 120);
	return 0;
}

/* Gives the arrays random numbers*/
void set_array_rand(int x[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		x[i] = rand_int(30,100);
}

/* The function that returns a random number for the arrays*/
int rand_int(int a, int b)
{
	return rand()%(b-a+1) + a;
}

/* A function the sort the arrays*/
void Sorting(int x[], int n)
{
	int i, j, min, temp;
	for(j = 0; j < n - 1; j++){
		min = j;
		for(i = j+1; i < n; i++){
			if(x[i] < x[min]){
				min = i;
			}
		}
	if(min != j){
		temp = x[j];
		x[j] = x[min];
		x[min] = temp;
		}
	}
}


/* Function to merge array a and b together into array c*/
void MERGE(int a[], int na, int b[], int nb, int c[], int nc)
{
	int i = 0, k = 0, j = 0;
	while(k != na){
		c[i] = a[k];
		i++;
		k++;
	}
	while(j != nb){
		c[i] = b[j];
		i++;
		j++;
	}
	Sorting(c, nc);
/*merge array a and array b into array c while keeping it sorted.*/
}

/* Printing out array c*/
void PRINT_ARRAY(char* name, int x[], int nx)
{
	int i;
	for(i = 0; i < nx; i++)
		printf(" %d ", x[i]);
}
