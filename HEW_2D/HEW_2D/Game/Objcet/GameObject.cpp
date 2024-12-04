#include "GameObject.h"

void GameObject::Init(const wchar_t* imgname, int sx, int sy)
{
	//UV���W��ݒ�
	splitX = sx;
	splitY = sy;
	vertexList[1].u = 1.0f / splitX;
	vertexList[2].v = 1.0f / splitY;
	vertexList[3].u = 1.0f / splitX;
	vertexList[3].v = 1.0f / splitY;

	// ���_�o�b�t�@���쐬����
	// �����_�o�b�t�@��VRAM�ɒ��_�f�[�^��u�����߂̋@�\
	D3D11_BUFFER_DESC bufferDesc;
	bufferDesc.ByteWidth = sizeof(vertexList);// �m�ۂ���o�b�t�@�T�C�Y���w��
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;// ���_�o�b�t�@�쐬���w��
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA subResourceData;
	subResourceData.pSysMem = vertexList;// VRAM�ɑ���f�[�^���w��
	subResourceData.SysMemPitch = 0;
	subResourceData.SysMemSlicePitch = 0;

	HRESULT hr = d3d11->GetDevice()->CreateBuffer(&bufferDesc, &subResourceData, &m_pVertexBuffer);

	// �e�N�X�`���ǂݍ���
//	hr = DirectX::CreateWICTextureFromFile(
	
	
	Device, imgname, NULL, &m_pTextureView);
	hr = DirectX::CreateWICTextureFromFileEx(d3d11->GetDevice(), d3d11->GetDeviceContext(), imgname, 0, D3D11_USAGE_DEFAULT,
		D3D11_BIND_SHADER_RESOURCE, 0, 0, DirectX::WIC_LOADER_IGNORE_SRGB, nullptr, &m_pTextureView);
	if (FAILED(hr))
	{
		MessageBoxA(NULL, "�e�N�X�`���ǂݍ��ݎ��s", "�G���[", MB_ICONERROR | MB_OK);
		return;
	}
}

void GameObject::Draw()
{
	//���_�o�b�t�@��ݒ�
	UINT strides = sizeof(Vertex);
	UINT offsets = 0;
	d3d11->GetDeviceContext()->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &strides, &offsets);

	// �e�N�X�`�����s�N�Z���V�F�[�_�[�ɓn��
	d3d11->GetDeviceContext()->PSSetShaderResources(0, 1, &m_pTextureView);

	//�萔�o�b�t�@���X�V
	ConstBuffer cb;

	// �v���W�F�N�V�����ϊ��s����쐬
	cb.matrixProj = DirectX::XMMatrixOrthographicLH( SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 3.0f);
	cb.matrixProj = DirectX::XMMatrixTranspose(cb.matrixProj);

	// ���[���h�ϊ��s��̍쐬
	// ���I�u�W�F�N�g�̈ʒu�E�傫���E�������w��
	cb.matrixWorld = DirectX::XMMatrixScaling(m_Scale.x, m_Scale.y, m_Scale.z);
	cb.matrixWorld *= DirectX::XMMatrixRotationZ(angle * 3.14f / 180);
	cb.matrixWorld *= DirectX::XMMatrixTranslation(m_Position.x, m_Position.y, m_Position.z);
	cb.matrixWorld = DirectX::XMMatrixTranspose(cb.matrixWorld);

	// UV�A�j���[�V�����̍s��쐬
	float u = (float)numU / splitX;
	float v = (float)numV / splitY;
	cb.matrixTex = DirectX::XMMatrixTranslation(u, v, 0.0f);
	cb.matrixTex = DirectX::XMMatrixTranspose(cb.matrixTex);

	//���_�J���[�̃f�[�^���쐬
	cb.color = color;

	// �s����V�F�[�_�[�ɓn��
	d3d11->GetDeviceContext()->UpdateSubresource(d3d11->GetConststBuffer(), 0, NULL, &cb, 0, 0);

	d3d11->GetDeviceContext()->Draw(4, 0); // �`�施��
}

void GameObject::Uninit()
{
	//�J������
	SAFE_RELEASE(m_pVertexBuffer);
	SAFE_RELEASE(m_pTextureView);
}

void GameObject::SetPos(float x, float y, float z) 
{
	//���W���Z�b�g����
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

void GameObject::SetSize(float x, float y, float z) 
{
	//�傫�����Z�b�g����
	m_Scale.x = x;
	m_Scale.y = y;
	m_Scale.z = z;
}

void GameObject::SetAngle(float a) 
{
	//�p�x���Z�b�g����
	angle = a;
}
void GameObject::SetColor(float r, float g, float b, float a)
{
	//�F���Z�b�g����
	color.x = r;
	color.y = g;
	color.z = b;
	color.w = a;
}

DirectX::XMFLOAT3 GameObject::GetPos(void)
{
	//���W���Q�b�g
	return m_Position;
}
  
DirectX::XMFLOAT3 GameObject::GetSize(void)
{
	//�傫�����Q�b�g
	return m_Scale;
}

float GameObject::GetAngle(void)
{
	//�p�x���Q�b�g
	return angle;
}

DirectX::XMFLOAT4 GameObject::GetColor(void)
{
	//�F���Q�b�g
	return color;
}
            
