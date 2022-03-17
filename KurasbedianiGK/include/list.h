#ifndef MP2_LAB4_POLYNOMS_LIST_H
#define MP2_LAB4_POLYNOMS_LIST_H

#include "monom.h"
#include "node.h"
#include <ostream>
#include <cmath>

template<typename T>
class List {
private:
    Node<T> *head = nullptr;
    std::size_t size = 0;
public:
    explicit List();

    explicit List(Node<T> *_node);

    explicit List(const List<T> &_list);

    ~List();

    Node<T> *get_head() const;

    const std::size_t &get_size() const;

    void insert(const T &_data);

    void remove(const T &_data);

    List &operator=(const List &list);

    friend std::ostream &operator<<(std::ostream &os, const List &list);
};

template<typename T>
List<T>::List() {
    head = nullptr;
    size = 0;
}

template<typename T>
List<T>::List(Node<T> *_node) {
    if (_node) {
        head = new Node<T>(_node->data, _node->next);
        size = 1;
    }
}

template<typename T>
List<T>::List(const List<T> &_list) {
    if (_list.head == nullptr) {
        head = nullptr;
    } else {
        head = new Node<T>(_list.head->data, nullptr);

        Node<T> *list_currentNode = _list.head;
        Node<T> *this_currentNode = head;
        while (list_currentNode->next != nullptr) {
            this_currentNode->next = new Node<T>(list_currentNode->next->data, nullptr);
            this_currentNode = this_currentNode->next;
            list_currentNode = list_currentNode->next;
        }
    }
    size = _list.size;
}

template<typename T>
List<T>::~List() {
    Node<T> *tmp, *tmp1;
    tmp = head;
    tmp1 = tmp;
    while (tmp1 != nullptr) {
        tmp1 = tmp->next;
        delete tmp;
        tmp = tmp1;
    }
    size = 0;
}

template<typename T>
Node<T> *List<T>::get_head() const {
    return head;
}

template<typename T>
const std::size_t &List<T>::get_size() const {
    return size;
}

template<typename T>
void List<T>::insert(const T &_data) {
    if (head == nullptr) {
        head = new Node<T>(_data, nullptr);
    } else {
        head = new Node<T>(_data, head);
    }
}

template<>
void List<Monom>::insert(const Monom &_data) {
    if (fabs(_data.get_coefficient()) > 1e-8) {
        if (head == nullptr) {
            head = new Node<Monom>(_data, nullptr);
            ++size;
        } else {
            Node<Monom> *tmp = head;

            if (tmp->data.get_power() == _data.get_power()) {
                head = new Node<Monom>(tmp->data + _data,
                                       tmp->next);
            } else if (tmp->data < _data) {
                head = new Node<Monom>(_data, head);
                ++size;
            } else {
                while (tmp->next != nullptr && tmp->next->data.get_power() > _data.get_power()) {
                    tmp = tmp->next;
                }
                if (tmp->next != nullptr && tmp->next->data.get_power() == _data.get_power()) {
                    tmp->next = new Node<Monom>(tmp->next->data + _data,
                                                tmp->next->next);
                } else {
                    tmp->next = new Node<Monom>(_data, tmp->next);
                    ++size;
                }
            }
        }
    }
}

template<typename T>
void List<T>::remove(const T &_data) {
    if (head != nullptr) {
        Node<T> *prev = head;
        Node<T> *tmp;
        bool find = false;


        if (head->data == _data) {
            head = head->next;
            delete prev;
            find = true;
        }

        while (!find && (prev->next != nullptr)) {
            if (prev->next->data == _data) {

                tmp = prev->next;
                prev->next = prev->next->next;
                delete tmp;
                find = true;
            } else
                prev = prev->next;
        }
    }
}

template<typename T>
List<T> &List<T>::operator=(const List &list) {
    if (this != &list) {
        delete head;
        head = new Node<T>(list.head->data, nullptr);

        Node<T> *list_currentNode = list.head;
        Node<T> *this_currentNode = head;
        while (list_currentNode->next != nullptr) {
            this_currentNode->next = new Node<T>(list_currentNode->next->data, nullptr);
            this_currentNode = this_currentNode->next;
            list_currentNode = list_currentNode->next;
        }
    }
    return *this;
}

/*template<typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &list) {
    Node<T> *tmp = list.get_head();
    while (tmp) {
        os << tmp->data << ' ';
        tmp = tmp->next;
    }
    return os;
}*/

std::ostream &operator<<(std::ostream &os, const List<Monom> &list) {
    Node<Monom> *tmp = list.head;
    const double eps = 1e-8;
    bool wereMoreThanEpsCoef = false;
    while (tmp) {
        if (fabs(tmp->data.get_coefficient()) > eps) {
            wereMoreThanEpsCoef = true;
            os << tmp->data;
        }
        tmp = tmp->next;
    }
    if (!wereMoreThanEpsCoef) {
        os << 0.0;
    }
    return os;
}

#endif //MP2_LAB4_POLYNOMS_LIST_H
