#include "GameObject.h"

/**
 * @brief �R���X�g���N�^
 * @param _D3d11 D3D�N���X�̎Q��
*/
GameObject::GameObject(D3D11& _D3d11) :D3d11(_D3d11)
{
	// std::vector���g�����߃R���X�g���N�^�ŏ�����
	vertices = {
		//   x     y    z       r    g    b    a     u    v
		{ -0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},	// 0�Ԗڂ̒��_���W
		{ 0.5f,  0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 1.0f,0.0f },		// 1�Ԗڂ̒��_���W
		{ -0.5f, -0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 0.0f,1.0f },		// 2�Ԗڂ̒��_���W
		{ 0.5f, -0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 1.0f,1.0f },		// 3�Ԗڂ̒��_���W
	};
}

GameObject::~GameObject()
{

}

void GameObject::Init(const wchar_t* imgname, bool _animation = false, int sx, int sy)
{
	// �A�j���[�V�����L����ݒ�
	IsAnimation = _animation;

	//UV���W��ݒ�
	m_Split.x = static_cast<float>(sx);
	m_Split.y = static_cast<float>(sy);
	vertices[1].u = 1.0f / m_Split.x;
	vertices[2].v = 1.0f / m_Split.y;
	vertices[3].u = 1.0f / m_Split.x;
	vertices[3].v = 1.0f / m_Split.y;

	// ���_�o�b�t�@���쐬����
	// �����_�o�b�t�@��VRAM�ɒ��_�f�[�^��u�����߂̋@�\
	D3D11_BUFFER_DESC bufferDesc;
	//bufferDesc.ByteWidth = sizeof(vertices);	// �m�ۂ���o�b�t�@�T�C�Y���w��ivector�Ȃ̂Œ��Ӂj
	bufferDesc.ByteWidth = static_cast<UINT>(vertices.size() * sizeof(Vertex));
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;// ���_�o�b�t�@�쐬���w��
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA subResourceData;
	subResourceData.pSysMem = vertices.data();	// VRAM�ɑ���f�[�^���w��ivector�Ȃ̂Œ��Ӂj
	subResourceData.SysMemPitch = 0;
	subResourceData.SysMemSlicePitch = 0;

	HRESULT hr = D3d11.GetDevice()->CreateBuffer(&bufferDesc, &subResourceData, &m_pVertexBuffer);

	// �e�N�X�`���ǂݍ���
//	hr = DirectX::CreateWICTextureFromFile(Device, imgname, NULL, &m_pTextureView);
	hr = DirectX::CreateWICTextureFromFileEx(D3d11.GetDevice(), D3d11.GetDeviceContext(), imgname, 0, D3D11_USAGE_DEFAULT,
		D3D11_BIND_SHADER_RESOURCE, 0, 0, DirectX::WIC_LOADER_IGNORE_SRGB, nullptr, &m_pTextureView);
	if (FAILED(hr))
	{
		MessageBoxA(NULL, "�e�N�X�`���ǂݍ��ݎ��s", "�G���[", MB_ICONERROR | MB_OK);
		return;
	}
}


/**
 * @brief �I�u�W�F�N�g�̍X�V 
*/
void GameObject::Update(void)
{

}


void GameObject::Draw(void)
{
	//���_�o�b�t�@��ݒ�
	UINT strides = sizeof(Vertex);
	UINT offsets = 0;
	D3d11.GetDeviceContext()->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &strides, &offsets);

	// �e�N�X�`�����s�N�Z���V�F�[�_�[�ɓn��
	D3d11.GetDeviceContext()->PSSetShaderResources(0, 1, &m_pTextureView);

	//�萔�o�b�t�@���X�V
	ConstBuffer cb;

	// �v���W�F�N�V�����ϊ��s����쐬
	cb.matrixProj = DirectX::XMMatrixOrthographicLH( SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 3.0f);
	cb.matrixProj = DirectX::XMMatrixTranspose(cb.matrixProj);

	// ���[���h�ϊ��s��̍쐬
	// ���I�u�W�F�N�g�̈ʒu�E�傫���E�������w��
	cb.matrixWorld = DirectX::XMMatrixScaling(transform.GetScale().x, transform.GetScale().y, transform.GetScale().z);
	cb.matrixWorld *= DirectX::XMMatrixRotationZ(transform.GetRotation().z * 3.14f / 180);
	cb.matrixWorld *= DirectX::XMMatrixTranslation(transform.GetPosition().x, transform.GetPosition().y, transform.GetPosition().z);
	cb.matrixWorld = DirectX::XMMatrixTranspose(cb.matrixWorld);

	// UV�A�j���[�V�����̍s��쐬
	float u = (float)m_Number.x / m_Split.x;
	float v = (float)m_Number.y / m_Split.y;
	cb.matrixTex = DirectX::XMMatrixTranslation(u, v, 0.0f);
	cb.matrixTex = DirectX::XMMatrixTranspose(cb.matrixTex);

	//���_�J���[�̃f�[�^���쐬
	cb.color = color;

	// �s����V�F�[�_�[�ɓn��
	D3d11.GetDeviceContext()->UpdateSubresource(D3d11.GetConstantBuffer(), 0, NULL, &cb, 0, 0);

	D3d11.GetDeviceContext()->Draw(4, 0); // �`�施��
}

void GameObject::Uninit()
{
	//�J������
	SAFE_RELEASE(m_pVertexBuffer);
	SAFE_RELEASE(m_pTextureView);
}

void GameObject::SetPosition(Vector3 _Pos) 
{
	//���W���Z�b�g����
	transform.SetPosition(_Pos);
}

void GameObject::SetScale(Vector3 _Size) 
{
	//�傫�����Z�b�g����
	transform.SetScale(_Size);
}

void GameObject::SetRotation(Vector3 _Rot) 
{
	//�p�x���Z�b�g����
	transform.SetRotation(_Rot);
}

void GameObject::SetColor(Vector4 _Color)
{
	//�F���Z�b�g����
	color.x = _Color.x;
	color.y = _Color.y;
	color.z = _Color.z;
	color.w = _Color.w;
}

void GameObject::SetUV(Vector2 _UV)
{
	m_Number.x = _UV.x;
	m_Number.y = _UV.y;
}

/**
 * @brief �A�j���[�V�����J�ڊ֐�
 * �����ł͒ʏ�̃A�j���[�V�����݂̂��`���A�e�h���N���X�Ŋe�X�̃A�j���[�V�����������`����
*/
void GameObject::Animation(void)
{
	// �ʏ�A�j���[�V�����̂�
	if (IsAnimation)
	{
		// �����ɃA�j���[�V�����J�ڏ���������
		switch (m_State)
		{
		case Run:
			// ��j���݂̉摜�ԍ� % �A�j���[�V���������� = 0�@�i�摜�ԍ����Ō�܂ōs�������A�j���[�V�����̐܂�Ԃ��j�̏ꍇ
			// �摜�ԍ���1�����炵�Ă����A�Ƃ��̏��������悳����
			break;
		case Jump:
			break;
		default:
			break;
		}
	}
	else {
		// �A�j���[�V�������Ȃ��ݒ�̏ꍇ�͊֐��I��
		return;
	}
	/*m_Number.x = _UV.x;
	m_Number.y = _UV.y;

	switch (m_State)
	{
	case Run:
		break;
	case Jump:
		break;
	default:
		break;
	}
	switch (m_State)
	{
	case Run:
		if (m_Number.x == 1)
		{
			m_Number.x = 0;
		}
		else {
			m_Number.x += 1;
		}
		break;
	case Jump:

		break;
	default:
		break;
	}*/
}

Vector3 GameObject::GetPosition(void)
{
	//���W���Q�b�g
	return transform.GetPosition();
}
  
Vector3 GameObject::GetScale(void)
{
	//�傫�����Q�b�g
	return transform.GetScale();
}

Vector3 GameObject::GetRotation(void)
{
	//�p�x���Q�b�g
	return transform.GetRotation();
}

Vector4 GameObject::GetColor(void)
{
	//�F���Q�b�g
	return color;
}

Vector2 GameObject::GetUV(void)
{
	//UV���W���Q�b�g
	return m_Number;
}
            
