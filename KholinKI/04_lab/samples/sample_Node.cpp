#include "Node.h"

int main() {
	cout << "Creating object Node with name sample_node..." << endl;
	Node<double> sample_node;

	cout << endl;
	cout << "The node does not contain any data at this time" << endl;
	cout << endl;

	cout << "Let`s add something. For example, value type double 4" << endl << endl;
	sample_node.data = 4;
	cout << "sample_node" << endl;
	cout << "Data: "  << sample_node.data << endl;
	cout << "pNext: " << "nullptr" << endl;
	cout << endl;

	cout << "OK!we'll move on to the next node" << endl;
	sample_node.pNext = new Node<double>;
	cout << "Add something again in new node" << endl;
	cout << endl;
	sample_node.pNext->data = 6;
	cout << "sample_node.pNext" << endl;
	cout << "Data: " << sample_node.pNext->data << endl;
	cout << "pNext: " << "nullptr" << endl;
	cout << endl;

	cout << "in the same way creating next nodes..." << endl;
	return 0;
}