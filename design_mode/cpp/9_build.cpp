// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ- ������ģʽ

#include <iostream>

// ������ģʽ��ͨ��ͳһ�Ĺ淶�ĳ����࣬���༯�ɺ�ʵ�ֲ�ͬ�Ĺ��ܡ�
//             �������඼�����������Ĵ��麯��������

using namespace std;

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

// ������࣬��������������ʵ�ֵķ���
class buildPerson {
public:
	virtual void createHead() = 0;
	virtual void createBody() = 0;
	virtual void createHand() = 0;
	virtual void createFoot() = 0;
};

// �����ʵ����
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

// �������࣬������ݲ�ͬ�Ķ��󣬵��ò�ͬ���ѹ淶�õ�ʵ��
class buildClass {
public:
	void construct(buildPerson* buildperson) {
		buildperson_ = buildperson;
	}

	void constructPerson() {
		if (buildperson_) {
			buildperson_->createHead();
			buildperson_->createBody();
			buildperson_->createHand();
			buildperson_->createFoot();
		}
	}

private:
	buildPerson* buildperson_ = nullptr;
};

int main9()
{
	// �����߶���
	buildClass* buildclass = new buildClass();

	// �����person���󣬴��뽨���ߣ��ɽ����ߵ����ѹ淶�õķ�����
	buildThinPerson* buildthinperson = new buildThinPerson();
	buildclass->construct(buildthinperson);
	buildclass->constructPerson();

	SAFE_DELETE(buildthinperson);

	buildFatPerson* buildfatperson = new buildFatPerson();
	buildclass->construct(buildfatperson);
	buildclass->constructPerson();

	SAFE_DELETE(buildfatperson);
	SAFE_DELETE(buildclass);

	return 0;
}


