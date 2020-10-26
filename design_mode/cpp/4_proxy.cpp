// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ����ģʽ

#include <iostream>

using namespace std;

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif


// ����ģʽ
// �����࣬�������ܽӿ�
// ʵ���࣬�̳г����࣬��ʵ�ֹ���
// �����࣬���ɳ����࣬����ʵ����ĳ�Ա������ͨ��ʵ����Ķ��������þ���ʵ�ֹ��ܵĺ���


// �����Ϊ�����������ɲ�����
class SchoolGirl
{
public:
	void setname(string name) {
		name_ = name;
	}

	string getname() {
		return name_;
	}

private:
	string name_;
};

// ����ӿ�
class CGiveGift
{
public:
	virtual void GiveDolls() = 0;
	virtual void GiveFollows() = 0;
	virtual void GiveChocolates() = 0;
};

// ׷�����࣬����ʵ��������ӿ�
class Pursuit : public CGiveGift {
public:
	Pursuit(SchoolGirl* schoolgirl) {
		schoolgirl_ = schoolgirl;
	}

	void GiveDolls() {
		if (schoolgirl_) {
			cout << "pursuit give dolls to " << schoolgirl_->getname() << "\n";
		}
	}

	void GiveFollows() {
		if (schoolgirl_) {
			cout << "pursuit give follows to " << schoolgirl_->getname() << "\n";
		}
	}

	void GiveChocolates() {
		if (schoolgirl_) {
			cout << "pursuit give chocolates to " << schoolgirl_->getname() << "\n";
		}
	}

private:
	SchoolGirl* schoolgirl_ = nullptr;
};

// �����࣬�ڲ��������ʵ����Ķ����ڼ̳еĺ����е���
class Proxy : public CGiveGift {
public:
	Proxy(SchoolGirl* schoolgirl) {
		pursuit_ = new Pursuit(schoolgirl);
	}

	~Proxy() {
		SAFE_DELETE(pursuit_);
	}
	
	void GiveDolls() {
		if (pursuit_) {
			pursuit_->GiveDolls();
		}
	}

	void GiveFollows() {
		if (pursuit_) {
			pursuit_->GiveFollows();
		}
	}

	void GiveChocolates() {
		if (pursuit_) {
			pursuit_->GiveChocolates();
		}
	}


private:
	Pursuit* pursuit_ = nullptr;
};


int main()
{
	SchoolGirl* schoolgirl = new SchoolGirl();
	schoolgirl->setname("���");

	// �������
	Proxy* proxy = new Proxy(schoolgirl);
	// ��������е��þ���ʵ����Ķ����ʵ�ַ���
	proxy->GiveDolls();
	proxy->GiveFollows();
	proxy->GiveChocolates();

	SAFE_DELETE(proxy)
	SAFE_DELETE(schoolgirl)

	return 0;
}


