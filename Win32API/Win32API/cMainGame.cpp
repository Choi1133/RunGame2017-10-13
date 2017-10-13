#include "stdafx.h"
#include "cMainGame.h"
#include "cMap.h"
#include "cPlayer.h"
#include "cTitle.h"
#include "cCoins.h"


cMainGame::cMainGame()
	: m_isPlaying(false)
{
	m_pMap = new cMap;
	m_pPlayer = new cPlayer;
	m_pTitle = new cTitle;

	m_pCoinImage = new cImage;
	m_pCoinImage->Setup("images/coins.bmp", 150, 50, 6, 1, WINSIZEX / 2, WINSIZEY / 2 + 50, true, RGB(255, 0, 255));


}

cMainGame::~cMainGame()
{
	delete m_pPlayer;
	delete m_pMap;
	delete m_pTitle;
	delete m_pCoinImage;


	
}

void cMainGame::Setup()
{
	m_pMap->Setup();
	m_pPlayer->Setup();
	m_pTitle->Setup();

}

void cMainGame::Update()
{
	cGameNode::Update();

	if (m_isPlaying)
	{
		m_pMap->Update();
		m_pPlayer->Update();

		CoinUpdate();
		CoinFrame();
	
		for (auto iter = m_vecCoin.begin(); iter != m_vecCoin.end(); ++iter)
		{
			RECT rt;
			if (IntersectRect(&rt,
				&m_pPlayer->GetPlayerImage()->GetBoundingBox(),
				&iter->GetCoins()->GetBoundingBox()))
			{
				m_vecCoin.erase(iter);
				break;


			}

		}
			
	
	
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_RETURN))
	{
		Setup();
		m_isPlaying = true;
	}
}

void cMainGame::Render()
{
	// 흰색으로 이미지를 칠한다.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	if (m_isPlaying)
	{
		m_pMap->Render();

		m_pPlayer->Render();
		for (auto iter = m_vecCoin.begin(); iter != m_vecCoin.end(); ++iter)
		{
			iter->Render();

		}

		string str("코인 갯수 : ");

		char szStr[128];
		//str += "asdfasdfsadf";
		str += itoa(m_vecCoin.size(), szStr, 10); // itoa => 인트형을 문자열로 변환 (변환 소스, 임시 저장소, 숫자의 진수)
		TextOutA(g_hDC, 100, 200, str.c_str(), str.length());
	}
	else
	{
		//TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2, "Enter to Start", strlen("Enter to Start"));
		m_pTitle->Render();
		
	}
}

void cMainGame::MakeCoin()
{
	cCoins tCoin;
	tCoin.SetImg(m_pCoinImage);
	m_vecCoin.push_back(tCoin);
}

void cMainGame::CoinUpdate()
{

	static int count = 0;

	if (count >= 10)
	{
		count = 0;

		MakeCoin();
	}
	else
		++count;


	for (auto iter = m_vecCoin.begin(); iter != m_vecCoin.end(); ++iter)
	{

		iter->Update();
	}

}

void cMainGame::CoinFrame()
{

	static int count2 = 0;

	if (count2 >= 5)
	{
		count2 = 0;
		m_pCoinImage->SetFrameY(0);
		m_pCoinImage->SetFrameX(1 + m_pCoinImage->GetFrameX() + 1);
		m_pCoinImage->SetMaxFrameX(5);

		if (m_pCoinImage->GetFrameX() > m_pCoinImage->GetMaxFrameX())
		{
			m_pCoinImage->SetFrameX(0);
		}

	}
	else
		++count2;
}
