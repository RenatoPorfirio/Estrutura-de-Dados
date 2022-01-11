#include <iostream>
#include "BTree.h"

using namespace std;

template <class T>
void print(BTNode<T>* u){
	if(u != NULL)
		cout << u->key << endl;
}

int main(){
	BTree<int> t; //arvore inicializada (root = null);
	t.setRoot(new BTNode(1)); //alocando memoria no ponteiro da raiz;
	
	BTNode<int>* a = t.getRoot(); //o ponteiro "a" passa a apontar para a raiz da arvore;
	BTNode<int>* b = a->set_leftChild(new BTNode(2)); //o ponteiro "b" passa a apontar para o novo espaco de memoria alocado como filho a esquerda do no "a";
	BTNode<int>* c = a->set_rightChild(new BTNode(3)); //o ponteiro "c" passa a apontar para o novo espaco de memoria alocado como filho a direita do no "a";
	
	b->set_leftChild(new BTNode(4)); //adicionando filho a esqueda de b;
	b->set_rightChild(new BTNode(5)); //adicionando filho a direita de b;
	c->set_leftChild(new BTNode(6)); //adicionando filho a esqueda de c;
	c->set_rightChild(new BTNode(7)); //adicionando filho a direita de c;
	
	t.bftraverse<void>(print);
	return 0;
}
