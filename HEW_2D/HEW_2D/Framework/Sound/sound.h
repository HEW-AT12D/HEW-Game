#pragma once

#include <xaudio2.h>

// �T�E���h�t�@�C��
typedef enum
{
	BGM_STAGESELECT,	// �X�e�[�W�I��BGM
	BGM_GAMECLEAR,		// �Q�[���N���A�V�[��BGM
	BGM_INGAME,			// �C���Q�[��BGM
	BGM_GAMEOVER,		// �Q�[���I�[�o�[BGM
	BGM_TITLE,			// �^�C�g���V�[��BGM
	SE_BIRIBIRI,		// �r���r��SE
	SE_CLICK,			// �N���b�NSE
	SE_DOON,			// �h�H��SE
	SE_GETMAGAZINE,		// �}�K�W���擾SE
	SE_PATAPATA,		// �p�^�p�^SE
	SE_SHOT,			// �[������SE
	SE_POYON,			// �|����SE
	SE_SUCTION,			// �z������SE



	SOUND_LABEL_MAX,
} SOUND_LABEL;

// �p�����[�^�\����
typedef struct
{
	LPCSTR filename;	// �����t�@�C���܂ł̃p�X��ݒ�
	bool bLoop;			// true�Ń��[�v�B�ʏ�BGM��ture�ASE��false�B
	//bool SandW;			//! ���̋���̐؂�ւ����K�v�ȃT�E���h�𔻒�
	//float volume;		//! ���̑傫���i1.0f���m�[�}��)
} PARAM;		//PARAM�^�\����


/**
 * @brief �T�E���h�}�l�[�W���̂悤�ȏ��
 * 
 * ����͎��Ԃ��Ȃ��̂ŃV���O���g���őS���̃f�[�^�����ĊǗ�����
*/
class Sound {

private:

	PARAM m_param[SOUND_LABEL_MAX] =
	{
		{"Game/Asset/Sound/BGM/StageSelectSceneBGM.wav", true},	// �X�e�[�W�I��BGM�i���[�v������̂�true�ݒ�j
		{"Game/Asset/Sound/BGM/ClearSceneBGM.wav", true},		// �Q�[���N���A�V�[��BGM
		{"Game/Asset/Sound/BGM/GameBGM.wav", true},  			// �C���Q�[��BGM
		{"Game/Asset/Sound/BGM/GameOverSceneBGM.wav", true},	// �Q�[���I�[�o�[�V�[��BGM
		{"Game/Asset/Sound/BGM/TitleSceneBGM.wav", true},		// �^�C�g���V�[��BGM
		{"Game/Asset/Sound/SE/BiriBiri.wav", false},			// �u�r���r���vSE�i���[�v���Ȃ��̂�false�ݒ�j
		{"Game/Asset/Sound/SE/Click.wav", false},				// �N���b�NSE�i���[�v���Ȃ��̂�false�ݒ�j
		{"Game/Asset/Sound/SE/Doon.wav", false},				// �u�r���r���vSE�i���[�v���Ȃ��̂�false�ݒ�j
		{"Game/Asset/Sound/SE/Magazine.wav", false},			// �}�K�W���擾SE�i���[�v���Ȃ��̂�false�ݒ�j
		{"Game/Asset/Sound/SE/PataPata.wav", false},			// �u�p�^�p�^�vSE�i���[�v���Ȃ��̂�false�ݒ�j
		{"Game/Asset/Sound/SE/Shot.wav", false},				// �[������SE�i���[�v���Ȃ��̂�false�ݒ�j		
		{"Game/Asset/Sound/SE/Slime_Poyon.wav", false},			// �u�|�����vSE�i���[�v���Ȃ��̂�false�ݒ�j
		{"Game/Asset/Sound/SE/Suction.wav", false},				// �z������SE�i���[�v���Ȃ��̂�false�ݒ�j


	};

	IXAudio2* m_pXAudio2 = NULL;
	IXAudio2MasteringVoice* m_pMasteringVoice = NULL;
	IXAudio2SourceVoice* m_pSourceVoice[SOUND_LABEL_MAX];
	WAVEFORMATEXTENSIBLE m_wfx[SOUND_LABEL_MAX]; // WAV�t�H�[�}�b�g
	XAUDIO2_BUFFER m_buffer[SOUND_LABEL_MAX];
	BYTE* m_DataBuffer[SOUND_LABEL_MAX];

	HRESULT FindChunk(HANDLE, DWORD, DWORD&, DWORD&);
	HRESULT ReadChunkData(HANDLE, void*, DWORD, DWORD);

	int Distance = 0;	//�v���C���[�ƃI�u�W�F�N�g�̋��������炤�ϐ�



public:
	// �Q�[�����[�v�J�n�O�ɌĂяo���T�E���h�̏���������
	HRESULT Init(void);

	// �Q�[�����[�v�I����ɌĂяo���T�E���h�̉������
	void Uninit(void);

	// �����Ŏw�肵���T�E���h���Đ�����
	void Play(SOUND_LABEL label);		//enum�Ō��߂��f�[�^�ň����Ƃ��ēn���Ă���

	// �����Ŏw�肵���T�E���h���~����
	void Stop(SOUND_LABEL label);

	//! �����Ŏw�肵���T�E���h�̉��ʂ�ύX����	//�ォ��ǉ��i�o���j
	void ChangeVolume(SOUND_LABEL label,int );

	// �����Ŏw�肵���T�E���h�̍Đ����ĊJ����
	void Resume(SOUND_LABEL label);

	//volume�ϐ��̃Z�b�^�[�E�Q�b�^�[�֐��i���ʒ����̂��߁j
	int SetDistance(int);
	int GetDistance(void);


	static Sound& GetInstance(void);



	/*===�T�E���h�t���[�����[�N�݌v===*/

	/*
	���̒�~
	���̍Đ�
	���̃��[�v
	�V�[�����Ƃł̉��y�̐؂�ւ�(�����Ⴄ����)
	���̋���i�Q�[���V�X�e�����ʊO�Ȃ珬�����Ȃǁj���ꂪ��Ԗ��H
	*/
};