
// FileManagerServerDoc.cpp : CFileManagerServerDoc 类的实现
//

#include "stdafx.h"
#include "FileManagerServer.h"

#include "FileManagerServerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileManagerServerDoc

IMPLEMENT_DYNCREATE(CFileManagerServerDoc, CDocument)

BEGIN_MESSAGE_MAP(CFileManagerServerDoc, CDocument)
END_MESSAGE_MAP()


// CFileManagerServerDoc 构造/析构

CFileManagerServerDoc::CFileManagerServerDoc()
{
	// TODO: 在此添加一次性构造代码

}

CFileManagerServerDoc::~CFileManagerServerDoc()
{
}

BOOL CFileManagerServerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CFileManagerServerDoc 序列化

void CFileManagerServerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CFileManagerServerDoc 诊断

#ifdef _DEBUG
void CFileManagerServerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFileManagerServerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFileManagerServerDoc 命令
