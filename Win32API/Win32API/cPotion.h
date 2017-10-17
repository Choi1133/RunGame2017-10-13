#pragma once
#include "cImage.h"

class cPlayer;

struct  tagPotion
{
	int		nPosX;
	int		nPosY;
	int		nScore;
	float	fMoveSpeed;
};

class cPotion
{
private:
	cImage*  m_pPotion;
	cPlayer* m_pPlayer;

	vector<tagPotion> m_vecStPotion;


public:
	cPotion();
	~cPotion();

	void Setup();
	void Update();
	void Render();

	void SetPotion(cImage* img) { m_pPotion = img; }

	cImage* GetPotion() { return m_pPotion; }

	void MakePotion();
	void PotionFrame();
	
	void SetPlayer(cPlayer* player) { m_pPlayer = player; }

};

