#include "mfeScene.h"

namespace mfe {
	Scene::Scene() : mLayers{}
	{
		createLayers();
	}

	void Scene::createLayers() {
		mLayers.resize((UINT)enums::eLayerType::Max);

		//아래의 for문을 std::for_each문으로 변환하면 다음과 같은 형태를 보인다.
		//std::for_each(mLayers.begin(), mLayers.end(), [](Layer*& layer) {  //이 문장은 람다식으로 이를 활용
		//		layer = new Layer();
		//	}
		//);

		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++) {
			mLayers[i] = new Layer();
		}
	}

	void Scene::Initialize()
	{
		for (Layer* layer : mLayers) {
			if (layer == nullptr)
				continue;
			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer* layer : mLayers) {
			if (layer == nullptr)
				continue;
			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers) {
			if (layer == nullptr)
				continue;
			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers) { 
			if (layer == nullptr)
				continue;
			layer->Render(hdc);
		}
	}

	void Scene::OnEnter() {

	}

	void Scene::OnExit() {

	}

	void Scene::AddGameObject(GameObject* gameObject, const enums::eLayerType type) {
		mLayers[(UINT)type]->AddGameObject(gameObject);  //type 레이어에 해당하는 레이어에 오브젝트 추가
	}

	Scene::~Scene()
	{

	}
}