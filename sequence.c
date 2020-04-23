#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

struct LIST {
    int elements[MAX];
    int last;
};
void insert(int x, int p, LIST& L);
int locate(int x, LIST& L);
int retrieve(int p, LIST& L);
void delete_(int p, LIST& L);
int previous(int p, LIST& L);
int next(int p, LIST& L);
void makenull(LIST& L);
int first(LIST& L);
int end(LIST& L);
void show(LIST& L);
int main() {
	LIST L;
	makenull(L);
	int i = 9;
	for (; i >= 0; i--) {
		insert(i, 0, L);
		show(L);
		//printf("Position: %d\n", locate(0, L));
		//printf("Retrieve %d: %d\n", i-1, retrieve(i-1, L));
	}
	delete_(5, L);
	show(L);
	printf("Previous %d: %d\n", 5, previous(5, L));
	printf("Next %d: %d\n", 5, next(5, L));
	printf("First: %d\n", first(L));
	printf("Last: %d\n", end(L));
    return 0;
}

void insert(int x, int p, LIST& L) {
	if (p < 0 || (L.last >= 0 && p > L.last)) {
		printf("error position!\n");
	}
	else if (L.last == MAX - 1)
		printf("the list is full!\n");
	else {
		int i = L.last;
		for (; i >= p; i--)
			L.elements[i + 1] = L.elements[i];
		L.elements[p] = x;
		L.last++;
	}
}

int locate(int x, LIST& L) {
	int i = 0;
	for (; i <= L.last; i++)
		if (L.elements[i] == x)
			return i;
	return -1;
}

int retrieve(int p, LIST& L) {
	if (L.last == -1) {
		printf("the list is empty!\n");
		return -1;
	}
	else if (p < 0 || (L.last >= 0 && p > L.last)) {
		printf("error position\n");
		return -1;
	}
	else
		return L.elements[p];

}

void delete_(int p, LIST& L) {
	if (L.last == -1) {
		printf("the list is empty!\n");
	}
	else if (p < 0 || (L.last >= 0 && p > L.last)) {
		printf("error position\n");
	}
	else {
		int i = p;
		for (; i < L.last; i++)
			L.elements[i] = L.elements[i + 1];
		L.last--;
	}
}

int previous(int p, LIST& L) {
	if (L.last == -1) {
		printf("the list is empty!\n");
		return -1;
	}
	else if (p < 1 || (L.last >= 0 && p > L.last)) {
		printf("error position\n");
		return -1;
	}
	return L.elements[p - 1];
}

int next(int p, LIST& L) {
	if (L.last == -1) {
		printf("the list is empty!\n");
		return -1;
	}
	else if (p < 0 || (L.last >= 0 && p > L.last - 1)) {
		printf("error position\n");
		return -1;
	}
	return L.elements[p + 1];

}

void makenull(LIST& L) {
	L.last = -1;
}

int first(LIST& L) {
	if (L.last == -1) {
		printf("The list is empty");
		return -1;
	}
	return L.elements[0];
}

int end(LIST& L) {
	if (L.last == -1) {
		printf("The list is empty");
		return -1;
	}
	return L.elements[L.last];
}

void show(LIST& L) {
	int i = 0;
	for (; i <= L.last; i++)
		printf("%d ", L.elements[i]);
	printf("\n");
}

