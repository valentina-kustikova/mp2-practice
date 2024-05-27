#include "TNode.h"

int main() {
	cout << "Creating object TNode with name sample_TNode..." << endl;
	TNode<double> sample_TNode;

	cout << endl;
	cout << "The TNode does not contain any data at this time" << endl;
	cout << endl;

	cout << "Let`s add something. For example, value type double 4" << endl << endl;
	sample_TNode.data = 4;
	cout << "sample_TNode" << endl;
	cout << "Data: "  << sample_TNode.data << endl;
	cout << "pNext: " << "nullptr" << endl;
	cout << endl;

	cout << "OK!we'll move on to the next TNode" << endl;
	sample_TNode.pNext = new TNode<double>;
	cout << "Add something again in new TNode" << endl;
	cout << endl;
	sample_TNode.pNext->data = 6;
	cout << "sample_TNode.pNext" << endl;
	cout << "Data: " << sample_TNode.pNext->data << endl;
	cout << "pNext: " << "nullptr" << endl;
	cout << endl;

	cout << "in the same way creating next TNodes..." << endl;
	return 0;
}