#include "stdio.h"
#include "stdlib.h"
#include <Windows.h>
HANDLE hOutput, hOutBuf; //�����i�̹��w�İϥy�`
COORD coord = {0, 0};    //���w�ĳB�z���
DWORD bytes = 0;
void set()
{
    hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,    //�w�q�i�{�i�H���w�İϼg�ƾ�
        FILE_SHARE_WRITE, //�w�q�w�İϥi�@�ɼg�v��
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL);
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,    //�w�q�i�{�i�H���w�İϼg�ƾ�
        FILE_SHARE_WRITE, //�w�q�w�İϥi�@�ɼg�v��
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL);
    //���è�ӽw�İϪ�����
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
