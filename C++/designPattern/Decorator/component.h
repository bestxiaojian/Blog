#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>
using namespace std;

//所有饮料的基类
class IBeverage {
public:
	virtual string Name() = 0;
	virtual double Cost() = 0;
};




#endif