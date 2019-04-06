//clientApp有时无法对realSubject进行直接访问或者比较麻烦;
//这时候为了隔离，解耦，增加一个访问realSubject的代理proxy

class ISubject {
public:
	virtual void process();
};

class SubjectProxy:public ISubject {
public:
	virtual void process() {
		//对realsubject的一种间接访问
		//实际项目中往往复杂一些
		//...
	}
};

class realSubject:public ISubject {
public:
	virtual void process() {
		//...
	}
};

class clientApp {
public:
	clientApp() {
		subject = new SubjectProxy();
	}
	void DoTask() {
		//...
		subject->process();
		//...
	}
private:
	ISubject* subject;
};