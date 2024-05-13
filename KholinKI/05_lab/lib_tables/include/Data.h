#ifndef DATA_H
#define DATA_H

template<typename T> struct Data {
	T value;//значение
	Data(const T& val);
	Data(const Data& obj);
};

template<typename T>
Data<T>::Data(const T& val) {
	value = val;
}

template<typename T>
Data<T>::Data(const Data& obj) {
	value = obj.value;
}
#endif