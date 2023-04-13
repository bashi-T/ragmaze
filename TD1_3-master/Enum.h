#pragma once

enum Type {
	BEANS,//豆
	SOYMILK,//豆乳
	TOFU,//豆腐
	FREEZ//凶器
};

enum Scene {
	TITLE,//タイトル
	SELECT,//ステージセレクト
	PLAY,//プレイ
	RESULT//リザルト
};

enum MapInfo {
    NONE,
    BLOCK,//ブロック
    THORN,//とげ
    HOT,//熱
    BLOWER_UP,//風(上)
    NETWORK,//網
    START,//スタート
    GOAL,//ゴール
    MILKMC,//豆乳作る君
    TOFUMC,//豆腐作る君
    FREEZMC,//凍らせる君
    MOVEFLOOR,//動く床
    BLOWER_LEFT,//風(左)
    BLOWER_RIGHT//風(右)
};