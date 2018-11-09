
// observerDlg.h : header file
//

#pragma once


// CobserverDlg dialog
class CobserverDlg : public CDialogEx
{
// Construction
public:
	CobserverDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OBSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};

// Observer play
class IHanFeizi {
public:
	// 韩非子 吃早饭
	virtual void haveBreakfast() = 0;
	// 韩非子 要娱乐
	virtual void haveFun() = 0;
};

class HanFeizi : public IHanFeizi {
private:
	// 韩非子 是否在吃饭
	BOOL isHavingBreakfast = false;
	// 韩非子 是否在娱乐
	BOOL isHavingFun = false;

public:
	void haveBreakfast() {
		// 韩非子：开始吃饭了
		this->isHavingBreakfast = true;
	}

	void haveFun() {
		// 韩非子：开始娱乐了
		this->isHavingFun = true;
	}

	void setHavingBreakfast(BOOL b)
	{
		this->isHavingBreakfast = b;
	}

	BOOL getHavingBreakfast()
	{
		return this->isHavingBreakfast;
	}

	void setHavingFun(BOOL b)
	{
		this->isHavingFun = b;
	}

	BOOL getHavingFun()
	{
		return this->isHavingFun;
	}
};

class ILiSi {
	// 发现有动静，行动
public:
	virtual void update(CString context) = 0;
};

class LiSi : public ILiSi {
	// 李斯是个观察者，一旦韩非子行动，他就要汇报秦老板
public:
	void reportToQinShiHuang(CString context) {
		// 报告老板，韩非子有活动
	}

	void update(CString context) {
		// 观察到韩非子行动
		this->reportToQinShiHuang(context);
		// 汇报完毕
	}
};

class Syp {
private:
	HanFeizi hanfeizi;
	LiSi lisi;
	CString type;

public:
	Syp(HanFeizi _hanfeizi, LiSi _lisi, CString _type) {
		this->hanfeizi = _hanfeizi;
		this->lisi = _lisi;
		this->type = _type;
	}

	// Override
	void run()
	{
		while (true)
		{
			if (this->type == "breakfast") {
				// 判断韩非子是否在吃早饭
				if (this->hanfeizi.getHavingBreakfast())
				{
					this->lisi.update("韩非子在吃饭");
					// 重置状态
					this->hanfeizi.setHavingBreakfast(false);
				}
			}
			else
			{
				if (this->hanfeizi.getHavingFun())
				{
					this->lisi.update("韩非子在玩耍");
					// 重置状态
					this->hanfeizi.setHavingFun(false);
				}
			}

		}
	}
};