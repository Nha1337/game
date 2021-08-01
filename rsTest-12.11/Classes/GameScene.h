#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Enemy.h"
#include "Player.h"
#include "EndedScene.h"

class GameScene: public cocos2d::CCLayer
{
public:
	virtual bool init();
	~GameScene();

	//���ص�����
	void menuPauseCallback(CCObject* pSender);
	void menuContinueCallback(CCObject* pSender);
	void menuRestartCallback(CCObject* pSender);
	void menuExitCallback(CCObject* pSender);
	void gameOver(float t);
	void cleanUpEnmey(CCNode *object);

	CREATE_FUNC(GameScene);

private:
	CCLayerColor *pUiLayer;	//UI��
	CCLayer* pBgLayer;		//������
	CCLayer* pLogicLayer;	//��Ϸ�߼��㣨�ӵ����ɻ����л�������㣩

	cocos2d::CCSprite* playerSprite;	 
	cocos2d::CCSprite* pBgSprite1;
	cocos2d::CCSprite* pBgSprite2;

	CCSpriteFrameCache* cacheBg;
	CCSpriteFrameCache* cacheShoot;
	int makeBulletTime;		//�ӵ����ɼ��ʱ��
	int makeEnemyTime1, makeEnemyTime2, makeEnemyTime3;//���ֵл����ɼ��ʱ��
	int bgheight;			//������ͼ�ĸ�
	int score;
	CCLabelTTF* pScoreLabel;
	cocos2d::CCArray* enemyArray;
	cocos2d::CCArray* bulletArray;
	
	bool isGamePaused;
	bool isGameOver;

	unsigned int bulletSound;


	void initDate();
	void preloadMuiscFile();

	//����
	void uILayer();
	void bgLayer();
	void logicLayer();

	//����������
	CCSprite* createSingleBullet(CCSpriteFrameCache* cache, char* s);
	Player* makePlayer();
	void makeBullet();
	void makeEnemy();

	//��ײ���
	bool isCollision(CCSprite* sprite1, CCSprite* sprite2);
	void enemyAndPlayerCollision(CCArray* enemyArray, Enemy* enemy);
	void enemyAndBulletCollision(CCArray* enemyArray1, CCArray* bulletArray1);

	//������
	void playerExplodeAnimation();
	void enemyHitAnimation(Enemy *enemy);
	void enemyExplodeAnimation(Enemy* enemy);
	
	//����ѭ��
	void rollBg();

	//����
	void update(float t);
};

#endif