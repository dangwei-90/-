// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - �н���ģʽ

#include <iostream>
#include <vector>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

class Colleague;

// �н�ӿ� ������
class Mediator {
public:
  virtual void Send(string str, Colleague* colleague) = 0;
};

// ��Ӧ�ӿ� ������
class Colleague {
public:
  virtual void Notify() = 0;

  void SetMediator(Mediator* mediator) {
    mediator_ = mediator;
  }

protected:
  Mediator* mediator_ = nullptr;
};

// ��Ӧ�ӿ�A
class ConcreteColleagueA : public Colleague{
public:
  void SetMediatorA(Mediator* mediator) {
    mediator_ = mediator;
  }

  void Send(string str) {
    mediator_->Send(str, this);
  }

  void Notify() {
    cout << "A get a msg" << endl;
  }
};

// ��Ӧ�ӿ�B
class ConcreteColleagueB : public Colleague {
public:
  void SetMediatorB(Mediator* mediator) {
    mediator_ = mediator;
  }

  void Send(string str) {
    mediator_->Send(str, this);
  }

  void Notify() {
    cout << "B get a msg" << endl;
  }
};

// ʵ���н飺A�� send to B�࣬ B�� send to A��
class ConcreteMediator : public Mediator {
public:
  void SetColleagueA(ConcreteColleagueA* colleague) {
    colleague_a_ = colleague;
  }

  void SetColleagueB(ConcreteColleagueB* colleague) {
    colleague_b_ = colleague;
  }

  void Send(string str, Colleague* colleague) {
    cout << str << endl;
    if (colleague == colleague_a_) {
      colleague_b_->Notify();
    }
    else {
      colleague_a_->Notify();
    }
  }

private:
  ConcreteColleagueA* colleague_a_ = nullptr;
  ConcreteColleagueB* colleague_b_ = nullptr;
};

int main21()
{
  ConcreteMediator* mediator = new ConcreteMediator();

  ConcreteColleagueA* colleague_a = new ConcreteColleagueA();
  ConcreteColleagueB* colleague_b = new ConcreteColleagueB();

  colleague_a->SetMediator(mediator);
  colleague_b->SetMediator(mediator);

  mediator->SetColleagueA(colleague_a);
  mediator->SetColleagueB(colleague_b);

  colleague_a->Send("a , send a msg");
  colleague_b->Send("b , send a msg");

  SAFE_DELETE(colleague_a);
  SAFE_DELETE(colleague_b);
  SAFE_DELETE(mediator);

	return 0;
}