#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include <vector>
#include "component.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) {\
	if(p) {\
		delete (p);\
		(p) = NULL;\
	}\
}
#endif

class Composite: public Component {
public:
	Composite(string name): Component(name) {
		
	}

	virtual ~Composite() {
		
	}

	void Add(Component* cmpt) {
		m_elements.push_back(cmpt);
	}

	void Remove(Component* cmpt) {
		vector<Component*>::iterator it = m_elements.begin();
		while(it != m_elements.end()) {
			if (*it == cmpt) {
				SAFE_DELETE(cmpt);
				m_elements.erase(it);
				break;
			}
			++it;
		}
	}

	Component* GetChild(int index) {
		if (index >= m_elements.size())
			return NULL;
		return m_elements[index];
	}

	void Operation(int indent) {
		string newStr(indent,'-');
		cout << newStr << "+" << m_strName << endl;
		//显示每个节点的孩子
		vector<Component*>::iterator it = m_elements.begin();
		while(it != m_elements.end()) {
			(*it)->Operation(indent + 2);
			++it;
		}
	}

private:
	Composite();

protected:
	vector<Component*> m_elements;
}

#endif