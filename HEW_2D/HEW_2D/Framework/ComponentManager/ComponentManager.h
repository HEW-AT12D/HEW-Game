#pragma once
#include "../Component/IComponent/IComponent.h"

/**
 * @brief �R���|�[�l���g�Ǘ��N���X
 * 
 * �R���|�[�l���g�ǂ��Ǘ�����H��shared_ptr�ŊǗ�
 * 
 * ���̃N���X�Ŏ��ׂ�����
 * ���̃N���X��ێ�����e�I�u�W�F�N�g�̃|�C���^
*/
class ComponentManager
{
public:
	ComponentManager(GameObject& _Owner) :m_Owner(_Owner) {
		
	}

	~ComponentManager() {
		Uninit();
	};

	//-----------------------
	//-----�e���v���[�g�֐�-----
	//-----------------------
	/**
	 * @brief 
	 * @tparam T 
	 * map�ɃR���|�[�l���g��ǉ�
	 * �����R���|�[�l���g�����ɑ��݂��Ă�����G���[�o������
	*/

	/**
	 * @brief �R���|�[�l���g�ǉ��֐�
	 * @tparam T �R���|�[�l���g
	 * @param  
	 * @return �R���|�[�l���g��weak_ptr�������g���ꍇ��lock()��������shared_ptr�ɕϊ����Ă���g��(�Q�ƃJ�E���g�͑����Ȃ��̂ő��v)
	*/
	template <class T>
	std::weak_ptr<T> AddComponent(void) 
	{
		// !�w�肵���R���|�[�l���g��map�ɒǉ�
		auto component = std::make_shared<T>();
		// !���ɓ����R���|�[�l���g�����݂��Ă����
		if (m_Components.find(std::type_index(typeid(T))) != m_Components.end())
		{
			//! �G���[
			throw std::runtime_error("����R���|�[�l���g�����ɑ��݂��Ă��܂�");
		}

		// !�Ȃ���Ώ��������Ēǉ�
		component->Init();
		m_Components.emplace(std::type_index(typeid(T)), component);

		// �g���g��Ȃ��͒u���Ă����āA�R���|�[�l���g�̃|�C���^��Ԃ��Ă����������H
		// ��shared_ptr��Ԃ��ƕςɏ��L�҂���������\��������̂ŁAweak_ptr��Ԃ�
		return std::weak_ptr<T>(component);
	}

	/**
	 * @brief �R���|�[�l���g�擾�֐�
	 * @tparam T �R���|�[�l���g�̌^
	 * @return �R���|�[�l���g�̃|�C���^
	 * 
	 * weak_ptr�Ŏ擾����֐������Ă���������
	*/
	template <class T>
	std::shared_ptr<T> GetComponent(void)
	{
		// �R���|�[�l���g����T��
		for (auto& component : m_Components)
		{
			//! ���ɓ����R���|�[�l���g�����݂��Ă���΁��w�肵���^�ɃL���X�g�ł����
			if (T* comp = dynamic_cast<T*>(component.second.get())
			{
				//! ���̃R���|�[�l���g�̃|�C���^��Ԃ�
				return std::shared_ptr<T>(component.second, comp);
			}
		}
		// �R���|�[�l���g�����݂��Ȃ���΃G���[�o��
		std::cerr<< typeid(T).name() << "�������Ă��܂���" <<std::endl;
	}

	/**
	 * @brief �I�u�W�F�N�g�̃R���|�[�l���g�����ׂĎ擾����֐�
	 * @tparam T 
	 * @param  
	 * @return �S�ẴR���|�[�l���g
	*/
	/*template <class T>
	std::vector<IComponent*> GetComponents(T)
	{
		
	}*/

	//-----------------------
	//--------�ʏ�֐�--------
	//-----------------------
	void Init(void);	// ���L����I�u�W�F�N�g�̃|�C���^���ǂ��n�������R���X�g���N�^�H�֐��H
	void Update(void);
	void Uninit(void);


private:
	//! �R���|�[�l���g�}�l�[�W����ێ�����I�u�W�F�N�g�̎Q�Ɓi�R���|�[�l���g�����I�u�W�F�N�g�͕K�����݂��Ă��Ȃ���΂����Ȃ����߁j
	GameObject& m_Owner;
	//!	�R���|�[�l���g�̌^���L�[�ɂ��ăR���|�[�l���g�̃|�C���^��ێ����Ă������P�̃I�u�W�F�N�g�͓����R���|�[�l���g�͈��ނ������ĂȂ�
	std::unordered_map<std::type_index, std::shared_ptr<IComponent>> m_Components;
};


