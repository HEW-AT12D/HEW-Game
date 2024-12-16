#include "../../Game/Core/Application/Application.h"
//-------main.hの参照周りでおかしくなりそうな気がするので注意

int main(void) {
#if defined(DEBUG) || defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif//defined(DEBUG) || defined(_DEBUG)

    // アプリケーション実行
    Application app;
    app.Run();

    return 0;
}
