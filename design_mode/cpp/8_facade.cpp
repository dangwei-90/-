// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ���ģʽ

#include <iostream>

// ���ģʽ���������е�ϵ�нӿڣ��ṩ���ָ�����ϵ�ͳһ�ӿڣ������ϲ����

using namespace std;

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

class subSystemOne {
public:
	void create() {
		cout << "sub system one create\n";
	}

	void clear() {
		cout << "sub system one clear\n";
	}
};

class subSystemTwo {
public:
	void create() {
		cout << "sub system two create\n";
	}

	void clear() {
		cout << "sub system two clear\n";
	}
};

class subSystemThree {
public:
	void create() {
		cout << "sub system three create\n";
	}

	void clear() {
		cout << "sub system three clear\n";
	}
};

class subSystemFour {
public:
	void create() {
		cout << "sub system four create\n";
	}

	void clear() {
		cout << "sub system four clear\n";
	}
};

// ������ṩ�ӿڵ��ࡣ
// �ͻ���ֻ���ĵ����ĸ���ϵĽӿڷ�����������Ҫ���ľ����ʵ��
class Facade {
public:
	Facade() {
		subsystemone_ = new subSystemOne();
		subsystemtwo_ = new subSystemTwo();
		subsystemthree_ = new subSystemThree();
		subsystemfour_ = new subSystemFour();
	}

	~Facade() {
		SAFE_DELETE(subsystemone_);
		SAFE_DELETE(subsystemtwo_);
		SAFE_DELETE(subsystemthree_);
		SAFE_DELETE(subsystemfour_);
	};

	void one_and_two_create() {
		subsystemone_->create();
		subsystemtwo_->create();
	}

	void three_and_four_clear() {
		subsystemthree_->clear();
		subsystemfour_->clear();
	}

private:
	subSystemOne* subsystemone_ = nullptr;
	subSystemTwo* subsystemtwo_ = nullptr;
	subSystemThree* subsystemthree_ = nullptr;
	subSystemFour* subsystemfour_ = nullptr;
};

int main8()
{
	Facade* facade = new Facade();
	facade->one_and_two_create();
	facade->three_and_four_clear();

	SAFE_DELETE(facade)

	return 0;
}


