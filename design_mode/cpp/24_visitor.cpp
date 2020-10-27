 // ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ

#include <iostream>
#include <vector>

using namespace std;

class Person;
class Man;
class Women;

class Action {
public:
  virtual void GetManConclusion(Man* man) = 0;
  virtual void GetWomenConlusion(Women* women) = 0;
};

class Person {
public:
  virtual void Accept(Action* action) = 0;
};

class Success : public Action {
public:
  void GetManConclusion(Man* man) {
    cout << "���˳ɹ�ʱ������...." << endl;
  }

  void GetWomenConlusion(Women* women) {
    cout << "Ů�˳ɹ�ʱ������...." << endl;
  }
};

class Fail : public Action {
public:
  void GetManConclusion(Man* man) {
    cout << "����ʧ��ʱ������...." << endl;
  }

  void GetWomenConlusion(Women* women) {
    cout << "Ů��ʧ��ʱ������...." << endl;
  }
};

class Amtiveness : public Action {
public:
  void GetManConclusion(Man* man) {
    cout << "��������ʱ������...." << endl;
  }

  void GetWomenConlusion(Women* women) {
    cout << "Ů������ʱ������...." << endl;
  }
};

class Man :public Person {
public:
  void Accept(Action* action) {
    action->GetManConclusion(this);
  }
};

class Women :public Person {
public:
  void Accept(Action* action) {
    action->GetWomenConlusion(this);
  }
};

int main24()
{
  vector<Person*> person;
  person.push_back(new Man());
  person.push_back(new Women());
  
  Success* success = new Success();
  for (auto it = person.begin(); it != person.end(); it++)
  {
    (*it)->Accept(success);
  }

  Fail* fail = new Fail();
  for (auto it = person.begin(); it != person.end(); it++)
  {
    (*it)->Accept(fail);
  }

  Amtiveness* amtiveness = new Amtiveness();
  for (auto it = person.begin(); it != person.end(); it++)
  {
    (*it)->Accept(amtiveness);
  }
	return 0;
}