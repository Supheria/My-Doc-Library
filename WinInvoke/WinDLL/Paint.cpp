#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "Paint.h"

HINSTANCE hInst;//����ʵ�����

int DrawGraph(int width, int height, HDC hdc)
{
    HBITMAP hSun = (HBITMAP)LoadImage(hInst, L"1.jpg", IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    HDC hMemDc = CreateCompatibleDC(hdc);//��ȡ�ڴ��豸����������ʹ��  λͼ�����ڴ��б�������
    SelectObject(hMemDc, hSun);//ѡ��λͼ���������ڴ��豸������
    BitBlt(hdc, 0, 0, width, height, hMemDc, 0, 0, SRCCOPY);//��λͼ���ڴ渴�Ƶ�����
    DeleteDC(hMemDc);//ɾ���豸�ڴ��������е�λͼ
    return 1;
}