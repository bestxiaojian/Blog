#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <iostream>
#include <string>

using namespace std;

class Component {
public:
	Component(string name): m_strName(name) {
		
	}

	virtual ~Component() {
		
	}

	virtual void Add(Component* cmpt) = 0; //添加构件
	virtual void Remove(Component* cmpt) = 0; //删除构件
	virtual Component* getChild(int index) = 0; //获取构件
	virtual void Operation(int indent) = 0; //显示构件

private:
	Component();
protected:
	string m_strName;
};

#endif