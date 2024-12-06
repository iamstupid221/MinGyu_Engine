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
			// Ű�� ���ȴ�
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
			
			else // Ű�� �� ���ȴ�
			{
				// ���� �����ӿ� ������ �־���. up
				if (Keys[i].bPressed == true)
				{
					Keys[i].state = eKeyState::Up;
					// ���� �����ӵ� ���ݵ� ������ ���� �ʴ�. none
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