#pragma once
#include "cGameNode.h"

class cMap;
class cPlayer;
class cTitle;
class cCoins;

class cMainGame : public cGameNode
{
private:
	bool			m_isPlaying;

	cMap*			m_pMap;
	cPlayer*		m_pPlayer;
	cTitle*			m_pTitle;
	cCoins*			m_pCoins;

	vector<cCoins>	m_vecCoin;



public:
	cMainGame();
	~cMainGame();

	void Setup();
	virtual void Update() override;
	virtual void Render() override;

	void MakeCoin();
};