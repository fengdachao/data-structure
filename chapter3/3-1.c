#include "stdio.h"

struct Chain {
	int data;
	Chain* next;
};

int main() {
	struct Chain header;
	struct Chain previous;
	previous.data = -1;
	header.data = -1;
	header.next = &previous;
	for(int i = 0; i < 10 ; i++) {
		if (previous.data == -1) {
			previous.data = i;
		}
		else {
			struct Chain d;
			d.data = i;
			previous.next = &d;
			previous = d;
		}
	}
	struct Chain chain = header;
	while(chain.next != NULL) {
		printf("%d", chain.data);
		chain = &chain.next;
	}
	return 0;
}

