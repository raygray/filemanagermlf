
// FileManagerServerView.h : CFileManagerServerView 类的接口
//


#pragma once


class CFileManagerServerView : public CListView
{
protected: // 仅从序列化创建
	CFileManagerServerView();
	DECLARE_DYNCREATE(CFileManagerServerView)

// 属性
public:
	CFileManagerServerDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CFileManagerServerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // FileManagerServerView.cpp 中的调试版本
inline CFileManagerServerDoc* CFileManagerServerView::GetDocument() const
   { return reinterpret_cast<CFileManagerServerDoc*>(m_pDocument); }
#endif

