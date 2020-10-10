// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ

#include <iostream>

using namespace std;

// demo one
class Target {
public:
	void Request() {
		cout << "normal request" << endl;
	}
};

class Adaptee {
public:
	void SpecialRequest() {
		cout << "special request" << endl;
	}
};

class Adapter : public Target {
public:
	void Request() {
		adaptee->SpecialRequest();
	}

private:
	Adaptee* adaptee = new Adaptee();
};

// demo two
class CPlayer {
public:
	CPlayer() {}

	CPlayer(string name) {
		name_ = name;
	}

	virtual void attack() {};

	virtual void stop() {};

public:
	string name_;
};

class CForwards : public CPlayer {
public:
	CForwards(string name) {
		name_ = name;
	}

	void attack() {
		cout << name_ << ", attack!" << endl;
	}

	void stop() {
		cout << name_ << ", stop!" << endl;
	}
};

class CCenters : public CPlayer {
public:
	CCenters(string name) {
		name_ = name;
	}

	void attack() {
		cout << name_ << ", attack!" << endl;
	}

	void stop() {
		cout << name_ << ", stop!" << endl;
	}
};

class CGuards : public CPlayer {
public:
	CGuards(string name) {
		name_ = name;
	}

	void attack() {
		cout << name_ << ", attack!" << endl;
	}

	void stop() {
		cout << name_ << ", stop!" << endl;
	}
};

class ForeignCenter {
public:
	void SetForeignName(string name) {
		name_ = name;
	}

	void attack() {
		cout << name_ << ", attack!" << endl;
	}

	void stop() {
		cout << name_ << ", stop!" << endl;
	}

public:
	string name_;
};

class Translator : public CPlayer {
public:
	Translator(string name) {
		foreign->SetForeignName(name);
	}

	void attack() {
		foreign->attack();
	}

	void stop() {
		foreign->stop();
	}

public:
	ForeignCenter* foreign = new ForeignCenter();
};

int main()
{
	Adapter* adapter = new Adapter();
	adapter->Request();

	CPlayer* forward = new CForwards("ǰ��1��");
	forward->attack();
	forward->stop();

	CPlayer* center = new CCenters("�з�3��");
	center->attack();
	center->stop();

	CPlayer* guard = new CGuards("����1��");
	guard->attack();
	guard->stop();

	CPlayer* translator = new Translator("Ҧ��");
	translator->attack();
	translator->stop();

	return 0;
}


