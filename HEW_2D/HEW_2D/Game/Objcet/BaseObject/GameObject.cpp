#include "GameObject.h"

/**
 * @brief コンストラクタ
 * @param _D3d11 D3Dクラスの参照
*/
GameObject::GameObject(D3D11& _D3d11) :D3d11(_D3d11)
{
	// std::vectorを使うためコンストラクタで初期化
	vertices = {
		//   x     y    z       r    g    b    a     u    v
		{ -0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f},	// 0番目の頂点座標
		{ 0.5f,  0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 1.0f,0.0f },		// 1番目の頂点座標
		{ -0.5f, -0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 0.0f,1.0f },		// 2番目の頂点座標
		{ 0.5f, -0.5f, 0.5f, 1.0f,1.0f,1.0f,1.0f, 1.0f,1.0f },		// 3番目の頂点座標
	};
}

GameObject::~GameObject()
{

}

void GameObject::Init(const wchar_t* imgname, bool _animation = false, int sx, int sy)
{
	// アニメーション有無を設定
	IsAnimation = _animation;

	//UV座標を設定
	m_Split.x = static_cast<float>(sx);
	m_Split.y = static_cast<float>(sy);
	vertices[1].u = 1.0f / m_Split.x;
	vertices[2].v = 1.0f / m_Split.y;
	vertices[3].u = 1.0f / m_Split.x;
	vertices[3].v = 1.0f / m_Split.y;

	// 頂点バッファを作成する
	// ※頂点バッファ→VRAMに頂点データを置くための機能
	D3D11_BUFFER_DESC bufferDesc;
	//bufferDesc.ByteWidth = sizeof(vertices);	// 確保するバッファサイズを指定（vectorなので注意）
	bufferDesc.ByteWidth = static_cast<UINT>(vertices.size() * sizeof(Vertex));
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;// 頂点バッファ作成を指定
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA subResourceData;
	subResourceData.pSysMem = vertices.data();	// VRAMに送るデータを指定（vectorなので注意）
	subResourceData.SysMemPitch = 0;
	subResourceData.SysMemSlicePitch = 0;

	HRESULT hr = D3d11.GetDevice()->CreateBuffer(&bufferDesc, &subResourceData, &m_pVertexBuffer);

	// テクスチャ読み込み
//	hr = DirectX::CreateWICTextureFromFile(Device, imgname, NULL, &m_pTextureView);
	hr = DirectX::CreateWICTextureFromFileEx(D3d11.GetDevice(), D3d11.GetDeviceContext(), imgname, 0, D3D11_USAGE_DEFAULT,
		D3D11_BIND_SHADER_RESOURCE, 0, 0, DirectX::WIC_LOADER_IGNORE_SRGB, nullptr, &m_pTextureView);
	if (FAILED(hr))
	{
		MessageBoxA(NULL, "テクスチャ読み込み失敗", "エラー", MB_ICONERROR | MB_OK);
		return;
	}
}


/**
 * @brief オブジェクトの更新 
*/
void GameObject::Update(void)
{

}


void GameObject::Draw(void)
{
	//頂点バッファを設定
	UINT strides = sizeof(Vertex);
	UINT offsets = 0;
	D3d11.GetDeviceContext()->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &strides, &offsets);

	// テクスチャをピクセルシェーダーに渡す
	D3d11.GetDeviceContext()->PSSetShaderResources(0, 1, &m_pTextureView);

	//定数バッファを更新
	ConstBuffer cb;

	// プロジェクション変換行列を作成
	cb.matrixProj = DirectX::XMMatrixOrthographicLH( SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 3.0f);
	cb.matrixProj = DirectX::XMMatrixTranspose(cb.matrixProj);

	// ワールド変換行列の作成
	// →オブジェクトの位置・大きさ・向きを指定
	cb.matrixWorld = DirectX::XMMatrixScaling(transform.GetScale().x, transform.GetScale().y, transform.GetScale().z);
	cb.matrixWorld *= DirectX::XMMatrixRotationZ(transform.GetRotation().z * 3.14f / 180);
	cb.matrixWorld *= DirectX::XMMatrixTranslation(transform.GetPosition().x, transform.GetPosition().y, transform.GetPosition().z);
	cb.matrixWorld = DirectX::XMMatrixTranspose(cb.matrixWorld);

	// UVアニメーションの行列作成
	float u = (float)m_Number.x / m_Split.x;
	float v = (float)m_Number.y / m_Split.y;
	cb.matrixTex = DirectX::XMMatrixTranslation(u, v, 0.0f);
	cb.matrixTex = DirectX::XMMatrixTranspose(cb.matrixTex);

	//頂点カラーのデータを作成
	cb.color = color;

	// 行列をシェーダーに渡す
	D3d11.GetDeviceContext()->UpdateSubresource(D3d11.GetConstantBuffer(), 0, NULL, &cb, 0, 0);

	D3d11.GetDeviceContext()->Draw(4, 0); // 描画命令
}

void GameObject::Uninit()
{
	//開放処理
	SAFE_RELEASE(m_pVertexBuffer);
	SAFE_RELEASE(m_pTextureView);
}

void GameObject::SetPosition(Vector3 _Pos) 
{
	//座標をセットする
	transform.SetPosition(_Pos);
}

void GameObject::SetScale(Vector3 _Size) 
{
	//大きさをセットする
	transform.SetScale(_Size);
}

void GameObject::SetRotation(Vector3 _Rot) 
{
	//角度をセットする
	transform.SetRotation(_Rot);
}

void GameObject::SetColor(Vector4 _Color)
{
	//色をセットする
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
 * @brief アニメーション遷移関数
 * ここでは通常のアニメーションのみを定義し、各派生クラスで各々のアニメーション処理を定義する
*/
void GameObject::Animation(void)
{
	// 通常アニメーションのみ
	if (IsAnimation)
	{
		// ここにアニメーション遷移処理を書く
		switch (m_State)
		{
		case Run:
			// 例）現在の画像番号 % アニメーション分割数 = 0　（画像番号が最後まで行った→アニメーションの折り返し）の場合
			// 画像番号を1ずつ減らしていく、とかの書き方がよさそう
			break;
		case Jump:
			break;
		default:
			break;
		}
	}
	else {
		// アニメーションしない設定の場合は関数終了
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
	//座標をゲット
	return transform.GetPosition();
}
  
Vector3 GameObject::GetScale(void)
{
	//大きさをゲット
	return transform.GetScale();
}

Vector3 GameObject::GetRotation(void)
{
	//角度をゲット
	return transform.GetRotation();
}

Vector4 GameObject::GetColor(void)
{
	//色をゲット
	return color;
}

Vector2 GameObject::GetUV(void)
{
	//UV座標をゲット
	return m_Number;
}
            
