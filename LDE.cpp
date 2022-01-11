/*Para teste dos metodos, retire os comandos do formato de comentario e execute o codigo linha por linha*/

#include <iostream>
#include "LDE.h"

using std::cout;

template<class T>
void print(LDENode<T>* u){
	cout << u->val << " ";
}

int main(){
	LDE<int> q; //estado esperado: {};
//	q.push(2); //estado esperado: {2};
//	q.push(3); //estado esperado: {3,2};
//	q.push(4); //estado esperado: {4,3,2};
//	q.push(5); //estado esperado: {5,4,3,2};
//	q.reverse(); //estado esperado: {2,3,4,5};
//	q.push(1); //estado esperado: {1,2,3,4,5};
//	q.reverse(); //estado esperado: {5,4,3,2,1};
//	q.clear(); //estado esperado: {};
//	q.reverse(); //estado esperado: {};
//	q.push_back(3); //estado esperado: {3};
//	q.push(5); //estado esperado: {5,3};
//	q.pop_back(); //estado esperado: {5};
//	q.push_back(4); //estado esperado: {5,4};

	q.forEach<void>(print);
	cout << "\n" << q.size();
	return 0;
}
