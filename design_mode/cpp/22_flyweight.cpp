// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ��Ԫģʽ

#include <iostream>
#include <vector>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

// �����ӿ� ������
class Flyweight {
public:
  virtual void Operation(int num) = 0;
};

// �ɹ��õķ���ʵ��
class ConreteFlyweight : public Flyweight {
public:
  void Operation(int num) {
    cout << "flyweight , num: " << num << endl;
  }
};

// ���ɹ��õķ���ʵ��
class UnsharedConreteFlyweight : public Flyweight {
public:
  void Operation(int num) {
    cout << "unshared flyweight , num: " << num << endl;
  }
};

class FlyweightFactory {
public:
  FlyweightFactory() {
    // д�����ã������ڴ����
    flyweight_.push_back(new ConreteFlyweight());
  }

  ~FlyweightFactory()
  {
    for (auto it = flyweight_.begin(); it != flyweight_.end(); it++)
    {
      SAFE_DELETE(*it);
    }
    flyweight_.clear();
  }

  Flyweight* GetFlyweight() {
    vector<Flyweight*>::iterator p = flyweight_.begin();
    return *p;
  }

private:
  vector<Flyweight*> flyweight_;
};

int main()
{
  FlyweightFactory* flyweight_factory = new FlyweightFactory();

  Flyweight* concrete_flyweight = flyweight_factory->GetFlyweight();
  concrete_flyweight->Operation(12);

  Flyweight* concrete_flyweight_2 = flyweight_factory->GetFlyweight();
  concrete_flyweight_2->Operation(13);

  UnsharedConreteFlyweight* unshared_concrete_flyweight = new UnsharedConreteFlyweight();
  unshared_concrete_flyweight->Operation(16);

  SAFE_DELETE(unshared_concrete_flyweight);
  SAFE_DELETE(flyweight_factory);

	return 0;
}