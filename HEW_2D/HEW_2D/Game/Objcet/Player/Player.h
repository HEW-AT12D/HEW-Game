#pragma once
#include "../SoundGun/SoundGun.h"
#include "../Character/Character.h"
#include "../SoundGun/Magazine.h"
#include "../SoundGun/CrossHair.h"

/**
 * @brief �v���C���[�N���X
 * 
 * ���K�v�Ȃ��́�
 * �E�ړ����x
 * �E�W�����v��
 * �E�����蔻��
 * 
 * ���̓�̓v���C���[�̃����o�Ƃ��Ď�������̂ł͂Ȃ��A�V�[�����ŃI�u�W�F�N�g�}�l�[�W������AddObject���s���A��������e�I�u�W�F�N�g�Ƃ��ăv���C���[���Z�b�g����
 * �E�[���e
 * �E�}�K�W��
 * 
 * �}�K�W�����������摜�o�����ȍ~�͋[���������Ă��Ȃ��Ă��摜��������p�ɂ���
 * 
 * �A�j���[�V�������F�L�������ƂɃX�e�[�g�i��ԁj���������Ă����A���̏�Ԃɉ������A�j���[�V�����𓮂���
 * 
 * �A�j���[�V����
 * �A�N�V�������s���̏ꍇ���t���[���X�v���C�g�؂�ւ�����
 * ���{�^�������Ă鎞�̓A�N�V������
 * 
 * 
 * �}�K�W���������A�v���C���[�̕`��őS�ĕ`�悷��΂����͂��I�I
 * ���摜(�V�F�[�_�[���\�[�X�r���[�Ƃ��H)��z��ɂ���ׂ����H
 * 
*/
class Magazine;

class Player :public Character
{
public:
	Player(D3D11& _D3d11, Sound* _sound = nullptr) :Character(_D3d11, _sound) {
		m_Velocity = { 0.0f };
		m_MoveSpeed = 5.0f;
		m_JumpPower = 10.5f; //7.5
		IsShot = false;
		IsSuction = false;
		m_Soundgun = nullptr;
		//m_Magazines.clear();
		UsingMagIdx = 1;		// 0�Ԗڂ̃}�K�W���̓h�H����p�Ȃ̂�1�Ԗڂ���X�^�[�g
		BombCount = 0;
	};

	/**
	 * @brief �f�X�g���N�^
	*/
	~Player() {
		Uninit();
	};
	
	void Update(void) override;		// �v���C���[�ŗL�̓��͂͂����Ŏ擾����
	void Draw(void) override;		// �[���g�p�ŕ`����@�ύX���������ꍇ�p�ɐ錾
	void Uninit(void) override;		// ���

	void Animation(ANIMATIONSTATE _Anim_Name);	// �v���C���[�ʂ̃A�j���[�V�����֐�

	void SetChild(GameObject* _child) override;

	void UpdateMove(void);			// �v���C���[�̈ړ��X�V�֐�
	void UpdateCrossHair(void);		// �N���X�w�A�̍X�V�֐�
	void UpdateCurrentMag(void);	// ���ݎg�p���̃}�K�W�����Z�b�g

	std::pair<std::pair<Tag, std::string>, IOnomatopoeia*> StartSuction(std::vector<std::pair<std::pair<Tag, std::string>, IOnomatopoeia*>> _onomatopoeias);
	bool Suction(std::pair<std::pair<Tag, std::string>, IOnomatopoeia*>);	// �z�����݊֐�(�߂�l�ŋz�����ݏ������I���������𔻒�)
	void Shot(void);		// �[���̔��ˊ֐�

	void SetIsShot(bool _flg);
	bool GetIsShot(void);
	void SetIsSuction(bool _flg);
	bool GetIsSuction(void);
	void SetMagCursor(GameObject* _mag);	// �}�K�W���̃J�[�\�����Z�b�g

	// ���Ƃ��Ƃ��Ă���(�I������Ă���}�K�W�����ɂ���)�[���̏���n���֐�
	IOnomatopoeia* GetLoadedBullet(void);

	// �}�K�W�����ׂĂ��擾����֐�
	std::vector<Magazine*>& GetMagazines(void);
	// �e�ɑ��U����Ă���}�K�W����Ԃ��֐�
	Magazine* GetUsingMag(void);

	int GetMagIdx(void);
	void SetMagIdx(int _num);

	// �}�K�W������Ԃ�
	size_t GetMagCount(void);

private:
	std::vector<Magazine*> m_Magazines;	// �}�K�W���i�ϒ��j,0�Ԗڂ̓h�H����p�ɂ��āA���̌�̓J�E���g�𑝂₵�ăh�H�����Ǘ�����]
	int UsingMagIdx;	// �}�K�W���̉��Ԗڂ��g��(���U����)��
	bool IsSuction;		// �z�����ݒ����H
	bool IsShot;		// ���˒����H
	bool isFacingLeft = false;	// ���������H
	int BombCount;		// �h�H���̃J�E���g
	// �[���e(�z�����ޗ����摜���������邽�߂Ɏg�����V�F�[�_�[���\�[�X�r���[�Ƃ���z��ɂ���Ή摜�͕����ǂݍ��߂�����)
	SoundGun* m_Soundgun;			// �[���e
	CrossHair* m_pCrossHair;		// �N���X�w�A
	GameObject* m_pMagCursor = nullptr;	// �}�K�W���J�[�\��
};

