#pragma once
#include "cImage.h"

class cCoins
{
private:
	cImage*	 m_pCoins;


public:
	cCoins();
	~cCoins();

	void Setup();
	void Update();
	void Render();
};

