#include <stdio.h>
#include <stdlib.h>

struct cell {
	int data;
	cell* nxt;
};
typedef cell* LIST;
typedef cell* pos;

pos insert(int x, pos p, LIST L);
pos locate(int x, LIST L);
int retrieve(pos p, LIST L);
void delete_(pos p, LIST L);
pos previous(pos p, LIST L);
pos next(pos p, LIST L);
void makenull(LIST L);
pos first(LIST L);
pos end(LIST L);
void travel(LIST L);

int main() {
	LIST L = (LIST)malloc(sizeof(cell));
	if (!L) {
		printf("The storage is full! Cannot malloc!\n");
		return NULL;
	}
	L->nxt = NULL;

	int i = 9;
	pos tmp = NULL;
	for (; i >= 0; i--) {
		tmp = insert(i, L, L);
		//printf("Inserted: %d\n", tmp->data);
		//travel(L);

		//printf("Retrieve %d: %d\n", i, retrieve(tmp, L));
		/*
		tmp = locate(5, L);
		if (tmp)
			printf("Locate: %d\n", tmp->data);
		else
			printf("Cannot find!\n");*/
	}
	//delete_(tmp, L);
	travel(L);
	printf("Previous %d: %d\n", tmp->nxt->data, previous(tmp->nxt, L)->data);
	printf("Next %d: %d\n", tmp->nxt->data, next(tmp->nxt, L)->data);
	printf("First: %d\n", first(L)->data);
	printf("End: %d\n", end(L)->data);
	makenull(L->nxt);
	delete L;
	return 0;
}

pos insert(int x, pos p, LIST L) {
	pos tmp = (LIST)malloc(sizeof(cell));
	if (!tmp) {
		printf("The storage is full! Cannot malloc!\n");
		return NULL;
	}
	tmp->data = x;
	tmp->nxt = p->nxt;
	p->nxt = tmp;
	return tmp;
}

pos locate(int x, LIST L) {
	pos tmp = L->nxt;
	for (; tmp; tmp = tmp->nxt)
		if (tmp->data == x)
			return tmp;
	return NULL;
}

int retrieve(pos p, LIST L) {
	if (p->nxt)
		return p->nxt->data;
	return -1;
}

void delete_(pos p, LIST L) {
	pos tmp = p->nxt;
	if (tmp) {
		p->nxt = tmp->nxt;
		delete tmp;
	}
}

pos previous(pos p, LIST L) {
	pos tmp = L->nxt;
	for (; tmp->nxt; tmp = tmp->nxt)
		if (tmp->nxt == p)
			return tmp;
	return NULL;
}

pos next(pos p, LIST L) {
	return p->nxt;
}

void makenull(LIST L) {
	makenull(L->nxt);
	delete L;
}

pos first(LIST L) {
	return L->nxt;
}

pos end(LIST L) {
	pos tmp = L->nxt;
	for (; tmp->nxt; tmp = tmp->nxt);
	return tmp;
}

void travel(LIST L) {
	pos tmp = L->nxt;
	for (; tmp; tmp = tmp->nxt)
		printf("%d ", tmp->data);
	printf("\n");
}