#include "stdafx.h"
#include "cBlock.h"
#include "cPlayer.h"

cBlock::cBlock()
{
	m_pImageBlock = new cImage;
	m_pImageBlock->Setup("images/block.bmp", 50, 50);

	m_pImageBlock2 = new cImage;
	m_pImageBlock2->Setup("images/block.bmp", 50, 100);


}


cBlock::~cBlock()
{

	delete m_pImageBlock;
	delete m_pImageBlock2;
}

void cBlock::Setup()
{
	m_nGenDelay = 0;
}

void cBlock::Update()
{
	static int count = 0;
	if (count >= 100)
	{
		count = 0;

		CreateBlock();
	}
	else
		++count;


	for (auto iter = m_vecImgBlock.begin(); iter != m_vecImgBlock.end(); ++iter)
	{
		iter->PosX -= 3.0f;
	}


	for (auto iter = m_vecImgBlock.begin(); iter != m_vecImgBlock.end(); ++iter)
	{
		RECT rt;
		RECT rtBlock = RectMake(iter->PosX,iter->PosY,
			m_pImageBlock->GetFrameWidth(),
			m_pImageBlock->GetFrameHeight());

		RECT rtBlock2 = RectMake(iter->PosX, iter->PosY,
			m_pImageBlock2->GetFrameWidth(),
			m_pImageBlock2->GetFrameHeight());

		if (IntersectRect(&rt, &rtBlock, &m_pPlayer->GetPlayerImage()->GetBoundingBox()))
		{
			if (m_pPlayer->GetDamageDelay() == 0)
			{
				m_pPlayer->SetDamageDelay(30);
			}
		}

		if (IntersectRect(&rt, &rtBlock2, &m_pPlayer->GetPlayerImage()->GetBoundingBox()))
		{

			if (m_pPlayer->GetDamageDelay() == 0)
			{
				m_pPlayer->SetDamageDelay(30);
			}
		}
		
	}


	for (auto iter = m_vecImgBlock.begin(); iter != m_vecImgBlock.end(); ++iter)
	{
		if (iter->PosX < -20)
		{
			m_vecImgBlock.erase(iter);
			break;
		}

	}

}

void cBlock::Render()
{

	for (auto iter = m_vecImgBlock.begin(); iter != m_vecImgBlock.end(); ++iter)
	{
		switch (iter->type)
		{
			case ET_ONEBLOCK:
				m_pImageBlock->Render(g_hDC, iter->PosX, iter->PosY + 50);
				break;
			case ET_TWOBLOCK:
				m_pImageBlock2->Render(g_hDC, iter->PosX, iter->PosY);
				break;
		}
	}
}

void cBlock::CreateBlock()
{
	tagBlock stBlock;

	stBlock.type = (E_TYPE)GetRandom(ET_MAX);
	stBlock.PosX = WINSIZEX  + 50;
	stBlock.PosY = WINSIZEY / 2 + 120;

	switch (stBlock.type)
	{
	case ET_ONEBLOCK:
		m_nScore = -10;
		break;
	case ET_TWOBLOCK:
		m_nScore = -15;
		break;

	}

	m_vecImgBlock.push_back(stBlock);

}
