#include <iostream>
#include "arrayQueue.h"

using namespace std;

int main(){
	arrayQueue<int> a;
//	a.add(2); //estado esperado: {2}
//	a.add(3); //estado esperado: {2,3}
//	a.add(4); //estado esperado: {2,3,4}
//	a.remove(); //estado esperado: {3,4}
//	a.add(3); //estado esperado: {3,4,3}
//	a.add(2); //estado esperado: {3,4,3,2}
//	a.add(1); //estado esperado: {3,4,3,2,1}
//	a.add(0); //estado esperado: {3,4,3,2,1,0}
//	a.remove();//estado esperado: {4,3,2,1,0}
	a.print();
	cout << a.size() << "\n";
	return 0;
}
