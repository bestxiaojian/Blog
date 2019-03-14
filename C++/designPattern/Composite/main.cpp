#include "composite.h"
#include "leaf.h"

int main() {
	Component* pRoot = new Composite("江湖公司(任我行)");
	//创建分支
	Component* pDepart1 = new Composite("日月神教(东方不败)");
	pDepart1->Add(new Leaf("光明左使(向问天)"));
	pDepart1->Add(new Leaf("光明右使(曲洋)");
	pRoot->Add(pDepart1);
	
	Component* pDepart2 = new Composite("五岳剑派(左冷蝉)");
	pDepart2->Add(new Leaf("嵩山"));
	pDepart2->Add(new Leaf("华山"));
	
}