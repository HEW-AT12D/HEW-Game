#include"Gravity.h"

const float gravity = 19.6f; // �d�͉����x�i�P��: m/s^2�j
float velocityY = 0.5f;     // ���������̏������x
const float deltaTime = 0.016f; // 1�t���[���̌o�ߎ��ԁi60FPS�z��j

bool isJump = false;//�W�����v�̃t���O

//�d�͉����x�֐�
void Gravity(GameObject* player,Vector3 p_pos)
{
	//�ʒu�̍X�V
	//Vector3 p_pos = player->GetPosition();
	p_pos.y -= 15;
	//p_pos.y -= 5;
	player->SetPosition(p_pos);
	
	

	//�f�o�b�N
	std::cout << "player��Y���W�F" << p_pos.y << ",�������x�F" << velocityY << std::endl;
}

//�W�����v�֐�
void Jump(GameObject* player, Vector3 p_pos)
{
	// �d�͂̓K�p
	velocityY += 150;

	// �ʒu�̍X�V
	p_pos.y += velocityY * deltaTime;
	player->SetPosition(p_pos);

}
