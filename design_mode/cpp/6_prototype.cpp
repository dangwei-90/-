// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ԭ��ģʽ

#include <iostream>

using namespace std;

class Prototype {
public:
	Prototype(string id) {
		_id = id;
	}

	virtual void SetID(string id) {
		_id = id;
	}

	virtual string GetID(){
		return _id;
	}

	virtual Prototype* Clone() = 0;

private:
	string _id;
};

class ConcreatePrototype : Prototype {
public :
	ConcreatePrototype(string id):Prototype(id) {
		_id = id;
	}

	void SetID(string id) {
		_id = id;
	}

	string GetID() {
		return _id;
	}

	Prototype* Clone() {
		ConcreatePrototype* prototype = new ConcreatePrototype("p");
		*prototype = *this;
		return prototype;
	}

private:
	string _id;
};

int main6()
{
	ConcreatePrototype* p1 = new ConcreatePrototype("p1");
	ConcreatePrototype* p2 = (ConcreatePrototype*)p1->Clone();
	cout << "p1: " << p1 << endl;
	cout << "p1 id: " << p1->GetID() << endl;
	cout << "p2: " << p2 << endl;
	cout << "p2 id: " << p2->GetID() << endl;

	cout << "--------------------\n";
	p1->SetID("p1 set");
	p2->SetID("p2 set");
	cout << "p1 id: " << p1->GetID() << endl;
	cout << "p2 id: " << p2->GetID() << endl;

	return 0;
}


