#ifndef DATA_H
#define DATA_H

template<typename T> struct Data {
	T value;

	Data(const T& val);
};

template<typename T>
Data<T>::Data(const T& val) {
	value = val;
}
#endif