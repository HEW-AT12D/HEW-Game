#include "ObjectManager.h"




size_t ObjectManager::GetObjectCount(void)
{
	return Objects.size();
}


/**
 * @brief �I�u�W�F�N�g�擾�֐�
 * @param _Tag �I�u�W�F�N�g�^�O
 * @param _Name �t���������O
 * @return �I�u�W�F�N�g�̐��|�C���^
*/
GameObject* ObjectManager::GetGameObject(const Tag& _Tag, const std::string _Name)
{
	// �^�O�Ɩ��O�̈�v����I�u�W�F�N�g��������(������Ȃ��ꍇ��end()���Ԃ��Ă���)
	auto iterator = Objects.find(std::make_pair(_Tag, _Name));
	// ���������ꍇ
	if (iterator != Objects.end())
	{
		return iterator->second.get();
	}

	// ������Ȃ����nullprt��Ԃ�
	return nullptr;
}


/**
 * @brief �I�u�W�F�N�g�폜�֐�
 * @param object 
*/
void ObjectManager::DeleteObject(Tag _ObjName) {
	//! �I�u�W�F�N�g�z�񂪋�łȂ����
	if (!this->Objects.empty()) {
		//! �w�肵���v�f���폜
		//Objects.(_ObjName);
	}
}

/**
 * @brief �I�u�W�F�N�g������
 * �R���X�g���N�^�ŃI�u�W�F�N�g���ꊇ�ǉ���Init���ŏ��������ǂ����H�����ꂼ�ꏉ�����l���Ⴄ�̂ł����ŃI�u�W�F�N�g��Init���񂹂Ȃ�
 * 
 * �����ł̓R���e�i�̏������������s��
*/
void ObjectManager::Init(void) {
	// �I�u�W�F�N�g�Ǘ��p�R���e�i�̏�����
	Objects.clear();
}

void ObjectManager::Update(void) {

	

	// �͈�for��
	for (auto& obj : Objects)
	{
		// ��ʊO�ɏo����I�u�W�F�N�g���폜
		// first���L�[�iObjectName�j,second���I�u�W�F�N�g�{��
		if (obj.second->GetPosition().x > SCREEN_WIDTH / 2 || obj.second->GetPosition().x < 0 - SCREEN_WIDTH / 2 ||
			obj.second->GetPosition().y > SCREEN_HEIGHT / 2 || obj.second->GetPosition().y < 0 - SCREEN_HEIGHT / 2) {
			//this->DeleteObject(obj.first);		// �I�u�W�F�N�g�̃L�[���w�肵�č폜
		}
	}
	
}

void ObjectManager::Draw(void) {
	D3d11.StartRender();
	// �͈�for��
	for (auto& obj : Objects)
	{
		// first���L�[�iObjectName�j,second���I�u�W�F�N�g�{��
		obj.second->Draw();
	}
	D3d11.FinishRender();
}

void ObjectManager::Uninit(void) {
	// �͈�for��
	for (auto& obj : Objects)
	{
		// first���L�[�iObjectName�j,second���I�u�W�F�N�g�{��
		// �I�u�W�F�N�g�̒��g�����
		obj.second->Uninit();
	}
	// �R���e�i�S�̂����
	Objects.clear();
}
