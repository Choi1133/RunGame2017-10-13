#pragma once
#include "cImage.h"

class cCoins
{
private:
	cImage*	 m_pCoins;
	float	 m_fPosX;
	float	 m_fPosY;

	int		 m_nScore;


public:
	cCoins();
	~cCoins();

	void Setup();
	void Update();
	void Render();
	void SetImg(cImage* Img) { m_pCoins = Img; }

	cImage* GetCoins() { return m_pCoins; }
	float	GetPosX() { return m_fPosX; }
	float	GetPosY() { return m_fPosY; }
	int		GetScore() { return m_nScore; }
	

	RECT GetBoundingBox() { return m_pCoins->GetBoundingBox(); }
};

