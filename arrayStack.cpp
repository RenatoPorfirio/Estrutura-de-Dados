#include <iostream>
#include "arrayStack.h"

using namespace std;

int main(){
	arrayStack<int> a;
//	a.push(3); //estado esperado: {3};
//	a.push(5); //estado esperado: {3,5};
//	a.push(7); //estado esperado: {3,5,7};
//	a.pop(); //estado esperado: {3,5};
//	a.pop(); //estado esperado: {3};
//	a.pop(); //estado esperado: {};
//	a.push(2); //estado esperado: {2};
//	a.push(3); //estado esperado: {2,3};
	
	a.print();
	cout << a.size();
	return 0;
}
