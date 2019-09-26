#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"
#include <stack>

template <typename T>

class BSTree {
    Node<T> *root;
    size_t nodes;
    //Añadiendo a la clase

    Node<T> *intree( Node<T> *nodo) {
        if(nodo->left != nullptr) {
            return intree(nodo->left);
        }
        return nodo;
    }

public:
    BSTree() : root(nullptr), nodes(0){};

    Node<T>* remove( Node<T> *node, int data) {
        if (node == nullptr) {
            return nullptr;
        }
        if (data > node->data) {
            node->right = remove(node->right, data);
        } else if(data < node->data) {
            node->left = remove(node->left, data);
        } else {
            if (node->left == nullptr) {
                Node<T> *temp = node;
                node = node->right;
                if (temp == root)
                    root = node;
                nodes--;
                delete temp;
            }else if (node->right == nullptr) {
                Node<T> *temp = node;
                node = node->left;
                if (temp == root)
                    root = node;
                nodes--;
                delete temp;
            }else if (node->left == nullptr && node->right == nullptr) {
                if (node == root)
                    root = nullptr;
                nodes--;
                delete(node);
                node = nullptr;
            }else{
                Node<T> *temp = intree(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }}
        return node;
    }

    bool find(T data) {
        if (root == nullptr){
            return false;
        }
        Node<T> *it = root;
        while(data != it->data){
            if (data<it->data && it->left ){
                it = it->left;
            } else if (data> it->data && it->right ){
                    it = it->right;
                }
            else
                return false;
        }
        return true;
        // TODO
    }

    void insert(T data) {
        Node<T> * temp = new Node<T>(data);
        if (nodes != 0){
            Node<T> *ite = root;
            bool  clock = true;
            while (clock){
                if (data != ite->data){
                    if (data > ite->data){
                        if (ite->right ){
                            ite =ite->right;
                        }else{
                            ite->right = temp;
                            nodes++;
                            clock = false;
                        }
                    }else{
                        if(ite->left ){
                            ite = ite->left;
                        }else{
                            ite->left = temp;
                            nodes++;
                            clock = false;
                        }
                    }
                }else
                    clock = false;
            }
        } else{
            root = temp;
            nodes++;
        }
    }



    bool remove(T data) {
        if(remove(root,data) == nullptr)
            return false;
        else return true;
        // TODO
    }

    size_t size() {
        return nodes;
        // TODO
    }

    size_t height() {
        auto temp = root;
        if (temp) {
            size_t left = getHeight(temp->left);
            size_t rigth   = getHeight(temp->right);
            if (left > rigth) {
                return (left + 1);
            } else {
                return (rigth + 1);
            }
        }else
            return 0;
        // TODO
    }

    void traversePreOrder() {
        Node<T> *preorder = root;
        if (preorder == nullptr){
            throw out_of_range("Nothing");
        } else{
            cout<<preorder->data<<" ";
            print(preorder->left);
            print(preorder->right);
        }
        // TODO
    }

    void traverseInOrder() {
        Node<T> *inorder = root;
        if (inorder == nullptr){
            throw out_of_range("Nothing");
        } else{
            print(inorder->left);
            cout<<inorder->data<<" ";
            print(inorder->right);
        }
        // TODO
    }

    void traversePostOrder(){
        Node<T> *postorder = root;
        if (postorder == nullptr){
            throw out_of_range("Nothing");
        } else{
                print(postorder->left);
                print(postorder->right);
            cout<<postorder->data<<" ";
        }
        // TODO
    }

    void armariterador( stack<Node<T>*> *iterador, Node<T>* actual){
        if (actual != nullptr){
            iterador->push(actual);
            armariterador(iterador,actual->left);
        }
    }

    Iterator<T> begin() {
        stack<Node<T>*>* stacks;
        stacks=new stack<Node<T>*>;
        Node<T>* nulo = nullptr;
        stacks->push(nulo);
        armariterador(stacks,root);
        return Iterator<T>(stacks);
        // TODO
    }

    Iterator<T> end() {
        stack<Node<T>*> *iterador = new stack<Node<T>*>;
        Node<T> * final = nullptr;
        iterador->push(final);
        return Iterator<T>(iterador);
        // TODO

    }
    ~BSTree() {
        if(root != nullptr){
            delete root;
        }
        // TODO

    }

};

#endif
