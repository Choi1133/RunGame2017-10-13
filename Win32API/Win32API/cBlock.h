#pragma once
#include "cImage.h"



class cBlock
{
private:
	cImage*  m_pImageBlock;
	int		 m_nPosX;
	int		 m_nPosY;


public:
	cBlock();
	~cBlock();


	void Setup();
	void Update();
	void Render();
};

