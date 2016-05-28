#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int num;
void strassen(int a[][num], int b[][num], int c[][num], int size);
int isPowerOfTwo (unsigned int x) // check that entered number is in the power of 2 or not?
{
  return ((x != 0) && ((x & (~x + 1)) == x));
}
int getRandomNumber(int minimum, int maximum){ // generating the random number with inclusive range 
	int i;
	
	i = rand()%(maximum-(minimum+1))+(minimum+1);
	return i;
}

void printMatrix(int coloumn, int (*ptr_arr)[coloumn]){ // printing the matrix 
	int i,j;
	
	for (i = 0; i < coloumn; ++i)
	{
		for ( j = 0; j < coloumn; ++j)
			{
				printf("%d\t",ptr_arr[i][j]);
			}
		printf("\n");		
	}
	printf("\n");
}

void simpleMultiplication(int num, int (*array1)[num],int (*array2)[num],int (*result)[num]){ // simple matrix multiplication
	int i,j,k;
	
	for ( i = 0; i < num; ++i) // initializing with the zero
	{
		for ( j = 0; j < num; ++j)
		{
			result[i][j]=0;
		}
	}
	
	for ( i = 0; i < num; ++i)
	{
		for ( j = 0; j < num; ++j)
		{
			for ( k = 0; k < num; ++k)
			{	
				result[i][j]=result[i][j]+(array1[i][k]*array2[k][j]); 
			}
		}
	}
	
}

int main(int argc, char *args[]){
	srand( (unsigned)time( NULL ) );
	int size=-1,i,j,power=atoi(args[1]);
	//printf("Creating Random Array1 and Array2 in 2 power, (Size 0 for exit)enter the size:\n");
	//scanf("%d",&power);
	if(isPowerOfTwo(power)){ // checking that number is in power of 2, if yes than check if value is not less than 2
		if(power<2){
			printf("strassen matrix Multiplication doesn't apply for size less than 2*2 matrix\n");
			return 0;
		}else{
			size=power;
		}	
	}else{
		printf("strassen matrix Multiplication required matrix in 2^k * 2^k order. K>0.\n");
		return 0;
	}
	//size=(int)(pow(2,power));
	num=size;
	int maximum=10;
	int minimum=(-10);
	int array1[size][size],array2[size][size],result1[size][size],result2[size][size];
	for ( i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			array1[i][j]=getRandomNumber(minimum,maximum);
			array2[i][j]=getRandomNumber(minimum,maximum);
		}
	}
	printf("-------------Matrix-1---------------\n");
	printMatrix(size,array1);
	printf("-------------Matrix-2----------------\n");
	printMatrix(size,array2);
	simpleMultiplication(size,array1,array2,result1);
	printf("==============Result of Simple Multiplication================\n");
	printMatrix(size,result1);
	printf("===============strassen's matrix Multiplication===============\n");
	strassen(array1,array2,result2,size);
	printMatrix(size,result2);
	return 0;
}






void strassen(int a[][num], int b[][num], int c[][num], int size) { // implementation of the stressan matrix multiplication

int p1[size/2][size/2], p2[size/2][size/2], p3[size/2][size/2], p4[size/2][size/2], p5[size/2][size/2], p6[size/2][size/2], p7[size/2][size/2];

int temp1[size/2][size/2], temp2[size/2][size/2];

int i, j;

if(size >= 2) {	//give recursive calls



for(i = 0; i < size / 2; i++) { //p1

	for(j = 0; j < size / 2; j++) {

		temp1[i][j] = a[i][j] + a[i + size / 2][j + size / 2];
		temp2[i][j] = b[i][j] + b[i + size / 2][j + size / 2];
	}

}



num = size / 2;

strassen(temp1, temp2, p1, size / 2); 



for(i = 0; i < size / 2; i++) { // p2

	for(j = 0; j < size / 2; j++) {

		temp1[i][j] = a[i + size / 2][j] + a[i + size / 2][j + size / 2];
		temp2[i][j] = b[i][j];
	}

}



num = size / 2;

strassen(temp1, temp2, p2, size / 2);



for(i = 0; i < size / 2; i++) { //p3

	for(j = 0; j < size / 2; j++) {

		temp1[i][j] = a[i][j];
		temp2[i][j] = b[i][j + size / 2] - b[i + size / 2][j + size / 2];
	}

}



num = size / 2;

strassen(temp1, temp2, p3, size / 2);



for(i = 0; i < size / 2; i++) { //p4

	for(j = 0; j < size / 2; j++) {

		temp1[i][j] = a[i + size / 2][j + size / 2];
		temp2[i][j] = b[i + size / 2][j] - b[i][j];
	}

}



num = size / 2;

strassen(temp1, temp2, p4, size / 2);



for(i = 0; i < size / 2; i++) { //p5

	for(j = 0; j < size / 2; j++) {

		temp1[i][j] = a[i][j] + a[i][j + size / 2];
		temp2[i][j] = b[i + size / 2][j + size / 2];
	}

}



num = size / 2;

strassen(temp1, temp2, p5, size / 2);



for(i = 0; i < size / 2; i++) { //p6

	for(j = 0; j < size / 2; j++) {

	temp1[i][j] = a[i + size / 2][j] - a[i][j];
	temp2[i][j] = b[i][j] + b[i][j + size / 2];
	}

}


num = size / 2;

strassen(temp1, temp2, p6, size / 2);



for(i = 0; i < size / 2; i++) { //p7

	for(j = 0; j < size / 2; j++) {

	temp1[i][j] = a[i][j + size / 2] - a[i + size / 2][j + size / 2];
	temp2[i][j] = b[i + size / 2][j] + b[i + size / 2][j + size / 2];
	}

}



num = size / 2;

strassen(temp1, temp2, p7, size / 2);



for(i = 0; i < size / 2; i++) { //c11, c12, c21, c22 

	for(j = 0; j < size / 2; j++) {

		c[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
		c[i][j + size / 2] = p3[i][j] + p5[i][j];
		c[i + size / 2][j] = p2[i][j] + p4[i][j];
		c[i + size / 2][j + size / 2] = p1[i][j] + p3[i][j] - p2[i][j] + p6[i][j];
		
		}

	}
}

else if(size == 1) {

c[0][0] = a[0][0] * b[0][0];

}


}
