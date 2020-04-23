#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	node* nxt;
};
typedef node* cell;

int main() {
	int n = 3, m = 3, i=2;
	cell head = (cell)malloc(sizeof(node)), tmp = NULL;
	head->data = 1;
	head->nxt = NULL;
	for (tmp = head; i <= n; i++) {
		cell pos = (cell)malloc(sizeof(node));
		pos->data = i;
		tmp->nxt = pos;
		pos->nxt = NULL;
		tmp = pos;
	}
	tmp->nxt = head;

	cell pre = tmp;
	tmp = head;
	int counter = 1;
	while (tmp != tmp->nxt) {
		if (counter == m) {
			pre->nxt = tmp->nxt;
			delete tmp;
			tmp = pre->nxt;
			counter = 1;
		}
		pre = pre->nxt;
		tmp = tmp->nxt;
		counter++;
	}
	printf("%d\n", tmp->data);
	return 0;
}