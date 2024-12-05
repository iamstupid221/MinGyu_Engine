#pragma once
#include "CommonInclude.h"

namespace mi
{
	class GameObject2
	{
	public:
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition1(float x, float y) { x1 = x, y1 = y; }
		float GetXPosition() { return x1; }
		float GetYPosition() { return y1; }
	private:
		float x1;
		float y1;
	};
}