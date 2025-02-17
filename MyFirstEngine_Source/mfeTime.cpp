#include "mfeTime.h"

namespace mfe {
	//LARGE_INTEGER -> ����ü�� �����̱� ������ �ʱ�ȭ�� �Ʒ��� ���� �ؾ� �Ѵ�.
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initialize()
	{
		//cpu ���� �������� ���ϴ� �Լ�
		QueryPerformanceFrequency(&CpuFrequency);

		//���α׷��� �������� �� ������ ���ϴ� �Լ�
		//�� �Լ��� ��ȯ�ϴ� ���� ���� �������� ����
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		//������Ʈ �� ������ ���� �������� ������ �;� �Ѵ�.(�׷��� ���� ���������� ���̸� �� �� �ֱ� ����)
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency = 
			static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);  //������ ����(QuadPart�� LARGE_INTEGER �ڷ����� ��� ������� 8����Ʈ�� ��� ����ϰڴٴ� �ǹ� - longlong�� ����)
		//static_cast�� c++���� �����ϴ� ������� <> �ȿ� �ִ� �ڷ������� �� ��ȯ�� �� �� ����� üũ�ؼ� ���� ������ ����ȯ�� ���� ������ ������ �߻���Ų��.
		//�� ��ȯ�� �ϴ� ������ longlong Ÿ���� 8����Ʈ�� float Ÿ���� 4����Ʈ�� ũ���� ���̰� �־� �̸� �����ϱ� ���ؼ��� ũ�⸦ ����� �ϱ� �����̴�.

		//���� ���������� ���� �������� ���� �Ǹ� ���� ��Ȳ���� ��������� �������� ���� �� �ִ�.
		//���� ���� float ������ �� ������ ������ ������ �������� ���� ������ �������� ���̰� �� ������ ���� ������ �������̰� �ð��� ���ϱ� ���ؼ� �� �������� ���ؾ� �ϱ� �����̴�.

		//���� ������ ������(�� �����ӵ��� ������ ������) / cpu ���� ������ -> �� �����ӿ� �� �ʰ� �ҿ�Ǿ����� �� �� �ִ�.
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;  //���� �ð��� �������� ���� �������� ���� ���Ű� �Ǿ��⿡ ��, ���� �������� �Ǵ� ���̱� ������ ���� �������� ���� ������ ���� �����Ѵ�.
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;  //�Լ� �ȿ����� static ����
		//static ������ ����� ������ �ʱ�ȭ�� �� ���� �Ͼ�� �ϱ� �����̴�.
		//static ������ �� ���� �ʱ�ȭ�ϱ� ������ �� �Լ��� ������ ���� ���� �� ȣ��Ǿ ������ ���� ���ϸ� �� ���� �����ϱ� ������ �� ���� �ʱ�ȭ�ϰ� ���� ��� ����ǰ� ���� �� static ������ ���
		float fps = 1.0f / DeltaTimeValue;  //��ǻ���� �ʴ� ������ ��

		time += DeltaTimeValue;

		wchar_t strTime[50] = L"";  //char - 1����Ʈ ���� �ڷ���, wchar - 2����Ʈ ���� �ڷ���(�׷��� ������ ''�� �ƴ� ""���� �ʱ�ȭ)
		//�׷��� ""�� const charŸ���̱� ������ �ʱ�ȭ �� �� ""�տ� L�� �ٿ��� const wcharŸ������ ����ؾ� �Ѵ�.(����� ���� ""�� ����� ���� L�� �ٿ��־�� �Ѵ�.)
		wchar_t strFps[50] = L"";

		swprintf_s(strTime, 50, L"Time : %.0f", time);  //wchar�� ���ڸ� ������ �� ����ϴ� �Լ�(wchar���̱� ������ ""�տ� L�� �ٴ´�.)
		//sprintf�� ������ ������ �ϴµ� ù ��° ���ڷ� wchar�� �迭�� �� ��° ���ڷ� �迭�� ũ�Ⱑ ����.(�� �迭�� �� �� �ִ� �Ѱ踦 ����ϴ� ���̶� ���� �ȴ�.)
		//�� ��° ���ں��ʹ� printf�� ����ϴ� ��ó�� ����ϸ� �ǰ� �� ��° ���ڷ� ������ ������ ù ��° ���ڷ� ���� �迭�� �����ϰ� �ȴ�.
		//std::wcout - ���� swprintf�� ���� ������ �ϴ� c++ ����� ����ε� �̰��� ����Ϸ��� ��� ���� �� ����� ������ ���� ������ �����ϱ⿡ �̹����� ���� ���� �ۼ��ؼ� ���
		swprintf_s(strFps, 50, L"Fps : %.0f", fps);

		int lenTime = wcsnlen_s(strTime, 50);  //�� �Լ��� wchar_t�� �迭�� ����Ǿ� �ִ� ���ڿ��� ���� ���̸� ��ȯ�ϴ� ������ �� ��° ���ڴ� �迭�� �ִ� ũ�⸦ �ǹ��Ѵ�.
		int lenFps = wcsnlen_s(strFps, 50);

		//ȭ�鿡 ���ڸ� ����ϴ� �Լ�
		//ù ��° ���ڷδ� dc�� �� �� ��° ���ڴ� ȭ�鿡 ����� ��ġ�� �� ��° ���ڴ� ����� ���ڿ��� �ټ� ��° ���ڷδ� ����� ���ڿ��� ���̸� �޾Ƽ� ȭ�鿡 ������ִ� �Լ��̴�.
		TextOut(hdc, 0, 15, strTime, lenTime);

		TextOut(hdc, 0, 30, strFps, lenFps);
	}
}