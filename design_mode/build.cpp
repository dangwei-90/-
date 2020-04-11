// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ

#include <iostream>

using namespace std;

class buildPerson {
public:
	virtual void createHead() {};
	virtual void createBody() {};
	virtual void createHand() {};
	virtual void createFoot() {};
};

class buildThinPerson: public buildPerson {
public:
	void createHead() {
		cout << "thin head" << endl;
	}
	void createBody() {
		cout << "thin body" << endl;
	}
	void createHand() {
		cout << "thin hand" << endl;
	}
	void createFoot() {
		cout << "thin foot" << endl;
	}
};

class buildFatPerson : public buildPerson {
public:
	void createHead() {
		cout << "fat head" << endl;
	}
	void createBody() {
		cout << "fat body" << endl;
	}
	void createHand() {
		cout << "fat hand" << endl;
	}
	void createFoot() {
		cout << "fat foot" << endl;
	}
};

class buildClass {
public:
	void construct(buildPerson* buildperson) {
		_buildperson = buildperson;
	}

	void constructPerson() {
		_buildperson->createHead();
		_buildperson->createBody();
		_buildperson->createHand();
		_buildperson->createFoot();
	}

private:
	buildPerson* _buildperson = new buildPerson();
};

int main()
{
	buildClass* buildclass = new buildClass();

	buildThinPerson* buildthinperson = new buildThinPerson();
	buildclass->construct(buildthinperson);
	buildclass->constructPerson();

	buildFatPerson* buildfatperson = new buildFatPerson();
	buildclass->construct(buildfatperson);
	buildclass->constructPerson();

	return 0;
}


