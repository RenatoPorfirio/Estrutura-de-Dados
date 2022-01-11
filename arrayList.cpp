#include <iostream>
#include "arrayList.h"

using std::cout;

int main(){
	arrayList<int>a;
	a.add(0,2); //estado esperado: {2}
	a.add(0,3); //estado esperado: {3,2}
	a.add(2,4); //estado esperado: {3,2,4}
	a.set(2,5); //estado esperado: {3,2,5}
	a.add(0,8); //estado esperado: {8,3,2,5}
	a.add(0,7); //estado esperado: {7,8,3,2,5}
	a.remove(0); //estado esperado: {8,3,2,5}
	
	cout << a.get(0) << " ";
	cout << a.get(1) << " ";
	cout << a.get(2) << " ";
	cout << a.get(3) << "\n";
	cout << a.max_size();
	return 0;
}
