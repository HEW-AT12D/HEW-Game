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
	Player(D3D11& _D3d11) :Character(_D3d11) {
		m_Velocity = { 0.0f };
		m_MoveSpeed = 5.0f;
		m_JumpPower = 10.5f; //7.5
		IsShot = false;
		IsSuction = false;
		m_Soundgun = nullptr;
		m_Magazines.clear();
		UseMagNumber = 1;		// 0�Ԗڂ̃}�K�W���̓h�H����p�Ȃ̂�1�Ԗڂ���X�^�[�g
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

	void Animation(STATE _Anim_Name);	// �v���C���[�ʂ̃A�j���[�V�����֐�

	void SetChild(const std::shared_ptr<GameObject> _child) override;

	// �}�K�W�����擾�����Ƃ��ɁAUI�Ƃ��ĕ\��������W��ݒ肵���������Ɏ擾����UI�Ƃ��ĕ\������Ă���}�K�W���̍��W���ɔz�u���遨�}�K�W���̍��W���~����
	//void SetMagazine(std::shared_ptr<Magazine> _mag);

	// TODO:2025/01/27 �[���e�N���X�ŋz�����݊֐��쐬���v���C���[�̋z�����݂ł͂�������s���A���̊֐��̖߂�l�ŋz�����񂾋[����Ԃ��A�}�K�W���ɃZ�b�g����΍s����͂�
	
	// TODO:2025/01/28 �ړ����Ȃ���z�����񂾂炤�܂��z�����܂�Ȃ��o�O�𒼂��B�f����������������������
	bool Suction(std::weak_ptr<GameObject>);	// �z�����݊֐�(�߂�l�ŋz�����ݏ������I���������𔻒�)
	void Shot(void);		// �[���̔��ˊ֐�

	void SetIsShot(bool _flg);
	bool GetIsShot(void);
	void SetIsSuction(bool _flg);
	bool GetIsSuction(void);

	// ���Ƃ��Ƃ��Ă���(�I������Ă���}�K�W�����ɂ���)�[���̏���n���֐�
	IOnomatopoeia* GetLoadedBullet(void);

	// �e�ɑ��U����Ă���}�K�W����Ԃ��֐�
	std::shared_ptr<Magazine> GetUsingMag(void);

	int GetMagNumber(void);
	void SetMagNumber(int _num);

	// �}�K�W������Ԃ�
	size_t GetMagCount(void);

private:
	bool IsSuction;		// �z�����ݒ����H
	bool IsShot;		// ���˒����H
	int UseMagNumber;	// �}�K�W���̉��Ԗڂ��g��(���U����)��
	int BombCount;		// �h�H���̃J�E���g
	// �[���e(�z�����ޗ����摜���������邽�߂Ɏg�����V�F�[�_�[���\�[�X�r���[�Ƃ���z��ɂ���Ή摜�͕����ǂݍ��߂�����)
	std::shared_ptr<SoundGun> m_Soundgun;		// �[���e
	std::vector<std::shared_ptr<Magazine>> m_Magazines;	// �}�K�W���i�ϒ��j,0�Ԗڂ̓h�H����p�ɂ��āA���̌�̓J�E���g�𑝂₵�ăh�H�����Ǘ�����H
	std::shared_ptr<CrossHair> m_CrossHair;		// �N���X�w�A
};

