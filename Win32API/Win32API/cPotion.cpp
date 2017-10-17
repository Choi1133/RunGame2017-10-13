#include "stdafx.h"
#include "cPotion.h"
#include "cPlayer.h"

cPotion::cPotion()
{
	m_pPotion = new cImage;
	m_pPotion->Setup("images/potion.bmp", 100, 30, 5, 1, true, RGB(255, 0, 255));

	
	m_pPlayer = new cPlayer;
	
}


cPotion::~cPotion()
{
	delete m_pPotion;
	delete m_pPlayer;
}

void cPotion::Setup()
{
	
}

void cPotion::Update()
{

	static int count = 0;
	if (count >= 400)
	{
		count = 0;

		MakePotion();
	}
	else
		++count;

	for (auto iter = m_vecStPotion.begin(); iter != m_vecStPotion.end(); ++iter)
	{
		iter->nPosX -= 3;
	}

	PotionFrame();

	for (auto iter = m_vecStPotion.begin(); iter != m_vecStPotion.end(); ++iter)
	{
		RECT rt;
		RECT rtPotion = RectMake(iter->nPosX, iter->nPosY,
			m_pPotion->GetFrameWidth(),
			m_pPotion->GetFrameHeight());

 		if (IntersectRect(&rt, &rtPotion, &m_pPlayer->GetPlayerImage()->GetBoundingBox()))
		{
			m_vecStPotion.erase(iter);
			break;
		}


	}

	for (auto iter = m_vecStPotion.begin(); iter != m_vecStPotion.end(); ++iter)
	{
		if (iter->nPosX < -50)
		{
			m_vecStPotion.erase(iter);
			break;
		}
	}
	

	
}

void cPotion::Render()
{
	for (auto iter = m_vecStPotion.begin(); iter != m_vecStPotion.end(); ++iter)
	{
		BoundingLineMake(g_hDC, iter->nPosX ,
			iter->nPosY, m_pPotion->GetFrameWidth(), m_pPotion->GetFrameHeight());
		
		m_pPotion->FrameRender(g_hDC, iter->nPosX, iter->nPosY);
	}

	
}

void cPotion::MakePotion()
{
	tagPotion stPotion;
	stPotion.nPosX = WINSIZEX + 50;
	stPotion.nPosY = WINSIZEY / 2 + 50;
	stPotion.fMoveSpeed = 3.0f;
	stPotion.nScore = 5;

	m_vecStPotion.push_back(stPotion);
}

void cPotion::PotionFrame()
{

	static int count2 = 0;

	if (count2 >= 5)
	{
		count2 = 0;
		m_pPotion->SetFrameY(0);
		m_pPotion->SetFrameX(1 + m_pPotion->GetFrameX() + 1);
		m_pPotion->SetMaxFrameX(5);

		if (m_pPotion->GetFrameX() > m_pPotion->GetMaxFrameX())
		{
			m_pPotion->SetFrameX(0);
		}

	}
	else
		++count2;
}


