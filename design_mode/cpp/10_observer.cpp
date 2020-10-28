// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - �۲���ģʽ

#include <iostream>
#include <vector> 

// �۲���ģʽ��ͨ�� AddObserver �Ѷ���Ž�vector�С�
//             ������Ϣ֪ͨʱ����vector���е�Observer����֪ͨ������������Ϣ֪ͨ�ɷ��ȡ�

using namespace std;

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

class Secretary;

class Observer {
public:
	virtual void Notify() = 0;

protected:
	string name_ = "";
	Secretary* secretary_ = nullptr;
};

// ����Ĺ۲���ʵ����
class Secretary{
public:
	// ������ӹ۲���
	void addObserver(Observer* observer) {
		observers_.push_back(observer);
	}

	// �����Ƴ��۲���
	void removeObserver(Observer* observer) {
		vector<Observer*>::iterator p = observers_.begin();
		while (p != observers_.end())
		{
			if ((*p) == observer) {
				observers_.erase(p);
				break;
			}
			p++;
		}
	}

	// �����й۲��߽�����Ϣ�ɷ�
	// ����ͨ����Ϣ����ֵ�����ɷ��жϡ�
	void Notify() {
		vector<Observer*>::iterator p = observers_.begin();
		while (p != observers_.end())
		{
			(*p)->Notify();
			p++;
		}
	}

private:
	vector<Observer*> observers_;
};

// ����Ĵ��۲��ߵ�ʵ��
class WorkerAObserver : public Observer {
public:
	WorkerAObserver(string name, Secretary* secretary) {
		name_ = name;
		secretary_ = secretary;
	}

	void Notify() {
		cout << "secretary notify:" << name_ << " boss come" << endl;
	}
};

class WorkerBObserver : public Observer {
public:
	WorkerBObserver(string name, Secretary* secretary) {
		name_ = name;
		secretary_ = secretary;
	}

	void Notify() {
		cout << "secretary notify:" << name_ << " boss come" << endl;
	}
};


int main10()
{
	Secretary* secretary = new Secretary();

	WorkerAObserver* workerA = new WorkerAObserver("David", secretary);
	WorkerBObserver* workerB = new WorkerBObserver("Tom", secretary);
	secretary->addObserver(workerA);
	secretary->addObserver(workerB);

	secretary->Notify();

	cout << "remove workerA" << endl;
	secretary->removeObserver(workerA);
	SAFE_DELETE(workerA);

	secretary->Notify();

	SAFE_DELETE(secretary);
  SAFE_DELETE(workerB)

	return 0;
}


