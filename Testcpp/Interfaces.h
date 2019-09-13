#pragma once

#include <Windows.h>
#include <Propsys.h>

static CLSID CLSID_NowPlayingSessionManager = { 0xBCBB9860, 0xC012, 0x4AD7, { 0xA9, 0x38, 0x6E, 0x33, 0x7A, 0xE6, 0xAB, 0xA5 } };
static IID IID_NowPlayingSessionManager = { 0xa7052211, 0x8b56, 0x43c4, {0x8f, 0x26, 0x12, 0x85, 0x2f, 0x73, 0x03, 0xa3} };

static PROPERTYKEY PKEY_TITLE = { { 0xF29F85E0, 0x4FF9, 0x1068, { 0xAB, 0x91, 0x08, 0x00, 0x2B, 0x27, 0xB3, 0xD9 } },0x2 };
static PROPERTYKEY PKEY_ARTIST = { { 0x56A3372E, 0xCE9C, 0x11D2, { 0x9F, 0x0E, 0x00, 0x60, 0x97, 0xC6, 0x86, 0xF6 } },0x2 };
static PROPERTYKEY PKEY_AppUserModel_ID = { {0x9F4C2855, 0x9F79, 0x4B39, {0xA8, 0xD0, 0xE1, 0xD4, 0x2D, 0xE1, 0xD5, 0xF3}}, 0x5 };

static PROPERTYKEY PKEY_Tile_LongDisplayName = { {0x86D40B4D, 0x9069, 0x443C, {0x81, 0x9A, 0x2A, 0x54, 0x9, 0xD, 0xCC, 0xEC}}, 0xB };
static PROPERTYKEY PKEY_AppUserModel_PackageFullName = { {0x9F4C2855, 0x9F79, 0x4B39, {0xA8, 0xD0, 0xE1, 0xD4, 0x2D, 0xE1, 0xD5, 0xF3}}, 0x15 };

struct INowPlayingSessionManager;
struct INowPlayingSession;
struct IMediaPlaybackDataSource;

struct IMediaPlaybackDataSource : public IUnknown
{
public:
	virtual void unknown18h() = 0;
	virtual void unknown20h() = 0;
	virtual void GetInformation(IPropertyStoreCache **) = 0;
};

struct INowPlayingSession : public IUnknown
{
public:
	virtual void unknown18h() = 0;
	virtual void unknown20h() = 0;
	virtual void unknown28h() = 0;
	virtual void unknown30h() = 0;
	virtual void unknown38h() = 0;
	virtual void unknown40h() = 0;
	virtual void unknown48h() = 0;
	virtual void unknown50h() = 0;
	virtual void GetMedia(IMediaPlaybackDataSource **) = 0;
};

struct INowPlayingSessionManager : public IUnknown
{
public:
	virtual void unknown18h() = 0;
	virtual void GetCurrentSession(INowPlayingSession **) = 0;
	virtual void unknown28h() = 0;
	virtual void unknown30h() = 0;
	virtual void GetAllSession(long*, INowPlayingSession***) = 0;
};

void WINAPI Init();
void WINAPI Refresh();
void WINAPI GetSongInformation(wchar_t* text);
bool WINAPI GetAble();
void WINAPI NextSession();