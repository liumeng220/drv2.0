// DLGCreatorData.cpp : implementation file
//

#include "stdafx.h"
#include "DLGCreatorData.h"
#include "afxdialogex.h"


// CDLGCreatorData dialog

IMPLEMENT_DYNAMIC(CDLGCreatorData, CDialogEx)

CDLGCreatorData::CDLGCreatorData(CString sDefLayer,CWnd* pParent /*=NULL*/)
	: CDialogEx(CDLGCreatorData::IDD, pParent),
	mBuildingLayer(sDefLayer)
{

}

CDLGCreatorData::~CDLGCreatorData()
{
}

void CDLGCreatorData::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BUILDING, mBuildingLayer);
	DDX_Text(pDX, IDC_EDIT_PATH, mPathFile);
	DDX_Text(pDX, IDC_EDIT_SPAN, mSpan);
}


BEGIN_MESSAGE_MAP(CDLGCreatorData, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SELPATH, &CDLGCreatorData::OnBnClickedButtonSelpath)
	ON_BN_CLICKED(IDC_BUTTON_SELVECTOR, &CDLGCreatorData::OnBnClickedButtonSelvector)
	ON_BN_CLICKED(IDOK, &CDLGCreatorData::OnBnClickedOk)
END_MESSAGE_MAP()


// CDLGCreatorData message handlers


void CDLGCreatorData::OnBnClickedButtonSelpath()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, NULL, NULL, OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, _T("文本文件(*.txt)|*.txt||"));
	if( dlg.DoModal() != IDOK )
	{
		return;
	}
	mPathFile = dlg.GetPathName();
	UpdateData(FALSE);
}


void CDLGCreatorData::OnBnClickedButtonSelvector()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, NULL, NULL, OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, _T("shp文件(*.shp)|*.shp||"));
	if( dlg.DoModal() != IDOK )
	{
		return;
	}
	mBuildingLayer = dlg.GetPathName();
	UpdateData(FALSE);
}


void CDLGCreatorData::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (mBuildingLayer.IsEmpty() || mSpan.IsEmpty() || mPathFile.IsEmpty())
	{
		AfxMessageBox(_T("参数不正确，请检查"));
		return;
	}
}
