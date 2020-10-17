 // ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ

#include <iostream>

using namespace std;

class Implementor {
public:
  virtual void Operation() = 0;
};

class ImplementorA : public Implementor {
public:
  void Operation (){
    cout << "Operation A" << endl;
  }
};

class ImplementorB : public Implementor {
public:
  void Operation() {
    cout << "Operation B" << endl;
  }
};

class Abstruction {
public:
  Abstruction() {};
  Abstruction(Implementor* implementor) {
    implementor_ = implementor;
  }

  void SetImplementor(Implementor* implementor) {
    implementor_ = implementor;
  }

  void Operation() {
    implementor_->Operation();
  }

private:
  Implementor* implementor_ = nullptr;
};


int main18()
{
  /*
  Abstruction* abstruction = new Abstruction();
  // memory leak
  abstruction->SetImplementor(new ImplementorA());
  abstruction->Operation();

  // memory leak
  abstruction->SetImplementor(new ImplementorB());
  abstruction->Operation();
  */

  Implementor* implementor = new ImplementorA(); 
  // also , can use SetImplementor();
  Abstruction* abstruction = new Abstruction(implementor);
  abstruction->Operation();
  delete implementor;
  implementor = nullptr;
  delete abstruction;
  abstruction = nullptr;

  implementor = new ImplementorB();
  abstruction = new Abstruction(implementor);
  abstruction->Operation();
  delete implementor;
  implementor = nullptr;
  delete abstruction;
  abstruction = nullptr;


	return 0;
}


