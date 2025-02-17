#include "mfeTime.h"

namespace mfe {
	//LARGE_INTEGER -> 구조체의 형태이기 때문에 초기화를 아래와 같이 해야 한다.
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initialize()
	{
		//cpu 고유 진동수를 구하는 함수
		QueryPerformanceFrequency(&CpuFrequency);

		//프로그램이 시작했을 때 진동수 구하는 함수
		//이 함수가 반환하는 값을 앞전 진동수로 저장
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		//업데이트 할 때마다 현재 진동수를 가지고 와야 한다.(그래야 앞전 진동수와의 차이를 알 수 있기 때문)
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency = 
			static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);  //진동수 차이(QuadPart는 LARGE_INTEGER 자료형의 사용 방법으로 8바이트를 모두 사용하겠다는 의미 - longlong과 같다)
		//static_cast는 c++에서 제공하는 기능으로 <> 안에 있는 자료형으로 형 변환을 할 때 요류를 체크해서 문제 없으면 형변환을 문제 있으면 오류를 발생시킨다.
		//형 변환을 하는 이유는 longlong 타입은 8바이트고 float 타입은 4바이트로 크기의 차이가 있어 이를 대입하기 위해서는 크기를 맞춰야 하기 때문이다.

		//현재 진동수에서 앞전 진동수를 빼게 되면 앞전 상황에서 현재까지의 진동수를 구할 수 있다.
		//위와 같은 float 연산을 한 이유는 이전에 측정한 진동수와 현재 측정한 진동수의 차이가 한 프레임 동안 진동한 진동수이고 시간을 구하기 위해선 이 진동수를 구해야 하기 때문이다.

		//현재 진동한 진동수(한 프레임동안 진동한 진동수) / cpu 고유 진동수 -> 한 프레임에 몇 초가 소요되었는지 알 수 있다.
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;  //이제 시간을 구했으니 현재 진동수는 이제 과거가 되었기에 즉, 앞전 진동수가 되는 것이기 때문에 앞전 진동수에 현재 진동수 값을 대입한다.
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;  //함수 안에서의 static 변수
		//static 변수를 사용한 이유는 초기화는 한 번만 일어나야 하기 때문이다.
		//static 변수는 한 번만 초기화하기 때문에 이 함수가 루프를 돌아 여러 번 호출되어도 변수의 값이 변하면 그 값을 유지하기 때문에 한 번만 초기화하고 값이 계속 변경되게 만들 때 static 변수를 사용
		float fps = 1.0f / DeltaTimeValue;  //컴퓨터의 초당 프레임 수

		time += DeltaTimeValue;

		wchar_t strTime[50] = L"";  //char - 1바이트 문자 자료형, wchar - 2바이트 문자 자료형(그렇기 때문에 ''이 아닌 ""으로 초기화)
		//그러나 ""은 const char타입이기 때문에 초기화 할 때 ""앞에 L을 붙여서 const wchar타입임을 명시해야 한다.(출력할 때도 ""을 사용할 때는 L을 붙여주어야 한다.)
		wchar_t strFps[50] = L"";

		swprintf_s(strTime, 50, L"Time : %.0f", time);  //wchar형 문자를 복사할 때 사용하는 함수(wchar형이기 때문에 ""앞에 L이 붙는다.)
		//sprintf와 동일한 동작을 하는데 첫 번째 인자로 wchar형 배열을 두 번째 인자로 배열의 크기가 들어간다.(이 배열의 들어갈 수 있는 한계를 명시하는 것이라 보면 된다.)
		//세 번째 인자부터는 printf를 사용하는 것처럼 사용하면 되고 세 번째 인자로 들어오는 내용을 첫 번째 인자로 들어온 배열에 저장하게 된다.
		//std::wcout - 위의 swprintf와 같은 역할을 하는 c++ 입출력 방식인데 이것을 사용하려면 어느 나라 언어를 사용할 것인지 등의 설정이 복잡하기에 이번에는 위와 같이 작성해서 사용
		swprintf_s(strFps, 50, L"Fps : %.0f", fps);

		int lenTime = wcsnlen_s(strTime, 50);  //이 함수는 wchar_t형 배열에 저장되어 있는 문자열의 실제 길이를 반환하는 값으로 두 번째 인자는 배열의 최대 크기를 의미한다.
		int lenFps = wcsnlen_s(strFps, 50);

		//화면에 문자를 출력하는 함수
		//첫 번째 인자로는 dc를 두 세 번째 인자는 화면에 출력할 위치를 네 번째 인자는 출력할 문자열을 다섯 번째 인자로는 출력할 문자열의 길이를 받아서 화면에 출력해주는 함수이다.
		TextOut(hdc, 0, 15, strTime, lenTime);

		TextOut(hdc, 0, 30, strFps, lenFps);
	}
}