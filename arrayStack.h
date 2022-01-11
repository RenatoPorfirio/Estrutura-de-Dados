#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "arrayList.h"

using std::cout;

template <class T>
class arrayStack : protected arrayList<T>{
protected:
	using arrayList<T>::vet;
	using arrayList<T>::leng;
	using arrayList<T>::maxleng;
	using arrayList<T>::resize;
public:
	arrayStack() : arrayList<T>(){} //igual ao da arrayList
	arrayStack(int t) : arrayList<T>(t){} //igual ao da arrayList
	~arrayStack(){delete [] vet;}
	void push(T); //adiciona um elemento na pilha. O elemento sempre sera adicionado no fim do array;
	T pop(); //remove o ultimo elemento adicionado e o retorna;
	using arrayList<T>::get;
	using arrayList<T>::set;
	using arrayList<T>::size;
	void print();
};

/*=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=*/

/*implementacoes dos metodos declarados*/

template <class T>
void arrayStack<T>::push(T x){
	if(leng == maxleng) resize();
	vet[leng] = x;
	leng++;
}

template <class T>
T arrayStack<T>::pop(){
	if(leng == 0) return (T)NULL;
	T x = vet[--leng];
	return x;
}

template <class T>
void arrayStack<T>::print(){
	int t = size();
	for(int i = 0; i < t ; i++)
		cout << vet[i] << " ";
	cout << "\n";
}

#endif
