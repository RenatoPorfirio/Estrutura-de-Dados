#include <iostream>
#include "BSTree.h"

using std::cout;
using std::endl;

template <class T>
void print(BTNode<T>* u){
	if(u != NULL)
		cout << u->key << endl;
}

int main(){
	BSTree<char> t;
	t.add('g');
	t.add('d');
	t.add('j');
	t.add('i');
	t.remove('g');
	t.add('e');
	t.inOrder<void>(print);
	cout << t.find('g');
	return 0;
}
