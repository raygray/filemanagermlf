
// FileManagerServerDoc.cpp : CFileManagerServerDoc ���ʵ��
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


// CFileManagerServerDoc ����/����

CFileManagerServerDoc::CFileManagerServerDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CFileManagerServerDoc::~CFileManagerServerDoc()
{
}

BOOL CFileManagerServerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CFileManagerServerDoc ���л�

void CFileManagerServerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CFileManagerServerDoc ���

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


// CFileManagerServerDoc ����
