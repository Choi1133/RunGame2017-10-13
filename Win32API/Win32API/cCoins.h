#pragma once
#include "cImage.h"

class cCoins
{
private:
	cImage*	 m_pCoins;
	float	 m_fPosX;
	float	 m_fPosY;


public:
	cCoins();
	~cCoins();

	void Setup();
	void Update();
	void Render();
	void SetImg(cImage* Img) { m_pCoins = Img; }

	cImage* GetCoins() { return m_pCoins; }
	
};

