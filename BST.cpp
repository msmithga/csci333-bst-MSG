#include "BST.h"
#include <iostream>

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;  
  return true;
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
  Node<T>** curr = &root;

  while(*curr != 0 && (*curr)->getValue() != v) {
    if(v < (*curr)->getValue()) {
	curr = &((*curr)->getLeftChild());
    }else if(v > (*curr)->getValue()) {
        curr = &((*curr)->getRightChild());
    }
  }

  if(*curr != 0) {
    Node<T>* rm = *curr;
    if(rm->getRightChild() == 0 && rm->getLeftChild() == 0) {
      *curr = 0;
    }else if(rm->getRightChild() == 0) {
      *curr = (*curr)->getLeftChild();
    }else if(rm->getLeftChild() == 0) {
      *curr = (*curr)->getRightChild();
    }else{
      Node<T>* ios = rm->getRightChild();
      while(ios->getLeftChild() != 0) {
        ios = ios->getLeftChild();
      }
      ios->setLeftChild(*(rm->getLeftChild()));
      *curr = (*curr)->getRightChild();
    }
    delete rm;
  }
}


template <typename T>
void BST<T>::printTree() {


}


template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
