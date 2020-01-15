//
// Created by 大石創 on 2020/01/14.
//
//
//#ifndef ZEMI_OPENCV_INCLUDE_H
//#define ZEMI_OPENCV_INCLUDE_H
//
//#endif //ZEMI_OPENCV_INCLUDE_H
#pragma once

#include <opencv2/opencv.hpp>

/*
--core--
�摜�E�s��f�[�^�\���̒�
�z�񑀍�
XML�����YAML���o��
�R�}���h���C���p�[�T�[
���[�e�B���e�B�@�\�Ȃ�
--highgui--
�摜�f�[�^�̃E�B���h�E�\���̂��߂̃��W���[��
namedWindow(�E�B���h�E�̐���)
imshow(�E�B���h�E�ɉ摜�f�[�^�̕\��)
waitKey(�L�[���͂̑ҋ@)
destroyAllWindows(�E�B���h�E�̔j��)
�ȂǂɕK�v
--imgcodecs--
�Î~����o�͂�s�����߂ɗp����o��
imread(�摜�f�[�^��t�@�C������ǂݍ���)
imwrite(�摜�f�[�^��t�@�C���ɏ����o��)
�ȂǂɕK�v
--imgproc--
��{�I�ȉ摜�����̂��߂̃��W���[��
�q�X�g�O����
�摜�t�B���^�����O
�摜�̊􉽊w�ϊ�
�ȂǂɕK�v
*/

/*
--#pragma CV_LIBRARY(lib_name)--
���C�u����������N���鏈����define�������
*/

#define CV_LIB_PREFIX comment(lib, "opencv_"

#ifdef _DEBUG
#define CV_LIB_SUFFIX CV_LIB_VERSION "d.lib")
#else
#define CV_LIB_SUFFIX CV_LIB_VERSION ".lib")
#endif

#define CV_LIB_VERSION CVAUX_STR(CV_MAJOR_VERSION)\
    CVAUX_STR(CV_MINOR_VERSION)\
    CVAUX_STR(CV_SUBMINOR_VERSION)

#define CV_LIBRARY(lib_name) CV_LIB_PREFIX CVAUX_STR(lib_name) CV_LIB_SUFFIX

#pragma CV_LIBRARY(core)
#pragma CV_LIBRARY(imgcodecs)
#pragma CV_LIBRARY(highgui)
#pragma CV_LIBRARY(imgproc)

#define __USE_OPEN_CP__
//#ifdef _DEBUG
//#ifdef __USE_OPEN_CP__
//#pragma comment(lib, "opencpd.lib")
//#endif
//#else
//#ifdef __USE_OPEN_CP__
//#pragma comment(lib, "opencp.lib")
//#endif
//#endif
//#ifdef _DEBUG
//#pragma comment(lib,"OpenCPd.lib")
//#else
//#pragma