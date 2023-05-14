; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCreateDSN
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Library.h"
LastPage=0

ClassCount=22
Class1=CLibraryApp
Class3=CMainFrame
Class4=CAboutDlg

ResourceCount=11
Resource1=IDD_SETODBC
Resource2=IDD_READER_MAINTAIN
Class2=CChildView
Class5=CLoginDlg
Class6=CReaderDataSet
Resource3=IDD_ABOUTBOX
Class7=CReaderMDlg
Resource4=IDD_LENDOUT
Class8=CClerkMDlg
Class9=CBorrowDataSet
Class10=CBookDataSet
Class11=CConfigDataSet
Resource5=IDR_MAINFRAME
Class12=CBookMDlg
Class13=CFineDataSet
Resource6=IDD_BOOK_MAINTAIN
Class14=CFineHistoryDataSet
Class15=CLendOutDlg
Resource7=IDD_LOGIN
Class16=CFineDlg
Resource8=IDD_FINE
Class17=CCreateDSN
Resource9=IDD_CLERK_MAINTAIN
Class18=CReturnBookDlg
Class19=CBorrowSet
Resource10=IDD_ReturnBook
Class20=CReaderQry
Class21=CReaderQryDlg
Class22=CReaderBorrowInfo
Resource11=IDD_DLGREADERQRY

[CLS:CLibraryApp]
Type=0
HeaderFile=Library.h
ImplementationFile=Library.cpp
Filter=N

[CLS:CChildView]
Type=0
HeaderFile=ChildView.h
ImplementationFile=ChildView.cpp
Filter=N

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_ReaderQry




[CLS:CAboutDlg]
Type=0
HeaderFile=Library.cpp
ImplementationFile=Library.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_LOGIN_IN
Command9=ID_LOGIN_OUT
Command10=ID_USER_MAINTAIN
Command11=ID_BOOK_MAINTAIN
Command12=ID_READER_MAINTAIN
Command13=ID_LEND_OUT
Command14=ID_RETURN_BACK
Command15=ID_FINE
Command16=ID_ReaderQry
Command17=ID_APP_ABOUT
CommandCount=17

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_EDIT_PASTE
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_CUT
Command10=ID_EDIT_UNDO
CommandCount=10

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_APP_ABOUT
CommandCount=5

[DLG:IDR_MAINFRAME]
Type=1
Class=?
ControlCount=0

[DLG:IDD_LOGIN]
Type=1
Class=CLoginDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308354
Control3=IDC_STATIC,static,1342308354
Control4=IDC_LOGIN_NAME,edit,1350631552
Control5=IDC_LOGIN_PASSWORD,edit,1350631584
Control6=IDC_CONFIRM,button,1342242817
Control7=IDC_CANCEL,button,1342242816
Control8=IDC_STATIC,static,1342177287
Control9=IDC_STATIC,static,1342177287

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLoginDlg

[CLS:CReaderDataSet]
Type=0
HeaderFile=ReaderDataSet.h
ImplementationFile=ReaderDataSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CReaderDataSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[READER_ID], 12, 16
Column2=[NAME], 12, 16
Column3=[IDCARD], 12, 36
Column4=[MAXNUM_CAN_BORROW], 5, 2
Column5=[FLAG_BORROW], 12, 2

[DLG:IDD_READER_MAINTAIN]
Type=1
Class=CReaderMDlg
ControlCount=24
Control1=IDC_STATIC,static,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_READER_NAME_FOR_Q,edit,1350631552
Control5=IDC_READER_ID_FOR_Q,edit,1350631552
Control6=IDC_STATIC,static,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342177287
Control11=IDC_READER_ID,edit,1350631552
Control12=IDC_READER_NAME,edit,1350631552
Control13=IDC_IDCARD,edit,1350631552
Control14=IDC_FIRST,button,1342242816
Control15=IDC_PRIOR,button,1342242816
Control16=IDC_NEXT,button,1342242816
Control17=IDC_LAST,button,1342242816
Control18=IDC_NEW,button,1342242816
Control19=IDC_EDIT,button,1342242816
Control20=IDC_SAVE,button,1342242816
Control21=IDC_CANCEL_REC,button,1342242816
Control22=IDC_ENQUERY,button,1342242816
Control23=IDC_DELETE,button,1342242816
Control24=IDC_EXIT,button,1342242816

[CLS:CReaderMDlg]
Type=0
HeaderFile=ReaderMDlg.h
ImplementationFile=ReaderMDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CReaderMDlg

[DLG:IDD_CLERK_MAINTAIN]
Type=1
Class=CClerkMDlg
ControlCount=28
Control1=IDC_USERNAME_Q,edit,1350631552
Control2=IDC_USERID_Q,edit,1350631552
Control3=IDC_USERID,edit,1350631552
Control4=IDC_USERNAME,edit,1350631552
Control5=IDC_IDCARD,edit,1350631552
Control6=IDC_PASSWORD,edit,1350631584
Control7=IDC_POSITION,combobox,1344340227
Control8=IDC_STATIC,static,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342177287
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342177287
Control16=IDC_FIRST,button,1342242816
Control17=IDC_PRIOR,button,1342242816
Control18=IDC_NEXT,button,1342242816
Control19=IDC_LAST,button,1342242816
Control20=IDC_NEW,button,1342242816
Control21=IDC_EDIT,button,1342242816
Control22=IDC_SAVE,button,1342242816
Control23=IDC_CANCEL_REC,button,1342242816
Control24=IDC_ENQUERY,button,1342242816
Control25=IDC_DELETE,button,1342242816
Control26=IDC_EXIT,button,1342242816
Control27=IDC_STATIC,static,1342308354
Control28=IDC_STATIC,static,1342308354

[CLS:CClerkMDlg]
Type=0
HeaderFile=ClerkMDlg.h
ImplementationFile=ClerkMDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_USERNAME_Q

[CLS:CBorrowDataSet]
Type=0
HeaderFile=BorrowDataSet.h
ImplementationFile=BorrowDataSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CBorrowDataSet

[DB:CBorrowDataSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[READER_ID], 12, 60
Column2=[BOOK_ID], 12, 60
Column3=[BORROW_DATE], 11, 16
Column4=[B_CLERK_ID], 12, 60
Column5=[ID], 4, 4

[CLS:CBookDataSet]
Type=0
HeaderFile=BookDataSet.h
ImplementationFile=BookDataSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CBookDataSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[BOOK_ID], 12, 60
Column2=[BOOK_NAME], 12, 100
Column3=[AUTHOR], 12, 60
Column4=[PRESS], 12, 100
Column5=[PRESS_DATE], 11, 16
Column6=[FLAG_BORROW], 12, 20

[CLS:CConfigDataSet]
Type=0
HeaderFile=ConfigDataSet.h
ImplementationFile=ConfigDataSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CConfigDataSet]
DB=1
DBType=ODBC
ColumnCount=0

[DLG:IDD_BOOK_MAINTAIN]
Type=1
Class=CBookMDlg
ControlCount=30
Control1=IDC_BOOKNAME_Q,edit,1350631552
Control2=IDC_BOOKID_Q,edit,1350631552
Control3=IDC_BOOKID,edit,1350631552
Control4=IDC_BOOKNAME,edit,1350631552
Control5=IDC_AUTHOR,edit,1350631552
Control6=IDC_PRESS,edit,1350631552
Control7=IDC_PRESSDATE,edit,1350631552
Control8=IDC_FLAG_BORROW,edit,1350631552
Control9=IDC_STATIC,static,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342177287
Control13=IDC_STATIC,static,1342308354
Control14=IDC_STATIC,static,1342308354
Control15=IDC_STATIC,static,1342308354
Control16=IDC_STATIC,static,1342177287
Control17=IDC_FIRST,button,1342242816
Control18=IDC_PRIOR,button,1342242816
Control19=IDC_NEXT,button,1342242816
Control20=IDC_LAST,button,1342242816
Control21=IDC_NEW,button,1342242816
Control22=IDC_EDIT,button,1342242816
Control23=IDC_SAVE,button,1342242816
Control24=IDC_CANCEL_REC,button,1342242816
Control25=IDC_ENQUERY,button,1342242816
Control26=IDC_DELETE,button,1342242816
Control27=IDC_EXIT,button,1342242816
Control28=IDC_STATIC,static,1342308354
Control29=IDC_STATIC,static,1342308354
Control30=IDC_STATIC,static,1342308354

[CLS:CBookMDlg]
Type=0
HeaderFile=BookMDlg.h
ImplementationFile=BookMDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CBookMDlg

[CLS:CFineDataSet]
Type=0
HeaderFile=FineDataSet.h
ImplementationFile=FineDataSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CFineDataSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[READER_ID], 12, 60
Column2=[AMOUNT], 4, 4
Column3=[DAYS], 5, 2
Column4=[FINE_DATE], 11, 16
Column5=[CLERK_ID], 12, 60
Column6=[ID], 4, 4

[CLS:CFineHistoryDataSet]
Type=0
HeaderFile=FineHistoryDataSet.h
ImplementationFile=FineHistoryDataSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CFineHistoryDataSet

[DB:CFineHistoryDataSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[READER_ID], 12, 60
Column2=[AMOUNT], 4, 4
Column3=[DAYS], 5, 2
Column4=[FINE_DATE], 11, 16
Column5=[OK_DATE], 11, 16
Column6=[ID], 4, 4

[DLG:IDD_LENDOUT]
Type=1
Class=CLendOutDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_READER_ID,edit,1350631552
Control5=IDC_BOOK_ID,edit,1350631552
Control6=IDC_STATIC,static,1342177287
Control7=IDC_CONFIRM,button,1342242817
Control8=IDC_CANCEL,button,1342242816

[CLS:CLendOutDlg]
Type=0
HeaderFile=LendOutDlg.h
ImplementationFile=LendOutDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLendOutDlg
VirtualFilter=dWC

[DLG:IDD_FINE]
Type=1
Class=CFineDlg
ControlCount=15
Control1=IDC_STATIC,static,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_READER_ID,edit,1350631552
Control4=IDC_STATIC,static,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342177287
Control9=IDC_DAYS,edit,1484849280
Control10=IDC_READER_NAME,edit,1484849280
Control11=IDC_AMOUNT,edit,1484849280
Control12=IDC_CONFIRM,button,1342242817
Control13=IDC_EXIT,button,1342242816
Control14=IDC_STATIC,static,1342308352
Control15=IDC_FINE_DATE,edit,1484849280

[CLS:CFineDlg]
Type=0
HeaderFile=FineDlg.h
ImplementationFile=FineDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CFineDlg

[DLG:IDD_SETODBC]
Type=1
Class=CCreateDSN
ControlCount=12
Control1=IDC_STATIC,static,1342177287
Control2=IDC_STATIC,static,1342177287
Control3=IDC_STATIC,static,1342308354
Control4=IDC_STATIC,static,1342308354
Control5=IDC_STATIC,static,1342308354
Control6=IDC_STATIC,static,1342308354
Control7=IDC_ODBCDSN,edit,1484849280
Control8=IDC_FILENAME,edit,1350631552
Control9=IDC_USERNAME,edit,1350631552
Control10=IDC_PASSWORD,edit,1350631552
Control11=IDC_CREATE,button,1342242816
Control12=IDC_CANCEL,button,1342242816

[CLS:CCreateDSN]
Type=0
HeaderFile=CreateDSN.h
ImplementationFile=CreateDSN.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCreateDSN

[DLG:IDD_ReturnBook]
Type=1
Class=CReturnBookDlg
ControlCount=14
Control1=IDCANCEL,button,1342177280
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDITBook_ID,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDITReaderName,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDITBorrowDate,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDITReturnDate,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDITDays,edit,1350631552
Control12=IDC_STATIC,static,1342177287
Control13=IDC_STATIC,static,1342177287
Control14=IDC_STATIC,static,1342177287

[CLS:CReturnBookDlg]
Type=0
HeaderFile=ReturnBookDlg.h
ImplementationFile=ReturnBookDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CReturnBookDlg
VirtualFilter=dWC

[CLS:CBorrowSet]
Type=0
HeaderFile=BorrowSet.h
ImplementationFile=BorrowSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CBorrowSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[READER_ID], 12, 60
Column2=[NAME], 12, 16
Column3=[IDCARD], 12, 36
Column4=[MAXNUM_CAN_BORROW], 5, 2
Column5=[FLAG_BORROW], 5, 2

[CLS:CReaderQry]
Type=0
HeaderFile=ReaderQry.h
ImplementationFile=ReaderQry.cpp
BaseClass=CDialog
Filter=D
LastObject=CReaderQry
VirtualFilter=dWC

[DLG:IDD_DLGREADERQRY]
Type=1
Class=CReaderQryDlg
ControlCount=11
Control1=IDC_STATIC,static,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_READERID,edit,1350631552
Control4=IDC_STATIC,static,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_READERNAME,edit,1484849280
Control7=IDC_STATIC,static,1342308352
Control8=IDC_READERIDCARD,edit,1484849280
Control9=IDC_STATIC,static,1342177287
Control10=IDC_LISTBOOK,SysListView32,1350631441
Control11=IDC_QUERY,button,1342242817

[CLS:CReaderQryDlg]
Type=0
HeaderFile=ReaderQryDlg.h
ImplementationFile=ReaderQryDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LISTBOOK

[CLS:CReaderBorrowInfo]
Type=0
HeaderFile=ReaderBorrowInfo.h
ImplementationFile=ReaderBorrowInfo.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CReaderBorrowInfo

[DB:CReaderBorrowInfo]
DB=1
DBType=ODBC
ColumnCount=11
Column1=[BOOK].[BOOK_ID], 12, 60
Column2=[BOOK_NAME], 12, 100
Column3=[AUTHOR], 12, 60
Column4=[PRESS], 12, 100
Column5=[PRESS_DATE], 11, 16
Column6=[FLAG_BORROW], 12, 20
Column7=[READER_ID], 12, 60
Column8=[BORROW].[BOOK_ID], 12, 60
Column9=[BORROW_DATE], 11, 16
Column10=[B_CLERK_ID], 12, 60
Column11=[ID], 4, 4

