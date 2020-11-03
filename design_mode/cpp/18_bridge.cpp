 // ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - �Ž�ģʽ

#include <iostream>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

// �����ӿ�
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
  Implementor* implementor = new ImplementorA();
  // also , can use SetImplementor();
  Abstruction* abstruction = new Abstruction(implementor);
  abstruction->Operation();
  SAFE_DELETE(implementor);
  SAFE_DELETE(abstruction);

  implementor = new ImplementorB();
  abstruction = new Abstruction(implementor);
  abstruction->Operation();
  SAFE_DELETE(implementor);
  SAFE_DELETE(abstruction);


  return 0;
}