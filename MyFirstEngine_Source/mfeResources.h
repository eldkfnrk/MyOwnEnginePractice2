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
		static T* Load(const std::wstring& key, const std::wstring& path) {  //�� �Լ��� �ε��� ���ҽ��� �̸��� ���ҽ��� ��θ� ���ڷ� �ް� �ȴ�.
			T* resource = Resources::Find<T>(key);  //������ ������ Find ���ø� �Լ��� ���� ���ҽ��� ã�´�.

			if (resource != nullptr) {
				return resource;  //���ҽ��� �����ϸ� ã�� ���ҽ��� ��ȯ�ϰ� �Լ� ����
			}

			resource = new T();  //���ҽ��� ���ٸ� ���Ӱ� ���ҽ� ����

			if (FAILED(resource->Load(path))) {  
				assert(false);  
			}

			resource->SetName(key);  //���� ���� ���ҽ��� �̸� ����
			resource->SetPath(path);  //���� ���� ���ҽ��� ��� ����
			mResources.insert(std::make_pair(key, resource));  //���ҽ��� �����ϴ� Ʈ���� ���� ���� ���ҽ� �߰�

			return resource;  //���� if���� �ε带 ������ �� �ɸ��� �Ǳ⿡ if���� �ɸ��� �ʾ����� �ε带 ���������� ������ ���̴� �ε��� ���ҽ��� ��ȯ���ָ� �ȴ�.
		}

		~Resources();

	private:
		static std::map<std::wstring, Resource*> mResources;  //��𼭵� �����ؼ� ����� �����ϰ� �ؾ� �ϱ� ������ Ŭ������ ���� ������ ����(���� ����ó�� ����ϱ� ���ؼ�)
	};
}