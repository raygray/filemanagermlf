
// FileManagerServerView.h : CFileManagerServerView ��Ľӿ�
//


#pragma once


class CFileManagerServerView : public CListView
{
protected: // �������л�����
	CFileManagerServerView();
	DECLARE_DYNCREATE(CFileManagerServerView)

// ����
public:
	CFileManagerServerDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CFileManagerServerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // FileManagerServerView.cpp �еĵ��԰汾
inline CFileManagerServerDoc* CFileManagerServerView::GetDocument() const
   { return reinterpret_cast<CFileManagerServerDoc*>(m_pDocument); }
#endif

