#ifndef DECORATOR_H_
#define DECORATOR_H_

#include "component.h"

class CondimentDecorator: public IBeverage {
public:
	CondimentDecorator(IBeverage* bv): m_pBeverage(bv) {
		
	}

	string Name() {
		return m_pBeverage->Name();
	}

	double Cost() {
		return m_pBeverage->Cost();
	}

protected:
	IBeverage* m_pBeverage;
};




#endif