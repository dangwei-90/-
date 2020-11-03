 // ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ������ģʽ

// ����C++�Ѿ�ʵ�ֵĵ�����

#include <iostream>
#include <vector>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

// �������ӿ�
class Iterator {
public:
  virtual string First() = 0;
  virtual string Next() = 0;
  virtual bool IsEnd() = 0;
  virtual string GetCurrent() = 0;
};

// ����һ�����ݵĽӿ�
class Aggregate {
public:
  virtual void Push(const string& str) = 0;
  virtual string Pop(size_t index) = 0;
  virtual size_t Count() = 0;
  virtual Iterator* CreateIterator() = 0;
};

// �������ӿڵľ���ʵ��
// �������ݽӿڣ��������ݵĲ���
class ConcreteIterator : public Iterator {
public:
  ConcreteIterator(Aggregate* aggregate) {
    aggregate_ = aggregate;
  }

  string First() {
    return aggregate_->Pop(0);
  }

  string Next() {
    if (current_ + 1 < aggregate_->Count()) {
      current_++;
      return aggregate_->Pop(current_);
    }
    else {
      return "";
    }
  }

  bool IsEnd() {
    if (current_ + 1 == aggregate_->Count()) {
      return true;
    }
    else {
      return false;
    }
  }

  string GetCurrent() {
    return aggregate_->Pop(current_);
  }

private:
  Aggregate* aggregate_ = nullptr;
  size_t current_ = 0;
};

// ���ݵľ���ʵ��
class ConcreteAggregate : public Aggregate {
public:
  ConcreteAggregate() {}
  ~ConcreteAggregate () {
    SAFE_DELETE(iterator_);
  }

  void Push(const string& str) {
    vec_str_.push_back(str);
  }
  
  string Pop(size_t index) {
    return vec_str_[index];
  }

  size_t Count() {
    return vec_str_.size();
  }

  Iterator* CreateIterator() {
    if (iterator_ == nullptr) {
      iterator_ = new ConcreteIterator(this);
    }
    return iterator_;
  }

private:
  vector<string> vec_str_;
  Iterator* iterator_ = nullptr;
};

int main16()
{
  // ConcreteAggregate��Ա����vector���д��� 
  // ����CreateIterator����ʵ���˵��õ������ӿڣ�������this������������
  ConcreteAggregate* concrete_aggregate = new ConcreteAggregate();
  concrete_aggregate->Push("a");
  concrete_aggregate->Push("b");
  concrete_aggregate->Push("c");
  concrete_aggregate->Push("d");

  Iterator* iterator = concrete_aggregate->CreateIterator();

  cout << iterator->First() << endl;
  while (!iterator->IsEnd()) {
    cout << iterator->Next() << endl;
  }

  SAFE_DELETE(concrete_aggregate);

	return 0;
}


