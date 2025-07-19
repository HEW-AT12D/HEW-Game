#include "../../Game/EntryPoint/main.h"
#include "input.h"

//�R���X�g���N�^
Input::Input()
{
	VibrationTime = 0;
}

//�f�X�g���N�^
Input::~Input()
{
	//�U�����I��������
	XINPUT_VIBRATION vibration;
	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
	vibration.wLeftMotorSpeed = 0;
	vibration.wRightMotorSpeed = 0;
	XInputSetState(0, &vibration);
}

/**
 * @brief �C���X�^���X�擾�֐�
 * @return ���g�̃C���X�^���X
*/
Input& Input::GetInstance(void)
{
	// ����Ăяo�����Ɏ��g�̃C���X�^���X�𐶐�
	static Input Instance;
	return Instance;
}

void Input::Update()
{
	//1�t���[���O�̓��͂��L�^���Ă���
	for (int i = 0; i < 256; i++) { keyState_old[i] = keyState[i]; }
	controllerState_old = controllerState;

	//�L�[���͂��X�V
	BOOL hr = GetKeyboardState(keyState);

	//�R���g���[���[���͂��X�V(XInput)
	XInputGetState(0, &controllerState);

	// ���g���K�[��Ԃ��X�V
	m_PrevLeftTrigger = m_LeftTrigger;
	m_LeftTrigger = controllerState.Gamepad.bLeftTrigger;

	//�U���p�����Ԃ��J�E���g
	if (VibrationTime > 0) {
		VibrationTime--;
		if (VibrationTime == 0) { //�U���p�����Ԃ��o�������ɐU�����~�߂�
			XINPUT_VIBRATION vibration;
			ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
			vibration.wLeftMotorSpeed = 0;
			vibration.wRightMotorSpeed = 0;
			XInputSetState(0, &vibration);
		}
	}
}

//�L�[����
bool Input::GetKeyPress(int key) //�v���X
{
	return keyState[key] & 0x80;
}
bool Input::GetKeyTrigger(int key) //�g���K�[
{
	return (keyState[key] & 0x80) && !(keyState_old[key] & 0x80);
}
bool Input::GetKeyRelease(int key) //�����[�X
{
	return !(keyState[key] & 0x80) && (keyState_old[key] & 0x80);
}

//���A�i���O�X�e�B�b�N
DirectX::XMFLOAT2 Input::GetLeftAnalogStick(void)
{
	SHORT x = controllerState.Gamepad.sThumbLX; // -32768�`32767
	SHORT y = controllerState.Gamepad.sThumbLY; // -32768�`32767

	DirectX::XMFLOAT2 res;
	res.x = x / 32767.0f; //-1�`1
	res.y = y / 32767.0f; //-1�`1
	return res;
}
//�E�A�i���O�X�e�B�b�N
DirectX::XMFLOAT2 Input::GetRightAnalogStick(void)
{
	SHORT x = controllerState.Gamepad.sThumbRX; // -32768�`32767
	SHORT y = controllerState.Gamepad.sThumbRY; // -32768�`32767

	DirectX::XMFLOAT2 res;
	res.x = x / 32767.0f; //-1�`1
	res.y = y / 32767.0f; //-1�`1
	return res;
}

// ���g���K�[
float Input::GetLeftTrigger(void)
{
	BYTE t = controllerState.Gamepad.bLeftTrigger; // 0�`255
	return t / 255.0f;
}
bool Input::GetLeftTriggerPress() {
	return m_LeftTrigger > TRIGGER_THRESHOLD;
}
bool Input::GetLeftTriggerTrigger() {
	return (m_LeftTrigger > TRIGGER_THRESHOLD) && (m_PrevLeftTrigger <= TRIGGER_THRESHOLD);
}
bool Input::GetLeftTriggerRelease() {
	return (m_LeftTrigger <= TRIGGER_THRESHOLD) && (m_PrevLeftTrigger > TRIGGER_THRESHOLD);
}

// �E�g���K�[
float Input::GetRightTrigger(void)
{
	BYTE t = controllerState.Gamepad.bRightTrigger; // 0�`255
	return t / 255.0f;
}

//�{�^������
bool Input::GetButtonPress(WORD btn) //�v���X
{
	return (controllerState.Gamepad.wButtons & btn) != 0;
}
bool Input::GetButtonTrigger(WORD btn) //�g���K�[
{
	return (controllerState.Gamepad.wButtons & btn) != 0 && (controllerState_old.Gamepad.wButtons & btn) == 0;
}
bool Input::GetButtonRelease(WORD btn) //�����[�X
{
	return (controllerState.Gamepad.wButtons & btn) == 0 && (controllerState_old.Gamepad.wButtons & btn) != 0;
}

//�U��
void Input::SetVibration(int frame, float powor)
{
	// XINPUT_VIBRATION�\���̂̃C���X�^���X���쐬
	XINPUT_VIBRATION vibration;
	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));

	// ���[�^�[�̋��x��ݒ�i0�`65535�j
	vibration.wLeftMotorSpeed = (WORD)(powor * 65535.0f);
	vibration.wRightMotorSpeed = (WORD)(powor * 65535.0f);
	XInputSetState(0, &vibration);

	//�U���p�����Ԃ���
	VibrationTime = frame;
}

//!  ZR��ZL�̓��͔���
bool Input::IzZLPressed()
{
	return controllerState.Gamepad.bLeftTrigger > TRIGGER_THRESHOLD;	//!�@ZL�����ȏ㉟�����܂ꂽ��
}

bool Input::IzZRPressed()
{
	return controllerState.Gamepad.bRightTrigger > TRIGGER_THRESHOLD;	//!�@ZL�����ȏ㉟�����܂ꂽ��
}