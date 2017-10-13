#include "stdafx.h"
#include "cCoins.h"


cCoins::cCoins()
{
	m_fPosX = WINSIZEX + 100;
	m_fPosY = rand() % WINSIZEY / 2 + 100;

	RectMakeCenter(m_rtBody, m_fPosX, m_fPosY);
}


cCoins::~cCoins()
{
}

void cCoins::Setup()
{
	
}

void cCoins::Update()
{
	
	m_fPosX -= 3.0f;

	m_rtBody.left -= 3.0f;
	m_rtBody.right -= 3.0f;

}

void cCoins::Render()
{	

	RectangleMake(g_hDC,m_rtBody);
	m_pCoins->FrameRender(g_hDC, m_fPosX, m_fPosY);
		
}
