#pragma once
#include "cGameNode.h"

class cMap;
class cPlayer;
class cTitle;
class cCoins;

class cMainGame : public cGameNode
{
private:

	int				m_nScore1;
	bool			m_isPlaying;

	cMap*			m_pMap;
	cPlayer*		m_pPlayer;
	cTitle*			m_pTitle;

	vector<cCoins>	m_vecCoin;
	cImage*			m_pCoinImage;

	cImage*			m_pImgMain;
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