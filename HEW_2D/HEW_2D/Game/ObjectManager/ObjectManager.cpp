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
		obj.second->Update();
	}
	
}


/**
 * @brief �`��
 * 
 * �J����������ꍇ�́A���̃I�u�W�F�N�g�̑傫���ȓ��ɂ�����̂�����`�悷��
 * �J�������Ȃ��ꍇ�͂��̂܂ܕ`��
*/
void ObjectManager::Draw(void) {
	D3d11.StartRender();


	// �J����������ꍇ
	if (auto cam = HasCamera())
	{
		// �`�悷��ׂ��I�u�W�F�N�g���i�[���Ă���
		std::vector<std::pair<std::pair<Tag, std::string>, std::shared_ptr<GameObject>>> drewobj;
		
		// �J�����̕`��͈�
		float left = cam->GetPosition().x - cam->GetScale().x / 2;  // �J�����̍��[
		float right = cam->GetPosition().x + cam->GetScale().x / 2; // �J�����̉E�[
		float up = cam->GetPosition().y + cam->GetScale().y / 2;    // �J�����̏�[
		float down = cam->GetPosition().y - cam->GetScale().y / 2;  // �J�����̉��[

		// �I�u�W�F�N�g���`�F�b�N
		for (auto& obj : Objects) {
			float objX = obj.second->GetPosition().x;
			float objY = obj.second->GetPosition().y;

			// �I�u�W�F�N�g��x���W���J�����̎��E�͈͓��A����y���W�����E�͈͓��ɂ���ꍇ
			if (left <= objX && objX <= right && down <= objY && objY <= up) {
				// �I�u�W�F�N�g��`�悷��ׂ����X�g�ɒǉ�
				drewobj.push_back(obj);  // �K�v�ɉ����Ēǉ�����
				obj.second->Draw();      // �I�u�W�F�N�g��`��
			}
		}

		// �͈�for��
		// ��ɔw�i����`��
		for (auto& obj : drewobj)
		{
			if (obj.first.first == BACKGROUND)
			{
				// first���L�[�iObjectName�j,second���I�u�W�F�N�g�{��
				obj.second->Draw();
			}
		}

		// �w�i��UI�ȊO��`��
		for (auto& obj : drewobj)
		{
			if (obj.first.first != BACKGROUND && obj.first.first != UI)
			{
				obj.second->Draw();
			}
		}

		// �Ō��UI��`��
		for (auto& obj : drewobj)
		{
			if (obj.first.first == UI)
			{
				obj.second->Draw();
			}
		}
		
	}
	// �J�������Ȃ��ꍇ
	else
	{
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


/**
 * @brief �S�ẴI�u�W�F�N�g���擾
 * @return 
*/
std::vector<std::pair<std::pair<Tag, std::string>, std::shared_ptr<GameObject>>> ObjectManager::GetAllObjects(void)
{
	std::vector<std::pair<std::pair<Tag, std::string>, std::shared_ptr<GameObject>>> ret;
	for (auto& obj : Objects)
	{
		ret.emplace_back(obj);
	}
	return ret;
}


/**
 * @brief �J����������΂��̃|�C���^��Ԃ�
 * @param  
 * @return 
*/
std::shared_ptr<Camera> ObjectManager::HasCamera(void)
{
	for (const auto& obj : Objects) {
		if (auto casted = std::dynamic_pointer_cast<Camera>(obj.second)) {
			return casted;  // 1����������I��
		}
	}
}
