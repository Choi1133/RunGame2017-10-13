#include "stdafx.h"
#include "cBlock.h"


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
	if (m_nGenDelay > GEN_DELAY)	
		++m_nGenDelay;
	else
	{
		m_nGenDelay = 0;
		CreateBlock();
	}


	for (auto iter = m_vecImgBlock.begin(); iter != m_vecImgBlock.end(); ++iter)
	{
		iter->PosX += 3.0f;
	}

}

void cBlock::Render()
{

	for (auto iter = m_vecImgBlock.begin(); iter != m_vecImgBlock.end(); ++iter)
	{
		switch (iter->type)
		{
	case ET_ONEBLOCK:
		m_pImageBlock->Render(g_hDC, iter->PosX, iter->PosY);
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
	stBlock.PosX = WINSIZEX + 50;
	stBlock.PosY = WINSIZEY / 2 + 200;

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
