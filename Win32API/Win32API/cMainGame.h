#pragma once
#include "cGameNode.h"

class cMap;
class cPlayer;
class cTitle;
class cCoins;
class cBlock;
class cPotion;

class cMainGame : public cGameNode
{
private:

	int				m_nScore1;
	bool			m_isPlaying;

	cMap*			m_pMap;
	cPlayer*		m_pPlayer;
	cTitle*			m_pTitle;
	cBlock*			m_pBlock;
	cPotion*		m_pPotion;


	vector<cCoins>	m_vecCoin;
	vector<cPotion> m_vecPotion;
	cImage*			m_pCoinImage;

	cImage*			m_pImgMain;

	cImage*			m_pImgNum1;
	cImage*			m_pImgNum2;
	cImage*			m_pImgNum3;

	int				m_nSour;
	int				m_nMainSpeed;


public:
	cMainGame();
	~cMainGame();

	void Setup();
	virtual void Update() override;
	virtual void Render() override;

	void MakeCoin();

	void CoinUpdate();
	void CoinFrame();
	void CoinCollision();
	void CoinSystem();



};