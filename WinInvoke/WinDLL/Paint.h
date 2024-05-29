#pragma once
#include <wtypes.h>


/*--------------------------------
函数功能：画图
参数二：分辨率宽度
参数三：分辨率高度
参数四：显示句柄
返回值：0 ->成功， 其他 ->失败
------------------------------------*/
extern "C" _declspec(dllexport) int DrawGraph(int width, int height, HDC hdc);