#pragma once

enum Type {
	BEANS,//��
	SOYMILK,//����
	TOFU,//����
	FREEZ//����
};

enum Scene {
	TITLE,//�^�C�g��
	SELECT,//�X�e�[�W�Z���N�g
	PLAY,//�v���C
	RESULT//���U���g
};

enum MapInfo {
    NONE,
    BLOCK,//�u���b�N
    THORN,//�Ƃ�
    HOT,//�M
    BLOWER_UP,//��(��)
    NETWORK,//��
    START,//�X�^�[�g
    GOAL,//�S�[��
    MILKMC,//�������N
    TOFUMC,//�������N
    FREEZMC,//���点��N
    MOVEFLOOR,//������
    BLOWER_LEFT,//��(��)
    BLOWER_RIGHT//��(�E)
};