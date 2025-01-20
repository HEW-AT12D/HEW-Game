#pragma once
#include "../Onomatopeia/IOnomatopoeia/IOnomatopoeia.h"


/**
 * @brief ポヨン（飛び跳ねる）
 *
 * 付与されたオブジェクトの弾力を高める
 * →velocityを高める
 * 　→当たったら跳ね返す
*/
class Poyon : public IOnomatopoeia
{
public:
	Poyon(D3D11 _D3d11) :IOnomatopoeia(_D3d11) {

	}
	~Poyon();

private:

};


Poyon::~Poyon()
{
}
