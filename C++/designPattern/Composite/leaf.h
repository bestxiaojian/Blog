#ifndef LEAF_H_
#define LEAF_H_

#include "component.h"

class Leaf: public Component {
public:
	Leaf(string name): Component(name) {
		
	}

	virtual ~Leaf() {
		
	}
	
	void Add(Component* cmpt) {
		cout << "Can't add to leaf." << endl;
	}
	
	void Remove(Component* cmpt) {
		cout << "Can't remove from a leaf." << endl;
	}
	
	Component* getChild(int index) {
		cout << "Can't get child from leaf." << endl;
		return NULL;
	}

	void Operation(int indent) {
		string newStr(indent,"-");
		cout << newStr << " " << m_strName << endl;
	}

private:
	Leaf();
};





#endif