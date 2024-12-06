#include "miInput.h"

namespace mi
{
	std::vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
		VK_LEFT,VK_RIGHT,VK_DOWN,VK_UP,
	};

	void Input::Initailize()
	{
		createKeys();
	}

	void Input::Update()
	{
		for (size_t i = 0; i < Keys.size(); i++)
		{
			// 키가 눌렸다
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (Keys[i].bPressed == true)
				{
					Keys[i].state = eKeyState::Pressed;
				}
				else
					Keys[i].state = eKeyState::Down;

				Keys[i].bPressed = true;
			}
			
			else // 키가 안 눌렸다
			{
				// 이전 프레임에 눌려져 있었다. up
				if (Keys[i].bPressed == true)
				{
					Keys[i].state = eKeyState::Up;
					// 이전 프레임도 지금도 눌려져 있지 않다. none
				}
				else
					Keys[i].state = eKeyState::None;
				Keys[i].bPressed = false;
			}
		}
	}

	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key Key = {};
			Key.bPressed = false;
			Key.state = eKeyState::None;
			Key.KeyCode = (eKeyCode)i;

			Keys.push_back(Key);
		}
	}

	
}