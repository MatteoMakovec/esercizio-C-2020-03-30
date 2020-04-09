#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

unsigned long fibonacci(unsigned int n);
unsigned long * fibonacci_array(unsigned int n);
unsigned long * reverse(unsigned long * array, unsigned int i, unsigned int j);
unsigned long * complete_reverse(unsigned long * array, unsigned int array_len);
void swap(unsigned long *x, unsigned long *y);
void output(unsigned long* array, unsigned int n);
void bubble_sort(unsigned long * array, unsigned int array_dimension);

int main(int argc, char *argv[]) {
	// [ A ]
	printf(" [ A ] \n");
	unsigned int n = 39;
	printf("\nThe item (%u) of the Fibonacci's series is: %lu\n\n", n, fibonacci(n));


	// [ B ]
	printf(" **********************************************\n");
	printf(" [ B ] \n\n");
	unsigned long *fibonacci_result = fibonacci_array(n);
	output(fibonacci_result, n);


	// [ C ]
	printf("\n\n **********************************************\n");
	printf(" [ C ] \n\n");
	unsigned long *fibonacci_result_copy = calloc(n+1, sizeof(unsigned long));
	memcpy(fibonacci_result_copy, fibonacci_result, (n+1) * sizeof(unsigned long));
	printf("Make copy of the array:\n");
	output(fibonacci_result_copy, n);
	printf("\n\nReverse the array:\n");
	complete_reverse(fibonacci_result_copy, n+1);
	output(fibonacci_result_copy, n);
	printf("\n\nUse Bubble Sort:\n");
	bubble_sort(fibonacci_result_copy, n+1);
	output(fibonacci_result_copy, n);
	printf("\n\nCompare the arrays:\n");
	int r = memcmp(fibonacci_result, fibonacci_result_copy, n+1);
	if(r == 0){
		printf("They are the same array!!");
	}
	else{
		printf("They are two different arrays!!");
	}


	return 0;
}


unsigned long fibonacci(unsigned int n) {
	unsigned long firstNum = 0;
	unsigned long secondNum = 1;
	unsigned long result = 0;

	switch (n) {
		case 0:
			result = firstNum;
			break;
		case 1:
			result = secondNum;
			break;
		default:
			for (int i = 1; i < n; i++) {
				result = secondNum + firstNum;
				firstNum = secondNum;
				secondNum = result;
			}
			break;
	}

	return result;
}


unsigned long * fibonacci_array(unsigned int n) {
	unsigned long *result = calloc(n+1, sizeof(unsigned long));

	switch (n) {
		case 0:
			break;
		case 1:
			result[1] = 1;
			break;
		default:
			for (int i = 1; i < n+1; i++) {
				result[i] = fibonacci(i);
			}
			break;
	}

	return result;
}


unsigned long * reverse(unsigned long * array, unsigned int i, unsigned int j) {
	while (i < j) {
		j--;
		swap(&array[i], &array[j]);
		i++;
	}

	return array;
}


unsigned long * complete_reverse(unsigned long * array, unsigned int array_len) {
	return reverse(array, 0, array_len);
}


void swap(unsigned long *x, unsigned long *y) {
	unsigned long t = *x;
	*x = *y;
	*y = t;
}


void bubble_sort(unsigned long * array, unsigned int array_dimension) {
	unsigned int n = array_dimension;
	unsigned int newn;
	do {
		newn = 0;
		for (unsigned int i = 1; i < n; i++) {
			if (array[i-1] > array[i]) {
				swap(&array[i-1], &array[i]);
				newn = i;
			}

		}

		n = newn;

	} while (n > 1);
}


void output(unsigned long* array, unsigned int n) {
	for(int i = 0; i < n+1; i++){
		printf("%lu  ", array[i]);
	}
}
