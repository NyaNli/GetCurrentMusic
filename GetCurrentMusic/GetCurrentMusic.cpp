// GetCurrentMusic.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Interfaces.h"

INowPlayingSessionManager* manager = NULL;
INowPlayingSession** sessions = NULL;
long sessioncount = 0;
long currentindex = 0;

bool Getable = false;

//Call it yourself!!!
void WINAPI Init()
{
	CoInitialize(NULL);
	CoCreateInstance(CLSID_NowPlayingSessionManager, NULL, CLSCTX_LOCAL_SERVER, IID_NowPlayingSessionManager, (void**)& manager);
	Refresh();
}

void WINAPI Refresh()
{
	if (!manager)
	{
		Getable = false;
		return;
	}
	//manager->GetCurrentSession(&session);
	if (sessioncount > 0)
	{
		for (int i = 0; i < sessioncount; i++)
			sessions[i]->Release();
		sessioncount = 0;
		sessions = NULL;
	}
	manager->GetAllSession(&sessioncount, &sessions);
	if (sessioncount <= 0)
		Getable = false;
	else
	{
		currentindex = 0;
		Getable = true;
	}
}

void WINAPI GetSongInformation(wchar_t* text)
{
	IMediaPlaybackDataSource* media = NULL;
	sessions[currentindex]->GetMedia(&media);
	if (!media)
	{
		Getable = false;
		return;
	}
	IPropertyStoreCache* store;
	PROPVARIANT pv;
	text[0] = 0;
	media->GetInformation(&store);
	if (!store)
	{
		Getable = false;
		return;
	}
	store->GetValue(PKEY_ARTIST, &pv);
	if (pv.vt == 0x001f)
	{
		wcscpy_s(text, 255, pv.pwszVal);
		wcscat_s(text, 255, L" - ");
	}
	PropVariantClear(&pv);
	store->GetValue(PKEY_TITLE, &pv);
	if (pv.vt == 0x001f)
		wcscat_s(text, 255, pv.pwszVal);
	PropVariantClear(&pv);
	store->Release();
	media->Release();
}

bool WINAPI GetAble()
{
	return Getable;
}

void WINAPI NextSession()
{
	currentindex++;
	if (currentindex >= sessioncount)
		currentindex = 0;
}