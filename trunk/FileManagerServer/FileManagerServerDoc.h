
// FileManagerServerDoc.h : CFileManagerServerDoc ��Ľӿ�
//


#pragma once


class CFileManagerServerDoc : public CDocument
{
protected: // �������л�����
	CFileManagerServerDoc();
	DECLARE_DYNCREATE(CFileManagerServerDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CFileManagerServerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


