#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include "Subject.h"
#include <string>
using namespace std;

class Observer {
public:
	virtual ~Observer();
	virtual void Update(Subject* sub) = 0;
	virtual void PrintInfo() = 0;
protected:
	Observer();
	State _st;
private:
	
};

class ConcreteObserverA: public Observer {
public:
	virtual Subject* GetSubject() const;
	ConcreteObserverA(Subject* sub);
	virtual ~ConcreteObserverA();
	void Update(Subject* sub);
	void PrintInfo();
protected:

private:
	Subject* _sub;
};

class ConcreteObserverB: public Observer {
public:
	virtual Subject* GetSubject() const;
	ConcreteObserverB(Subject* sub);
	virtual ~ConcreteObserverB();
	void Update(Subject* sub);
	void PrintInfo();
protected:

private:
	Subject* _sub;
};

#endif