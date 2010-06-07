
// FileManagerServerView.cpp : CFileManagerServerView ���ʵ��
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

// CFileManagerServerView ����/����

CFileManagerServerView::CFileManagerServerView()
{
	// TODO: �ڴ˴���ӹ������

}

CFileManagerServerView::~CFileManagerServerView()
{
}

BOOL CFileManagerServerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CListView::PreCreateWindow(cs);
}

void CFileManagerServerView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: ���� GetListCtrl() ֱ�ӷ��� ListView ���б�ؼ���
	//  �Ӷ������������ ListView��
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


// CFileManagerServerView ���

#ifdef _DEBUG
void CFileManagerServerView::AssertValid() const
{
	CListView::AssertValid();
}

void CFileManagerServerView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CFileManagerServerDoc* CFileManagerServerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileManagerServerDoc)));
	return (CFileManagerServerDoc*)m_pDocument;
}
#endif //_DEBUG


// CFileManagerServerView ��Ϣ�������
void CFileManagerServerView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: ��Ӵ�������Ӧ�û��Դ�����ͼ��ʽ�ĸ���	
	CListView::OnStyleChanged(nStyleType,lpStyleStruct);	
}
