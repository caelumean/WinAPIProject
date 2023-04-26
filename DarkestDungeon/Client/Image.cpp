#include "Image.h"
#include "Application.h"
#include "Resources.h"

extern Application application;

Image* Image::Create(const std::wstring& name, UINT widht, UINT height, COLORREF rgb)
{
	// 이미지에 0넣어서 만드는 사람 혹시 있을지 모르니깐 
	if (widht == 0 || height == 0)
		return nullptr;

	// 해당 이미지가 이미 만들어져 있는지 검색해봐야하므로 
	Image* image = Resources::Find<Image>(name);
	// 만약에 이미지가 null이 아니라면 있는 거 쓰면된다.
	if (image != nullptr)
		return image;

	//그렇지 않으면 new 이미지~
	image = new Image();
	// application의 gethdc를 가져온다.
	HDC mainHdc = application.GetHdc();

	// 이미지에 mBitmap에 비트맵을 만들어준다.
	image->mBitmap = CreateCompatibleBitmap(mainHdc, widht, height);
	// 이미지에 hdc가 필요하기때문에 mainhdc를 넣어준다.
	image->mHdc = CreateCompatibleDC(mainHdc);

	// 이 dc에다가 bitmap연결 시켜줘야한다.
	HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
	DeleteObject(oldBitmap);

	image->mWidth = widht;
	image->mHeight = height;

	image->SetKey(name);
	Resources::Insert<Image>(name, image);

	// 이미지 중간에 맞추고나서 주위에 있는 검정색을 없애기 위해 rectangle로 하얀색을 초기화해줌
	// 선 하나 생길 수 있기때문에 -1,-1
	//Rectangle(image->GetHdc(), -1, -1, image->mWidth + 1, image->mHeight + 1);

	// Setting Image Color
	HBRUSH brush = CreateSolidBrush(rgb);
	HBRUSH oldBrush = (HBRUSH)SelectObject(image->GetHdc(), brush);
	Rectangle(image->GetHdc(), -1, -1, image->mWidth + 1, image->mHeight + 1);
	SelectObject(image->GetHdc(), oldBrush);
	DeleteObject(oldBrush);

	return image;
}

Image::Image()
    : mBitmap(NULL)
    ,mHdc(NULL)
    ,mWidth(0)
    ,mHeight(0)
{
}

Image::~Image()
{
}

HRESULT Image::Load(const std::wstring& path)
{
	mBitmap = (HBITMAP)LoadImageW(nullptr
		, path.c_str(), IMAGE_BITMAP
		, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (mBitmap == nullptr)
		return E_FAIL;

	BITMAP bitInfo = {};
	GetObject(mBitmap, sizeof(BITMAP), &bitInfo);

	mWidth = bitInfo.bmWidth;
	mHeight = bitInfo.bmHeight;

	HDC mainDC = application.GetHdc();
	mHdc = CreateCompatibleDC(mainDC);

    // 이 이미지에 어떤 오브젝트랑 연결해줄 건지
    // SelectObject
	HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
	DeleteObject(oldBitmap);

    // 잘됐다면 S_OK
    return S_OK;
}

COLORREF Image::GetPixel(int x, int y)
{
	return ::GetPixel(mHdc, x, y);
}

void Image::SetPixel(int x, int y, COLORREF color)
{
	::SetPixel(mHdc, x, y, color);
}
