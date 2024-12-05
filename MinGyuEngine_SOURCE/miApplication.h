#pragma once
#include "CommonInclude.h"
#include "miGameObject.h"
#include "miGameObject2.h"
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


		//�÷��̾�
		GameObject mPlayer;
		GameObject2 wPlayer;
	};

}
