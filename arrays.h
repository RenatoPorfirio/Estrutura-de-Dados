#ifndef ARRAY_H
#define ARRAY_H
#include <cassert>

using std::max;
using std::cout;

template <class T> class array{
protected:
	T *vet;
	int length;
	int t;
	void resize();
public:
	array();
	array(int);
	int size(){return t;}
	int arraySize(){return length;}
	bool add(int, T);
	T remove(int);
	T get(int i){assert(i < length); return vet[i];}
	T set(int, T);
	void print(){
		for(int i=0;i<t;i++) cout << get(i) << " ";
	}
};

template <class T> class arrayQueue : protected array<T>{
protected:
	using array<T>::add;
	using array<T>::remove;
public:
	arrayQueue():array<T>(){}
	arrayQueue(int x):array<T>(x){}
	bool add(T x){return add(size(),x);}
	T remove(){return remove(0);}
	using array<T>::size;
	using array<T>::get;
	void print(){
		int t = size();
		for(int i=0; i < t; i++)
			cout << get(i) << " ";
	}
};

template <class T> class arrayStack : protected array<T>{
protected:
	using array<T>::add;
	using array<T>::remove;
	using array<T>::vet;
public:
	arrayStack():array<T>(){}
	arrayStack(int x):array<T>(x){}
	bool push(T x){return add(0,x);}
	T pop(){return remove(0);}
	using array<T>::size;
	using array<T>::get;
	void print(){
		int t = size();
		for(int i=0; i < t; i++)
			cout << get(i) << " ";
	}
};
	
template <class T> array<T>::array(){
	length = 1;
	t = 0;
	vet = new T[1];
}
	
template <class T> array<T>::array(int i){
	length = i;
	t = 0;
	vet = new T[i];
}
	
template <class T> void array<T>::resize(){
	int leng = max(2*t, 1);
	T *aux = new T[leng];
	for(int i=0; i < t; i++)
		aux[i] = vet[i];
	length = leng;
}
	
template <class T> bool array<T>::add(int i, T x){
	if(t == length) resize();
	if(length <= i) return false;
	for(int j=t-1; i <= j; j--)
		vet[j+1] = vet[j];
	vet[i] = x;
	t++;
	return true;
}
	
template <class T> T array<T>::remove(int i){
	if(length <= i) return (T)NULL;
	T x = vet[i];
	for(int j=i; j < t-1; j++)
		vet[j] = vet[j+1];
	t--;
	if(3*t <= length) resize();
	return x;
}
	
template <class T> T array<T>::set(int i, T x){
	if(length <= i) return (T)NULL;
	T y = vet[i];
	vet[i] = x;
	return y;
}


#endif
