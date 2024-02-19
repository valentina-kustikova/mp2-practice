#include "TList.h"

#define count_links 4

int main() {
	Node<int>* First = new Node<int>(10);
	TList<int>* list = new TList<int>(First);
	for (int i = 0; i < count_links; i++) {
		list->insert_last(i);
	}
	list->remove(10);
	return 0;
}