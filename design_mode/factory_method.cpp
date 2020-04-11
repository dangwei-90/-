// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ

#include <iostream>

using namespace std;

// base
class Operation {
public:
	virtual int GetResult() {
		return 0;
	}

public:
	int first_num_ = 0;
	int second_num_ = 0;
};

// plus
class PlusOperation :public Operation {
public:
	int GetResult() {
		return first_num_ + second_num_;
	}
};

// Sub
class SubOperation :public Operation {
public:
	int GetResult() {
		return first_num_ - second_num_;
	}
};

// Mult
class MultOperation : public Operation {
public:
	int GetResult() {
		return first_num_ * second_num_;
	}
};

// interface
class CFactory {
public:
	virtual Operation* CreateOperation() {
		return nullptr;
	};
};

class PlusFactory : public CFactory {
public:
	Operation* CreateOperation() {
		return new PlusOperation();
	}
};

class SubFactory : public CFactory {
public:
	Operation* CreateOperation() {
		return new SubOperation();
	}
};

class MultFactory : public CFactory {
public:
	Operation* CreateOperation() {
		return new MultOperation();
	}
};

int main5()
{
	CFactory* factory = new MultFactory();
	Operation* op = factory->CreateOperation();
	op->first_num_ = 5;
	op->second_num_ = 3;
	cout << op->GetResult() << endl;

	return 0;
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
