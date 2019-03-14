#ifndef CONCRETE_COMPONENT_H_
#define CONCRETE_COMPONENT_H_

#include "component.h"

/********  具体的饮料  *********/

//黑咖啡
class HouseBlend: public IBeverage {
public:
	string Name() {
		return "HouseBlend";
	}
	
	double Cost() {
		return 30.0;
	}
};

//深度烘焙咖啡豆
class DarkRoast: public IBeverage {
public:
	string Name() {
		return "DarkRoast";
	}
	
	double Cost() {
		return 28.5;
	}
};




#endif