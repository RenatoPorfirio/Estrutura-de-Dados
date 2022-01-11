#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

template <class T>
class arrayList{
protected:
	T* vet; //ponteiro para un array padrao
	int leng; //quantidade de elementos adicionados
	int maxleng; //tamanho do array
	void resize(); //redimensiona a arrayList
public:
	arrayList(); //constroi uma arrayList com maxleng = 1
	arrayList(int); //constroi uma arrayList com um maxleng passado como parametro
	~arrayList(){delete [] vet;}
	int size(){return leng;}
	int max_size(){return maxleng;}
	T get(int); //retorna o i-esimo elemento da lista (se i > maxleng, retorna um NULL do tipo T. Exemplo: no caso de uma string, retornaria uma string vazia;
	T set(int,T); //altera o valor armazenado numa dada posicao do array, retornando o valor anteriormente armazenado;
	bool add(int,T); //adiciona um elemento em uma dada posicao apos deslocar (n-i) casas para liberar o espaco desejado. Tambem incrementa a variavel leng;
	T remove(int); //remove um elemento em uma dada posicao deslocando (n-i) casas para preencher o espaco liberado. Tambem decrementa a variavel leng;
};

/*=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=*/

/*implementacoes dos metodos declarados*/

template <class T>
arrayList<T>::arrayList(){
	vet = new T[1];
	leng = 0;
	maxleng = 1;
}

template <class T>
arrayList<T>::arrayList(int tam){
	vet = new T[tam];
	leng = 0;
	maxleng = tam;
}

template <class T>
void arrayList<T>::resize(){
	int new_maxleng = leng < 1 ? 1 : 2*leng;
	T* vet_aux = new T[new_maxleng];
	for(int i = 0; i < maxleng; i++)
		vet_aux[i] = vet[i];
	delete [] vet;
	vet = vet_aux;
	maxleng = new_maxleng;
}

template <class T>
T arrayList<T>::get(int i){
	if(i >= maxleng) return -1;
	return vet[i];
}

template <class T>
T arrayList<T>::set(int i, T x){
	if(i >= maxleng) return (T)NULL;
	T y = vet[i];
	vet[i] = x;
	return y;
}

template <class T>
bool arrayList<T>::add(int i, T x){
	if(i > maxleng) return false;
	if(leng == maxleng) resize();
	for(int j = maxleng; j > i; j--)
		vet[j] = vet[j-1];
	vet[i] = x;
	leng++;
	return true;
}

template <class T>
T arrayList<T>::remove(int i){
	if(i >= maxleng) return -1;
	T y = vet[i];
	for(int j = i; j < maxleng-1; j++)
		vet[j] = vet[j+1];
	leng--;
	if(3*leng <= maxleng) resize();
	return y;
}

#endif
