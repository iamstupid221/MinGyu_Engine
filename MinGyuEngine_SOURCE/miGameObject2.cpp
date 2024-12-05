#include "miGameObject2.h"

namespace mi
{
	void GameObject2::Update()
	{
		if (GetAsyncKeyState('W') & 0x8000)
		{
			y1 -= 0.01f;
		}

		if (GetAsyncKeyState('S') & 0x8000)
		{
			y1 += 0.01f;
		}

		if (GetAsyncKeyState('A') & 0x8000)
		{
			x1 -= 0.01f;
		}

		if (GetAsyncKeyState('D') & 0x8000)
		{
			x1 += 0.01f;
		}
	}

	void GameObject2::LateUpdate()
	{

	}

	void GameObject2::Render(HDC hdc)
	{
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

		HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
		HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);

		Ellipse(hdc, 300 + x1, 300 + y1, 200 + x1, 200 + y1);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, hOldPen);

		DeleteObject(hBrush);
		DeleteObject(hPen);
	}

}
