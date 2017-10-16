#include "stdafx.h"
#include "cCoins.h"


cCoins::cCoins()
	
{
	m_fPosX = WINSIZEX + 100;
	m_fPosY = rand() % WINSIZEY / 2 + 100;

}


cCoins::~cCoins()
{
}

void cCoins::Setup()
{
	m_nScore = 10;
}

void cCoins::Update()
{
	
	m_fPosX -= 3.0f;

	
	//RectMakeCenter(m_rtBody, m_fPosX, m_fPosY);

	


}

void cCoins::Render()
{	
	

	BoundingLineMake(g_hDC,m_fPosX + 5 ,
	m_fPosY + 12, m_pCoins->GetFrameWidth() - 10, m_pCoins->GetFrameHeight() - 25);

	m_pCoins->FrameRender(g_hDC, m_fPosX, m_fPosY);
		
}
