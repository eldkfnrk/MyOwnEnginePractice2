#pragma once
#include "mfeResource.h"

namespace mfe {
	class Resources
	{
	public:
		Resources();

		template <typename T>
		static T* Find(const std::wstring& key) {  //찾고자 하는 리소스의 이름을 인자로 전달받는다.
			//key와 동일한 이름의 리소스를 찾는다. STL은 데이터를 찾거나 접근하면 해당 데이터에 접근할 수 있는 포인터 변수를 가지고 있는 iterator라는 클래스를 반환해준다.
			//그렇기 때문에 아래와 같이 해당 트리 타입의 iterator 클래스를 만들어 값을 넣어주는 식으로 활용해야 한다.
			//std::map<std::wstring, Resource*>::iterator iter = mResources.find(key);
			auto iter = mResources.find(key);  //위의 iterator 선언문은 좀 길고 보기도 살짝 불편한 면이 있어 이와 같이 auto키워드를 사용하여 선언하면 간단하게 선언이 가능하다.
			//여기서 auto란 무엇인가 하면 자동으로 알맞는 자료형으로 선언해주는 키워드이다.
			//무슨 의미인가 하면 변수를 초기화할 때 대입하는 값의 자료형에 맞게 변수의 자료형을 알아서 자동으로 맞춰준다는 의미이다.
			//그래서 길고 쓰기 불편해서 가독성을 줄이는 자료형을 사용할 때는 auto키워드를 사용하는 것이 조금 더 편하게 작업할 수 있는 방법이다.
			//그러나 auto를 쓰는 것이 무조건 좋은 것만은 아니다. 만약 auto를 사용하여 변수를 선언해놓고 해당 변수를 사용하려고 할 때 이게 무슨 자료형의 변수인지를 헷갈릴 수 있는 문제가
			//생길 수도 있기 때문인데 그렇기에 auto는 가독성을 높이는 용도로 사용하는 것이 좋고 무조건 auto를 사용하는 것은 지양하는 것이 좋다.

			if (iter == mResources.end()) {  //find함수는 만약 찾는 데이터가 없으면 트리의 마지막을 반환해주기 때문에 이와 같이 찾았는지 아닌지를 판단할 수 있다.
				return nullptr;
			}

			//iter->second는 값을 반환한다.(first는 키의 해당하는 이름을 반환한다.)
			//여기서 iter->second는 Resource* 형의 값을 반환하는데 이 함수는 반환형이 T* 즉, 자식 클래스 중 하나의 포인터를 반환형으로 하고 있다.
			//그렇다면 iter->second를 그냥 반환하면 당연하게도 자료형이 안 맞으니 문제가 발생할 수 있어서 알맞는 형 변환이 필요하다.
			//이때 필요한 것이 SceneManager를 만들 때도 사용해보았던 dynamic_cast<>()이다.
			//dynamic_cast<>()는 부모 자식 간의 형 변환을 해주는 함수로 클래스의 상속 관계에서 형 변환이 필요할 때 사용하는 함수이다.
			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path) {  //이 함수는 로드할 리소스의 이름과 리소스의 경로를 인자로 받게 된다.
			T* resource = Resources::Find<T>(key);  //위에서 정의한 Find 템플릿 함수를 통해 리소스를 찾는다.

			if (resource != nullptr) {
				return resource;  //리소스가 존재하면 찾은 리소스를 반환하고 함수 종료
			}

			resource = new T();  //리소스가 없다면 새롭게 리소스 생성

			if (FAILED(resource->Load(path))) {  //FAILED는 HRESULT 자료형을 판단하는 함수로 인자가 S_OK이면 false를 S_FALSE면 true를 반환해준다.
				//FAILED를 쓰게 되면 비교문을 쓰지 않아도 되고 가독성도 올라가니 윈도우 API를 사용할 때는 HRESULT를 사용하는 것이 좋다.
				//MessageBox(nullptr, L"Image Load Failed!", L"Error", MB_OK);  //로드 실패 시 띄어줄 메시지 박스

				//assert()함수는 디버깅 모드에서 개발자가 오류가 생기면 치명적일 것이라는 곳에 심어 놓는 에러 검출용 코드이다.
				//즉, 오류가 발생할 경우 치명적인 문제가 발생한 것이니 이를 수정하기 위해 프로그램을 강제 종료시키는 함수이다.
				//이 함수가 호출되면 프로그램은 에러 메시지 박스를 띄어주고 강제 종료된 후 호출된 함수의 위치로 이동시켜 문제가 발생한 위치를 바로 찾을 수 있다.
				assert(false);  //이 함수가 호출이 되었다는 것은 곧 이미지 로드 시 문제가 있었다는 것을 의미한다.
			}

			resource->SetName(key);  //새로 만든 리소스의 이름 설정
			resource->SetPath(path);  //새로 만든 리소스의 경로 설정
			mResources.insert(std::make_pair(key, resource));  //리소스를 관리하는 트리에 새로 만든 리소스 추가

			return resource;  //위의 if문은 로드를 실패할 때 걸리게 되기에 if문에 걸리지 않았으면 로드를 정상적으로 성공한 것이니 로드한 리소스를 반환해주면 된다.
		}

		~Resources();

	private:
		//리소스들을 관리할 것이기 때문에 리소스를 모아두는 컨테이너가 필요하다.
		//배열을 컨테이너로 사용하면 리소스를 검색할 때 인덱스를 하나하나 순서대로 순회해서 알맞는 것을 가져오기 때문에 비효율적이다.
		//리스트 또한 배열과 마찬가지의 이유로 리소스의 컨테이너로 사용하기 부적절하다.
		//그래서 이들보다 효율적인 트리를 사용하여서 리소스들을 관리할 것이다.
		//키는 리소스의 이름 값은 해당 이름의 리소스를 가지는 노드를 소유한 트리를 생성
		static std::map<std::wstring, Resource*> mResources;  //어디서든 접근해서 사용이 가능하게 해야 하기 때문에 클래스의 정적 변수로 선언(전역 변수처럼 사용하기 위해서)
	};
}