#include <stdio.h>
#include <malloc.h>

#define Arrsize 5

void mergeSoft(int a[], int L, int R);
void merge(int a[], int L, int mid, int R);

int main() {
	int a[Arrsize] = { 6,2,4,2,2 };

	mergeSoft(a, 0, Arrsize - 1);
	//´òÓ¡Êý×é
	for (int i = 0; i < Arrsize; i++) {
		printf("%d ", a[i]);
	}
	







	return 0;
}

void mergeSoft(int a[], int L, int R) {
	int mid = L + ((R - L) >> 1);
	
	if (L == R) {
		return ;
	}
	mergeSoft(a, L, mid);
	mergeSoft(a, mid+1, R);
	merge(a, L, mid, R);
	return;
}

void merge(int a[], int L,int mid,int R) {
	int res = 0;
	int p1 = L;
	int p2 = mid + 1;
	int* help = (int*)malloc(sizeof(int) * (R - L + 1));
	int i = 0;



	while (p1 <= mid && p2 <= R) {
		
		help[i++] = a[p1] < a[p2] ? a[p1++] : a[p2++];
	}
	while (p1 <= mid) {
		help[i++] = a[p1++];
	}

	while (p2 <= R) {
		help[i++] = a[p2++];
	}

	for (int j = 0; j < i; j++) {
		a[L + j] = help[j];
	}
	free(help);
	return;
}

