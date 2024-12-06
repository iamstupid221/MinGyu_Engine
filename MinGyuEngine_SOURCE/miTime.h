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
		static LARGE_INTEGER CpuFrequency; // �ش� cpu�� ���� ������
		static LARGE_INTEGER PrevFrequency; // ���� ������
		static LARGE_INTEGER Currentfrequency; // ���� ������
		static float DeltaTimeValue;
	};

}

