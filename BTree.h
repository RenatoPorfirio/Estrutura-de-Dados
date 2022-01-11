#ifndef BTREE_H
#define BTREE_H

#include <algorithm> //para uso da funcao max
#include <cstddef>
#include "LDE.h"

using std::max;

template <class T>
class BTNode //No elementar para a BTree
{
public:
	T key; //chave armazenada;
	BTNode* parent; //ponteiro para o no pai;
	BTNode* left; //ponteiro para o no a esquerda;
	BTNode* right; //ponteiro para o no a direita;
	BTNode(T x){
		key = x;
		parent = left = right = NULL;
	}
	BTNode* set_leftChild(BTNode<T>*); //adiciona um no filho passado como parametro a esquerda;
	BTNode* set_rightChild(BTNode<T>*); //adiciona um no filho passado como parametro a direita;
};

template <class T> 
class BTree{
	template <class Typ>
	void aux_preOrder(BTNode<T>*,Typ(*f)(BTNode<T>*)); //metodo auxiliar para preOrder;
	template <class Typ>
	void aux_inOrder(BTNode<T>*,Typ(*f)(BTNode<T>*)); //metodo auxiliar para inOrder;
	template <class Typ>
	void aux_posOrder(BTNode<T>*,Typ(*f)(BTNode<T>*)); //metodo auxiliar para posOrder;
protected:
	BTNode<T>* root; //no para a raiz;
public:
	BTree(){root = NULL;}
	~BTree(){clear(root);}
	int size(BTNode<T>*); //determina o tamanho de uma subarvore dado o no raiz;
	BTNode<T>* getRoot(){return root;} //retorna um ponteiro para a raiz da arvore;
	void setRoot(BTNode<T>* u){root = u;} //modifica o no raiz da arvore, modificando tambem sua estrutura;
	int height(BTNode<T>*); //retorna a altura de um no passado como parametro;
	int depth(BTNode<T>*); //retorna a profundidade de um no passado como parametro;
	void clear(BTNode<T>*); //deleta uma subarvore, tendo como raiz o no passado como parametro;
	template <class Typ>
	void bftraverse(Typ(*f)(BTNode<T>*)); //faz uma travessia por nivel na arvore, aplicando uma funcao passada como parametro em cada no da arvore da esquerda para a direita, nivel por nivel;	
	template <class Typ>
	void preOrder(Typ(*f)(BTNode<T>*)){aux_preOrder(root,f);} //semelhante ao metodo bftraverse, porem, a ordem de aplicacao eh: no pai, filho a esquerda, filho a direita;
	template <class Typ>
	void inOrder(Typ(*f)(BTNode<T>*)){aux_inOrder(root,f);} //semelhante ao metodo bftraverse, porem, a ordem de aplicacao eh: filho a esquerda, no pai, filho a direita;
	template <class Typ>
	void posOrder(Typ(*f)(BTNode<T>*)){aux_posOrder(root,f);} //semelhante ao metodo bftraverse, porem, a ordem de aplicacao eh: filho a esquerda, filho a direita, no pai;
};

/*=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=*/

/*implementacoes dos metodos declarados*/

template <class T>
BTNode<T>* BTNode<T>::set_leftChild(BTNode<T>* u){
	if(u != NULL) u->parent = this;
	this->left = u;
	return u;
}

template <class T>
BTNode<T>* BTNode<T>::set_rightChild(BTNode<T>* u){
	if(u != NULL) u->parent = this;
	this->right = u;
	return u;
}

template <class T>
int BTree<T>::size(BTNode<T>* u){
	if(u == NULL) return 0;
	return 1 + size(u->left) + size(u->right);
}

template <class T>
int BTree<T>::height(BTNode<T>* u){
	if(u == NULL) return -1;
	return 1 + max(height(u->left),height(u->right));
}

template <class T>
int BTree<T>::depth(BTNode<T>* u){
	if(u == NULL) return -1;
	return 1 + depth(u->parent);
}

template <class T>
void BTree<T>::clear(BTNode<T>* u){
	if(u == NULL) return;
	clear(u->left);
	clear(u->right);
	delete u;
}

template <class T> template <class Typ>
void BTree<T>::bftraverse(Typ(*f)(BTNode<T>*)){
	LDE< BTNode<T>* > q;
	BTNode<T>* u = root;
	q.push_back(u);
	while(q.size() > 0){
		u = q.pop();
		f(u);
		if(u == NULL) return;
		if(u->left != NULL) q.push_back(u->left);
		if(u->right != NULL) q.push_back(u->right);
	}
}

template <class T> template <class Typ>
void BTree<T>::aux_preOrder(BTNode<T>* u,Typ(*f)(BTNode<T>*)){
	if(u == NULL) return;
	f(u);
	aux_preOrder(u->left,f);
	aux_preOrder(u->right,f);
}

template <class T> template <class Typ>
void BTree<T>::aux_inOrder(BTNode<T>* u,Typ(*f)(BTNode<T>*)){
	if(u == NULL) return;
	aux_inOrder(u->left,f);
	f(u);
	aux_inOrder(u->right,f);
}

template <class T> template <class Typ>
void BTree<T>::aux_posOrder(BTNode<T>* u,Typ(*f)(BTNode<T>*)){
	if(u == NULL) return;
	aux_posOrder(u->left,f);
	aux_posOrder(u->right,f);
	f(u);
}

#endif
