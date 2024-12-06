#pragma once
#include "CommonInclude.h"
namespace mi
{
	//enum Ŭ���� : ���ڸ� ���ڷ� ����ϱ� ���� Ŭ����
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	//enum Ŭ���� : ���ڸ� ���ڷ� ����ϱ� ���� Ŭ����
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

		//Ű �ϳ�
		struct Key
		{
			eKeyCode KeyCode; //�� ����Ű����
			eKeyState state; //Ű�� ����
			bool bPressed; //Ű�� ������ �ִ��� üũ
		};
		 
		static void Initailize(); //�ʱ�ȭ
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


