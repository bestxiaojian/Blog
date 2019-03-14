#ifndef ADAPTER_H_
#define ADAPTER_H_

#include "target.h"
#include "adaptee.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) {if(p){delete (p);(p) = NULL;}}
#endif

//电源适配器
class PowerAdapter: public IRussiaSocket {
public:
	PowerAdapter(): m_pCharger(new OwnCharger()) {
		
	}

	~PowerAdapter() {
		SAFE_DELETE(m_pCharger);
	}
	
	void Charge() {
		//使用自带的充电器充电
		m_pCharger->ChargeWithFeetFlat();
	}

private:
	OwnCharger* m_pCharger;  //持有需要被适配的接口对象-自带的充电器哈
};

#endif