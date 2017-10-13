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
	m_pCoins = new cCoins;

	

	
}

cMainGame::~cMainGame()
{
	delete m_pPlayer;
	delete m_pMap;
	delete m_pTitle;
	delete m_pCoins;

	
}

void cMainGame::Setup()
{
	m_pMap->Setup();
	m_pPlayer->Setup();
	m_pTitle->Setup();
	m_pCoins->Setup();

}

void cMainGame::Update()
{
	cGameNode::Update();

	if (m_isPlaying)
	{
		m_pMap->Update();
		m_pPlayer->Update();
		m_pCoins->Update();
	
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_RETURN))
	{
		Setup();
		m_isPlaying = true;
	}
}

void cMainGame::Render()
{
	// Èò»öÀ¸·Î ÀÌ¹ÌÁö¸¦ Ä¥ÇÑ´Ù.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	if (m_isPlaying)
	{
		m_pMap->Render();

		m_pPlayer->Render();

		m_pCoins->Render();

	
		
	}
	else
	{
		//TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2, "Enter to Start", strlen("Enter to Start"));
		m_pTitle->Render();
		
	}
}