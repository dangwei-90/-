// simple_factory.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ����ģʽ

#include <iostream>

using namespace std;

// ��ͬ���ԵĽӿ�
class CashSuper {
public:
	virtual double acceptCash(double money) = 0;
};

// ����Ĳ���ʵ������
// �����շ�
class CashNormal : public CashSuper {
public:
	double acceptCash(double money) {
		return money;
	}
};

// ����Ĳ���ʵ������
// �����շ�
class CashRebate : public CashSuper {
public:
	CashRebate(double moneyRebate) {
		moneyRebate_ = moneyRebate;
	}

	double acceptCash(double money) {
		return money * moneyRebate_;
	}

private:
	double moneyRebate_ = 0;
};

// ����Ĳ���ʵ������
// �����շ�
class CashReturn : public CashSuper {
public:
	CashReturn(double total, double ret) {
		total_ = total;
		return_ = ret;
	}

	double acceptCash(double money) {
		if (money > total_) {
			return money - return_;
		}
		else {
			return money;
		}
	}

private:
	double total_ = 0;
	double return_ = 0;
};

// ���ݾ��岻ͬ�Ĳ��ԣ�������ͬ�Ķ��󣬰������Եľ����㷨
class CashContext {
public:
	CashContext(int ntype) {
		switch (ntype) {
		case 1:
		{
			cashSuper_ = new CashNormal();
			break;
		}
		case 2:
		{
			cashSuper_ = new CashRebate(0.8);
			break;
		}
		case 3:
		{
			cashSuper_ = new CashReturn(500, 300);
			break;
		}
		default:
			break;
		}
	}

	~CashContext() {
		if (cashSuper_ != nullptr) {
			delete cashSuper_;
			cashSuper_ = nullptr;
		}
	}

	double GetCashResult(double money) {
		return cashSuper_->acceptCash(money);
	}

private:
	CashSuper* cashSuper_ = nullptr;
};

int main()
{
	// �ͻ���ֻ���ĵ��ò������ͣ��������Ĳ��Եľ���ʵ��
	int ntype = 3;
	CashContext* cashContext = new CashContext(ntype);
	cout << cashContext->GetCashResult(1000) << "\n";

	delete cashContext;
	cashContext = nullptr;

	ntype = 2;
	cashContext = new CashContext(ntype);
	cout << cashContext->GetCashResult(1000) << "\n";

	delete cashContext;
	cashContext = nullptr;

	return 0;
}


