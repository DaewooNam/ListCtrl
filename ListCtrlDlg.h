
// ListCtrlDlg.h: 헤더 파일
//

#pragma once

enum LC_TYPE {LCT_ICON,LCT_SICON,LCT_LIST,LCT_REPORT,LCT_MAX};


// CListCtrlDlg 대화 상자
class CListCtrlDlg : public CDialogEx
{
// 생성입니다.
public:
	CListCtrlDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTCTRL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	CListCtrl*		m_pListCtrl[LCT_MAX];


	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHdnItemclickList4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickList4(NMHDR *pNMHDR, LRESULT *pResult);
};
