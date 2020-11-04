 // ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ������ģʽ
// ������ģʽ���е���OA��������������������һ��һ�������ߡ�

#include <iostream>
#include <vector>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

class Handler {
public:
  virtual void SetNextHandler(Handler* handler) = 0;
  virtual void HandlerRequest(int count) = 0;

protected:
  Handler* handler_ = nullptr;
};

class FirstHandler :public Handler {
public:
  void SetNextHandler(Handler* handler) {
    handler_ = handler;
  }

  void HandlerRequest(int count) {
    if (count <= 10) {
      cout << "first handler get it: " << count << endl;
    }
    else {
      if (handler_ != nullptr) {
        handler_->HandlerRequest(count);
      }
      else {
        cout << "no next handler" << endl;
      }
    }
  }
};

class SecondHandler :public Handler {
public:
  void SetNextHandler(Handler* handler) {
    handler_ = handler;
  }

  void HandlerRequest(int count) {
    if (count > 10 && count <= 20) {
      cout << "second handler get it: " << count << endl;
    }
    else {
      if (handler_ != nullptr) {
        handler_->HandlerRequest(count);
      }
      else {
        cout << "no next handler" << endl;
      }
    }
  }
};

class ThirdHandler :public Handler {
public:
  void SetNextHandler(Handler* handler) {
    handler_ = handler;
  }

  void HandlerRequest(int count) {
    if (count >= 30) {
      cout << "third handler get it: " << count << endl;
    }
    else {
      if (handler_ != nullptr) {
        handler_->HandlerRequest(count);
      }
      else {
        cout << "no next handler" << endl;
      }
    }
  }
};

int main()
{
  vector<int> nums = { 3, 10 ,2 ,54, 90, 33, 41, 5, 20 };
  FirstHandler* firsthandler = new FirstHandler();
  SecondHandler* secondhandler = new SecondHandler();
  ThirdHandler* thirdhandler = new ThirdHandler();

  firsthandler->SetNextHandler(secondhandler);
  secondhandler->SetNextHandler(thirdhandler);

  for (auto num : nums) {
    firsthandler->HandlerRequest(num);
  }

  SAFE_DELETE(firsthandler);
  SAFE_DELETE(secondhandler);
  SAFE_DELETE(thirdhandler);

	return 0;
}


