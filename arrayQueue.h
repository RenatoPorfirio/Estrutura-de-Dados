#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#import "arrayList.h"
using std::cout;

template <class T>
class arrayQueue : protected arrayList<T>{
protected:
	using arrayList<T>::vet;
	using arrayList<T>::maxleng;
	using arrayList<T>::leng;
	int init;
	int last;
	void resize();
public:
	arrayQueue() : arrayList<T>(){}; //inicializa igual a arrayList
	arrayQueue(int t) : arrayList<T>(t){}; //inicializa igual a arrayList
	T get(int); //retorna o elemento na posicao dada da fila (sendo 0 a primeira posicao). Se nao existir determinada posicao, retorna (T)NULL;
	T set(int,T); //altera o elemento na posicao dada da fila (sendo 0 a primeira posicao) e retorna o antigo valor armazenado na mesma. Se nao existir determinada posicao, retorna (T)NULL;
	void add(T); //adiciona um elemento no fim da fila;
	T remove(); //remove o elemento que esta a mais tempo na fila;
	void print();
	using arrayList<T>::size; //retorna o tamanho da fila e retorna seu valor;
};

/*=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=*/

/*implementacoes dos metodos declarados*/

template <class T>
void arrayQueue<T>::resize(){
	int new_maxleng = leng < 1 ? 1 : 2*leng;
	T* vet_aux = new T[new_maxleng];
	for(int i = 0; i < maxleng; i++)
		vet_aux[i] = vet[(init+i)%maxleng];
	delete [] vet;
	vet = vet_aux;
	init = 0;
	last = leng-1;
	maxleng = new_maxleng;
}

template <class T>
T arrayQueue<T>::get(int i){
	int mod = (init + i) % maxleng;
	return arrayList<T>::get(mod);
}

template <class T>
T arrayQueue<T>::set(int i, T x){
	int mod = (init + i) % maxleng;
	return arrayList<T>::set(mod,x);
}

template <class T>
void arrayQueue<T>::add(T x){
	if(leng == maxleng) resize();
	last = (init + leng) % maxleng;
	vet[last] = x;
	leng++;
}

template <class T>
T arrayQueue<T>::remove(){
	if(leng == 0) return (T)NULL;
	T x = vet[init];
	init = (init + 1) % maxleng;
	leng--;
	if(3*leng <= maxleng) resize();
	return x;
}

template <class T>
void arrayQueue<T>::print(){
	for(int i = 0; i < leng; i++)
		cout << vet[(init+i)%maxleng] << " ";
	cout << "\n";
}

#endif
