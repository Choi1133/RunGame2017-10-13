#pragma once
#include "cImage.h"


#define GEN_DELAY 100

class cPlayer;


enum E_TYPE {ET_ONEBLOCK, ET_TWOBLOCK,ET_MAX};

struct tagBlock
{
	E_TYPE type;

	int PosX;
	int PosY;
};


class cBlock
{
private:
	vector<tagBlock>   m_vecImgBlock;



	cImage*  m_pImageBlock;
	cImage*  m_pImageBlock2;

	int		 m_nGenDelay;
	int		 m_nScore;
	

	cPlayer*	 m_pPlayer;


public:
	cBlock();
	~cBlock();


	void Setup();
	void Update();
	void Render();

	void SetPlayer(cPlayer* player) { m_pPlayer = player; }

	void CreateBlock();


};

