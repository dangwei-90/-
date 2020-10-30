// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ������ģʽ

// ������ģʽ����Ϊ���������ݵĽӿ�֮�������

#include <iostream>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

// ����һ
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
	~Adapter() {
		SAFE_DELETE(adaptee_);
	}

	void Request() {
		adaptee_->SpecialRequest();
	}

private:
	Adaptee* adaptee_ = new Adaptee();
};

// ������
class CPlayer {
public:
	CPlayer() {}

	virtual void attack() = 0;

	virtual void stop() = 0;

public:
	string name_ = "";
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

// ������ģʽ���û����� ForeignCenter �ķ���
class Translator : public CPlayer {
public:
	Translator(string name) {
		foreign_->SetForeignName(name);
	}

	~Translator() {
		SAFE_DELETE(foreign_);
	}

	void attack() {
		foreign_->attack();
	}

	void stop() {
		foreign_->stop();
	}

public:
	ForeignCenter* foreign_ = new ForeignCenter();
};

int main()
{
	// ʾ��һ
	Adapter* adapter = new Adapter();
	adapter->Request();
	SAFE_DELETE(adapter);

	// ʾ����
	CPlayer* forward = new CForwards("ǰ��1��");
	forward->attack();
	forward->stop();
	SAFE_DELETE(forward);

	CPlayer* center = new CCenters("�з�3��");
	center->attack();
	center->stop();
	SAFE_DELETE(center);

	CPlayer* guard = new CGuards("����1��");
	guard->attack();
	guard->stop();
	SAFE_DELETE(guard);

	// ͨ������������٣����з��룬���ö�Ӧ�ķ���
	CPlayer* translator = new Translator("Ҧ��");
	translator->attack();
	translator->stop();
	SAFE_DELETE(translator);

	return 0;
}


