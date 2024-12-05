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
			// Ű�� ���ȴ�
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
			
			else // Ű�� �� ���ȴ�
			{
				// ���� �����ӿ� ������ �־���. up
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Up;
					// ���� �����ӵ� ���ݵ� ������ ���� �ʴ�. none
				}
				else
					mKeys[i].state = eKeyState::None;
				mKeys[i].bPressed = false;
			}
		}
	}
}