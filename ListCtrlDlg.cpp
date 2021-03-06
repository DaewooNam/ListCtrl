
// ListCtrlDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ListCtrl.h"
#include "ListCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CListCtrlDlg 대화 상자



CListCtrlDlg::CListCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LISTCTRL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CListCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CListCtrlDlg::OnHdnItemclickList4)
	ON_NOTIFY(NM_CLICK, IDC_LIST4, &CListCtrlDlg::OnNMClickList4)
END_MESSAGE_MAP()


// CListCtrlDlg 메시지 처리기

BOOL CListCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_pListCtrl[LCT_ICON] = (CListCtrl*)GetDlgItem(IDC_LIST1); // list 주소 얻기
	m_pListCtrl[LCT_SICON] = (CListCtrl*)GetDlgItem(IDC_LIST2);
	m_pListCtrl[LCT_LIST] = (CListCtrl*)GetDlgItem(IDC_LIST3); // LIST BOX 값을 사용
	m_pListCtrl[LCT_REPORT] = (CListCtrl*)GetDlgItem(IDC_LIST4); // 제일 많이 사용(report 속성에만 Column 값이 할당)

	/*
	for (int i = 0; i < LCT_MAX; i++)
	{
		//m_pListCtrl[i]->InsertColumn(0,"subject",LVCFMT_CENTER,100); // index/ string / LVCFMT값이 가운데 정렬 / 길이

		m_pListCtrl[i]->InsertItem(0, "JAVA"); // 이미지 삽입은 복잡
		m_pListCtrl[i]->InsertItem(1, "API");
		m_pListCtrl[i]->InsertItem(2, "MFC");
		m_pListCtrl[i]->InsertItem(3, "UNITY");

	}
	*/



	m_pListCtrl[LCT_REPORT]->InsertColumn(0, "이름", LVCFMT_CENTER, 60);
	m_pListCtrl[LCT_REPORT]->InsertColumn(1, "나이", LVCFMT_CENTER, 50);
	//m_pListCtrl[LCT_REPORT]->InsertColumn(2, "전화번호", LVCFMT_CENTER, 100); // insert 방식은 2가지 방식으로 나뉜다.

	LVCOLUMN lvCol;
	ZeroMemory(&lvCol, sizeof(lvCol)); //초기화 무조건 해줘야 함 (수정시 사용)

	lvCol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT;
	lvCol.fmt = LVCFMT_CENTER; //format 형태 위드 긜고 문자
	lvCol.cx = 100;
	lvCol.pszText = "전화번호";

	m_pListCtrl[LCT_REPORT]->InsertColumn(2, &lvCol);

	ListView_SetExtendedListViewStyle(m_pListCtrl[LCT_REPORT]->m_hWnd, LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);


	m_pListCtrl[LCT_REPORT]->InsertItem(0, "키트리"); // 첫번째 값이 추가 되어야 SetItem 값이 변경이 가능
	m_pListCtrl[LCT_REPORT]->InsertItem(1, "한국정보");
	m_pListCtrl[LCT_REPORT]->InsertItem(2, "연구원");



	m_pListCtrl[LCT_REPORT]->SetItem(0, 1, LVIF_TEXT, "20", 0, 0, 0, 0); // item = row ,sub = colum
	m_pListCtrl[LCT_REPORT]->SetItem(0, 2, LVIF_TEXT, "010-111-111", 0, 0, 0, 0); // item = row ,sub = colum

	m_pListCtrl[LCT_REPORT]->SetItem(1, 1, LVIF_TEXT, "20", 0, 0, 0, 0); // item = row ,sub = colum
	m_pListCtrl[LCT_REPORT]->SetItem(1, 2, LVIF_TEXT, "010-111-111", 0, 0, 0, 0); // item = row ,sub = colum

	LVITEM item;

	ZeroMemory(&item, sizeof(item));

	item.mask		= LVIF_TEXT;
	item.iItem		= 2;
	item.iSubItem	= 1;
	item.pszText	= "50";
	m_pListCtrl[LCT_REPORT]->SetItem(&item);

	item.mask		= LVIF_TEXT;
	item.iItem		= 2;
	item.iSubItem	= 2;
	item.pszText	= "010-8464-8552";
	m_pListCtrl[LCT_REPORT]->SetItem(&item);





	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CListCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CListCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CListCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListCtrlDlg::OnHdnItemclickList4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	TRACE("OnHdnItemclickList4()\n %d", phdr->iItem);
	

	LVCOLUMN lvCol;
	ZeroMemory(&lvCol, sizeof(lvCol));
	
	lvCol.mask = LVCF_TEXT; //원하는 변하는 값들을 저장
	lvCol.pszText = new char[10];//넣어줄때는 공간을 할당해 줘야 함
	lvCol.cchTextMax = 10;


	m_pListCtrl[LCT_REPORT]->GetColumn(phdr->iItem,&lvCol);

	//AfxMessageBox(lvCol.pszText);

	//strcpy_s(lvCol.pszText, 5, "name");
	//m_pListCtrl[LCT_REPORT]->SetColumn(phdr->iItem,&lvCol);


	*pResult = 0;
}


void CListCtrlDlg::OnNMClickList4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	TRACE("OnNMClickList4() %d %d \n", pNMItemActivate->iItem, pNMItemActivate->iSubItem);

	LVITEM lvItem;
	ZeroMemory(&lvItem,sizeof(lvItem));

	lvItem.mask = LVIF_TEXT; //text 를 넣어준다 LVIF 인지 LVCF 인지 구분 (비트연산)
	lvItem.pszText = new char[15]; //format 외워야 될듯
	lvItem.cchTextMax = 15;

	lvItem.iItem = pNMItemActivate->iItem;
	lvItem.iSubItem = pNMItemActivate->iSubItem;


	m_pListCtrl[LCT_REPORT]->GetItem(&lvItem);
	AfxMessageBox(lvItem.pszText);


	//m_pListCtrl[LCT_REPORT]->GetItem(&lvItem);
//	m_pListCtrl[LCT_REPORT]->GetItem();

	//m_pListCtrl[LCT_REPORT]->SetItem(pNMItemActivate->iItem, pNMItemActivate->iSubItem, LVIF_TEXT, "none", 0, 0, 0, 0);
	*pResult = 0;
}
