 // ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ

#include <iostream>
#include <vector>

using namespace std;

class Flyweight {
public:
  virtual void Operation(int num) = 0;
};

class ConreteFlyweight : public Flyweight {
public:
  void Operation(int num) {
    cout << "flyweight , num: " << num << endl;
  }
};

class UnsharedConreteFlyweight : public Flyweight {
public:
  void Operation(int num) {
    cout << "unshared flyweight , num: " << num << endl;
  }
};

class FlyweightFactory {
public:
  FlyweightFactory() {
    flyweight_.push_back(new ConreteFlyweight());
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
	return 0;
}