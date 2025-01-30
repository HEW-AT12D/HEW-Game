#include "ObjectManager.h"
#include "../../Framework/Component/Collider/BoxCollider2D/Collider.h"


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
 * @brief �v���C���[�Ɖ����̓����蔻��
 * 
 * 
*/
void ObjectManager::Collider_Player_to_Object(void)
{
	// �v���C���[�擾
	auto playerobj = GetGameObjectPtr<Player>(PLAYER, "Player");
	
	// �ύX�\��̃I�u�W�F�N�g���L�^���郊�X�g
	std::vector<std::pair<std::pair<Tag, std::string>, std::shared_ptr<GameObject>>> toBeUpdated;


	// �v���C���[�Ɠ��������I�u�W�F�N�g���m�F
	for (auto& obj : Objects) {
		// �^�O���n�ʁA�I�u�W�F�N�g�A�G�̂��̂��������蔻������
		switch (obj.first.first)
		{
		// �I�u�W�F�N�g���n�ʂȂ�
		case BACKGROUND:
			// �n�ʂƂ̓����蔻������
			Collider_toGround(playerobj, obj.second);
			break;
		// �摜�͓����蔻������Ȃ�
		case IMAGE:
			break;
		// UI����������Ȃ�
		case UI:
			break;
		// �Q�[���I�u�W�F�N�g�Ȃ画������
		case OBJECT:
			// �����̓}�K�W���̔��������Ă���
			if (Collider_to_Object(playerobj, obj.second))
			{
				toBeUpdated.push_back(obj); // �ύX�Ώۂ��L�^
			}
			break;
		case GROUND:
			break;
		case PLAYER:
			break;
		case ENEMY:
			break;
		default:
			break;
		}
		
	}

	// �L�^�����ύX�Ώۂ�����(�}�K�W���p�����A���g��ς���΃I�u�W�F�N�g�̍폜���\)
	for (auto& it : toBeUpdated) {
		auto mag = std::dynamic_pointer_cast<Magazine>(it.second);
		if (mag) {
			// �}�K�W���̃^�O��ύX
			ChangeTag(it.first.first, it.first.second, UI);
			// �v���C���[�̎q�I�u�W�F�N�g�ɐݒ�
			playerobj.lock()->SetChild(mag);
			mag->SetScale(Vector3(50.0f, 50.0f, 0.0f));
			mag->SetPosition(Vector3(-800.0f, -500.0f, 0.0f));
		}
	}
}


/**
 * @brief �^�O�ύX�֐�
 * @param _oldtag �ύX�O�̃^�O
 * @param _name �^�O��ύX�������I�u�W�F�N�g��
 * @param _newTag �ύX��̃^�O
 * @return ����
*/
bool ObjectManager::ChangeTag(Tag _oldtag, const std::string _name, Tag _newTag)
{
	// ���݂̃L�[���쐬
	auto oldKey = std::make_pair(_oldtag, _name);

	// 1. ���̃L�[�ŃI�u�W�F�N�g������
	auto it = Objects.find(oldKey);
	if (it == Objects.end()) {
		std::cerr << "�I�u�W�F�N�g��������܂���: " << _name << std::endl;
		return false;
	}

	// 2. �I�u�W�F�N�g���擾���A�}�b�v����폜
	auto obj = it->second;
	Objects.erase(it);

	// 3. �V�����^�O�ōēo�^
	auto newKey = std::make_pair(_newTag, _name);
	Objects[newKey] = obj;

	return true;
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
		obj.second->Update();
	}
	
}

void ObjectManager::Draw(void) {
	D3d11.StartRender();
	// �͈�for��
	// ��ɔw�i����`��
	for (auto& obj : Objects)
	{
		if (obj.first.first == BACKGROUND)
		{
			// first���L�[�iObjectName�j,second���I�u�W�F�N�g�{��
			obj.second->Draw();
		}
	}

	// �w�i��UI�ȊO��`��
	for (auto& obj : Objects)
	{
		if (obj.first.first != BACKGROUND && obj.first.first != UI)
		{
			obj.second->Draw();
		}
	}

	// �Ō��UI��`��
	for (auto& obj : Objects)
	{
		if (obj.first.first == UI)
		{
			obj.second->Draw();
		}
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
