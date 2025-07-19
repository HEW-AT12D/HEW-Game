#include "../../Game/Core/Application/Application.h"

/**-------------------------------------
 * @brief エントリーポイント
 * -------------------------------------
*/
int main(void) {
#if defined(DEBUG) || defined(_DEBUG)
    // メモリリークした場合、その詳細を表示してくれる
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif//defined(DEBUG) || defined(_DEBUG)
    //_CrtSetBreakAlloc(2407);
    Application app;
    // アプリ初期化
    app.Init();

    // アプリケーション実行
    app.Run();

    return 0;
}
