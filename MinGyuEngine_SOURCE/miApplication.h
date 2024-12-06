#pragma once
#include "CommonInclude.h"
#include "miGameObject.h"
namespace mi
{
	class Application
	{
	public:
		Application();
		~Application(); 

		void Initialize(HWND hwnd, UINT width, UINT Height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;
		

		UINT mWidth;
		UINT mHeight;

		//플레이어
		GameObject mPlayer;
	};

}
