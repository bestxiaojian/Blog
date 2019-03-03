#include "Observer.h"
#include "Subject.h"

#include <iostream>
#include <string>

using namespace std;

Observer::Observer() {
	_st = '\0';
	cout << "Observer constructor entrance..." << endl;
}

Observer::~Observer() {
	
}

ConcreteObserverA::ConcreteObserverA(Subject* sub) {
	cout << "ConcreteObserverA constructor entrance[]" << endl;
	_sub = sub;
	_sub->Attach(this);
}

ConcreteObserverA::~ConcreteObserverA() {
	_sub->Detach(this);
	if (_sub != NULL) {
		delete _sub;
		_sub = NULL;
	}
}

Subject* ConcreteObserverA::GetSubject() const {
	return _sub;
}

void ConcreteObserverA::PrintInfo() {
	cout << "ConcreteObserverA observer..." << _sub->GetState() << endl;
}

void ConcreteObserverA::Update(Subject* sub) {
	_st = sub->GetState();
	PrintInfo();
}

ConcreteObserverB::ConcreteObserverB(Subject* sub) {
	_sub = sub;
	_sub->Attach(this);
}

ConcreteObserverB::~ConcreteObserverB() {
	_sub->Detach(this);
	if (_sub != NULL) {
		delete _sub;
		_sub = NULL;
	}
}

Subject* ConcreteObserverB::GetSubject() const {
	return _sub;
}

void ConcreteObserverB::PrintInfo() {
	cout << "ConcreteObserverB observer..." << _sub->GetState() << endl;
}

void ConcreteObserverB::Update(Subject* sub) {
	_st = sub->GetState();
	PrintInfo();
}








