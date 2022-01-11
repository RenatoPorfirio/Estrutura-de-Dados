#ifndef BSTREE_H
#define BSTREE_H

#include "BTree.h"

template <class T>
class BSTree : protected BTree<T>{
	BTNode<T>* aux_getNode(BTNode<T>*,T);
	bool aux_add(BTNode<T>*,T);
	BTNode<T>* getRightMin(BTNode<T>*);
protected:
	using BTree<T>::root;
	int tam;
public:
	BSTree() : BTree<T>(){tam = 0;}
	int size(){return tam;}
	BTNode<T>* getNode(T x){return aux_getNode(root,x);}
	bool find(T x){
		if(getNode(x) == NULL) return false;
		return true;
	}
	bool add(T x){return aux_add(root,x);}
	bool remove(T);
	using BTree<T>::bftraverse;
	using BTree<T>::preOrder;
	using BTree<T>::inOrder;
	using BTree<T>::posOrder;
	using BTree<T>::getRoot;
};

template <class T>
BTNode<T>* BSTree<T>::aux_getNode(BTNode<T>* u, T x){
	if(u == NULL) return NULL;
	if(x < u->key) return aux_getNode(u->left,x);
	if(x > u->key) return aux_getNode(u->right,x);
	return u;
}

template <class T>
bool BSTree<T>::aux_add(BTNode<T>* u, T x){
	if(root == NULL){
		root = new BTNode(x);
		tam++;
		return true;
	}
	if(x < u->key){
		if(u->left != NULL)
			return aux_add(u->left,x);
		u->set_leftChild(new BTNode<T>(x));
		tam++;
		return true;
	}
	if(x > u->key){
		if(u->right != NULL)
			return aux_add(u->right,x);
		u->set_rightChild(new BTNode<T>(x));
		tam++;
		return true;
	}
	return false;
}

template <class T>
BTNode<T>* BSTree<T>::getRightMin(BTNode<T>* u){
	u = u->right;
	while(u->left != NULL)
		u = u->left;
	return u;
}

template <class T>
bool BSTree<T>::remove(T x){
	BTNode<T>* u = getNode(x);
	if(u == NULL) return false;
	BTNode<T>* v = u->parent;
	if(u->left == NULL && u->right == NULL){
		if(u == root)
			root = NULL;
		else
			if(x < v->key) v->left = NULL;
			else v->right = NULL;
		delete u;
	}
	else if(u->left == NULL){
		if(u == root){
			root = u->right;
			root->parent = NULL;
		}
		else
			if(x < v->key)
				v->set_leftChild(u->right);
			else
				v->set_rightChild(u->right);
		delete u;
	}
	else if(u->right == NULL){
		if(u == root){
			root = u->left;
			root->parent = NULL;
		}
		else
			if(x < v->key)
				v->set_leftChild(u->left);
			else
				v->set_rightChild(u->left);
		delete u;
	}
	else{
		BTNode<T>* rightMin = getRightMin(u);
		u->key = rightMin->key;
		if(rightMin == u->right)
			u->set_rightChild(rightMin->right);
		else
			rightMin->parent->set_leftChild(rightMin->right);
		delete rightMin;
	}
	tam--;
	return true;
}

#endif
