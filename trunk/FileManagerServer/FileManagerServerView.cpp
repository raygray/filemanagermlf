
// FileManagerServerView.cpp : CFileManagerServerView 类的实现
//

#include "stdafx.h"
#include "FileManagerServer.h"

#include "FileManagerServerDoc.h"
#include "FileManagerServerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileManagerServerView

IMPLEMENT_DYNCREATE(CFileManagerServerView, CListView)

BEGIN_MESSAGE_MAP(CFileManagerServerView, CListView)
	ON_WM_STYLECHANGED()
END_MESSAGE_MAP()

// CFileManagerServerView 构造/析构

CFileManagerServerView::CFileManagerServerView()
{
	// TODO: 在此处添加构造代码

}

CFileManagerServerView::~CFileManagerServerView()
{
}

BOOL CFileManagerServerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CListView::PreCreateWindow(cs);
}

void CFileManagerServerView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: 调用 GetListCtrl() 直接访问 ListView 的列表控件，
	//  从而可以用项填充 ListView。
}

void CFileManagerServerView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFileManagerServerView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CFileManagerServerView 诊断

#ifdef _DEBUG
void CFileManagerServerView::AssertValid() const
{
	CListView::AssertValid();
}

void CFileManagerServerView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CFileManagerServerDoc* CFileManagerServerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileManagerServerDoc)));
	return (CFileManagerServerDoc*)m_pDocument;
}
#endif //_DEBUG


// CFileManagerServerView 消息处理程序
void CFileManagerServerView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: 添加代码以响应用户对窗口视图样式的更改	
	CListView::OnStyleChanged(nStyleType,lpStyleStruct);	
}
