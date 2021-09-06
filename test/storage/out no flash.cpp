#include "stdio.h"
#include "stdlib.h"
#include <Windows.h>
HANDLE hOutput, hOutBuf; //控制檯屏幕緩衝區句柄
COORD coord = {0, 0};    //雙緩衝處理顯示
DWORD bytes = 0;
void set()
{
    hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,    //定義進程可以往緩衝區寫數據
        FILE_SHARE_WRITE, //定義緩衝區可共享寫權限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL);
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,    //定義進程可以往緩衝區寫數據
        FILE_SHARE_WRITE, //定義緩衝區可共享寫權限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL);
    //隱藏兩個緩衝區的光標
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hOutput, &cci);
    SetConsoleCursorInfo(hOutBuf, &cci);
}
void show(int en)
{
    char data[10][10];
    int i, j;
    //
    if (en == 0)
    {
        for (i = 0; i < 10; i++)
        {
            coord.Y = i;
            WriteConsoleOutputCharacterA(hOutBuf, "\n out", 10, coord, &bytes);
        }
    }
    if (en == 1)
    {
        for (i = 0; i < 2; i++)
        {
            coord.Y = i;
            WriteConsoleOutputCharacterA(hOutput, "cyka", 10, coord, &bytes);
        }
    }
}
void out(int en)
{
    en == 0 ? SetConsoleActiveScreenBuffer(hOutBuf) : NULL;
    en == 1 ? SetConsoleActiveScreenBuffer(hOutput) : NULL;
}
int main()
{
    set();
    for (; 1;)
    {
        show(0);
        out(0);
        sleeep(1000);
        show(1);
        out(1);
        sleeep(1000);
    }
}
