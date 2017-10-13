#include "stdafx.h"
#include "cCoins.h"


cCoins::cCoins()
{


	m_pCoins = new cImage;
	m_pCoins->Setup("images/coins.bmp", 150, 50, 6, 1, WINSIZEX / 2, WINSIZEY / 2 + 50, true, RGB(255, 0, 255));
	
	
}


cCoins::~cCoins()
{
}

void cCoins::Setup()
{


}

void cCoins::Update()
{
	static int count = 0;

	if (count >= 5)
	{
		count = 0;


			m_pCoins->SetFrameY(0);
			m_pCoins->SetFrameX(1 + m_pCoins->GetFrameX() + 1);
			m_pCoins->SetMaxFrameX(5);

			if (m_pCoins->GetFrameX() > m_pCoins->GetMaxFrameX())
			{
				m_pCoins->SetFrameX(0);
			}
			


	}
	else
		++count;

	m_pCoins->SetPosX(m_pCoins->GetPosX() - 3.0f);


}

void cCoins::Render()
{
	
	m_pCoins->FrameRender(g_hDC, m_pCoins->GetPosX(), m_pCoins->GetPosY());
	
	
}
