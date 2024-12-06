#pragma once
#include "CommonInclude.h"

namespace mi
{
	class Time
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency; // 해당 cpu의 고유 진동수
		static LARGE_INTEGER PrevFrequency; // 이전 진동수
		static LARGE_INTEGER Currentfrequency; // 현재 진동수
		static float DeltaTimeValue;
	};

}

