#include "../../Game/Core/Application/Application.h"

/**-------------------------------------
 * @brief �G���g���[�|�C���g
 * -------------------------------------
*/
int main(void) {
#if defined(DEBUG) || defined(_DEBUG)
    // ���������[�N�����ꍇ�A���̏ڍׂ�\�����Ă����
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif//defined(DEBUG) || defined(_DEBUG)
    //_CrtSetBreakAlloc(2407);
    Application app;
    // �A�v��������
    app.Init();

    // �A�v���P�[�V�������s
    app.Run();

    return 0;
}
