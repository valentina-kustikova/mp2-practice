#ifndef _EXEPTION_H
#define _EXEPTION_H

using namespace std;
enum TypeExeption { WRONG_SIZE,WRONG_INDEX,WRONG_DIMENSION };
template <class T>
class Exeptions {
private:
	TypeExeption type;
	T wrong_value;
public:
	Exeptions(TypeExeption type, T wrong_value);

	void what()const;
};

template <class T>
Exeptions<T>::Exeptions(TypeExeption type, T wrong_value) {
	this->type = type;
	this->wrong_value = wrong_value;
}

template <class T>
void Exeptions<T>::what()const {
	switch (type) {
	case WRONG_SIZE: cout << "Size is negative or out of range: " << wrong_value << endl;
	case WRONG_INDEX: cout << "Index is negative or out of range of size array" << wrong_value << endl;
	case WRONG_DIMENSION: cout << "Not exist matrix with negative or zero dimension! " << wrong_value << endl;
	default: {cout << "Exeption not found!" << endl; abort(); }
	}
}

#endif
