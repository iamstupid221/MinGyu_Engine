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

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;


		//플레이어
		GameObject mPlayer;
	};

}
