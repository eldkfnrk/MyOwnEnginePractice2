#pragma once
#include "mfeResource.h"

namespace mfe {
	class Resources
	{
	public:
		Resources();

		template <typename T>
		static T* Find(const std::wstring& key) {  
			auto iter = mResources.find(key);  

			if (iter == mResources.end()) {
				return nullptr;
			}

			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path) {  //이 함수는 로드할 리소스의 이름과 리소스의 경로를 인자로 받게 된다.
			T* resource = Resources::Find<T>(key);  //위에서 정의한 Find 템플릿 함수를 통해 리소스를 찾는다.

			if (resource != nullptr) {
				return resource;  //리소스가 존재하면 찾은 리소스를 반환하고 함수 종료
			}

			resource = new T();  //리소스가 없다면 새롭게 리소스 생성

			if (FAILED(resource->Load(path))) {  
				assert(false);  
			}

			resource->SetName(key);  //새로 만든 리소스의 이름 설정
			resource->SetPath(path);  //새로 만든 리소스의 경로 설정
			mResources.insert(std::make_pair(key, resource));  //리소스를 관리하는 트리에 새로 만든 리소스 추가

			return resource;  //위의 if문은 로드를 실패할 때 걸리게 되기에 if문에 걸리지 않았으면 로드를 정상적으로 성공한 것이니 로드한 리소스를 반환해주면 된다.
		}

		~Resources();

	private:
		static std::map<std::wstring, Resource*> mResources;  //어디서든 접근해서 사용이 가능하게 해야 하기 때문에 클래스의 정적 변수로 선언(전역 변수처럼 사용하기 위해서)
	};
}