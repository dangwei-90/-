// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ״̬ģʽ

#include <iostream>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

// ״̬ģʽ�����ڶ���״̬����if else�߼���Ϊ����ʱ���ɲ���״̬ģʽ���йܿ�
// 
// ע�⣺�ڴ�й¶����

using namespace std;

class Work;
class FornoonState;

class State {
public:
	virtual void writeProgram(Work* work) = 0;
};

class Work {
public:
	Work();
	~Work() {
		SAFE_DELETE(state_);
	}

	void setHour(int hour) {
		hour_ = hour;
	}
	int getHour() {
		return hour_;
	}

	void setFinish(bool finish) {
		finish_ = finish;
	}
	int getFinish() {
		return finish_;
	}

	// �˴�ע���ڴ�й¶
	void setState(State* state) {
		SAFE_DELETE(state_);
		state_ = state;
	}

	void getCurrentState() {
		state_->writeProgram(this);
	}

private:
	int hour_ = 0;
	bool finish_ = false;
	State* state_ = nullptr;
};

class SleeptimeState : public State {
public:
	void writeProgram(Work* work) {
		cout << "time: " << work->getHour() << ", can not work ,need sleep" << endl;
	}
};

class GohomeState : public State {
public:
	void writeProgram(Work* work) {
		work->setFinish(true);
	}
};

class NigthtimeState : public State {
public:
	void writeProgram(Work* work) {
		if (work->getFinish()) {
			cout << "time: " << work->getHour() << ", work done, go home" << endl;
			work->setState(new GohomeState());
		}
		else {
			if (work->getHour() < 21) {
				cout << "time: " << work->getHour() << ", work very tired." << endl;
			}
			else {
				work->setState(new SleeptimeState());
				work->getCurrentState();
			}
		}
	}
};

class AfternoonState : public State {
public:
	void writeProgram(Work* work) {
		if (work->getHour() < 19) {
			cout << "time: " << work->getHour() << ", work tired." << endl;
		}
		else {
			work->setState(new NigthtimeState());
			work->getCurrentState();
		}
	}
};

class NoontimeState : public State {
public:
	void writeProgram(Work* work) {
		if (work->getHour() < 14) {
			cout << "time: " << work->getHour() << ", work hungry." << endl;
		}
		else {
			work->setState(new AfternoonState());
			work->getCurrentState();
		}
	}
};

class FornoonState : public State {
public:
	void writeProgram(Work* work) {
		if (work->getHour() < 12) {
			cout << "time: " << work->getHour() << ", work wonderful." << endl;
		} else {
			work->setState(new NoontimeState());
			work->getCurrentState();
		}
	}
};

Work::Work() {
	state_ = new FornoonState();
}

int main12()
{
	Work* work = new Work();

	work->setHour(8);
	work->getCurrentState();

	work->setHour(9);
	work->getCurrentState();

	work->setHour(12);
	work->getCurrentState();

	work->setHour(15);
	work->getCurrentState();

	work->setHour(17);
	work->getCurrentState();

	work->setHour(19);
	work->getCurrentState();

	work->setFinish(true);
	work->getCurrentState();

	work->setHour(21);
	work->getCurrentState();

	SAFE_DELETE(work);

	return 0;
}


