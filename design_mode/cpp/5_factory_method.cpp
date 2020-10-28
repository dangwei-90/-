// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ��������ģʽ

// ���ֹ���ģʽ������
// �򵥹���ģʽ ���ɿͻ���֪ͨ���������������Ʒ�Ķ���
// ����ģʽ     ���ɿͻ���ѡ�񴴽������Ʒ�Ķ���
// ���󹤳�ģʽ ���ͻ��˲���Ҫ���Ĳ�ͬ�����ľ���ʵ�֣�ֻ��Ҫ���ù����ṩ�Ľӿڼ��ɡ�

#include <iostream>

using namespace std;

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

// �����࣬���ܵĽӿ�
class Operation {
public:
	virtual int GetResult() = 0;

public:
	int first_num_ = 0;
	int second_num_ = 0;
};

// ������ľ���ʵ�֣��ӷ�����
class PlusOperation :public Operation {
public:
	int GetResult() {
		return first_num_ + second_num_;
	}
};

// ������ľ���ʵ�֣���������
class SubOperation :public Operation {
public:
	int GetResult() {
		return first_num_ - second_num_;
	}
};

// ������ľ���ʵ�֣��˷�����
class MultOperation : public Operation {
public:
	int GetResult() {
		return first_num_ * second_num_;
	}
};

// ���������࣬�������幦�ܶ���Ľӿ�
class CFactory {
public:
	virtual Operation* CreateOperation() = 0;
};

// ������ľ���ʵ�֣������ӷ�������Ķ���
class PlusFactory : public CFactory {
public:
	Operation* CreateOperation() {
		return new PlusOperation();
	}
};

// ������ľ���ʵ�֣���������������Ķ���
class SubFactory : public CFactory {
public:
	Operation* CreateOperation() {
		return new SubOperation();
	}
};

// ������ľ���ʵ�֣������˷�������Ķ���
class MultFactory : public CFactory {
public:
	Operation* CreateOperation() {
		return new MultOperation();
	}
};

int main5()
{
	// �ɿͻ��˾������������幦�ܵĹ���
	CFactory* factory = new MultFactory();
  // ���ݾ���Ĺ�������������Ĺ�����
	Operation* op = factory->CreateOperation();
	op->first_num_ = 5;
	op->second_num_ = 3;
	cout << op->GetResult() << endl;

	SAFE_DELETE(op)
	SAFE_DELETE(factory)

	return 0;
}
