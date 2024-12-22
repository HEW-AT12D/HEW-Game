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
	//HWND hWnd;						// ウィンドウハンドル代入用変数
	//Window::GetInstance().Init();	// ウィンドウ初期化
	//hWnd = Window::GetInstance().GetHandleWindow();		// ウィンドウハンドル取得
	//d3d11.Init(hWnd);				// ウィンドウ情報を使ってDirectXを初期化
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
	//! MSG：ウィンドウのイベントを識別するメッセージを保持するための構造体
	MSG msg = {};

	// FPS計測用変数
	int fpsCounter = 0;
	long long oldTick = GetTickCount64(); // 前回計測時の時間
	long long nowTick = oldTick; // 今回計測時の時間

	// FPS固定用変数
	LARGE_INTEGER liWork; // workがつく変数は作業用変数
	long long frequency;// どれくらい細かく時間をカウントできるか
	QueryPerformanceFrequency(&liWork);
	frequency = liWork.QuadPart;
	// 時間（単位：カウント）取得
	QueryPerformanceCounter(&liWork);
	long long oldCount = liWork.QuadPart;// 前回計測時の時間
	long long nowCount = oldCount;// 今回計測時の時間
	// ゲームループ
	while (1)
	{
		// 新たにメッセージがあれば
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// ウィンドウプロシージャにメッセージを送る
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			// 「WM_QUIT」メッセージを受け取ったらループを抜ける
			if (msg.message == WM_QUIT) {
				break;
			}
		}
		else
		{
			QueryPerformanceCounter(&liWork);// 現在時間を取得
			nowCount = liWork.QuadPart;
			// 1/60秒が経過したか？
			if (nowCount >= oldCount + frequency / 60) {



				//! ゲーム処理
				game.Update();

				//// カメラ更新
				//camera.Update();

				//// 入力処理更新
				//input.Update();

				//// テストプレーン更新
				////plane.Update();
				////cube.Update();
				////model.Update();
				////ball.Update();
				//
				//// オブジェクト更新
				//for (auto& o : Objects) {
				//	o->Update();
				//}

				//// 描画前処理
				//Renderer::Begin();

				//! 描画
				game.Draw();

				//// カメラセット
				//camera.Draw();

				//// テストプレーン描画
				//
				////plane.Draw();
				////cube.Draw();
				////model.Draw();
				////ball.Draw();

				//// オブジェクト描画
				//for (auto& o : Objects) {
				//	o->Draw();
				//}

				//// 描画後処理
				//Renderer::End();


				fpsCounter++; // ゲーム処理を実行したら＋１する
				oldCount = nowCount;
			}


		}
	}

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
