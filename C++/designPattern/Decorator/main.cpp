#include "concrete_component.h"
#include "concrete_decorator.h"

#include <iostream>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) {\
	if(p) {\
		delete (p);\
		(p) = NULL;\
	}\
}
#endif

int main() {
	/*******黑咖啡*******/
	
	IBeverage* pHouseBlend = new HouseBlend();
	cout << pHouseBlend->Name() << ":" << pHouseBlend->Cost() << endl;
	
	//给黑咖啡加奶油
	CondimentDecorator* pCream = new Cream(pHouseBlend);
	cout << pCream->Name() << ":" << pCream->Cost() << endl;
	
	//给黑咖啡加摩卡
	CondimentDecorator* pMocha = new Mocha(pHouseBlend);
	cout << pMocha->Name() << ":" << pMocha->Cost() << endl;

}
