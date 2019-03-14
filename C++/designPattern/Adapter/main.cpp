#include "adapter.h"

int main() {
	//创建个适配器
	IRussiaSocket* pAdapter = new PowerAdapter();
	
	//充电
	pAdapter->Charge();
	
	SAFE_DELETE(pAdapter);
	return 0;
}