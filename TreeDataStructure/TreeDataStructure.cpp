#include <iostream>
#include "Tree.h"

int main()
{
	Tree<float> t;

	t.insert(0.0f);

	t.insert(-1.0f);
	t.insert(-2.0f);
	t.insert(-0.5f);
	t.insert(-2.5f);
	t.insert(-3.0f);

	t.insert(1.0f);
	t.insert(2.0f);
	t.insert(2.5f);
	t.insert(3.0f);

	t.printTree(t.root, 0);

}
