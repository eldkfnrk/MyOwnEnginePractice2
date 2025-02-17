#include "mfeScene.h"

namespace mfe {
	Scene::Scene() : mLayers{}
	{
		mLayers.resize((UINT)eLayerType::Max);

		//�Ʒ��� for���� std::for_each������ ��ȯ�ϸ� ������ ���� ���¸� ���δ�.
		//std::for_each(mLayers.begin(), mLayers.end(), [](Layer*& layer) {  //�� ������ ���ٽ����� �̸� Ȱ��
		//		layer = new Layer();
		//	}
		//);

		for (size_t i = 0; i < (UINT)eLayerType::Max; i++) {
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

	void Scene::AddGameObject(GameObject* gameObject, const eLayerType type) {
		mLayers[(UINT)type]->AddGameObject(gameObject);  //type ���̾ �ش��ϴ� ���̾ ������Ʈ �߰�
	}

	Scene::~Scene()
	{

	}
}