#include "miInput.h"

namespace mi
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
	};

	void Input::Initailize()
	{

		mKeys.resize((UINT)eKeyCode::End);

		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key Key = {};
			Key.bPressed = false;
			Key.state = eKeyState::None;
			Key.KeyCode = (eKeyCode)i;

			mKeys.push_back(Key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			// 키가 눌렸다
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				else
					mKeys[i].state = eKeyState::Down;

				mKeys[i].bPressed = true;
			}
			
			else // 키가 안 눌렸다
			{
				// 이전 프레임에 눌려져 있었다. up
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Up;
					// 이전 프레임도 지금도 눌려져 있지 않다. none
				}
				else
					mKeys[i].state = eKeyState::None;
				mKeys[i].bPressed = false;
			}
		}
	}
}