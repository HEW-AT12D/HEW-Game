#include "../../EntryPoint/main.h"
#include "../../../Framework/Input/Input.h"
#include "Application.h"

using namespace SimpleMath;

/**
 * @brief アプリ全体としての初期化処理
 * 
 * ウィンドウ初期化→DirectX初期化→ゲーム初期化
 * の流れで進める
*/
void Application::Init(void)
{
	HWND hWnd;						// ウィンドウハンドル代入用変数
	Window::GetInstance().Init();	// ウィンドウ初期化
	hWnd = Window::GetInstance().GetHandleWindow();		// ウィンドウハンドル取得
	d3d11.Init(hWnd);				// DirectXを初期化
	game.Init();					// ゲーム初期化
	
	//player.Init(L"asset/char01.png", 3, 4);				//プレイヤーを初期化
	//player.SetPosition(Vector3(100.0f, 0.0f, 0.0f));	//位置を設定
	//player.SetScale(Vector3(200.0f, 300.0f, 0.0f));		//大きさを設定
	//player.SetRotation(Vector3(0.0f, 0.0f, 0.0f));		//角度を設定
	//player.SetColor(Vector4(1.0f, 1.0f, 1.0f, 0.5f));	//角度を設定

	//background.Init(L"asset/back_img_01.png");	//背景を初期化
	//background.SetPos(0.0f, 0.0f, 0.0f);		//位置を設定
	//background.SetSize(640.0f, 480.0f, 0.0f);	//大きさを設定
	//background.SetAngle(0.0f);					//角度を設定

}

void Application::Run(void)
{
	// ゲームの初期化（シーンマネージャの初期化）
	game.Init();

	// ゲーム処理開始
	game.Update();

	//Vector3 pos = player.GetPosition();
	//pos.x += 1.0f;

	//if (Input::GetInstance().GetKeyPress(VK_W)) { pos.y += 1.0f; }
	//if (Input::GetInstance().GetKeyPress(VK_A)) { pos.x -= 1.0f; }
	//if (Input::GetInstance().GetKeyPress(VK_S)) { pos.y -= 1.0f; }
	//if (Input::GetInstance().GetKeyPress(VK_D)) { pos.x += 1.0f; }

	//// Iキーでフルスクリーン化
	//if (Input::GetInstance().GetKeyTrigger(VK_I)) {
	//	d3d11.GetSwapChain()->SetFullscreenState(TRUE, NULL);
	//}
	//// Kキーでフルスクリーン解除
	//if (Input::GetInstance().GetKeyTrigger(VK_K)) {
	//	d3d11.GetSwapChain()->SetFullscreenState(FALSE, NULL);
	//}

	//player.SetPos(pos.x, pos.y, pos.z);
}

//void Application::Draw(void)
//{
//	d3d11.StartRender();	// 描画開始
//	background.Draw();		// 背景を描画
//	player.Draw();			// プレイヤーを描画
//	d3d11.FinishRender();	// 描画終了
//}

void Application::Uninit(void)
{
	//player.Uninit();		// プレイヤーを終了
	//background.Uninit();	// プレイヤーを終了
	d3d11.Release();		// DirectXを終了
}
