// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ԭ��ģʽ

// ԭ��ģʽ��ͨ��Ĭ�Ͽ������캯����ͨ��clone�ӿڣ�newһ���µĶ���

#include <iostream>

using namespace std;

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

class Prototype {
public:
	Prototype() {}

	virtual void SetID(string id) = 0;

	virtual string GetID() = 0;

	virtual Prototype* Clone() = 0;

protected:
	string id_ = "";
};

class ConcreatePrototype : Prototype {
public :
	ConcreatePrototype(string id){
		id_ = id;
	}

	void SetID(string id) {
		id_ = id;
	}

	string GetID() {
		return id_;
	}

	Prototype* Clone() {
		// ���ݵ�ǰ���� ��������һ���¶���(ǳ����)
		return new ConcreatePrototype(*this);

		/*
		ConcreatePrototype* prototype = new ConcreatePrototype("p");
		*prototype = *this;
		return prototype;
		*/
	}
};

int main()
{
	ConcreatePrototype* p1 = new ConcreatePrototype("p1");
	ConcreatePrototype* p2 = (ConcreatePrototype*)p1->Clone();

	// �˴�p2����ĳ�Ա������Ϊp1����ĳ�Ա������ֵ
	cout << "p1: " << p1 << endl;
	cout << "p1 id: " << p1->GetID() << endl;
	cout << "p2: " << p2 << endl;
	cout << "p2 id: " << p2->GetID() << endl;

	cout << "--------------------\n";
	// P1��P2���Ե����Լ��ķ���
	p1->SetID("p1 set");
	p2->SetID("p2 set");
	cout << "p1 id: " << p1->GetID() << endl;
	cout << "p2 id: " << p2->GetID() << endl;

	SAFE_DELETE(p2)
	SAFE_DELETE(p1)

	return 0;
}


