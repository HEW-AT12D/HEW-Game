#include "../../Game/Core/Application/Application.h"
//-------main.h�̎Q�Ǝ���ł��������Ȃ肻���ȋC������̂Œ���

int main(void) {
#if defined(DEBUG) || defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif//defined(DEBUG) || defined(_DEBUG)

    // �A�v���P�[�V�������s
    Application app;
    app.Run();

    return 0;
}
