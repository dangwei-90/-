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

  void testfun() {
    test_num_++;
    cout << "test object" << endl;
  }

public:
  static Singleton* singleton_;
  int test_num_ = 0;
};

Singleton* Singleton::singleton_ = nullptr;

int main()
{
  Singleton* test_a = Singleton::GetInstance();
  Singleton* test_b = Singleton::GetInstance();
  if (test_a == test_b) {
    cout << "same singleton" << endl;
  }

  test_a->testfun();

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