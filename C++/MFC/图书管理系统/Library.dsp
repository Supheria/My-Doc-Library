# Microsoft Developer Studio Project File - Name="Library" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Library - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Library.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Library.mak" CFG="Library - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Library - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Library - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Library - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Library - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Library - Win32 Release"
# Name "Library - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BookDataSet.cpp
# End Source File
# Begin Source File

SOURCE=.\BookMDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BorrowDataSet.cpp
# End Source File
# Begin Source File

SOURCE=.\BorrowSet.cpp
# End Source File
# Begin Source File

SOURCE=.\ChildView.cpp
# End Source File
# Begin Source File

SOURCE=.\ClerkDataSet.cpp
# End Source File
# Begin Source File

SOURCE=.\ClerkMDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ConfigDataSet.cpp
# End Source File
# Begin Source File

SOURCE=.\FineDataSet.cpp
# End Source File
# Begin Source File

SOURCE=.\FineDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FineHistoryDataSet.cpp
# End Source File
# Begin Source File

SOURCE=.\LendOutDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Library.cpp
# End Source File
# Begin Source File

SOURCE=.\Library.rc
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\ReaderBorrowInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\ReaderDataSet.cpp
# End Source File
# Begin Source File

SOURCE=.\ReaderMDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ReaderQryDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ReturnBookDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BookDataSet.h
# End Source File
# Begin Source File

SOURCE=.\BookMDlg.h
# End Source File
# Begin Source File

SOURCE=.\BorrowDataSet.h
# End Source File
# Begin Source File

SOURCE=.\BorrowSet.h
# End Source File
# Begin Source File

SOURCE=.\ChildView.h
# End Source File
# Begin Source File

SOURCE=.\ClerkDataSet.h
# End Source File
# Begin Source File

SOURCE=.\ClerkMDlg.h
# End Source File
# Begin Source File

SOURCE=.\ConfigDataSet.h
# End Source File
# Begin Source File

SOURCE=.\FineDataSet.h
# End Source File
# Begin Source File

SOURCE=.\FineDlg.h
# End Source File
# Begin Source File

SOURCE=.\FineHistoryDataSet.h
# End Source File
# Begin Source File

SOURCE=.\LendOutDlg.h
# End Source File
# Begin Source File

SOURCE=.\Library.h
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\ReaderBorrowInfo.h
# End Source File
# Begin Source File

SOURCE=.\ReaderDataSet.h
# End Source File
# Begin Source File

SOURCE=.\ReaderMDlg.h
# End Source File
# Begin Source File

SOURCE=.\ReaderQryDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ReturnBookDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Library.ico
# End Source File
# Begin Source File

SOURCE=.\res\Library.rc2
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section Library : {5E71F050-551F-11CF-8152-00AA00A40C25}
# 	2:5:Class:CrdoPreparedStatement
# 	2:10:HeaderFile:rdopreparedstatement.h
# 	2:8:ImplFile:rdopreparedstatement.cpp
# End Section
# Section Library : {2E7464A0-6ED1-11CE-9223-08002B369A33}
# 	2:5:Class:CrdoErrors
# 	2:10:HeaderFile:rdoerrors.h
# 	2:8:ImplFile:rdoerrors.cpp
# End Section
# Section Library : {43478D71-78E0-11CF-8E78-00A0D100038E}
# 	2:5:Class:CRdc
# 	2:10:HeaderFile:rdc.h
# 	2:8:ImplFile:rdc.cpp
# End Section
# Section Library : {5D545B93-97CA-11CF-8171-00AA00A40C25}
# 	2:5:Class:CrdoPreparedStatements
# 	2:10:HeaderFile:rdopreparedstatements.h
# 	2:8:ImplFile:rdopreparedstatements.cpp
# End Section
# Section Library : {2E746494-6ED1-11CE-9223-08002B369A33}
# 	2:5:Class:CrdoConnections
# 	2:10:HeaderFile:rdoconnections.h
# 	2:8:ImplFile:rdoconnections.cpp
# End Section
# Section Library : {B541C034-63BC-11CE-920C-08002B369A33}
# 	2:5:Class:CrdoError
# 	2:10:HeaderFile:rdoerror.h
# 	2:8:ImplFile:rdoerror.cpp
# End Section
# Section Library : {5E71F04B-551F-11CF-8152-00AA00A40C25}
# 	2:5:Class:C_rdoEngine
# 	2:10:HeaderFile:_rdoengine.h
# 	2:8:ImplFile:_rdoengine.cpp
# End Section
# Section Library : {2E746498-6ED1-11CE-9223-08002B369A33}
# 	2:5:Class:CrdoQueries
# 	2:10:HeaderFile:rdoqueries.h
# 	2:8:ImplFile:rdoqueries.cpp
# End Section
# Section Library : {2E746493-6ED1-11CE-9223-08002B369A33}
# 	2:5:Class:CrdoTables
# 	2:10:HeaderFile:rdotables.h
# 	2:8:ImplFile:rdotables.cpp
# End Section
# Section Library : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font.h
# 	2:8:ImplFile:font.cpp
# End Section
# Section Library : {5E71F053-551F-11CF-8152-00AA00A40C25}
# 	2:5:Class:CrdoEnvironments
# 	2:10:HeaderFile:rdoenvironments.h
# 	2:8:ImplFile:rdoenvironments.cpp
# End Section
# Section Library : {00028C02-0000-0000-0000-000000000046}
# 	2:5:Class:CMsDgridCtrl
# 	2:10:HeaderFile:msdgridctrl.h
# 	2:8:ImplFile:msdgridctrl.cpp
# End Section
# Section Library : {5E71F04F-551F-11CF-8152-00AA00A40C25}
# 	2:5:Class:C_rdoResultset
# 	2:10:HeaderFile:_rdoresultset.h
# 	2:8:ImplFile:_rdoresultset.cpp
# End Section
# Section Library : {2E746492-6ED1-11CE-9223-08002B369A33}
# 	2:5:Class:CrdoColumns
# 	2:10:HeaderFile:rdocolumns.h
# 	2:8:ImplFile:rdocolumns.cpp
# End Section
# Section Library : {7BF80981-BF32-101A-8BBB-00AA00300CAB}
# 	2:5:Class:CPicture
# 	2:10:HeaderFile:picture.h
# 	2:8:ImplFile:picture.cpp
# End Section
# Section Library : {5E71F04E-551F-11CF-8152-00AA00A40C25}
# 	2:5:Class:C_rdoColumn
# 	2:10:HeaderFile:_rdocolumn.h
# 	2:8:ImplFile:_rdocolumn.cpp
# End Section
# Section Library : {2E746496-6ED1-11CE-9223-08002B369A33}
# 	2:5:Class:CrdoResultsets
# 	2:10:HeaderFile:rdoresultsets.h
# 	2:8:ImplFile:rdoresultsets.cpp
# End Section
# Section Library : {5E71F052-551F-11CF-8152-00AA00A40C25}
# 	2:5:Class:CrdoParameter
# 	2:10:HeaderFile:rdoparameter.h
# 	2:8:ImplFile:rdoparameter.cpp
# End Section
# Section Library : {43478D73-78E0-11CF-8E78-00A0D100038E}
# 	2:21:DefaultSinkHeaderFile:rdc.h
# 	2:16:DefaultSinkClass:CRdc
# End Section
# Section Library : {5E71F04D-551F-11CF-8152-00AA00A40C25}
# 	2:5:Class:C_rdoConnection
# 	2:10:HeaderFile:_rdoconnection.h
# 	2:8:ImplFile:_rdoconnection.cpp
# End Section
# Section Library : {B541C03D-63BC-11CE-920C-08002B369A33}
# 	2:5:Class:CrdoTable
# 	2:10:HeaderFile:rdotable.h
# 	2:8:ImplFile:rdotable.cpp
# End Section
# Section Library : {00028C00-0000-0000-0000-000000000046}
# 	2:21:DefaultSinkHeaderFile:msdgridctrl.h
# 	2:16:DefaultSinkClass:CMsDgridCtrl
# End Section
# Section Library : {2E746495-6ED1-11CE-9223-08002B369A33}
# 	2:5:Class:CrdoParameters
# 	2:10:HeaderFile:rdoparameters.h
# 	2:8:ImplFile:rdoparameters.cpp
# End Section
# Section Library : {5E71F051-551F-11CF-8152-00AA00A40C25}
# 	2:5:Class:C_rdoEnvironment
# 	2:10:HeaderFile:_rdoenvironment.h
# 	2:8:ImplFile:_rdoenvironment.cpp
# End Section
