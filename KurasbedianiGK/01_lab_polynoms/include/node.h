#ifndef MP2_LAB4_POLYNOMS_NODE_H
#define MP2_LAB4_POLYNOMS_NODE_H

template<typename T>
class Node {
public:
    T data;
    Node<T> *next;

    explicit Node(const T &_data, Node<T> *_next = nullptr);

    Node(const Node<T> &_node);

    bool operator==(const Node<T> &rhs) const;

    bool operator!=(const Node<T> &rhs) const;

    bool operator<(const Node<T> &rhs) const;

    bool operator>(const Node<T> &rhs) const;

    bool operator<=(const Node<T> &rhs) const;

    bool operator>=(const Node<T> &rhs) const;
};

template<typename T>
Node<T>::Node(const T &_data, Node<T> *_next) : data(_data), next(_next) {}

template<typename T>
Node<T>::Node(const Node &_node) {
    data = _node.data;
    next = _node.next;
}

template<typename T>
bool Node<T>::operator<(const Node<T> &rhs) const {
    if (data < rhs.data)
        return true;
    if (rhs.data < data)
        return false;
    return next < rhs.next;
}

template<typename T>
bool Node<T>::operator>(const Node<T> &rhs) const {
    return rhs < *this;
}

template<typename T>
bool Node<T>::operator<=(const Node<T> &rhs) const {
    return !(rhs < *this);
}

template<typename T>
bool Node<T>::operator>=(const Node<T> &rhs) const {
    return !(*this < rhs);
}

template<typename T>
bool Node<T>::operator==(const Node<T> &rhs) const {
    return data == rhs.data;
}

template<typename T>
bool Node<T>::operator!=(const Node<T> &rhs) const {
    return !(rhs == *this);
}

#endif //MP2_LAB4_POLYNOMS_NODE_H
