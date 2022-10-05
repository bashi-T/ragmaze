#include <Novice.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<time.h>
const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_深海デリバリー";



// Windowsアプリでのエントリーポイント(main関数)
 int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 960, 720);
	int babble = Novice::LoadTexture("./REsources/colorbabble.png");
	int control = Novice::LoadTexture("./REsources/howtocontrol.png");
	int massagegc = Novice::LoadTexture("./REsources/massage2.png");
	int massagego = Novice::LoadTexture("./REsources/massage3.png");
	int massagelule = Novice::LoadTexture("./REsources/massage4.png");
	int massagesuke = 0xFFFFFF00;
	int stageclear = 0;
	int scene = 0;
	int titlecount = 0;
	int titlescroll=0;
	int selectscroll = 0;
	int stagecount=0;
	int countup=0;
	int CUC = 0;
	int babblex = 0;
	int babbley = 720;
	int bgm0 = Novice::LoadAudio("./Sounds/titlebgm.wav");
	int bgm1 = Novice::LoadAudio("./Sounds/stage1bgm.wav");
	int bgm2 = Novice::LoadAudio("./Sounds/stage2bgm.wav");
	int bgm3 = Novice::LoadAudio("./Sounds/stage3bgm.wav");
	int sound1 = Novice::LoadAudio("./Sounds/kettei.wav");
	int sound2 = Novice::LoadAudio("./Sounds/kettei2.wav");
	int sound3 = Novice::LoadAudio("./Sounds/awa.wav");
	int shotse = Novice::LoadAudio("./Sounds/shotse.wav");
	int chargese = Novice::LoadAudio("./Sounds/bombcharge.wav");
	int bombse = Novice::LoadAudio("./Sounds/barrier.wav");
	int damagese = Novice::LoadAudio("./Sounds/damage.wav");
	int bgmcount = -1;
	int stagebgm = -1; 
	int SEcount = -1;
	int bombSE = 0;
	int shotSE = 0;
	int charge = 0;

	typedef struct Title {
		int titlebg;
		int titlename;
		int howto;
		int selectbg;
		int SELECT;
		int select1;
		int select2;
		int select3;
		int back;
		int fish;
	};
	struct Title title = {
	  Novice::LoadTexture("./REsources/sinkaiTitle1.png"),
	  Novice::LoadTexture("./REsources/sinkaiTitle4.png"),
	  Novice::LoadTexture("./REsources/sinkaiTitle3.png"),
	  Novice::LoadTexture("./REsources/sinkaiTitle2.png"),
	  Novice::LoadTexture("./REsources/sinkaiTitle5.png"),
	  Novice::LoadTexture("./REsources/sinkaiTitle6.png"),
	  Novice::LoadTexture("./REsources/sinkaiTitle7.png"),
	  Novice::LoadTexture("./REsources/sinkaiTitle8.png"),
	  Novice::LoadTexture("./REsources/sinkaiTitle9.png"),
	  Novice::LoadTexture("./REsources/sinkaiTitle10.png"),
	};
	Title;
	typedef struct Titlexy {
		int titlebgX;
		int titlenameX;
		int howtoX;
		int selectbgX;
		int SELECTX;
		int select1X;
		int select2X;
		int select3X;
		int backX;
		int fishX;

		int titlebgY;
		int titlenameY;
		int howtoY;
		int selectbgY;
		int SELECTY;
		int select1Y;
		int select2Y;
		int select3Y;
		int backY;
		int fishY;
	};
	struct Titlexy titlexy = {
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /*ここまでX*/
	  0, 0, 0, 720, 720, 720, 720, 720, 720, 650,

	};
	Titlexy;

	typedef struct Stage {
		int stage1;
		int stage2;
		int stage3;
		
	};
	struct Stage stage = {
	  Novice::LoadTexture("./REsources/stage1.png"),
	  Novice::LoadTexture("./REsources/stage2.png"),
	  Novice::LoadTexture("./REsources/stage3-1.png"),
	};
	Stage;
	
	 typedef struct Stagexy{
	 	int stage1x;
	    int stage2x;
		int stage3x;

		int stage1y;
		int stage2y;
		int stage3y;
		
	};
	struct Stagexy stagexy = {
	  0, 0, 0, /*ここまでX*/
	  0, 0, 0, 

	};
	Stagexy;
	int utubo = 0;
	int tatiuo[20] = {0};
	int same = 0;
	int datu = 0;
	int hamosuityoku = 0;
	int hamokunekune = 0;
	int utubolife = 0;
	int tatiuolife[20] = {0};
	int samelife = 0;
	int datulife = 0;
	int hamosuityokulife = 0;
	int hamokunekunelife = 0;
	int utubo1 = Novice::LoadTexture("./REsources/utubo1.png");
	int utubo2 = Novice::LoadTexture("./REsources/utubo2.png");
	int utubo3 = Novice::LoadTexture("./REsources/utubo3.png");
	int utubo4 = Novice::LoadTexture("./REsources/utubo4.png");
	int utubo5 = Novice::LoadTexture("./REsources/utubo5.png");
	int utubo6 = Novice::LoadTexture("./REsources/utubo6.png");
	int utubo7 = Novice::LoadTexture("./REsources/utubo7.png");
	int utubo8 = Novice::LoadTexture("./REsources/utubo8.png");

	int tatiuo1 = Novice::LoadTexture("./REsources/tatiuo1.png");
	int tatiuo2 = Novice::LoadTexture("./REsources/tatiuo2.png");
	int tatiuo3 = Novice::LoadTexture("./REsources/tatiuo3.png");
	int tatiuo4 = Novice::LoadTexture("./REsources/tatiuo4.png");
	int tatiuo5 = Novice::LoadTexture("./REsources/tatiuo5.png");
	int tatiuo6 = Novice::LoadTexture("./REsources/tatiuo6.png");
	int tatiuo7 = Novice::LoadTexture("./REsources/tatiuo7.png");
	int tatiuo8 = Novice::LoadTexture("./REsources/tatiuo8.png");
	int tatiuo9 = Novice::LoadTexture("./REsources/tatiuo9.png");
	int tatiuo10 = Novice::LoadTexture("./REsources/tatiuo10.png");
	int tatiuo11 = Novice::LoadTexture("./REsources/tatiuo11.png");
	int tatiuo12 = Novice::LoadTexture("./REsources/tatiuo12.png");
	int tatiuo13 = Novice::LoadTexture("./REsources/tatiuo13.png");
	int tatiuo14 = Novice::LoadTexture("./REsources/tatiuo14.png");

	int same1 = Novice::LoadTexture("./REsources/same1.png");
	int same2 = Novice::LoadTexture("./REsources/same2.png");
	int same3 = Novice::LoadTexture("./REsources/same3.png");
	int same4 = Novice::LoadTexture("./REsources/same4.png");
	int same5 = Novice::LoadTexture("./REsources/same5.png");
	int same6 = Novice::LoadTexture("./REsources/same6.png");
	int same7 = Novice::LoadTexture("./REsources/same7.png");
	int same8 = Novice::LoadTexture("./REsources/same8.png");
	int same9 = Novice::LoadTexture("./REsources/same9.png");
	int same10 = Novice::LoadTexture("./REsources/same10.png");
	int same11 = Novice::LoadTexture("./REsources/same11.png");
	int same12 = Novice::LoadTexture("./REsources/same12.png");
	int same13 = Novice::LoadTexture("./REsources/same13.png");
	int same14 = Novice::LoadTexture("./REsources/same14.png");
	int same15 = Novice::LoadTexture("./REsources/same15.png");
	int same16 = Novice::LoadTexture("./REsources/same16.png");
	int same17 = Novice::LoadTexture("./REsources/same17.png");
	int same18 = Novice::LoadTexture("./REsources/same18.png");
	int same19 = Novice::LoadTexture("./REsources/same19.png");
	int same20 = Novice::LoadTexture("./REsources/same20.png");
	int same21 = Novice::LoadTexture("./REsources/same21.png");
	int same22 = Novice::LoadTexture("./REsources/same22.png");
	int same23 = Novice::LoadTexture("./REsources/same23.png");
	int same24 = Novice::LoadTexture("./REsources/same24.png");
	int same25 = Novice::LoadTexture("./REsources/same25.png");
	int same26 = Novice::LoadTexture("./REsources/same26.png");
	int same27 = Novice::LoadTexture("./REsources/same27.png");
	int same28 = Novice::LoadTexture("./REsources/same28.png");

	int datu1 = Novice::LoadTexture("./REsources/datu1.png");
	int datu2 = Novice::LoadTexture("./REsources/datu2.png");
	int datu3 = Novice::LoadTexture("./REsources/datu3.png");
	int datu4 = Novice::LoadTexture("./REsources/datu4.png");
	int datu5 = Novice::LoadTexture("./REsources/datu5.png");
	int datu6 = Novice::LoadTexture("./REsources/datu6.png");
	int datu7 = Novice::LoadTexture("./REsources/datu7.png");
	int datu8 = Novice::LoadTexture("./REsources/datu8.png");
	int datu9 = Novice::LoadTexture("./REsources/datu9.png");
	int datu10 = Novice::LoadTexture("./REsources/datu10.png");
	int datu11 = Novice::LoadTexture("./REsources/datu11.png");
	int datu12 = Novice::LoadTexture("./REsources/datu12.png");

	int hamosuityoku1 = Novice::LoadTexture("./REsources/hamosuityoku1.png");
	int hamosuityoku2 = Novice::LoadTexture("./REsources/hamosuityoku2.png");
	int hamosuityoku3 = Novice::LoadTexture("./REsources/hamosuityoku3.png");
	int hamosuityoku4 = Novice::LoadTexture("./REsources/hamosuityoku4.png");
	int hamosuityoku5 = Novice::LoadTexture("./REsources/hamosuityoku5.png");
	int hamosuityoku6 = Novice::LoadTexture("./REsources/hamosuityoku6.png");
	int hamosuityoku7 = Novice::LoadTexture("./REsources/hamosuityoku7.png");

	int hamokunekune1 = Novice::LoadTexture("./REsources/hamokunekune1.png");
	int hamokunekune2 = Novice::LoadTexture("./REsources/hamokunekune2.png");
	int hamokunekune3 = Novice::LoadTexture("./REsources/hamokunekune3.png");
	int hamokunekune4 = Novice::LoadTexture("./REsources/hamokunekune4.png");
	int hamokunekune5 = Novice::LoadTexture("./REsources/hamokunekune5.png");
	int hamokunekune6 = Novice::LoadTexture("./REsources/hamokunekune6.png");
	int hamokunekune7 = Novice::LoadTexture("./REsources/hamokunekune7.png");
	int hamokunekune8 = Novice::LoadTexture("./REsources/hamokunekune8.png");
	int hamokunekune9 = Novice::LoadTexture("./REsources/hamokunekune9.png");
	int hamokunekune10 = Novice::LoadTexture("./REsources/hamokunekune10.png");
	int hamokunekune11 = Novice::LoadTexture("./REsources/hamokunekune11.png");
	int hamokunekune12 = Novice::LoadTexture("./REsources/hamokunekune12.png");
	int hamokunekune13 = Novice::LoadTexture("./REsources/hamokunekune13.png");
	int hamokunekune14 = Novice::LoadTexture("./REsources/hamokunekune14.png");
	int hamokunekune15 = Novice::LoadTexture("./REsources/hamokunekune15.png");
	int hamokunekune16 = Novice::LoadTexture("./REsources/hamokunekune16.png");
	int hamokunekune17 = Novice::LoadTexture("./REsources/hamokunekune17.png");
	int hamokunekune18 = Novice::LoadTexture("./REsources/hamokunekune18.png");
	int hamokunekune19 = Novice::LoadTexture("./REsources/hamokunekune19.png");
	int hamokunekune20 = Novice::LoadTexture("./REsources/hamokunekune20.png");
	int hamokunekune21 = Novice::LoadTexture("./REsources/hamokunekune21.png");
	int hamokunekune22 = Novice::LoadTexture("./REsources/hamokunekune22.png");
	int hamokunekune23 = Novice::LoadTexture("./REsources/hamokunekune23.png");
	int hamokunekune24 = Novice::LoadTexture("./REsources/hamokunekune24.png");
	

	float utubox = 0;
	float tatiuox[20] = {0};
	float samex = 0;
	float datux = 0;
	float hamosuityokux = 0;
	float hamokunekunex = 0;

	float utuboy = 720;
	float tatiuoy[20] = {
	  720, 720, 720, 720, 720, 720, 720, 720, 720, 720,
	  720, 720, 720, 720, 720, 720, 720, 720, 720, 720,
	};
	float samey = 720;
	float datuy = 720;
	float hamosuityokuy = 720;
	float hamokunekuney = 720;

	float utubovelx = 0;
	float tatiuovelx[20] = {0};
	float samevelx = 0;
	float sameaccx = 1.005f;
	float datuvelx = 0;
	float hamosuityokuvelx = 0;
	float hamokunekunevelx = 0;

	float utubovely = 0;
	float tatiuovely[20] = {0};
	float samevely = 0;
	float sameacc = 1.005f;
	float datuvely = 0;
	float hamosuityokuvely = 0;
	float hamokunekunevely = 0;
		
	float utubohitx = 0;
	float tatiuohitx[20] = {0};
	float samehitx = 0;
	float datuhitx = 0;
	float hamosuityokuhitx = 0;
	float hamokunekunehitx = 0;

	float utubohity = 720;
	float tatiuohity[20] = {
	  720, 720, 720, 720, 720, 720, 720, 720, 720, 720,
	  720, 720, 720, 720, 720, 720, 720, 720, 720, 720,
	};
	float samehity = 720;
	float datuhity = 720;
	float hamosuityokuhity = 720;
	float hamokunekunehity = 720;

	int utubocount = 0;
	int tatiuocount[20] = {0};
	int samecount = 0;
	int datucount = 0;
	int hamosuityokucount = 0;
	int hamokunekunecount = 0;

	float enemylength[6] = {0};
	int tatiuonumber = 0;


	int jiki = 0;
	int jikilife = 1;
	int jikicount = 0;
	int jiki1 = Novice::LoadTexture("./REsources/sinkaijiki1.png");
	int jiki2 = Novice::LoadTexture("./REsources/sinkaijiki2.png");
	int jiki3 = Novice::LoadTexture("./REsources/sinkaijiki3.png");
	int jiki4 = Novice::LoadTexture("./REsources/sinkaijiki4.png");
	int jiki5 = Novice::LoadTexture("./REsources/sinkaijiki5.png");
	int jiki6 = Novice::LoadTexture("./REsources/sinkaijiki6.png");
	int jiki7 = Novice::LoadTexture("./REsources/sinkaijiki7.png");
	int jiki8 = Novice::LoadTexture("./REsources/sinkaijiki8.png");
	int jiki9 = Novice::LoadTexture("./REsources/sinkaijiki9.png");
	int jiki10 = Novice::LoadTexture("./REsources/sinkaijiki10.png");
	int jiki11 = Novice::LoadTexture("./REsources/sinkaijiki11.png");
	int jiki12 = Novice::LoadTexture("./REsources/sinkaijiki12.png");
	int jiki13 = Novice::LoadTexture("./REsources/sinkaijiki13.png");
	int jiki14 = Novice::LoadTexture("./REsources/sinkaijiki14.png");
	int jiki15 = Novice::LoadTexture("./REsources/sinkaijiki15.png");
	int jiki16 = Novice::LoadTexture("./REsources/sinkaijiki16.png");
	float xpos = 448;
	float ypos = -330;
	float Xpos = 480;
	float Ypos = 50;
	float jikihitx = 0;
	float jikihity = 0;
	int jikihitcount = 0;
	float lotatex = 0;
	float lotatey = 0;
	float xvec = 0;
	float Xvec = 0;
	float yvec = 0;
	float Yvec = 0;
	float speed;

	int bomb=0;
	int bomb0 = 0;
	int bomb1 = Novice::LoadTexture("./REsources/bomb1.png");
	int bomb2 = Novice::LoadTexture("./REsources/bomb2.png");
	int bomb3 = Novice::LoadTexture("./REsources/bomb3.png");
	int bomb4 = Novice::LoadTexture("./REsources/bomb4.png");
	int bomb5 = Novice::LoadTexture("./REsources/bomb5.png");
	int bomb6 = Novice::LoadTexture("./REsources/bomb6.png");
	int bomb7 = Novice::LoadTexture("./REsources/bomb7.png");
	int bomb8 = Novice::LoadTexture("./REsources/bomb8.png");
	int bomb9 = Novice::LoadTexture("./REsources/bomb9.png");
	int bomb10 = Novice::LoadTexture("./REsources/bomb10.png");
	int bomb11 = Novice::LoadTexture("./REsources/bomb11.png");
	int bomb12 = Novice::LoadTexture("./REsources/bomb12.png");
	int bomb13 = Novice::LoadTexture("./REsources/bomb13.png");
	int bomb14 = Novice::LoadTexture("./REsources/bomb14.png");
	int bomb15 = Novice::LoadTexture("./REsources/bomb15.png");
	int bomb16 = Novice::LoadTexture("./REsources/bomb16.png");
	int bomb17 = Novice::LoadTexture("./REsources/bomb17.png");
	float bombx = 0;
	float bomby = 0;
	float bombrange = 0;
	float bombhitx = 0;
	float bombhity = 0;
	float bombsize = 0;
	int bombcount = 0;
	int countbomb = 0;
	int bombcharge = 0;
	int bombcolor = 0x0000FFFF;
	int bombblue = 0x000008FF;
	int bombred = 0x050000FF;
	int bombsuke = 0x00000003;



	float whalexpos = 360;
	float whaleypos = -270;
	float whalehitx = 0;
	float whalehity = 0;
	int whalelife = 4;
	int whale = 0;
	int whale1 = Novice::LoadTexture("./REsources/whale5.png");
	int whale2 = Novice::LoadTexture("./REsources/whale4.png");
	int whale3 = Novice::LoadTexture("./REsources/whale3.png");
	int whale4 = Novice::LoadTexture("./REsources/whale2.png");
	int whale5 = Novice::LoadTexture("./REsources/whale1.png");
	float whalexvel = 0;
	float whaleyvel = 0;
	float whalexacc = 0;
	float whaleyacc = 0;

	
	int bullet = 0;
	int bullet1 = Novice::LoadTexture("./REsources/sinkaibullet1.png");
	int bullet2 = Novice::LoadTexture("./REsources/sinkaibullet2.png");
	int bullet3 = Novice::LoadTexture("./REsources/sinkaibullet3.png");
	int bullet4 = Novice::LoadTexture("./REsources/sinkaibullet4.png");
	int bullet5 = Novice::LoadTexture("./REsources/sinkaibullet5.png");
	int bullet6 = Novice::LoadTexture("./REsources/sinkaibullet6.png");
	int bullet7 = Novice::LoadTexture("./REsources/sinkaibullet7.png");
	int bullet8 = Novice::LoadTexture("./REsources/sinkaibullet8.png");
	int bullet9 = Novice::LoadTexture("./REsources/sinkaibullet9.png");
	int bullet10 = Novice::LoadTexture("./REsources/sinkaibullet10.png");
	int bullet11 = Novice::LoadTexture("./REsources/sinkaibullet11.png");
	int bullet12 = Novice::LoadTexture("./REsources/sinkaibullet12.png");
	int bullet13 = Novice::LoadTexture("./REsources/sinkaibullet13.png");
	int bullet14 = Novice::LoadTexture("./REsources/sinkaibullet14.png");
	int bullet15 = Novice::LoadTexture("./REsources/sinkaibullet15.png");
	int bullet16 = Novice::LoadTexture("./REsources/sinkaibullet16.png");
	int bullet17 = Novice::LoadTexture("./REsources/sinkaibullet17.png");
	int bullet18 = Novice::LoadTexture("./REsources/sinkaibullet18.png");
	int bullet19 = Novice::LoadTexture("./REsources/sinkaibullet19.png");
	int bullet20 = Novice::LoadTexture("./REsources/sinkaibullet20.png");
	int bullet21 = Novice::LoadTexture("./REsources/sinkaibullet21.png");
	int bullet22 = Novice::LoadTexture("./REsources/sinkaibullet22.png");
	int bullet23 = Novice::LoadTexture("./REsources/sinkaibullet23.png");
	int bullet24 = Novice::LoadTexture("./REsources/sinkaibullet24.png");

	int bullet1s = Novice::LoadTexture("./REsources/bulletstripe1.png");
	int bullet2s = Novice::LoadTexture("./REsources/bulletstripe2.png");
	int bullet3s = Novice::LoadTexture("./REsources/bulletstripe3.png");
	int bullet4s = Novice::LoadTexture("./REsources//bulletstripe4.png");
	int bullet5s = Novice::LoadTexture("./REsources//bulletstripe5.png");
	int bullet6s = Novice::LoadTexture("./REsources//bulletstripe6.png");
	int bullet7s = Novice::LoadTexture("./REsources//bulletstripe7.png");
	int bullet8s = Novice::LoadTexture("./REsources//bulletstripe8.png");
	int bullet9s = Novice::LoadTexture("./REsources//bulletstripe9.png");
	int bullet10s = Novice::LoadTexture("./REsources//bulletstripe10.png");
	int bullet11s = Novice::LoadTexture("./REsources//bulletstripe11.png");
	int bullet12s = Novice::LoadTexture("./REsources//bulletstripe12.png");
	int bullet13s = Novice::LoadTexture("./REsources//bulletstripe13.png");
	int bullet14s = Novice::LoadTexture("./REsources//bulletstripe14.png");
	int bullet15s = Novice::LoadTexture("./REsources//bulletstripe15.png");
	int bullet16s = Novice::LoadTexture("./REsources//bulletstripe16.png");
	int bullet17s = Novice::LoadTexture("./REsources//bulletstripe17.png");
	int bullet18s = Novice::LoadTexture("./REsources//bulletstripe18.png");
	int bullet19s = Novice::LoadTexture("./REsources//bulletstripe19.png");
	int bullet20s = Novice::LoadTexture("./REsources//bulletstripe20.png");
	int bullet21s = Novice::LoadTexture("./REsources//bulletstripe21.png");
	int bullet22s = Novice::LoadTexture("./REsources//bulletstripe22.png");
	int bullet23s = Novice::LoadTexture("./REsources//bulletstripe23.png");
	int bullet24s = Novice::LoadTexture("./REsources//bulletstripe24.png");
	int bulanime = 0;
	float bulposX[20] = {0};
	float bulposY[20] = {0};
	float bulvelX[20] = {0};
	float bulvelY[20] = {0};
	float bulPosX[20] = {0};
	float bulPosY[20] = {0};
	float bulVelX[20] = {0};
	float bulVelY[20] = {0};
	int bulletlife[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	float bullength = 0;
	float bulhitx[20] = {0};
	float bulhity[20] = {0};
	int tamacount[20] = {0};
	int bulletcount = 0;
	int bulcount = -1;
	int countbul = 0;
	float bullotate = 0.0f;
	int worldy = 1;

	float theta = (1.0 / 2.0f) * M_PI;
	float THETA = 1.0 / 2.0f;
	float bulletTheta = (THETA)*M_PI;
	float length = 0;

	

	int backeffect = 0;
	int back[6] = {0};
	int back1 = Novice::LoadTexture("./REsources/haikeifish1.png");
	int back2 = Novice::LoadTexture("./REsources/haikeifish2.png");
	int back3 = Novice::LoadTexture("./REsources/haikeifish3.png");
	int back4 = Novice::LoadTexture("./REsources/haikeifish4.png");
	float backx[5] = {0};
	float backy[5] = {720, 720, 720, 720, 720};
	int backcount = 0;
	int haikei = 0;
	int number = 0;
	int haikeinum = 0;
	int scroll = 0;


	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		speed = 0;
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///


		// タイトル画面
		if (scene == 0 && stagecount == 0) {
			bgm1 = Novice::LoadAudio("./Sounds/stage1bgm.wav");
			bgm2 = Novice::LoadAudio("./Sounds/stage2bgm.wav");
		    bgm3 = Novice::LoadAudio("./Sounds/stage3bgm.wav");

			whalelife = 4;
			whale = whale1;
			whalexpos = 360;
			whaleypos = -270;
			xpos = 448;
			ypos = -330;
			titlecount += 1;
			if (titlecount == 61) {
				titlexy.titlenameX = 5;
				titlexy.howtoX = 5;
				titlexy.SELECTX = 5;
				titlexy.select1X = 5;
				titlexy.select2X = 5;
				titlexy.select3X = 5;
				titlexy.backX = 5;
				titlexy.fishX = 5;
			}

			if (titlecount == 121) {
				titlexy.titlenameX = 0;
				titlexy.howtoX = 0;
				titlexy.SELECTX = 0;
				titlexy.select1X = 0;
				titlexy.select2X = 0;
				titlexy.select3X = 0;
				titlexy.backX = 0;
				titlexy.fishX = 0;
				titlecount = 0;
			}

			if (keys[DIK_SPACE] && titlexy.fishY >= 650) {
				SEcount = -1;
				titlescroll += 1;
				title.howto =0;
			}

			if (titlescroll > 0 && titlescroll <= 174) {
				titlescroll += 1;
				if (titlescroll >= 30 && titlescroll <= 173) {
					titlexy.titlebgY -= 5;
					titlexy.titlenameY -= 5;
					titlexy.howtoY -= 5;
					titlexy.SELECTY -= 5;
					titlexy.selectbgY -= 5;
					titlexy.select1Y -= 5;
					titlexy.select2Y -= 5;
					titlexy.select3Y -= 5;
					titlexy.backY -= 5;
					titlexy.fishY -= 5;
					selectscroll = 0;
				}
			}

			if (keys[DIK_S] && preKeys[DIK_S] == 0 && selectscroll <= 0) {
				titlexy.fishY += 70;
			}

			if (keys[DIK_W] && preKeys[DIK_W] == 0 && selectscroll <= 0) {
				titlexy.fishY -= 70;
			}

			if (titlexy.fishY == -70) {
				if (titlecount == 61) {
					titlexy.select1X = 20;
				}
				if (titlecount == 121) {
					titlexy.select1X = 5;
				}
			}

			if (titlexy.fishY == 0) {
				if (titlecount == 61) {
					titlexy.select2X = 20;
				}
				if (titlecount == 121) {
					titlexy.select2X = 5;
				}
			}

			if (titlexy.fishY == 70) {
				if (titlecount == 61) {
					titlexy.select3X = 20;
				}
				if (titlecount == 121) {
					titlexy.select3X = 5;
				}
			}

			if (titlexy.fishY == 140) {
				if (titlecount == 61) {
					titlexy.backX = 20;
				}
				if (titlecount == 121) {
					titlexy.backX = 5;
				}
			}

			if (titlexy.fishY == 140 && keys[DIK_SPACE] &&preKeys[DIK_S] == 0) {
				selectscroll += 1;
				SEcount = -1;
				title.howto = Novice::LoadTexture("./REsources/sinkaiTitle3.png");
            }
			if (selectscroll > 0 && selectscroll <= 174) {
				selectscroll += 1;

				if (selectscroll >= 30 && selectscroll <= 173) {
					titlexy.titlebgY += 5;
					titlexy.titlenameY += 5;
					titlexy.howtoY += 5;
					titlexy.SELECTY += 5;
					titlexy.selectbgY += 5;
					titlexy.select1Y += 5;
					titlexy.select2Y += 5;
					titlexy.select3Y += 5;
					titlexy.backY += 5;
					titlexy.fishY += 5;
					titlescroll = 0;
				}
			}
			if (titlexy.fishY == -70 && keys[DIK_SPACE]) {
				CUC = 1;
				SEcount = -1;
				stagecount = 1;
				title.select2 = 0;
				title.select3 = 0;
				title.back = 0;
			}
			if (titlexy.fishY == 0 && keys[DIK_SPACE]) {
				CUC = 1;
				SEcount = -1;
				stagecount = 2;
				title.select1 = 0;
				title.select3 = 0;
				title.back = 0;
			}
			if (titlexy.fishY == 70 && keys[DIK_SPACE]) {
				CUC = 1;
				SEcount = -1;
				stagecount = 3;
				title.select1 = 0;
				title.select2 = 0;
				title.back = 0;
			}
			if (titlexy.fishY <= -70 && keys[DIK_W]&& selectscroll <= 0 && titlexy.titlebgY == -720) {
				titlexy.fishY = -70;
			}
			if ( titlexy.fishY >= 140 && keys[DIK_S] && selectscroll <= 0 &&
			  titlexy.titlebgY == -720) {
				titlexy.fishY = 140;
			}
			 


		}//ここまでタイトル--------------------------------------------------------
		
		 //遷移
		if (CUC == 1) {
			
			Novice::StopAudio(bgmcount);
			bgmcount = -1;
			stageclear = 0;
			bombcharge = 0;
			massagesuke = 0xFFFFFF00;
			title.SELECT = 0;
			countup += 1;
			worldy = 0;
			if (countup == 40) {
				SEcount = -1;
			}
			if (countup >= 40) {
				babbley -= 20;
			}
			if (countup == 110 && scene == 0) {
				scene = 1;
			}
			if (countup == 110 && stageclear == 1) {
				scene = 0;
				stageclear = 0;
			}
			if (babbley == -2880) {
				babbley = 720;
				countup = 0;
				CUC = 0;
				bgmcount = -1;
				titlecount = 0;
				Novice::StopAudio(SEcount);
			}
			if (stagecount == 1) {
				stagexy.stage1x = 0;
				stagexy.stage1y = 0;
				stagexy.stage2x = 0;
				stagexy.stage2y = 0;
				stagexy.stage3x = 0;
				stagexy.stage3y = 0;
			}
			if (stagecount == 2) {
				stagexy.stage1x = 0;
				stagexy.stage1y = 0;
				stagexy.stage2x = 0;
				stagexy.stage2y = 0;
				stagexy.stage3x = 0;
				stagexy.stage3y = 0;
			}
			if (stagecount == 3) {
				stagexy.stage3x = 0;
				stagexy.stage3y = 0;
				stagexy.stage2x = 0;
				stagexy.stage2y = 0;
				stagexy.stage1x = 0;
				stagexy.stage1y = 0;
			}
		}

		if (CUC == 2) {
			bgm1 = 0;
			bgm2 = 0;
			bgm3 = 0;
			stageclear = 0;
			Novice::StopAudio(stagebgm);
			countup += 1;
			if (countup == 40) {
				SEcount = -1;
			}
			if (countup >= 40) {
				babbley -= 20;
				Novice::StopAudio(bgmcount);
			}
			if (countup == 110) {
				scene = 0;
				stagecount = 0;
				scroll = 0;

				title.titlebg = Novice::LoadTexture("./REsources/sinkaiTitle1.png");
				title.titlename = Novice::LoadTexture("./REsources/sinkaiTitle4.png");
				title.howto = Novice::LoadTexture("./REsources/sinkaiTitle3.png");
				title.selectbg = Novice::LoadTexture("./REsources/sinkaiTitle2.png");
				title.SELECT = Novice::LoadTexture("./REsources/sinkaiTitle5.png");
				title.select1 = Novice::LoadTexture("./REsources/sinkaiTitle6.png");
				title.select2 = Novice::LoadTexture("./REsources/sinkaiTitle7.png");
				title.select3 = Novice::LoadTexture("./REsources/sinkaiTitle8.png");
				title.back = Novice::LoadTexture("./REsources/sinkaiTitle9.png");
				title.fish = Novice::LoadTexture("./REsources/sinkaiTitle10.png");

				titlexy.titlebgX = 0;
				titlexy.titlenameX = 0;
				titlexy.howtoX = 0;
				titlexy.selectbgX = 0;
				titlexy.SELECTX = 0;
				titlexy.select1X = 0;
				titlexy.select2X = 0;
				titlexy.select3X = 0;
				titlexy.backX = 0;
				titlexy.fishX = 0;

				titlexy.titlebgY = 0;
				titlexy.titlenameY = 0;
				titlexy.howtoY = 0;
				titlexy.selectbgY = 720;
				titlexy.SELECTY = 720;
				titlexy.select1Y = 720;
				titlexy.select2Y = 720;
				titlexy.select3Y = 720;
				titlexy.backY = 720;
				titlexy.fishY = 650;
				titlescroll = 0;
			}

			if (babbley == -2880) {
				babbley = 720;
				countup = 0;
				Novice::StopAudio(SEcount);
				bgmcount = -1;
				CUC = 0;
			}
		}

		if (scene == 1) {
		
			
			scroll += 1;
			jikicount += 1;
			if (jikicount == 40) {
				jikicount = 0;
			}
			if (jikicount >= 0 && jikicount <= 9) {
				jiki = jiki1;
			}
			if (jikicount >= 10 && jikicount <= 19) {
				jiki = jiki2;
			}
			if (jikicount >= 20 && jikicount <= 29) {
				jiki = jiki3;
			}
			if (jikicount >= 30 && jikicount <= 39) {
				jiki = jiki4;
			}
			if (scroll > 0 && scroll < 301) {
				whaleypos += 1;
				ypos +=2;
			}


			if (scroll == 479) {
				bombcharge = 2000;
			}
			if (scroll >= 480) {/*ゲーム中*/
				scroll = 480;
				jikihitx = xpos + 32;
				jikihity = ypos + 32;
				whalehitx = whalexpos + 120;
				whalehity = whaleypos + 120;
				bombhitx = bombx;
				bombhity = bomby;

				if (jikilife == 1) {

					if (jikicount >= 0 && jikicount <= 9 && keys[DIK_SPACE]) {
						jiki = jiki5;
					}
					if (jikicount >= 10 && jikicount <= 19 && keys[DIK_SPACE]) {
						jiki = jiki6;
					}
					if (jikicount >= 20 && jikicount <= 29 && keys[DIK_SPACE]) {
						jiki = jiki7;
					}
					if (jikicount >= 30 && jikicount <= 39 && keys[DIK_SPACE]) {
						jiki = jiki8;
					}

					if (keys[DIK_D]) {
						theta = (0.0f) * M_PI;
						speed = 10.0f;
					}
					if (keys[DIK_A]) {
						theta = M_PI;
						speed = 10.0f;
					}
					if (keys[DIK_S]) {
						theta = (3.0 / 2.0f) * M_PI;
						speed = 10.0f;
					}
					if (keys[DIK_W]) {
						theta = (1.0 / 2.0f) * M_PI;
						speed = 10.0f;
					}

					if (keys[DIK_D] && keys[DIK_W]) {
						theta = (1.0 / 4.0f) * M_PI;
					}
					if (keys[DIK_A] && keys[DIK_W]) {
						theta = (3.0 / 4.0f) * M_PI;
					}
					if (keys[DIK_A] && keys[DIK_S]) {
						theta = (5.0 / 4.0f) * M_PI;
					}
					if (keys[DIK_D] && keys[DIK_S]) {
						theta = (7.0 / 4.0f) * M_PI;
					}

					if (whalexvel > 0 && keys[DIK_D] == 0) {
						whalexacc = -0.5;
					} else if (whalexvel == 0 && keys[DIK_D] == 0) {
						whalexacc = 0;
					}
					if (whalexvel < 0 && keys[DIK_A] == 0) {
						whalexacc = 0.5;
					} else if (whalexvel == 0 && keys[DIK_A] == 0) {
						whalexacc = 0;
					}
					if (whaleyvel > 0 && keys[DIK_S] == 0) {
						whaleyacc = -0.5;
					} else if (whaleyvel == 0 && keys[DIK_S] == 0) {
						whaleyacc = 0;
					}
					if (whaleyvel < 0 && keys[DIK_W] == 0) {
						whaleyacc = 0.5;
					} else if (whaleyvel == 0 && keys[DIK_W] == 0) {
						whaleyacc = 0;
					}

					if (keys[DIK_D]) {
						whalexacc = 0.25;
					}
					if (keys[DIK_A]) {
						whalexacc = -0.25;
					}
					if (keys[DIK_S]) {
						whaleyacc = 0.25;
					}
					if (keys[DIK_W]) {
						whaleyacc = -0.25;
					}

					if (whalexvel >= 10) {
						whalexvel = 10;
					}
					if (whalexvel <= -10) {
						whalexvel = -10;
					}
					if (whaleyvel >= 10) {
						whaleyvel = 10;
					}
					if (whaleyvel <= -10) {
						whaleyvel = -10;
					}
					if (keys[DIK_LSHIFT]) {
						speed = 0;
						speed = 0;
					}

					xvec = cosf(theta);
					yvec = sinf(theta);

					whalexvel = whalexvel + whalexacc;
					whaleyvel = whaleyvel + whaleyacc;
					whalexpos = whalexpos + whalexvel;
					whaleypos = whaleypos + whaleyvel;
					xpos += Xvec * speed;
					ypos += Yvec * speed;
					if (whalexpos < 0) {
						whalexpos = 0;
						whalexvel = 0;
						whalexacc = 0;
					}
					if (whalexpos > 720) {
						whalexpos = 720;
						whalexvel = 0;
						whalexacc = 0;
					}
					if (whaleypos < 0) {
						whaleypos = 0;
						whaleyvel = 0;
						whaleyacc = 0;
					}
					if (whaleypos > 480) {
						whaleypos = 480;
						whaleyvel = 0;
						whaleyacc = 0;
					}

					if (xpos <= 0 && keys[DIK_A]) {
						xpos = 0;
					}
					if (xpos >= 894 && keys[DIK_D]) {
						xpos = 894;
					}
					if (ypos <= 0 && keys[DIK_W]) {
						ypos = 0;
					}
					if (ypos >= 656 && keys[DIK_S]) {
						ypos = 656;
					}

					//射撃---------------------------------------------------------------------
					countbul += 1;
					bulanime += 1;
					if (bulanime == 60) {
						bulanime = 0;
					}
					if (keys[DIK_SPACE]) {
						bulletcount += 1;
					}

					if (bulletcount == 1) {
						bulcount += 1;
						shotSE = -1;

					}
					if (bulletcount == 20) {
						bulletcount = 0;
						Novice::StopAudio(shotSE);
					}
					if (bulcount >= 20) {
						bulcount = 20;
					}
					if (countbul == 41) {
						countbul = 1;
					}
					if (countbul >= 1 && countbul <= 10) {
						bullet = bullet1;
					}
					if (countbul >= 11 && countbul <= 20) {
						bullet = bullet2;
					}
					if (countbul >= 21 && countbul <= 30) {
						bullet = bullet3;
					}
					if (countbul >= 31 && countbul <= 40) {
						bullet = bullet4;
					}
					if (keys[DIK_SPACE] == 0) {
						if (
						  keys[DIK_V] &&
						  preKeys[DIK_V] == 0) { //射角・回転-----------------------------------
							THETA += 1.0 / 4.0f;
						}
					}

					if (THETA == 2.0f) {
						THETA = 0.0f;
					}
					if (keys[DIK_N] && preKeys[DIK_N] == 0) {
						THETA -= 1.0 / 4.0f;
					}
					if (THETA < 0.0f) {
						THETA = 7.0f / 4.0f;
					}
					if (THETA == 0.0) {
						if (bulanime >= 0 && bulanime <= 9) {
							bullet = bullet19;
						}
						if (bulanime >= 0 && bulanime <= 19) {
							bullet = bullet20;
						}
						if (bulanime >= 0 && bulanime <= 29) {
							bullet = bullet21;
						}
						if (bulanime >= 0 && bulanime <= 39) {
							bullet = bullet22;
						}
						if (bulanime >= 0 && bulanime <= 49) {
							bullet = bullet23;
						}
						if (bulanime >= 0 && bulanime <= 59) {
							bullet = bullet24;
						}
					}
					if (THETA == 2.0 / 4.0) {
						if (bulanime >= 0 && bulanime <= 9) {
							bullet = bullet1;
						}
						if (bulanime >= 0 && bulanime <= 19) {
							bullet = bullet2;
						}
						if (bulanime >= 0 && bulanime <= 29) {
							bullet = bullet3;
						}
						if (bulanime >= 0 && bulanime <= 39) {
							bullet = bullet4;
						}
						if (bulanime >= 0 && bulanime <= 49) {
							bullet = bullet5;
						}
						if (bulanime >= 0 && bulanime <= 59) {
							bullet = bullet6;
						}
					}
					if (THETA == 4.0 / 4.0) {
						if (bulanime >= 0 && bulanime <= 9) {
							bullet = bullet13;
						}
						if (bulanime >= 0 && bulanime <= 19) {
							bullet = bullet14;
						}
						if (bulanime >= 0 && bulanime <= 29) {
							bullet = bullet15;
						}
						if (bulanime >= 0 && bulanime <= 39) {
							bullet = bullet16;
						}
						if (bulanime >= 0 && bulanime <= 49) {
							bullet = bullet17;
						}
						if (bulanime >= 0 && bulanime <= 59) {
							bullet = bullet18;
						}
					}
					if (THETA == 6.0 / 4.0) {
						if (bulanime >= 0 && bulanime <= 9) {
							bullet = bullet7;
						}
						if (bulanime >= 0 && bulanime <= 19) {
							bullet = bullet8;
						}
						if (bulanime >= 0 && bulanime <= 29) {
							bullet = bullet9;
						}
						if (bulanime >= 0 && bulanime <= 39) {
							bullet = bullet10;
						}
						if (bulanime >= 0 && bulanime <= 49) {
							bullet = bullet11;
						}
						if (bulanime >= 0 && bulanime <= 59) {
							bullet = bullet12;
						}
					}
					if (THETA == 1.0 / 4.0) {
						if (bulanime >= 0 && bulanime <= 9) {
							bullet = bullet19s;
						}
						if (bulanime >= 0 && bulanime <= 19) {
							bullet = bullet20s;
						}
						if (bulanime >= 0 && bulanime <= 29) {
							bullet = bullet21s;
						}
						if (bulanime >= 0 && bulanime <= 39) {
							bullet = bullet22s;
						}
						if (bulanime >= 0 && bulanime <= 49) {
							bullet = bullet23s;
						}
						if (bulanime >= 0 && bulanime <= 59) {
							bullet = bullet24s;
						}
					}
					if (THETA == 3.0 / 4.0) {
						if (bulanime >= 0 && bulanime <= 9) {
							bullet = bullet1s;
						}
						if (bulanime >= 0 && bulanime <= 19) {
							bullet = bullet2s;
						}
						if (bulanime >= 0 && bulanime <= 29) {
							bullet = bullet3s;
						}
						if (bulanime >= 0 && bulanime <= 39) {
							bullet = bullet4s;
						}
						if (bulanime >= 0 && bulanime <= 49) {
							bullet = bullet5s;
						}
						if (bulanime >= 0 && bulanime <= 59) {
							bullet = bullet6s;
						}
					}
					if (THETA == 5.0 / 4.0) {
						if (bulanime >= 0 && bulanime <= 9) {
							bullet = bullet13s;
						}
						if (bulanime >= 0 && bulanime <= 19) {
							bullet = bullet14s;
						}
						if (bulanime >= 0 && bulanime <= 29) {
							bullet = bullet15s;
						}
						if (bulanime >= 0 && bulanime <= 39) {
							bullet = bullet16s;
						}
						if (bulanime >= 0 && bulanime <= 49) {
							bullet = bullet17s;
						}
						if (bulanime >= 0 && bulanime <= 59) {
							bullet = bullet18s;
						}
					}
					if (THETA == 7.0 / 4.0) {
						if (bulanime >= 0 && bulanime <= 9) {
							bullet = bullet7s;
						}
						if (bulanime >= 0 && bulanime <= 19) {
							bullet = bullet8s;
						}
						if (bulanime >= 0 && bulanime <= 29) {
							bullet = bullet9s;
						}
						if (bulanime >= 0 && bulanime <= 39) {
							bullet = bullet10s;
						}
						if (bulanime >= 0 && bulanime <= 49) {
							bullet = bullet11s;
						}
						if (bulanime >= 0 && bulanime <= 59) {
							bullet = bullet12s;
						}
					}
					bulletTheta = (THETA)*M_PI;

					/* Xpos = xpos;
					Ypos = ypos;
					xpos = -32;
					ypos = -32;
					lotatex = xpos * cos(bulletTheta) - ypos * sin(bulletTheta);
					lotatey = ypos * cos(bulletTheta) + ypos * sin(bulletTheta);
					xpos = Xpos + lotatex;
					ypos = Ypos + lotatey;*/

					
							  

					if (preKeys[DIK_SPACE] == 0) {
						for (int i = 0; i < bulcount; i++) {
							bulposX[i] = xpos + 32;
							bulposY[i] = ypos + 40;
						}
						bulcount = 0;
						bulletcount = 0;
					}

					Xvec = xvec;
					Yvec = yvec;
					length = sqrt(xvec * xvec + yvec * yvec);
					if (length != 0.0f) {
						Xvec = Xvec * Xvec / length;
						Yvec = Yvec * Yvec / length;
						if (keys[DIK_A]) {
							Xvec *= -1;
						}
						if (keys[DIK_W]) {
							Yvec *= -1;
						}
					}

					//ボム-------------------------------------------------------------------
					bombcharge += 1;
					bombx = (whalexpos + xpos) / 2;
					bomby = (whaleypos + ypos) / 2;
					bombrange = bomby - whaleypos + 250;
					if (whaleypos + ypos < whalexpos + xpos) {
						bombrange = bombx - whalexpos + 250;
					}
					if (bombcharge ==1999) {
						charge = -1;
					}
					if (bombcharge >= 2000 && bombcharge <= 2001) {
						bombcharge = 2000;
					}

					if (bombcharge == 2000) {
						countbomb = 1;
						
					}

					if (countbomb == 1) {
						if (jikicount >= 0 && jikicount <= 9) {
							jiki = jiki9;
						}
						if (jikicount >= 10 && jikicount <= 19) {
							jiki = jiki10;
						}
						if (jikicount >= 20 && jikicount <= 29) {
							jiki = jiki11;
						}
						if (jikicount >= 30 && jikicount <= 39) {
							jiki = jiki12;
						}
						if (jikicount >= 0 && jikicount <= 9 && keys[DIK_SPACE]) {
							jiki = jiki13;
						}
						if (jikicount >= 10 && jikicount <= 19 && keys[DIK_SPACE]) {
							jiki = jiki14;
						}
						if (jikicount >= 20 && jikicount <= 29 && keys[DIK_SPACE]) {
							jiki = jiki15;
						}
						if (jikicount >= 30 && jikicount <= 39 && keys[DIK_SPACE]) {
							jiki = jiki16;
						}
					}

					if (keys[DIK_B] && preKeys[DIK_B] == 0 && countbomb == 1) {
						countbomb = 2;
						bombcharge = 2002;
						bombSE = -1;
					}
				}

				if (countbomb == 2) {
					bombcharge = 2002;
					bombcount += 1;
					if (jikicount >= 0 && jikicount <= 9&&jikilife==1) {
						jiki = jiki1;
					}
					if (jikicount >= 10 && jikicount <= 19 && jikilife == 1) {
						jiki = jiki2;
					}
					if (jikicount >= 20 && jikicount <= 29 && jikilife == 1) {
						jiki = jiki3;
					}
					if (jikicount >= 30 && jikicount <= 39 && jikilife == 1) {
						jiki = jiki4;
					}
					if (jikicount >= 0 && jikicount <= 9 && keys[DIK_SPACE] && jikilife == 1) {
						jiki = jiki5;
					}
					if (jikicount >= 10 && jikicount <= 19 && keys[DIK_SPACE] && jikilife == 1) {
						jiki = jiki6;
					}
					if (jikicount >= 20 && jikicount <= 29 && keys[DIK_SPACE] && jikilife == 1) {
						jiki = jiki7;
					}
					if (jikicount >= 30 && jikicount <= 39 && keys[DIK_SPACE] && jikilife == 1) {
						jiki = jiki8;
					}
					if (bombcount % 5 == 1) {
						bombcolor -= bombsuke;
					}
				}

				if (bombcount >= 301) {
					countbomb = 0;
					bombcharge = 0;
					bombcount = 0;
					bombcolor = 0x0000FFFF;
				}

				if (countbomb == 2) {
					if (
					  (utubohitx - bombhitx) * (utubohitx - bombhitx) <=
					    (bombrange + 32) * (bombrange + 32) &&
					  (utubohity - bombhity) * (utubohity - bombhity) <=
					    (bombrange + 5) * (bombrange + 5) &&
					  utubolife == 1) {
						utubolife = 0;
					}

					if (samevely == 0 && stagexy.stage2y > -6200) {
						if (
						  (samehitx - bombhitx) * (samehitx - bombhitx) <=
						    (bombrange + 64) * (bombrange + 64) &&
						  (samehity - bombhity) * (samehity - bombhity) <=
						    (bombrange + 22) * (bombrange + 22) &&
						  samelife <= 2) {
							samelife -= 1;
						}
					}

					if (samevelx == 0 && stagexy.stage2y > -6200) {
						if (
						  (samehitx - bombhitx) * (samehitx - bombhitx) <=
						    (bombrange + 18) * (bombrange + 18) &&
						  (samehity - bombhity) * (samehity - bombhity) <=
						    (bombrange + 60) * (bombrange + 60) &&
						  samelife <= 2) {
							samelife -= 1;
						}
					}

					if (
					  (datuhitx - bombhitx) * (datuhitx - bombhitx) <=
					    (bombrange + 5) * (bombrange + 5) &&
					  (datuhity - bombhity) * (datuhity - bombhity) <=
					    (bombrange + 44) * (bombrange + 44)) {
						datulife -= 1;
					}

					if (
					  (hamosuityokuhitx - bombhitx) * (hamosuityokuhitx - bombhitx) <=
					    (bombrange + 5) * (bombrange + 5) &&
					  (hamosuityokuhity - bombhity) * (hamosuityokuhity - bombhity) <=
					    (bombrange + 44) * (bombrange + 44)) {
						hamosuityokulife -= 1;
					}

					if (
					  (hamokunekunehitx - bombhitx) * (hamokunekunehitx - bombhitx) <=
					    (bombrange + 32) * (bombrange + 32) &&
					  (hamokunekunehity - bombhity) * (hamokunekunehity - bombhity) <=
					    (bombrange + 5) * (bombrange + 5)) {
						hamokunekunelife -= 1;
					}
				}
				  
			}
				//背景の影-------------------------------------------------------------
				backcount += 1;
				if (backcount == 120) {
					haikei += 1;
					backcount = 0;
				}
				if (haikei >= 6) {
					haikei = 6;
				}
				unsigned int currentTime = time(nullptr);
				srand(currentTime);

				for (int j = 0; j < haikei; j++) {
					backy[j] -= worldy;
					if (backy[j] == -64) {
						backy[j] = 720;
					}
					if (backy[j] == 720) {
						number = rand();
						haikeinum = number % 4;
						switch (haikeinum) {
						case 0:
							back[j] = back1;
							backx[j] = 0;
							break;
						case 1:
							back[j] = back2;
							backx[j] = 894;
							break;
						case 2:
							back[j] = back3;
							backx[j] = 0;
							break;
						case 3:
							back[j] = back4;
							backx[j] = 894;
							break;
						}
					}
					if (back[j] == back1) {
						backx[j] += 1;
					}
					if (back[j] == back2) {
						backx[j] -= 1;
					}
					if (back[j] == back3) {
						backx[j] += 1;
					}
					if (back[j] == back4) {
						backx[j] -= 1;
					}
					if (backx[j] < -32) {
						backx[j] = -32;
					}
					if (backx[j] < 960) {
						backx[j] = 960;
					}
				}

				if (whalelife == 3) {
				    whale = whale2;
				}
				if (whalelife == 2) {
				    whale = whale3;
				}
				if (whalelife == 1) {
				    whale = whale4;
				}
				if (whalelife == 0) {
				    whale = whale5;
				    stagebgm = -1;
				    Novice::StopAudio(stagebgm);
			    }

				//敵の描写----------------------------------------------------------
				utubocount += 1;
				if (utubocount == 40) {
					utubocount = 0;
				}
				if (utubovelx < 0) {

					if (utubocount >= 0 && utubocount <= 9) {
						utubo = utubo1;
					}
					if (utubocount >= 10 && utubocount <= 19) {
						utubo = utubo2;
					}
					if (utubocount >= 20 && utubocount <= 29) {
						utubo = utubo3;
					}
					if (utubocount >= 30 && utubocount <= 39) {
						utubo = utubo4;
					}
				}
				if (utubovelx > 0) {

					if (utubocount >= 0 && utubocount <= 9) {
						utubo = utubo5;
					}
					if (utubocount >= 10 && utubocount <= 19) {
						utubo = utubo6;
					}
					if (utubocount >= 20 && utubocount <= 29) {
						utubo = utubo7;
					}
					if (utubocount >= 30 && utubocount <= 39) {
						utubo = utubo8;
					}
				}

				samecount += 1;
			    if (samecount == 80) {
				    samecount = 0;
			    }
			    if (samevelx == 0) {
				    if (samecount >= 0 && samecount <= 9) {
					    same = same21;
				    }
				    if (samecount >= 10 && samecount <= 19) {
					    same = same22;
				    }
				    if (samecount >= 20 && samecount <= 29) {
					    same = same23;
				    }
				    if (samecount >= 30 && samecount <= 39) {
					    same = same24;
				    }
				    if (samecount >= 40 && samecount <= 49) {
					    same = same25;
				    }
				    if (samecount >= 50 && samecount <= 59) {
					    same = same26;
				    }
				    if (samecount >= 60 && samecount <= 69) {
					    same = same27;
				    }
				    if (samecount >= 70 && samecount <= 79) {
					    same = same28;
				    }
			    }
				if (samevely == 0) {
					if (samevelx < 0) {
						
						if (samecount >= 0 && samecount <= 7) {
							same = same1;
						}
						if (samecount >= 8 && samecount <= 15) {
							same = same2;
						}
						if (samecount >= 16 && samecount <= 23) {
							same = same3;
						}
						if (samecount >= 24 && samecount <= 31) {
							same = same4;
						}
						if (samecount >= 32 && samecount <= 39) {
							same = same5;
						}
						if (samecount >= 40 && samecount <= 47) {
							same = same6;
						}
						if (samecount >= 48 && samecount <= 55) {
							same = same7;
						}
						if (samecount >= 56 && samecount <= 63) {
							same = same8;
						}
						if (samecount >= 64 && samecount <= 71) {
							same = same9;
						}
						if (samecount >= 72 && samecount <= 79) {
							same = same10;
						}
					}
					if (samevelx > 0) {
						
						if (samecount >= 0 && samecount <= 7) {
							same = same11;
						}
						if (samecount >= 8 && samecount <= 15) {
							same = same12;
						}
						if (samecount >= 16 && samecount <= 23) {
							same = same13;
						}
						if (samecount >= 24 && samecount <= 31) {
							same = same14;
						}
						if (samecount >= 32 && samecount <= 39) {
							same = same15;
						}
						if (samecount >= 40 && samecount <= 47) {
							same = same16;
						}
						if (samecount >= 48 && samecount <= 55) {
							same = same17;
						}
						if (samecount >= 56 && samecount <= 63) {
							same = same18;
						}
						if (samecount >= 64 && samecount <= 71) {
							same = same19;
						}
						if (samecount >= 72 && samecount <= 79) {
							same = same20;
						}
					}
				}

				datucount += 1;
				if (datucount == 30) {
					datucount = 0;
				}
				if (datulife == 1) {
					if (datucount >= 0 && datucount <= 4) {
						datu = datu1;
					}
					if (datucount >= 5 && datucount <= 9) {
						datu = datu2;
					}
					if (datucount >= 10 && datucount <= 14) {
						datu = datu3;
					}
					if (datucount >= 15 && datucount <= 19) {
						datu = datu4;
					}
					if (datucount >= 20 && datucount <= 24) {
						datu = datu5;
					}
					if (datucount >= 25 && datucount <= 29) {
						datu = datu6;
					}
				}
				hamosuityokucount += 1;
				if (hamosuityokucount == 70) {
					hamosuityokucount = 0;
				}
				if (hamosuityokuvely < 0) {
					if (hamosuityokucount >= 0 && hamosuityokucount <= 9) {
						hamosuityoku = hamosuityoku1;
					}
					if (hamosuityokucount >= 10 && hamosuityokucount <= 19) {
						hamosuityoku = hamosuityoku2;
					}
					if (hamosuityokucount >= 20 && hamosuityokucount <= 29) {
						hamosuityoku = hamosuityoku3;
					}
					if (hamosuityokucount >= 30 && hamosuityokucount <= 39) {
						hamosuityoku = hamosuityoku4;
					}
					if (hamosuityokucount >= 40 && hamosuityokucount <= 49) {
						hamosuityoku = hamosuityoku5;
					}
					if (hamosuityokucount >= 50 && hamosuityokucount <= 59) {
						hamosuityoku = hamosuityoku6;
					}
					if (hamosuityokucount >= 60 && hamosuityokucount <= 69) {
						hamosuityoku = hamosuityoku7;
					}
				}
				hamokunekunecount += 1;
				if (hamokunekunecount == 240) {
					hamokunekunecount = 0;
				}
				if (hamokunekunelife ==1) {
					if (hamokunekunecount >= 0 && hamokunekunecount <= 9) {
						hamokunekune = hamokunekune1;
					}
					if (hamokunekunecount >= 10 && hamokunekunecount <= 19) {
						hamokunekune = hamokunekune2;
					}
					if (hamokunekunecount >= 20 && hamokunekunecount <= 29) {
						hamokunekune = hamokunekune3;
					}
					if (hamokunekunecount >= 30 && hamokunekunecount <= 39) {
						hamokunekune = hamokunekune4;
					}
					if (hamokunekunecount >= 40 && hamokunekunecount <= 49) {
						hamokunekune = hamokunekune5;
					}
					if (hamokunekunecount >= 50 && hamokunekunecount <= 59) {
						hamokunekune = hamokunekune6;
					}
					if (hamokunekunecount >= 60 && hamokunekunecount <= 69) {
						hamokunekune = hamokunekune7;
					}
					if (hamokunekunecount >= 70 && hamokunekunecount <= 79) {
						hamokunekune = hamokunekune8;
					}
					if (hamokunekunecount >= 80 && hamokunekunecount <= 89) {
						hamokunekune = hamokunekune9;
					}
					if (hamokunekunecount >= 90 && hamokunekunecount <= 99) {
						hamokunekune = hamokunekune10;
					}
					if (hamokunekunecount >= 100 && hamokunekunecount <= 109) {
						hamokunekune = hamokunekune11;
					}
					if (hamokunekunecount >= 110 && hamokunekunecount <= 119) {
						hamokunekune = hamokunekune12;
					}
					if (hamokunekunecount >= 120 && hamokunekunecount <= 129) {
						hamokunekune = hamokunekune13;
					}
					if (hamokunekunecount >= 130 && hamokunekunecount <= 139) {
						hamokunekune = hamokunekune14;
					}
					if (hamokunekunecount >= 140 && hamokunekunecount <= 149) {
						hamokunekune = hamokunekune15;
					}
					if (hamokunekunecount >= 150 && hamokunekunecount <= 159) {
						hamokunekune = hamokunekune16;
					}
					if (hamokunekunecount >= 160 && hamokunekunecount <= 169) {
						hamokunekune = hamokunekune17;
					}
					if (hamokunekunecount >= 170 && hamokunekunecount <= 179) {
						hamokunekune = hamokunekune18;
					}
					if (hamokunekunecount >= 180 && hamokunekunecount <= 189) {
						hamokunekune = hamokunekune19;
					}
					if (hamokunekunecount >= 190 && hamokunekunecount <= 199) {
						hamokunekune = hamokunekune20;
					}
					if (hamokunekunecount >= 200 && hamokunekunecount <= 209) {
						hamokunekune = hamokunekune21;
					}
					if (hamokunekunecount >= 210 && hamokunekunecount <= 219) {
						hamokunekune = hamokunekune22;
					}
					if (hamokunekunecount >= 220 && hamokunekunecount <= 229) {
						hamokunekune = hamokunekune23;
					}
					if (hamokunekunecount >= 230 && hamokunekunecount <= 239) {
						hamokunekune = hamokunekune24;
					}
				}


				hamosuityokucount += 1;
				if (hamosuityokucount == 70) {
					hamosuityokucount = 0;
				}
				if (hamosuityokulife==1) {
					if (hamosuityokucount >= 0 && hamosuityokucount <= 9) {
						hamosuityoku = hamosuityoku1;
					}
					if (hamosuityokucount >= 10 && hamosuityokucount <= 19) {
						hamosuityoku = hamosuityoku2;
					}
					if (hamosuityokucount >= 20 && hamosuityokucount <= 29) {
						hamosuityoku = hamosuityoku3;
					}
					if (hamosuityokucount >= 30 && hamosuityokucount <= 39) {
						hamosuityoku = hamosuityoku4;
					}
					if (hamosuityokucount >= 40 && hamosuityokucount <= 49) {
						hamosuityoku = hamosuityoku5;
					}
					if (hamosuityokucount >= 50 && hamosuityokucount <= 59) {
						hamosuityoku = hamosuityoku6;
					}
					if (hamosuityokucount >= 60 && hamosuityokucount <= 69) {
						hamosuityoku = hamosuityoku7;
					}
				}
				for (int k = 0; k < tatiuonumber; k++) {
					tatiuocount[k] += 1;
					if (tatiuocount[k] == 240) {
						tatiuocount[k] = 0;
					}
					if (tatiuolife[k] == 1) {
						if (tatiuocount[k] >= 0 && tatiuocount[k] <= 9) {
							tatiuo[k] = tatiuo1;
						}
						if (tatiuocount[k] >= 10 && tatiuocount[k] <= 19) {
							tatiuo[k] = tatiuo2;
						}
						if (tatiuocount[k] >= 20 && tatiuocount[k] <= 29) {
							tatiuo[k] = tatiuo3;
						}
						if (tatiuocount[k] >= 30 && tatiuocount[k] <= 39) {
							tatiuo[k] = tatiuo4;
						}
						if (tatiuocount[k] >= 40 && tatiuocount[k] <= 49) {
							tatiuo[k] = tatiuo5;
						}
						if (tatiuocount[k] >= 50 && tatiuocount[k] <= 59) {
							tatiuo[k] = tatiuo6;
						}
						if (tatiuocount[k] >= 60 && tatiuocount[k] <= 69) {
							tatiuo[k] = tatiuo7;
						}
					}
				}
				//敵のスピード-----------------------------------------------------------
			     if (hamokunekunecount >= 0 && hamokunekunecount <= 69) {
				     hamokunekunevelx = 3;
				     hamokunekunevely = 0;
			     }
			     if (hamokunekunecount >= 70 && hamokunekunecount <= 129) {
				     hamokunekunevelx = 0;
				     hamokunekunevely = -5;
			     }
			     if (hamokunekunecount >= 130 && hamokunekunecount <= 199) {
				     hamokunekunevelx = -3;
				     hamokunekunevely = 0;
			     }
			     if (hamokunekunecount >= 200 && hamokunekunecount <= 239) {
				     hamokunekunevelx = 0;
				     hamokunekunevely = -5;
			     }
			    

				utubox += utubovelx;
			    utuboy += utubovely;
			    samevelx*= sameacc;
			    samevely*= sameacc;
			    samex += samevelx;
			    samey += samevely;
			    datux += datuvelx;
			    datuy += datuvely;
			    hamosuityokux += hamosuityokuvelx;
			    hamosuityokuy += hamosuityokuvely;
			    hamokunekunex += hamokunekunevelx;
			    hamokunekuney += hamokunekunevely;

			    //当たり判定---------------------------------------------------------
				utubohitx = utubox + 32;
				samehitx = samex + 64;
				datuhitx = datux + 16;
				hamosuityokuhitx = hamosuityokux + 16;
				hamokunekunehitx = hamokunekunex + 32;

				utubohity = utuboy + 32;
				samehity = samey + 64;
				datuhity = datuy + 48;
				hamosuityokuhity = hamosuityokuy + 48;
			    hamokunekunehity = hamokunekuney + 32;
			    for (int i = 0; i < bulcount;
			         i++) { //連射機構-------------------------------------------
				    if (keys[DIK_SPACE] == 0) {
					    tamacount[i] = 0;
				    }

				    if (tamacount[i] == 0) {
					    bulposX[i] = xpos + 32;
					    bulposY[i] = ypos + 40;
				    }

				    if (keys[DIK_SPACE]) {
					    bulvelX[i] = 20;
					    bulvelY[i] = 20;
					    tamacount[i] += 1;
					    bulletlife[i] = 1;
				    }

				    if (tamacount[i] == 400) {
					    tamacount[i] = 0;
				    }

				    bulvelX[i] = bulvelX[i] * cosf(bulletTheta);
				    bulvelY[i] = bulvelY[i] * sinf(bulletTheta);

				    bulVelX[i] = bulvelX[i];
				    bulVelY[i] = bulvelY[i];

				    bullength = sqrt(bulvelX[i] * bulvelX[i] + bulvelY[i] * bulvelY[i]);
				    if (bullength != 0.0f) {
					    bulVelX[i] = bulVelX[i] * bulVelX[i] / bullength;
					    bulVelY[i] = bulVelY[i] * bulvelY[i] / bullength;
				    }

				    bulposY[i] += bulvelY[i];
				    bulposX[i] += bulvelX[i];
				    bulhitx[i] = bulposX[i] + 32;
				    bulhity[i] = bulposY[i] + 32;
				    if (keys[DIK_SPACE]) {//bullet=16
					    if ((utubohitx - bulhitx[i]) * (utubohitx - bulhitx[i]) <= 2604 &&
					      (utubohity - bulhity[i]) * (utubohity - bulhity[i]) <= 1041 &&
					      utubolife == 1 && bulletlife[i] == 1) {
						    utubolife = 0;
						    bulletlife[i] = 0;
					    }
					     
					    if (samevely == 0 && stagexy.stage2y > -6200) {
						    if ((samehitx - bulhitx[i]) * (samehitx - bulhitx[i]) <= 6800 &&
						      (samehity - bulhity[i]) * (samehity - bulhity[i]) <= 1844 &&
						      samelife > 0 && bulletlife[i] == 1) {
							    samelife -= 1;
							    bulletlife[i] = 0;
						    }
					    }

					    if (samevelx == 0 && stagexy.stage2y > -6200) {
						    if ((samehitx - bulhitx[i]) * (samehitx - bulhitx[i]) <= 1556 &&
						      (samehity - bulhity[i]) * (samehity - bulhity[i]) <= 6176 &&
						      samelife > 0 && bulletlife[i] == 1) {
							    samelife -= 1;
							    bulletlife[i] = 0;
						    }
					    }
						      

					    if ((datuhitx - bulhitx[i]) * (datuhitx - bulhitx[i]) <= 841 &&
					      (datuhity - bulhity[i]) * (datuhity - bulhity[i]) <= 4000 &&
					      datulife == 1 && bulletlife[i] == 1) {
						    datulife -= 1;
						    bulletlife[i] = 0;
					    }
					      
					    if ((hamosuityokuhitx - bulhitx[i]) * (hamosuityokuhitx - bulhitx[i]) <=841 &&
					      (hamosuityokuhity - bulhity[i]) * (hamosuityokuhity - bulhity[i]) <=4000 &&
					      hamosuityokulife == 1 && bulletlife[i] == 1) {
						    hamosuityokulife -= 1;
						    bulletlife[i] = 0;
					    }
					      

					    if (
					      (hamokunekunehitx - bulhitx[i]) * (hamokunekunehitx - bulhitx[i]) <=2604 &&
					      (hamokunekunehity - bulhity[i]) * (hamokunekunehity - bulhity[i]) <=841 &&
					      hamokunekunelife == 1 && bulletlife[i] == 1) {
						    hamokunekunelife -= 1;
						    bulletlife[i] = 0;
					    }
					        
					        
				    }
			    }

			//クジラとの当たり判定 クジラ＝110　
				
				if ((utubohitx - whalehitx) * (utubohitx - whalehitx) <= 20164 && /*x=32 y=5 */
			      (utubohity - whalehity) * (utubohity - whalehity) <= 13225 && utubolife == 1) {
				    whalelife -= 1;
				    utubolife = 0;
				    SEcount = -1;

			    }
			      
			    if (samevely == 0 && stagexy.stage2y > -6200) {
				    if ((samehitx - whalehitx) * (samehitx - whalehitx) <= 30276 && /*x=64 y=22*/
				      (samehity - whalehity) * (samehity - whalehity) <= 17424 && samelife > 0) {
					    whalelife -= 1;
					    samelife = 0;
					    SEcount = -1;

				    }
			    }

			    if (samevelx == 0 && stagexy.stage2y > -6200) {
				    if (
				      (samehitx - whalehitx) * (samehitx - whalehitx) <= 16384 && /*x=18 y=60 */
				      (samehity - whalehity) * (samehity - whalehity) <= 28900 && samelife > 0) {
					    whalelife -= 1;
					    samelife = 0;
					    SEcount = -1;
				    }
			    }

			    if ((datuhitx - whalehitx) * (datuhitx - whalehitx) <= 13225 && /*x=5 y=44*/
			      (datuhity - whalehity) * (datuhity - whalehity) <= 23716 && datulife == 1) {
				    whalelife -= 1;
				    datulife = 0;
				    SEcount = -1;

			    }
			      
			    if ( (hamosuityokuhitx - whalehitx) * (hamosuityokuhitx - whalehitx) <=13225 && /*x=5 y=44*/
			      (hamosuityokuhity - whalehity) * (hamosuityokuhity - whalehity) <= 23716 &&
			      hamosuityokulife == 1) {
				    whalelife -= 1;
				    hamosuityokulife = 0;
				    SEcount = -1;

			    }
			        
			     
			    if ((hamokunekunehitx - whalehitx) * (hamokunekunehitx - whalehitx) <=20164 && /*x=32 y=5 */
			      (hamokunekunehity - whalehity) * (hamokunekunehity - whalehity) <= 13225 &&
			      hamokunekunelife == 1) {
				    whalelife -= 1;
				    hamokunekunelife = 0;
				    SEcount = -1;

			    }
			        

				//自機との当たり判定＝26------------------------------------------------
			    if((utubohitx - jikihitx) * (utubohitx - jikihitx) <= 3064 && /*x=32 y=5 */
			      (utubohity - jikihity) * (utubohity - jikihity) <= 961 && utubolife == 1) {
				    jikilife = 0;
			    }
			     
			    if (samevely == 0&&stagexy.stage2y>-6200) {
				    if((samehitx - jikihitx) * (samehitx - jikihitx) <= 8100 && /*x=64 y=22*/
				      (samehity - jikihity) * (samehity - jikihity) <= 2304 && samelife > 0) {
					   jikilife = 0;
				    }
				      
			    }
			    if (samevelx == 0 && stagexy.stage2y > -6200) {
				    if ((samehitx - jikihitx) * (samehitx - jikihitx) <= 1764 && /*x=18 y=60 */
				      (samehity - jikihity) * (samehity - jikihity) <= 7396 && samelife > 0) {
					    jikilife = 0;
				    }
			    }
				     
			    if ((datuhitx - jikihitx) * (datuhitx - jikihitx) <= 961 && /*x=5 y=44*/
			      (datuhity - jikihity) * (datuhity - jikihity) <= 4900 && datulife == 1) {
				    jikilife = 0;
			    }
			      

			    if ((hamosuityokuhitx - jikihitx) * (hamosuityokuhitx - jikihitx) <=961 && /*x=5 y=44*/
			      (hamosuityokuhity - jikihity) * (hamosuityokuhity - jikihity) <= 4900 &&
			      hamosuityokulife == 1) {
				    jikilife=0; 
			    }
			      
			        
			    if ((hamokunekunehitx - jikihitx) * (hamokunekunehitx - jikihitx) <=3064 && /*x=32 y=5 */
			      (hamokunekunehity - jikihity) * (hamokunekunehity - jikihity) <= 961 &&
			      hamokunekunelife == 1) {
				    jikilife = 0;
			    }
			      
			for (int k = 0; k < tatiuonumber; k++) {
				    tatiuohitx[k] = tatiuox[k] + 16;
				    tatiuohity[k] = tatiuoy[k] + 48;
				    tatiuoy[k] -= tatiuovely[k];
				    if (
				      (tatiuohitx[k] - whalehitx) * (tatiuohitx[k] - whalehitx) <=
				        20164 && /*x=5 y=44*/
				      (tatiuohity[k] - whalehity) * (tatiuohity[k] - whalehity) <= 13225 &&
				      tatiuolife[k] == 1) {
					    whalelife -= 1;
					    tatiuolife[k] = 0;
					    SEcount = -1;

				    }
				    if (
				      (tatiuohitx[k] - jikihitx) * (tatiuohitx[k] - jikihitx) <= 961 && /*x=5 y=44*/
				      (tatiuohity[k] - jikihity) * (tatiuohity[k] - jikihity) <= 4900 &&
				      tatiuolife[k] == 1) {
					    jikilife = 0;
				    }
				    for (int i = 0; i < bulcount; i++) {
					    if (
					      (tatiuohitx[k] - bulhitx[i]) * (tatiuohitx[k] - bulhitx[i]) <= 841 &&
					      (tatiuohity[k] - bulhity[i]) * (tatiuohity[k] - bulhity[i]) <= 4000) {
						    tatiuolife[k] = 0;
					    }
				    }
				    if (countbomb == 2) {
					    if (
					      (tatiuohitx[k] - bombhitx) * (tatiuohitx[k] - bombhitx) <=
					        (bombrange + 5) * (bombrange + 5) &&
					      (tatiuohity[k] - bombhity) * (tatiuohity[k] - bombhity) <=
					        (bombrange + 44) * (bombrange + 44)) {
						    tatiuolife[k] = 0;
					    }
				    }
			}
			   
				 
			if (jikilife == 0) {
				    jikihitcount += 1;
			}
			if (jikihitcount > 0 && jikicount % 20 >= 0 && jikicount % 20 <= 9) {
				jiki = 0;
			}
			if (jikihitcount > 0 && jikicount % 20 >= 10 && jikicount % 20 <= 19) {
				jiki = jiki1;
			}
			if (jikihitcount == 90) {
				    jikilife = 1;
				    jikihitcount = 0;
			}

			if (stagecount == 1 && scroll==480) { /*ステージ１・深さ100m－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－*/
				if (whalelife > 0) {
					worldy = 1;
				}
				if (whalelife <= 0) {
					worldy = 0;
				}
				if (stagexy.stage1y == -1) {
					bgmcount = -1;
				}
				stagexy.stage1y -= worldy;
				if (stagexy.stage1y <= -3780) {
					stagexy.stage1y = -3780;
				}
				
				if (stagexy.stage1y == -60) {
					hamosuityokux = 464;
					hamosuityokuy = 720;
					hamosuityokuvely = -7;
					hamosuityokulife = 1;
				}
				if (stagexy.stage1y == -180) {
					hamokunekunex = 300;
					hamokunekuney = 720;
					hamokunekunelife = 1;
				}
				if (stagexy.stage1y == -300) {
					tatiuonumber = 5;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuolife[2] = 1;
					tatiuolife[3] = 1;
					tatiuolife[4] = 1;
					tatiuox[0] = 500;
					tatiuoy[0] = 720;
					tatiuox[1] = 200;
					tatiuoy[1] = 920;
					tatiuox[2] = 600;
					tatiuoy[2] = 1180;
					tatiuox[3] = 700;
					tatiuoy[3] = 1060;
					tatiuox[4] = 500;
					tatiuoy[4] = 1340;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuovely[2] = 5;
					tatiuovely[3] = 5;
					tatiuovely[4] = 5;
				}
				if (stagexy.stage1y == -500) {
					utubox = -130;
					utubovelx = 5;
					utuboy = whaleypos + 100;
					utubolife = 1;
				}
				if (stagexy.stage1y == -700) {
					tatiuonumber = 5;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuolife[2] = 1;
					tatiuolife[3] = 1;
					tatiuolife[4] = 1;
					tatiuox[0] = 200;
					tatiuoy[0] = 720;
					tatiuox[1] = 350;
					tatiuoy[1] = 920;
					tatiuox[2] = 500;
					tatiuoy[2] = 1180;
					tatiuox[3] = 650;
					tatiuoy[3] = 1060;
					tatiuox[4] = 800;
					tatiuoy[4] = 1340;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuovely[2] = 5;
					tatiuovely[3] = 5;
					tatiuovely[4] = 5;
				}

				if (stagexy.stage1y == -1000) {
					datux = xpos + 32;
					datuy = 730;
					datuvely = -14;
					datulife = 1;
				}

				if (stagexy.stage1y == -1200) {
					hamokunekunex = xpos + 30;
					hamokunekuney = 720;
					hamokunekunelife = 1;

					hamosuityokux = 464;
					hamosuityokuy = 750;
					hamosuityokulife = 1;
				}
				if (stagexy.stage1y == -1500) {
					datux = xpos + 32;
					datuy = 730;
					datuvely = -14;
					datulife = 1;
				}

				if (stagexy.stage1y == -1800) {
					samex = whalexpos + 100;
					samey = 800;
					samevelx = 0;
					samevely = -7;
					samelife = 2;
				}

				if (stagexy.stage1y == -2100) {
					hamosuityokux = 464;
					hamosuityokuy = 720;
					hamosuityokulife = 1;
					samex = whalexpos + 100;
					samey = 900;
					samevelx = 0;
					samevely = -7;
					samelife = 2;
				}
				if (stagexy.stage1y == -2400) {
					hamokunekunex = 464;
					hamokunekuney = 720;
					hamokunekunelife = 1;
					samex = 1000;
					samey = whaleypos + 100;
					samevelx = -7;
					samevely = 0;
					samelife = 2;
				}
				if (stagexy.stage1y == -2700) {
					tatiuonumber = 5;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuolife[2] = 1;
					tatiuolife[3] = 1;
					tatiuolife[4] = 1;
					tatiuox[0] = 500;
					tatiuoy[0] = 720;
					tatiuox[1] = 200;
					tatiuoy[1] = 1020;
					tatiuox[2] = 600;
					tatiuoy[2] = 1320;
					tatiuox[3] = 700;
					tatiuoy[3] = 1620;
					tatiuox[4] = 500;
					tatiuoy[4] = 1920;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuovely[2] = 5;
					tatiuovely[3] = 5;
					tatiuovely[4] = 5;
					utubox = 1000;
					utubovelx = -5;
					utuboy = whaleypos + 100;
					utubolife = 1;
				}
				if (stagexy.stage1y == -3000) {
					utubox = -130;
					utuboy = whaleypos + 100;
					utubolife = 1;
				}
				if (stagexy.stage1y == -3400) {
					samex = whalexpos + 100;
					samey = 720;
					samevelx = 0;
					samevely = -7;
					samelife = 2;
				}

				if (stagexy.stage1y == -3779) {
					tatiuonumber = 20;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuolife[2] = 1;
					tatiuolife[3] = 1;
					tatiuolife[4] = 1;
					tatiuolife[5] = 1;
					tatiuolife[6] = 1;
					tatiuolife[7] = 1;
					tatiuolife[8] = 1;
					tatiuolife[9] = 1;
					tatiuolife[10] = 1;
					tatiuolife[11] = 1;
					tatiuolife[12] = 1;
					tatiuolife[13] = 1;
					tatiuolife[14] = 1;
					tatiuolife[15] = 1;
					tatiuolife[16] = 1;
					tatiuolife[17] = 1;
					tatiuolife[18] = 1;
					tatiuolife[19] = 1;
					
					tatiuox[0] = 500;
					tatiuoy[0] = 720;
					tatiuox[1] = 200;
					tatiuoy[1] = 800;
					tatiuox[2] = 600;
					tatiuoy[2] = 880;
					tatiuox[3] = 400;
					tatiuoy[3] = 960;
					tatiuox[4] = 500;
					tatiuoy[4] = 840;
					tatiuox[5] = 500;
					tatiuoy[5] = 720;
					tatiuox[6] = 200;
					tatiuoy[6] = 800;
					tatiuox[7] = 600;
					tatiuoy[7] = 880;
					tatiuox[8] = 400;
					tatiuoy[8] = 960;
					tatiuox[9] = 500;
					tatiuoy[9] = 840;
					tatiuox[10] = 500;
					tatiuoy[10] = 720;
					tatiuox[11] = 200;
					tatiuoy[11] = 1020;
					tatiuox[12] = 600;
					tatiuoy[12] = 1320;
					tatiuox[13] = 400;
					tatiuoy[13] = 1620;
					tatiuox[14] = 500;
					tatiuoy[14] = 1920;
					tatiuox[15] = 500;
					tatiuoy[15] = 2220;
					tatiuox[16] = 200;
					tatiuoy[16] = 2520;
					tatiuox[17] = 600;
					tatiuoy[17] = 2820;
					tatiuox[18] = 400;
					tatiuoy[18] = 3120;
					tatiuox[19] = 500;
					tatiuoy[19] = 3420;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuovely[2] = 5;
					tatiuovely[3] = 5;
					tatiuovely[4] = 5;
					tatiuovely[5] = 5;
					tatiuovely[6] = 5;
					tatiuovely[7] = 5;
					tatiuovely[8] = 5;
					tatiuovely[9] = 5;
					tatiuovely[10] = 5;
					tatiuovely[11] = 5;
					tatiuovely[12] = 5;
					tatiuovely[13] = 5;
					tatiuovely[14] = 5;
					tatiuovely[15] = 5;
					tatiuovely[16] = 5;
					tatiuovely[17] = 5;
					tatiuovely[18] = 5;
					tatiuovely[19] = 5;
				}

				
				if (tatiuoy[19] <= -200 && massagesuke < 0xFFFFFFFF && whalelife > 0) {
					stageclear = 1;
					if (massagesuke < 0xFFFFFFFF) {
						massagesuke += 0x00000001;
					}
					if (massagesuke == 0xFFFFFFFF) {
						CUC = 2;
					}
				}
			}

			if (stagecount == 2 && scroll == 480) { /*ステージ2・深さ600m*/
				if (whalelife > 0) {
					worldy = 1;
				}
				if (whalelife <= 0) {
					worldy = 0;
				}
				if (stagexy.stage2y == -1) {
					bgmcount = -1;
				}
				stagexy.stage2y -= worldy;
				if (stagexy.stage2y <= -6280) {
					stagexy.stage2y = -6280;
				}
				if (stagexy.stage2y == -100) {
					hamokunekunex = xpos + 30;
					hamokunekuney = 720;
					hamokunekunelife = 1;

					hamosuityokux = 464;
					hamosuityokuy = 750;
					hamosuityokuvely = -7;
					hamosuityokulife = 1;
				}
				if (stagexy.stage2y == 500) {
					utubox = 1000;
					utubovelx = -5;
					utuboy = whaleypos + 100;
					utubolife = 1;

					hamosuityokux = 344;
					hamosuityokuy = 750;
					hamosuityokuvely = -7;
					hamosuityokulife = 1;
				}

				if (stagexy.stage2y == -900) {
					samex = whalexpos + 100;
					samey = 720;
					samevelx = 0;
					samevely = -7;
					samelife = 2;

					datux = xpos + 32;
					datuy = 730;
					datuvely = -14;
					datulife = 1;

				}

				if (stagexy.stage2y == -1300) {
					datux = xpos + 32;
					datuy = 730;
					datuvely = -14;
					datulife = 1;

					utubox = 1000;
					utubovelx = -5;
					utuboy = whaleypos + 100;
					utubolife = 1;
				}

				if (stagexy.stage2y == -1500) {
					tatiuonumber = 19;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuolife[2] = 1;
					tatiuolife[3] = 1;
					tatiuolife[4] = 1;
					tatiuolife[5] = 1;
					tatiuolife[6] = 1;
					tatiuolife[7] = 1;
					tatiuolife[8] = 1;
					tatiuolife[9] = 1;
					tatiuolife[10] = 1;
					tatiuolife[11] = 1;
					tatiuolife[12] = 1;
					tatiuolife[13] = 1;
					tatiuolife[14] = 1;
					tatiuolife[15] = 1;
					tatiuolife[16] = 1;
					tatiuolife[17] = 1;
					tatiuolife[18] = 1;

					tatiuox[0] = 50;
					tatiuoy[0] = 720;
					tatiuox[1] = 100;
					tatiuoy[1] = 800;
					tatiuox[2] = 150;
					tatiuoy[2] = 880;
					tatiuox[3] = 200;
					tatiuoy[3] = 960;
					tatiuox[4] = 250;
					tatiuoy[4] = 840;
					tatiuox[5] = 300;
					tatiuoy[5] = 720;
					tatiuox[6] = 350;
					tatiuoy[6] = 800;
					tatiuox[7] = 400;
					tatiuoy[7] = 880;
					tatiuox[8] = 450;
					tatiuoy[8] = 960;
					tatiuox[9] = 500;
					tatiuoy[9] = 840;
					tatiuox[10] = 550;
					tatiuoy[10] = 720;
					tatiuox[11] = 600;
					tatiuoy[11] = 1020;
					tatiuox[12] = 650;
					tatiuoy[12] = 1320;
					tatiuox[13] = 700;
					tatiuoy[13] = 1620;
					tatiuox[14] = 750;
					tatiuoy[14] = 1920;
					tatiuox[15] = 800;
					tatiuoy[15] = 2220;
					tatiuox[16] = 850;
					tatiuoy[16] = 2520;
					tatiuox[17] = 900;
					tatiuoy[17] = 2820;
					tatiuox[18] = 950;
					tatiuoy[18] = 3120;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuovely[2] = 5;
					tatiuovely[3] = 5;
					tatiuovely[4] = 5;
					tatiuovely[5] = 5;
					tatiuovely[6] = 5;
					tatiuovely[7] = 5;
					tatiuovely[8] = 5;
					tatiuovely[9] = 5;
					tatiuovely[10] = 5;
					tatiuovely[11] = 5;
					tatiuovely[12] = 5;
					tatiuovely[13] = 5;
					tatiuovely[14] = 5;
					tatiuovely[15] = 5;
					tatiuovely[16] = 5;
					tatiuovely[17] = 5;
					tatiuovely[18] = 5;
				}
				if (stagexy.stage2y == -2300) {
					datux = xpos + 32;
					datuy = 730;
					datuvely = -14;
					datulife = 1;
				}

				if (stagexy.stage2y == -3000) {
					tatiuonumber = 19;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuolife[2] = 1;
					tatiuolife[3] = 1;
					tatiuolife[4] = 1;
					tatiuolife[5] = 1;
					tatiuolife[6] = 1;
					tatiuolife[7] = 1;
					tatiuolife[8] = 1;
					tatiuolife[9] = 1;
					tatiuolife[10] = 1;
					tatiuolife[11] = 1;
					tatiuolife[12] = 1;
					tatiuolife[13] = 1;
					tatiuolife[14] = 1;
					tatiuolife[15] = 1;
					tatiuolife[16] = 1;
					tatiuolife[17] = 1;
					tatiuolife[18] = 1;

					tatiuox[0] = 50;
					tatiuoy[0] = 720;
					tatiuox[1] = 100;
					tatiuoy[1] = 800;
					tatiuox[2] = 150;
					tatiuoy[2] = 880;
					tatiuox[3] = 200;
					tatiuoy[3] = 960;
					tatiuox[4] = 250;
					tatiuoy[4] = 840;
					tatiuox[5] = 300;
					tatiuoy[5] = 720;
					tatiuox[6] = 350;
					tatiuoy[6] = 800;
					tatiuox[7] = 400;
					tatiuoy[7] = 880;
					tatiuox[8] = 450;
					tatiuoy[8] = 960;
					tatiuox[9] = 500;
					tatiuoy[9] = 840;
					tatiuox[10] = 550;
					tatiuoy[10] = 720;
					tatiuox[11] = 600;
					tatiuoy[11] = 1020;
					tatiuox[12] = 650;
					tatiuoy[12] = 1320;
					tatiuox[13] = 700;
					tatiuoy[13] = 1620;
					tatiuox[14] = 750;
					tatiuoy[14] = 1920;
					tatiuox[15] = 800;
					tatiuoy[15] = 2220;
					tatiuox[16] = 850;
					tatiuoy[16] = 2520;
					tatiuox[17] = 900;
					tatiuoy[17] = 2820;
					tatiuox[18] = 950;
					tatiuoy[18] = 3120;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuovely[2] = 5;
					tatiuovely[3] = 5;
					tatiuovely[4] = 5;
					tatiuovely[5] = 5;
					tatiuovely[6] = 5;
					tatiuovely[7] = 5;
					tatiuovely[8] = 5;
					tatiuovely[9] = 5;
					tatiuovely[10] = 5;
					tatiuovely[11] = 5;
					tatiuovely[12] = 5;
					tatiuovely[13] = 5;
					tatiuovely[14] = 5;
					tatiuovely[15] = 5;
					tatiuovely[16] = 5;
					tatiuovely[17] = 5;
					tatiuovely[18] = 5;
				}
				if (stagexy.stage2y == -4400) {
					samex = whalexpos + 100;
					samey = 720;
					samevelx = 0;
					samevely = -7;
					samelife = 2;
				}
				if (stagexy.stage2y == -4700) {
					samex = 1000;
					samey = whaleypos + 100;
					samevelx = -7;
					samevely = 0;
					samelife = 2;
				}
				if (stagexy.stage2y == -5100) {
					samex = -70;
					samey = whaleypos + 100;
					samevelx = 7;
					samevely = 0;
					samelife = 2;
				}
				if (stagexy.stage2y == -5400) {
					samex = 1000;
					samey = whaleypos + 100;
					samevelx = -7;
					samevely = 0;
					samelife = 2;
				}
				if (stagexy.stage2y == -5700) {
					samex = -70;
					samey = whaleypos + 100;
					samevelx = 7;
					samevely = 0;
					samelife = 2;
				}

				if (stagexy.stage2y == -6200) {
					samex =288;
					samey = 720;
					samevelx = 0;
					samevely = -4;
					samelife = 60;
				}
				if (stagexy.stage2y <= -6200) {
					samehitx = samex + 192;
					samehity = samey + 192;

					if (samevelx == 0) {
						if (
						  (samehitx - jikihitx) * (samehitx - jikihitx) <= 17956 && /*x=108 y=360 jiki=26*/
						  (samehity - jikihity) * (samehity - jikihity) <= 148996 && samelife > 0) {
							jikilife = 0;
						}
					}

					if (samevelx == 0) {
						if (
						  (samehitx - whalehitx) * (samehitx - whalehitx) <= 51984 && /* whale=120*/
						  (samehity - whalehity) * (samehity - whalehity) <= 230400 &&
						  samelife > 0) {
							whalelife = 0;
							SEcount = -1;
						}
					}
					if (samevelx == 0) {
						if (
						  (samehitx - bombhitx) * (samehitx - bombhitx) <=
						    (bombrange + 108) * (bombrange + 108) &&
						  (samehity - bombhity) * (samehity - bombhity) <=
						    (bombrange + 360) * (bombrange + 360) &&
						  samelife <= 2) {
							samelife -= 1;
						}
					}
					for (int i = 0; i < bulcount;i++) {
						if (keys[DIK_SPACE]) {
							if (samevelx == 0) {
								if ((samehitx - bulhitx[i]) * (samehitx - bulhitx[i]) <= 15376 &&
								  (samehity - bulhity[i]) * (samehity - bulhity[i]) <= 141376 &&
								  samelife > 0 && bulletlife[i] == 1) {
									samelife -= 1;
									bulletlife[i] = 0;
								}
							}
						}
					}
					if (samelife <= 0) {
						stageclear = 1;
						if (massagesuke < 0xFFFFFFFF) {
							massagesuke += 0x00000001;
						}
						if (massagesuke == 0xFFFFFFFF) {
							CUC = 2;
						}
					}
					if (samelife > 0 && stagexy.stage2y <= -6280 && samey <= -600) {
						stageclear = 1;
						if (massagesuke < 0xFFFFFFFF) {
							massagesuke += 0x00000001;
						}
						if (massagesuke == 0xFFFFFFFF) {
							CUC = 2;
						}
					}
				}
			}
			if (stagecount == 3 && scroll == 480) { /*ステージ3・深さ2000m*/
				if (whalelife > 0) {
					worldy = 1;
				}
				if (whalelife <= 0) {
					worldy = 0;
				}
				if (stagexy.stage3y == -1) {
					bgmcount = -1;
				}
				stagexy.stage3y -= worldy;
				if (stagexy.stage3y <= -8280) {
					stagexy.stage3y = -8280;
				}
				if (stagexy.stage3y == -300) {
					samex = whalexpos + 100;
					samey = 720;
					samevelx = 0;
					samevely = -7;
					samelife = 3;
				}
				if (stagexy.stage3y == -300) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 7;
					tatiuovely[1] = 7;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 7;

				}
				if(stagexy.stage3y == -500) {
					samex = 1000;
					samey = whaleypos - 20;
					samevelx = 7;
					samevely = 0;
					samelife = 3;
				}
				if (stagexy.stage3y == -600) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;

				}
				if (stagexy.stage3y == -700) {
					utubox = -80;
					utubovelx = 5;
					utuboy = whaleypos + 100;
					utubolife = 1;
				}
				if (stagexy.stage3y == -900) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;

				}
				if (stagexy.stage3y == -1200) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;

				}
				if (stagexy.stage3y == -1400) {
					samex = 1000;
					samey = whaleypos + 150;
					samevelx = -7;
					samevely = 0;
					samelife = 2;
				}

				if (stagexy.stage3y == -1500) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;

				}
				if (stagexy.stage3y == -1700) {
					samex = -30;
					samey = whaleypos + 100;
					samevelx = 7;
					samevely = 0;
					samelife = 2;
				}

				if (stagexy.stage3y == -1800) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;

				}
				if (stagexy.stage3y == -2100) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;

				}
				if (stagexy.stage3y == -2300) {
					samex = whalexpos + 200;
					samey = 720;
					samevelx = 0;
					samevely = -7;
					samelife = 3;
				}

				if (stagexy.stage3y == -2400) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
				}
				if (stagexy.stage3y == -2500) {
					hamokunekunex = 400;
					hamokunekuney = 720;
					hamokunekunelife = 1;
				}
				if (stagexy.stage3y == -2700) {
					tatiuonumber = 5;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuolife[2] = 1;
					tatiuolife[3] = 1;
					tatiuolife[4] = 1;
					tatiuox[0] = 200;
					tatiuoy[0] = 720;
					tatiuox[1] = 300;
					tatiuoy[1] = 820;
					tatiuox[2] = 400;
					tatiuoy[2] = 920;
					tatiuox[3] = 500;
					tatiuoy[3] = 1020;
					tatiuox[4] = 600;
					tatiuoy[4] = 1120;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuovely[2] = 5;
					tatiuovely[3] = 5;
					tatiuovely[4] = 5;
					samex = whalexpos + 300;
					samey = 720;
					samevelx = 0;
					samevely = -7;
					samelife = 2;
				}
				if (stagexy.stage3y == -3000) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
				}
				if (stagexy.stage3y == -3200) {
					hamokunekunex = 500;
					hamokunekuney = 820;
					hamokunekunelife = 1;
				}

				if (stagexy.stage3y == -3300) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
					samex = whalexpos + 300;
					samey = 720;
					samevelx = 0;
					samevely = -7;
					samelife = 2;
				}
				if (stagexy.stage3y == -3600) {
					tatiuonumber = 20;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuolife[2] = 1;
					tatiuolife[3] = 1;
					tatiuolife[4] = 1;
					tatiuolife[5] = 1;
					tatiuolife[6] = 1;
					tatiuolife[7] = 1;
					tatiuolife[8] = 1;
					tatiuolife[9] = 1;
					tatiuolife[10] = 1;
					tatiuolife[11] = 1;
					tatiuolife[12] = 1;
					tatiuolife[13] = 1;
					tatiuolife[14] = 1;
					tatiuolife[15] = 1;
					tatiuolife[16] = 1;
					tatiuolife[17] = 1;
					tatiuolife[18] = 1;
					tatiuolife[19] = 1;

					tatiuox[0] = 900;
					tatiuoy[0] = 720;
					tatiuox[1] = 840;
					tatiuoy[1] = 800;
					tatiuox[2] = 780;
					tatiuoy[2] = 880;
					tatiuox[3] = 720;
					tatiuoy[3] = 960;
					tatiuox[4] = 660;
					tatiuoy[4] = 840;
					tatiuox[5] = 600;
					tatiuoy[5] = 720;
					tatiuox[6] = 540;
					tatiuoy[6] = 800;
					tatiuox[7] = 480;
					tatiuoy[7] = 880;
					tatiuox[8] = 420;
					tatiuoy[8] = 960;
					tatiuox[9] = 360;
					tatiuoy[9] = 840;
					tatiuox[10] = 300;
					tatiuoy[10] = 720;
					tatiuox[11] = 240;
					tatiuoy[11] = 1020;
					tatiuox[12] = 180;
					tatiuoy[12] = 1320;
					tatiuox[13] = 120;
					tatiuoy[13] = 1620;
					tatiuox[14] = 60;
					tatiuoy[14] = 1920;
					tatiuox[15] = 0;
					tatiuoy[15] = 2220;
					tatiuox[16] = 60;
					tatiuoy[16] = 2520;
					tatiuox[17] = 120;
					tatiuoy[17] = 2820;
					tatiuox[18] = 180;
					tatiuoy[18] = 3120;
					tatiuox[19] = 240;
					tatiuoy[19] = 3420;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuovely[2] = 5;
					tatiuovely[3] = 5;
					tatiuovely[4] = 5;
					tatiuovely[5] = 5;
					tatiuovely[6] = 5;
					tatiuovely[7] = 5;
					tatiuovely[8] = 5;
					tatiuovely[9] = 5;
					tatiuovely[10] = 5;
					tatiuovely[11] = 5;
					tatiuovely[12] = 5;
					tatiuovely[13] = 5;
					tatiuovely[14] = 5;
					tatiuovely[15] = 5;
					tatiuovely[16] = 5;
					tatiuovely[17] = 5;
					tatiuovely[18] = 5;
					tatiuovely[19] = 5;
					samex = whalexpos + 300;
					samey = 720;
					samevelx = 0;
					samevely = -7;
					samelife = 2;
				}
				if (stagexy.stage3y == -4000) {
					hamosuityokux = 564;
					hamosuityokuy = 750;
					hamosuityokuvely = -7;
					hamosuityokulife = 1;
				}
				if (stagexy.stage3y == -4200) {
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
				}
				if (stagexy.stage3y == -4400) {
					utubox = -80;
					utubovelx = 5;
					utuboy = whaleypos + 100;
					utubolife = 1;
				}

				if (stagexy.stage3y == -4500) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
					samex = 1000;
					samey = whaleypos + 150;
					samevelx = -7;
					samevely = 0;
					samelife = 2;
				}
				if (stagexy.stage3y == -4800) {
					tatiuonumber = 4;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[3] = 5;
					tatiuolife[3] = 1;
					tatiuox[3] = whalexpos + 250;
					tatiuoy[3] = 1020;
					tatiuovely[3] = 5;
				}
				if (stagexy.stage3y == -5100) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
					samex = whalexpos + 300;
					samey = 720;
					samevelx = 0;
					samevely = -7;
					samelife = 2;
				}
				if (stagexy.stage3y == -5200) {
					utubox = -80;
					utubovelx = 5;
					utuboy = whaleypos + 100;
					utubolife = 1;
				}

				if (stagexy.stage3y == -5400) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
				}
				if (stagexy.stage3y == -5500) {
					hamosuityokux = 264;
					hamosuityokuy = 750;
					hamosuityokuvely = -7;
					hamosuityokulife = 1;
				}
				if (stagexy.stage3y == -5700) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
					samex = whalexpos + 300;
					samey = 720;
					samevelx = 0;
					samevely = -7;
					samelife = 2;
				}
				if (stagexy.stage3y == -6000) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
				}
				if (stagexy.stage3y == -6100) {
					hamosuityokux = 364;
					hamosuityokuy = 750;
					hamosuityokuvely = -7;
					hamosuityokulife = 1;
				}
				if (stagexy.stage3y == -6300) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
					samex = -100;
					samey = whaleypos - 50;
					samevelx = 7;
					samevely = 0;
					samelife = 2;
				}

				if (stagexy.stage3y == -6400) {
				hamosuityokux = 564;
				hamosuityokuy = 750;
				hamosuityokuvely = -7;
				hamosuityokulife = 1;
				}

				if (stagexy.stage3y == -6600) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
				}
				if (stagexy.stage3y == -6700) {
					hamosuityokux = 264;
					hamosuityokuy = 850;
					hamosuityokuvely = -7;
					hamosuityokulife = 1;
					hamokunekunex = 300;
					hamokunekuney = 770;
					hamokunekunelife = 1;
				}

				if (stagexy.stage3y == -6900) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
					samex = 1000;
					samey = whaleypos + 100;
					samevelx = 7;
					samevely = 0;
					samelife = 2;
				}
				if (stagexy.stage3y == -7000) {
					utubox = -80;
					utubovelx = 5;
					utuboy = whaleypos + 100;
					utubolife = 1;
				}
				if (stagexy.stage3y == -7200) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
				}
				if (stagexy.stage3y == -7300) {
					utubox = 980;
					utubovelx = -5;
					utuboy = whaleypos + 100;
					utubolife = 1;
					hamosuityokux = 464;
					hamosuityokuy = 750;
					hamosuityokuvely = -7;
					hamosuityokulife = 1;

				}

				if (stagexy.stage3y == -7500) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
				}

				if (stagexy.stage3y == -7800) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
					samex = whalexpos + 300;
					samey = 720;
					samevelx = 0;
					samevely = -7;
					samelife = 2;
					utubox = -80;
					utubovelx = 5;
					utuboy = whaleypos + 100;
					utubolife = 1;
				}
				if (stagexy.stage3y == -8100) {
					tatiuonumber = 3;
					tatiuolife[0] = 1;
					tatiuolife[1] = 1;
					tatiuox[0] = whalexpos + 200;
					tatiuoy[0] = 720;
					tatiuox[1] = whalexpos - 50;
					tatiuoy[1] = 820;
					tatiuovely[0] = 5;
					tatiuovely[1] = 5;
					tatiuolife[2] = 1;
					tatiuox[2] = whalexpos + 250;
					tatiuoy[2] = 920;
					tatiuovely[2] = 5;
				}
				if (stagexy.stage3y == -8200) {
					samex = whalexpos + 100;
					samey = 720;
					samevelx = 0;
					samevely = -1;
					samelife = 60;
				}
				if (stagexy.stage3y == -8280) {
					samevely = -10;
				}
				
				if (samelife > 0 && stagexy.stage3y <= -8280 && samey <= -100) {
					stageclear = 1;
					if (massagesuke < 0xFFFFFFFF) {
						massagesuke += 0x00000001;
					}
					if (massagesuke == 0xFFFFFFFF) {
						CUC = 2;
					}
				}
			} 
	    }
		// gameover-------------------------------------------------------------
		if (whalelife <= 0) {
			whalelife = 0;
			Novice::StopAudio(stagebgm);
			stagebgm = -1;
		}
		if (whalelife == 0) {
			worldy = 0;
			Novice::StopAudio(bgmcount);
			if (massagesuke < 0xFFFFFFFF) {
				massagesuke += 0x00000001;
			}
			if (massagesuke == 0xFFFFFFFF) {
				CUC = 2;
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから-------------------------------------------------------------------------------------------------
		///
		
		
		
		if (scene == 0) {
			if (Novice::IsPlayingAudio(bgmcount) == 0 && bgmcount == -1 && CUC == 0) {
				bgmcount = Novice::PlayAudio(bgm0, true, 0.5f);
			}
			Novice::DrawSprite(
			  titlexy.titlebgX, titlexy.titlebgY, title.titlebg, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(
			  titlexy.titlenameX, titlexy.titlenameY, title.titlename, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(
			  titlexy.howtoX, titlexy.howtoY, title.howto, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(
			  titlexy.selectbgX, titlexy.selectbgY, title.selectbg, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(
			  titlexy.SELECTX, titlexy.SELECTY, title.SELECT, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(
			  titlexy.select1X, titlexy.select1Y, title.select1, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(
			  titlexy.select2X, titlexy.select2Y, title.select2, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(
			  titlexy.select3X, titlexy.select3Y, title.select3, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(titlexy.backX, titlexy.backY, title.back, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(titlexy.fishX, titlexy.fishY, title.fish, 1, 1, 0.0f, 0xFFFFFFFF);
			if (Novice::IsPlayingAudio(sound1) == 0 && SEcount == -1) {
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
					SEcount = Novice::PlayAudio(sound1, false, 0.5f);
				}
			}
		}	
		
		if (Novice::IsPlayingAudio(sound3) == 0 && SEcount == -1) {
			if (babbley<=719) {
				SEcount = Novice::PlayAudio(sound3, false, 0.8f);
			}
		}
		

		if (scene == 1) {
			if (Novice::IsPlayingAudio(stagebgm) == 0 && Novice::IsPlayingAudio(bgm1) == 0 &&
			  stagebgm == -1) {
				if (stagecount == 1 && scroll >= 480 && stagexy.stage1y == -1) {
					stagebgm = Novice::PlayAudio(bgm1, true, 0.5f);
				}
			}
			  
			if (Novice::IsPlayingAudio(stagebgm) == 0 && Novice::IsPlayingAudio(bgm2) == 0 &&
			  stagebgm == -1) {
				if (stagecount == 2 && scroll >= 480 && stagexy.stage2y == -1) {
					stagebgm = Novice::PlayAudio(bgm2, true, 0.5f);
				}
			}
			  
			if (Novice::IsPlayingAudio(stagebgm) == 0 && Novice::IsPlayingAudio(bgm3) == 0 &&
			  stagebgm == -1) {
				if (stagecount == 3 && scroll >= 480 && stagexy.stage3y == -1) {
					stagebgm = Novice::PlayAudio(bgm3, true, 0.5f);
				}
			}

			if (Novice::IsPlayingAudio(SEcount) == 0 && SEcount == -1) {
					SEcount = Novice::PlayAudio(damagese, false, 0.5f);
			}  
			
			if (stagecount == 1) {
				Novice::DrawSprite(
				  stagexy.stage1x, stagexy.stage1y, stage.stage1, 1, 1, 0.0f, 0xFFFFFFFF);
			}
			if (stagecount == 2) {
				Novice::DrawSprite(
				  stagexy.stage2x, stagexy.stage2y, stage.stage2, 1, 1, 0.0f, 0xFFFFFFFF);
			}
			if (stagecount == 3) {
				Novice::DrawSprite(
				  stagexy.stage3x, stagexy.stage3y, stage.stage3, 1, 1, 0.0f, 0xFFFFFFFF);
			}
			for (int i = 0; i < haikei; i++) {
				Novice::DrawSprite(backx[i], backy[i], back[i], 1, 1, 0.0f, 0xFFFFFFFF);
			}


			if (bombcount > 0 && bombcount < 301) {
				Novice::DrawEllipse(
				  bombx, bomby, bombrange, bombrange, 0.0f, bombcolor, kFillModeWireFrame);
				if (bombcount > 1 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 1, bombrange - 1, 0.0f, 0x0100FEFF,
					  kFillModeWireFrame);
				}
				if (bombcount > 2 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 2, bombrange - 2, 0.0f,
					  bombcolor - bombblue + bombred, kFillModeWireFrame);
				}
				if (bombcount > 3 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 3, bombrange - 3, 0.0f,
					  bombcolor - bombblue * 2 + bombred * 2, kFillModeWireFrame);
				}
				if (bombcount > 4 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 4, bombrange - 4, 0.0f,
					  bombcolor - bombblue * 3 + bombred * 3, kFillModeWireFrame);
				}
				if (bombcount > 5 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 5, bombrange - 5, 0.0f,
					  bombcolor - bombblue * 4 + bombred * 4, kFillModeWireFrame);
				}
				if (bombcount > 6 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 6, bombrange - 6, 0.0f,
					  bombcolor - bombblue * 5 + bombred * 5, kFillModeWireFrame);
				}
				if (bombcount > 7 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 7, bombrange - 7, 0.0f,
					  bombcolor - bombblue * 6 + bombred * 6, kFillModeWireFrame);
				}
				if (bombcount > 8 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 8, bombrange - 8, 0.0f,
					  bombcolor - bombblue * 7 + bombred * 7, kFillModeWireFrame);
				}
				if (bombcount > 9 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 9, bombrange - 9, 0.0f,
					  bombcolor - bombblue * 8 + bombred * 8, kFillModeWireFrame);
				}
				if (bombcount > 10 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 10, bombrange - 10, 0.0f,
					  bombcolor - bombblue * 9 + bombred * 9, kFillModeWireFrame);
				}
				if (bombcount > 11 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 11, bombrange - 11, 0.0f,
					  bombcolor - bombblue * 10 + bombred * 10, kFillModeWireFrame);
				}
				if (bombcount > 12 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 12, bombrange - 12, 0.0f,
					  bombcolor - bombblue * 11 + bombred * 11, kFillModeWireFrame);
				}
				if (bombcount > 13 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 13, bombrange - 13, 0.0f,
					  bombcolor - bombblue * 12 + bombred * 12, kFillModeWireFrame);
				}
				if (bombcount > 14 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 14, bombrange - 14, 0.0f,
					  bombcolor - bombblue * 13 + bombred * 13, kFillModeWireFrame);
				}
				if (bombcount > 15 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 15, bombrange - 15, 0.0f,
					  bombcolor - bombblue * 14 + bombred * 14, kFillModeWireFrame);
				}
				if (bombcount > 16 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 16, bombrange - 16, 0.0f,
					  bombcolor - bombblue * 15 + bombred * 15, kFillModeWireFrame);
				}
				if (bombcount > 17 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 17, bombrange - 17, 0.0f,
					  bombcolor - bombblue * 16 + bombred * 16, kFillModeWireFrame);
				}
				if (bombcount > 18 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 18, bombrange - 18, 0.0f,
					  bombcolor - bombblue * 17 + bombred * 17, kFillModeWireFrame);
				}
				if (bombcount > 19 && bombcount < 301) {
					Novice::DrawEllipse(
					  bombx, bomby, bombrange - 19, bombrange - 19, 0.0f,
					  bombcolor - bombblue * 18 + bombred * 18, kFillModeWireFrame);
				}
			}



			while (keys[DIK_SPACE]) {
				for (int j = 0; j < bulcount; j++) {
					if (bulletlife[j] == 1 && jikilife == 1) {
						Novice::DrawSprite(bulposX[j], bulposY[j], bullet, 1, 1, 0.0f, 0xFFFFFFFF);
					}
				}
				break;
			}

			for (int j = 0; j < haikei; j++) {
				Novice::DrawSprite(backx[j], backy[j], back[j], 1, 1, 0.0f, 0xFFFFFFFF);
				
			}
			Novice::DrawSprite(whalexpos, whaleypos, whale, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(xpos, ypos, jiki, 1, 1, 0.0f, 0xFFFFFFFF);
			
			
			if (scroll<480) {
				Novice::DrawSprite(0, 312, massagelule, 1, 1, 0.0f, 0xFFFFFFFF);
			}

			if (stageclear == 1) {
				Novice::DrawSprite(0, 312, massagegc, 1, 1, 0.0f, massagesuke);
			}
			if (whalelife == 0) {
				Novice::DrawSprite(0, 312, massagego, 1, 1, 0.0f, massagesuke);
			}

			if (utubolife == 1) {
				Novice::DrawSprite(utubox, utuboy, utubo, 1, 1, 0.0f, 0xFFFFFFFF);
			}
			if (samelife > 0 && stagexy.stage2y > -6200) {
				Novice::DrawSprite(samex, samey, same, 2, 2, 0.0f, 0xFFFFFFFF);
			}
			if (datulife == 1) {
				Novice::DrawSprite(datux, datuy, datu, 1, 1, 0.0f, 0xFFFFFFFF);
			}
			if (hamosuityokulife == 1) {
				Novice::DrawSprite(
				  hamosuityokux, hamosuityokuy, hamosuityoku, 1, 1, 0.0f, 0xFFFFFFFF);
			}
			if (hamokunekunelife == 1) {
				Novice::DrawSprite(
				  hamokunekunex, hamokunekuney, hamokunekune, 1, 1, 0.0f, 0xFFFFFFFF);
			}
			for (int k = 0; k < tatiuonumber; k++) {
				if (tatiuolife[k] == 1) {
					Novice::DrawSprite(tatiuox[k], tatiuoy[k], tatiuo[k], 1, 1, 0.0f, 0xFFFFFFFF);
				}
			}
			if (Novice::IsPlayingAudio(bombSE) == 0 && bombSE == -1) {
				if (stagecount == 1 && scroll >= 480) {
					bombSE = Novice::PlayAudio(bombse, false, 1.0f);
				}
			}
			if (Novice::IsPlayingAudio(charge) == 0 && charge == -1) {
				if (stagecount == 1 && scroll >= 480) {
					charge = Novice::PlayAudio(chargese, false, 0.5f);
				}
			}
			if (Novice::IsPlayingAudio(shotSE) == 0 && shotSE == -1) {
				if (bulletcount == 1) {
					shotSE = Novice::PlayAudio(shotse, false, 0.5f);
				}
			}
			if (stagexy.stage2y <= -6200) {
				if (samelife > 0) {
					Novice::DrawSprite(samex, samey, same, 6, 6, 0.0f, 0xFFFFFFFF);
				}
		    }
			Novice::DrawSprite(0, 0, control, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		Novice::DrawSprite(babblex, babbley, babble, 2, 2, 0.0f, 0xFFFFFFFF);

			//Novice::ScreenPrintf(10, 700, "%d,%d,%d,%f,%f", bgmcount,stagexy.stage2y,worldy, bombx, bomby);

			///
			/// ↑描画処理ここまで
			///

			// フレームの終了
			Novice::EndFrame();

			// ESCキーが押されたらループを抜ける
			if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
				break;
			}
    }

			// ライブラリの終了
			Novice::Finalize();
			return 0;
 }