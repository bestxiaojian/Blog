#ifndef TARGET_H_
#define TARGET_H_

#include <iostream>

//俄罗斯提供的插座
class IRussiaSocket {
public:
	virtual void Charge() = 0;
};

#endif