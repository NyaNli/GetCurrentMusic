// Testcpp.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <clocale>
#include <cstdio>
#include <Windows.h>
#include "Interfaces.h"

/*
#pragma comment(lib, "GetCurrentMusic.lib")

extern void Refresh();
extern void GetSongInformation(wchar_t text[255]);
extern bool GetAble();
extern void Init();
*/

int main()
{
	setlocale(LC_CTYPE, ".936");
	wchar_t ttt[255];
	Init();
	while (true)
	{
		Sleep(1000);
		if (GetAble())
		{
			GetSessionName(ttt);
			wprintf(ttt);
			wprintf(L"\n");
			NextSession();
		}
		else
		{
			Refresh();
		}
	}
    return 0;
}

