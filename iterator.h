#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

template <typename T>

class Iterator {

private:
    //Node<T> *current;
    stack<Node<T>*>* current;

public:
    //Iterator() {
        // TODO
    //}
    Iterator(stack<Node<T>*>*nodos) {
        current = NULL;
        this->current = nodos;
    }

    Iterator<T>& operator=(const Iterator<T> &other) {
        this->current = other.current;
        this->temp = current->top();
        // TODO
    }

    bool operator!=(Iterator<T> other) {
        return this->current->top() != other.current->top();
        // TODO
    }

    Iterator<T>& operator++() {
        Node<T>* temp = current->top();
        Node<T>* it= nullptr;
        current->pop();
        if (temp->right != nullptr){
            it = temp->right;
            current->push(it);
            while (it->left != nullptr){
                it = it->left;
                current->push(it);
            }
        }
        return *this;
        // TODO
    }
     /* Iterator<T>& operator--() {
         return *this;
         // TODO
     }*/
    T operator*() {
        if(current)
            return (this->current->top())->data;
        throw out_of_range("Empty");
        // TODO
    }

};
#endif
