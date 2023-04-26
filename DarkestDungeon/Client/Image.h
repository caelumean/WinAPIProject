#pragma once
#include "yaResource.h"


class Image : public Resource
{
public:

	//static Image* Create(const std::wstring& name, UINT widht, UINT height);
	static Image* Create(const std::wstring& name, UINT widht, UINT height, COLORREF rgb = RGB(255, 255, 255));

	Image();
	~Image();

	virtual HRESULT Load(const std::wstring& path) override;

	COLORREF GetPixel(int x, int y);
	void SetPixel(int x, int y, COLORREF color);

	HDC GetHdc() { return mHdc; }
	HBITMAP GetBitmap() { return mBitmap; }
	UINT GetWidth() { return mWidth; }
	UINT GetHeight() { return mHeight; }


private:
	HBITMAP mBitmap;
	// 이 이미지 파일에 접근해서 사용할려면 DC가 있어야한다.
	// 이미지 한 장당 DC있어야한다.
	HDC mHdc;
	UINT mWidth;
	UINT mHeight;

};

