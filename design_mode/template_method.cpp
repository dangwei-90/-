// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ

#include <iostream>

using namespace std;

class AbstractClass {
public:
	virtual void doSomething() {}

	virtual void doOtherthing() {}

public:
	void someDoIt() {
		doSomething();
		doOtherthing();
		cout << "do job" << endl;
	}
};

class aBoy : public AbstractClass {
public:
  void doSomething() {
		cout << "A boy do something and ";
	}

	void doOtherthing() {
		cout << " do otherthing about :";
	}
};

class aGirl : public AbstractClass {
public:
	void doSomething() {
		cout << "A girl do something and ";
	}

	void doOtherthing() {
		cout << "do otherthing about :";
	}
};

int main7()
{
	aBoy* aboy = new aBoy();
	aboy->someDoIt();

	aGirl* agirl = new aGirl();
	agirl->someDoIt();

	return 0;
}


