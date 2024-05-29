#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "Paint.h"

HINSTANCE hInst;//保存实例句柄

int DrawGraph(int width, int height, HDC hdc)
{
    HBITMAP hSun = (HBITMAP)LoadImage(hInst, L"1.jpg", IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    HDC hMemDc = CreateCompatibleDC(hdc);//获取内存设备描述表句柄，使得  位图能在内存中保存下来
    SelectObject(hMemDc, hSun);//选择位图对象，送入内存设备描述表；
    BitBlt(hdc, 0, 0, width, height, hMemDc, 0, 0, SRCCOPY);//把位图从内存复制到窗口
    DeleteDC(hMemDc);//删除设备内存描述表中的位图
    return 1;
}