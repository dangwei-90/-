// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ����ģʽ

// ֻ����һ��ʵ���������ڶ�ȡ�����ļ��ȡ�
// �ݲ������ͷ����⡣������ڳ�ª������ά���������岻��

#include <iostream>
#include <vector>
#include <mutex>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;


/////////////////////C++ 11///////////////////
class SingletonStatic {
public:
  ~SingletonStatic() {}

  static SingletonStatic* GetInstance() {
    static SingletonStatic* singleton_static = new SingletonStatic();
    return singleton_static;
  }
};
//////////////////////////////////////////////


//////////////////������ʽʵ��////////////////
// �����������̰߳�ȫ
mutex g_mt_lock;

class Singleton {
public:
  ~Singleton() {
  }

  static Singleton* GetInstance() {
    if (singleton_ == nullptr) {
      g_mt_lock.lock();
      if (singleton_ == nullptr) {
        singleton_ = new Singleton();
      }
      g_mt_lock.unlock();
    }

    return singleton_;
  }

public:
  static Singleton* singleton_;
};
Singleton* Singleton::singleton_ = nullptr;
////////////////////////////////////////////


int main17()
{
  // C++ 11 �� static ���ԣ�ʵ�ֵ���ģʽ
  SingletonStatic* test_a_static = SingletonStatic::GetInstance();
  SingletonStatic* test_b_static = SingletonStatic::GetInstance();
  if (test_a_static == test_b_static) {
    cout << "static same singleton" << endl;
  }
  else {
    cout << "static not same singleton" << endl;
  }

  // �����ķ�ʽʵ�ֵ���ģʽ
  Singleton* test_a = Singleton::GetInstance();
  Singleton* test_b = Singleton::GetInstance();
  if (test_a == test_b) {
    cout << "same singleton" << endl;
  }
  else {
    cout << "not same singleton" << endl;
  }


  /* �ݲ������ͷ����⡣������ڳ�ª������ά���������岻��
  //delete Singleton::GetInstance();
  delete test_a;
  test_a = nullptr;

  Singleton* test_c = Singleton::GetInstance();
  test_c->testfun();
  test_a->testfun();
  */

  return 0;
}