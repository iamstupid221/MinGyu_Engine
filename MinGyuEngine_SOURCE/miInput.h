#pragma once
#include "CommonInclude.h"
namespace mi
{
	//enum 클래스 : 숫자를 문자로 취급하기 위한 클래스
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	//enum 클래스 : 문자를 숫자로 취급하기 위한 클래스
	enum class eKeyCode
	{
		Q,W,E,R,T,Y,U,I,O,P,
		A,S,D,F,G,H,J,K,L,
		Z,X,C,V,B,N,M,
		Left,Right,Down,Up,
		End,
	};

	class Input
	{
	public:

		//키 하나
		struct Key
		{
			eKeyCode KeyCode; //나 무슨키인지
			eKeyState state; //키의 상태
			bool bPressed; //키가 눌려져 있는지 체크
		};
		 
		static void Initailize(); //초기화
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }

	private:
		static void createKeys();

	private:
		//eKeyState mState[] = eKeyState::Up;
		static std::vector<Key> Keys;
	};
}


