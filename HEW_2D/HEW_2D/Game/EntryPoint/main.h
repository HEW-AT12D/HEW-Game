#pragma once

#pragma warning(push)
#pragma warning(disable:4005)

#pragma warning(pop)

#pragma comment (lib,"winmm.lib")

#define _CRT_SECURE_NO_WARNINGS

// �v���R���p�C���w�b�_�[�ꗗ
// �p�ɂɎg�p����w�b�_�t�@�C���ꗗ
#include <windows.h>
#include <assert.h>
#include <memory>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <typeindex>
#include <string>
#include <DirectXMath.h>	// DirextX�̐��w�֘A�̃w�b�_�[�t�@�C��
#include <SimpleMath.h>
#include <stdlib.h>
#include <algorithm>
#include <d3d11.h>			// DirectX11���g�����߂̃w�b�_�[�t�@�C��

// DirectX::���ȗ�������
using namespace DirectX;

//! constexpr�F�R���p�C�����ɒl�����܂�萔
//! �ϐ��Ɠ����ŃX�R�[�v�����邱�ƁA�^���w��ł��邱�ƁA�R���p�C�����i�v���O�������s�O�j�ɒl�����܂�
//! ���R���p�C���ǂ��̂����̂͂܂��킩��Ȃ��̂ň�U���u�A�ォ��׋�
constexpr uint32_t SCREEN_WIDTH = 1920;
constexpr uint32_t SCREEN_HEIGHT = 1080;

// �萔��`
const auto ClassName = TEXT("HEW2D");			//!< �E�B���h�E�N���X��.
const auto WindowName = TEXT("���ƃ}�g�y");		//!< �E�B���h�E��.

