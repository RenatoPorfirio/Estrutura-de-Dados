#ifndef LDE_H
#define LDE_H

#include <cstddef>

template <class T>
class LDENode //no elementar para uma lista duplamente encadeada
{
public:
	T val; //valor armazenado;
	LDENode<T>* nxt; //ponteiro para o proximo elemento;
	LDENode<T>* prv; //ponteiro para o elemento anterior;
	LDENode(T x){
		val = x;
		nxt = prv = NULL;
	}
};
	
template <class T>
class LDE //lista duplamente encadeada
{
private:
	int leng;
protected:
	LDENode<T>* head; //ponteiro para o inicio da lista;
	LDENode<T>* tail; //ponteiro para o fim da lista;
public:
	LDE();
	~LDE(){clear();}
	int size(){return leng;} //retorna a quantidade de elementos armazenados na lista;
	void push(T); //adiciona um elemento no inicio da lista;
	void push_back(T); //adiciona um elemento no fim da lista;
	T pop(); //remove o primeiro elemento;
	T pop_back(); //remove o ultimo elemento;
	void reverse(); //inverte a ordem dos elementos da lista;
	void clear(); //apaga todos elementos da lista;
	template <class Typ>
	void forEach(Typ(*f)(LDENode<T>*)); //aplica uma funcao qualquer de tipo generico que recebe um LDENode<T>* como parametro em cada node do inicio (head) ate o fim (tail) da lista. Sintaxe: .forEach<tipo_da_funcao>(nome_da_funcao);
};

/*=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=*/

/*implementacoes dos metodos declarados*/
template <class T>
LDE<T>::LDE(){
	leng = 0;
	head = tail = NULL;
}

template <class T>
void LDE<T>::push(T x){
	LDENode<T>* u = new LDENode<T>(x);
	if(leng == 0)
		tail = u;
	else{
		u->nxt = head;
		head->prv = u;
	}
	head = u;
	leng++;
}

template <class T>
void LDE<T>::push_back(T x){
	LDENode<T>* u = new LDENode<T>(x);
	if(leng == 0)
		head = u;
	else{
		tail->nxt = u;
		u->prv = tail;
	}
	tail = u;
	leng++;
}

template <class T>
T LDE<T>::pop(){
	if(leng == 0) return (T)NULL;
	leng--;
	T y = head->val;
	LDENode<T>* u = head;
	head = head->nxt;
	delete u;
	if(leng > 0)
		head->prv = NULL;
	else
		tail = NULL;
	return y;
}

template <class T>
T LDE<T>::pop_back(){
	if(leng == 0) return (T)NULL;
	leng--;
	T y = tail->val;
	LDENode<T>* u = tail;
	tail = tail->prv;
	delete u;
	if(leng > 0)
		tail->nxt = NULL;
	else
		head = NULL;
	return y;
}

template <class T>
void LDE<T>::reverse(){
	LDENode<T>* u = head;
	head = tail;
	tail = u;
	while(u != NULL){
		LDENode<T>* v = u->prv;
		u->prv = u->nxt;
		u->nxt = v;
		u = u->prv;
	}
}

template <class T>
void LDE<T>::clear(){
	LDENode<T>* u = head;
	while(u != NULL){
		head = head->nxt;
		delete u;
		u = head;
	}
	tail = NULL;
	leng = 0;
}

template <class T> template <class Typ>
void LDE<T>:: forEach(Typ(*f)(LDENode<T>*)){
	LDENode<T>* u = head;
	while(u != NULL){
		f(u);
		u = u->nxt;
	}
}

#endif
