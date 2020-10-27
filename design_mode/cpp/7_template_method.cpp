// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ģ�巽��ģʽ

#include <iostream>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

// ���ࣺ�ṩ����ĳ�����̵ľ���ʵ�ַ�����
//       �����ڵľ��岽�裬������ɶ��ơ�
class AbstractClass {
public:
	virtual void doSomething() = 0;
	virtual void doOtherthing() = 0;

public:
	void someDoIt() {
		doSomething();
		doOtherthing();
		cout << "do job" << endl;
	}
};

// �����ʵ���Լ����Ƶľ��岽�衣������Ϻ�����̣��ɻ���ʵ�֡�
class aBoy : public AbstractClass {
public:
  void doSomething() {
		cout << "A boy do something and ";
	}

	void doOtherthing() {
		cout << " do otherthing about :";
	}
};

// �����ʵ���Լ����Ƶľ��岽�衣������Ϻ�����̣��ɻ���ʵ�֡�
class aGirl : public AbstractClass {
public:
	void doSomething() {
		cout << "A girl do something and ";
	}

	void doOtherthing() {
		cout << "do otherthing about :";
	}
};

int main()
{
	aBoy* aboy = new aBoy();
	aboy->someDoIt();
	SAFE_DELETE(aboy);

	aGirl* agirl = new aGirl();
	agirl->someDoIt();
	SAFE_DELETE(agirl);

	return 0;
}


