// GetCurrentMusic.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Interfaces.h"

INowPlayingSessionManager * manager;
INowPlayingSession * session;
IMediaPlaybackDataSource * media;

bool Getable;

void Init()
{
	CoCreateInstance(CLSID_NowPlayingSessionManager, NULL, CLSCTX_LOCAL_SERVER, IID_NowPlayingSessionManager, (void **)&manager);
}

void WINAPI Refresh()
{
	manager->GetCurrentSession(&session);
	if (!session)
		Getable = false;
	else
	{
		session->GetMedia(&media);
		if (!media)
			Getable = false;
		else
			Getable = true;
	}
}

void WINAPI GetSongInformation(wchar_t text[255])
{
	IPropertyStoreCache * store;
	PROPVARIANT pv;
	text[0] = 0;
	media->GetInformation(&store);
	if (!store)
	{
		Refresh();
		return;
	}
	store->GetValue(PKEY_ARTIST, &pv);
	if (pv.vt == 0x001f)
	{
		wcscpy_s(text, 255, pv.pwszVal);
		wcscat_s(text, 255, L" - ");
	}
	store->GetValue(PKEY_TITLE, &pv);
	if(pv.vt == 0x001f)
		wcscat_s(text, 255, pv.pwszVal);
}

bool WINAPI GetAble()
{
	return Getable;
}