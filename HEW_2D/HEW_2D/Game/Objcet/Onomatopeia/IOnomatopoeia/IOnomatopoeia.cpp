#include "../IOnomatopoeia/IOnomatopoeia.h"
#include "../../BaseObject/GameObject.h"



/**
 * @brief �t�F�[�h�C��/�t�F�[�h�A�E�g�i���Ԍo�߂Ŏ�邩�������j
 * ����͋[���o�����̓t�F�[�h�C��/�A�E�g���J��Ԃ����[�����������Ɏ��s����悤�ɂ�����
*/
void IOnomatopoeia::Fade_in_out(void)
{
	Color c_obj = m_Color;
	if (fade_check)
	{
		c_obj.w += 0.03f;
		if (c_obj.w >= 1.0f)
		{
			c_obj.w = 1.0f;
			fade_check = false;
		}
		m_Color = c_obj;
	}
	else {
		c_obj.w -= 0.03f;
		if (c_obj.w <= 0.0f)
		{
			c_obj.w = 0.0f;
			fade_check = true;
		}
		m_Color = c_obj;
	}
}



/**
 * @brief �X�V
*/
void IOnomatopoeia::Update(void)
{
	// �͂��������Ă���ꍇ�A���̕����֐i�ނ悤�ɂ���(�����Ƃ��͓��ɂȂ�)
	this->GameObject::Update();
}
