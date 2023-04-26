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
	// �� �̹��� ���Ͽ� �����ؼ� ����ҷ��� DC�� �־���Ѵ�.
	// �̹��� �� ��� DC�־���Ѵ�.
	HDC mHdc;
	UINT mWidth;
	UINT mHeight;

};

