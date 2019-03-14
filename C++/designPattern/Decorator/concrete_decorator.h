#ifndef CONCRETE_DECORATOR_H_
#define CONCRETE_DECORATOR_H_

#include "decorator.h"

//具体的调味品

//奶油
class Cream: public CondimentDecorator {
public:
	Cream(IBeverage* bv): CondimentDecorator(bv) {
		
	}
	
	string Name() {
		return m_pBeverage->Name() + "Cream";
	}
	
	double Cost() {
		return m_pBeverage->Cost() + 3.5;
	}
};

//摩卡
class Mocha: public CondimentDecorator {
public:
	Mocha(IBeverage* bv): CondimentDecorator(bv) {
		
	}
	
	string Name() {
		return m_pBeverage->Name() + "Macha";
	}
	
	double Cost() {
		return m_pBeverage->Cost() + 2.0;
	}

};

//糖浆
class Syrup: public CondimentDecorator {
public:
	Syrup(IBeverage* bv): CondimentDecorator(bv) {
		
	}

	string Name() {
		return m_pBeverage->Name() + "Syrup";
	}

	double Cost() {
		return m_pBeverage->Cost() + 3.0;
	}
};

#endif