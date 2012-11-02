#include "BST.h"

int main() {
  BST<int>* bst = new BST<int>();

  bst->insert(10);
  bst->insert(15);
  bst->insert(5);
  bst->insert(13);
  bst->insert(17);
  bst->insert(12);
  bst->insert(11);
  bst->insert(16);

  bst->remove(17);

  bst->print();


}
