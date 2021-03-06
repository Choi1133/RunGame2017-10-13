#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()

	
{
	m_pPlayerImage = new cImage;
	m_pPlayerImage->Setup("images/ch.bmp", 960, 960, 12, 12,
		200, MAP1_Y, true, RGB(255, 0, 255));
}


cPlayer::~cPlayer()
{
	delete m_pPlayerImage;
}

void cPlayer::Setup()
{
	m_nMapYPos = MAP1_Y;
	m_fJumpPower = 7.0f;
	

	m_nFrameX = 1;
	m_nFrameY = 0;

	m_nMaxFrameX = 8;
	m_nMaxFrameY = 0;
	m_nDamageDelay = 0;
	m_isSlide = false;

	SetLanding();
}

void cPlayer::Update()
{

	if (g_pKeyManager->isStayKeyDown(VK_LEFT) && m_pPlayerImage->GetPosX() > 0)
	{
		m_pPlayerImage->SetPosX(m_pPlayerImage->GetPosX() - 5.0f);
	}
	else if (g_pKeyManager->isStayKeyDown(VK_RIGHT) && m_pPlayerImage->GetPosX() < WINSIZEX)
	{
		m_pPlayerImage->SetPosX(m_pPlayerImage->GetPosX() + 5.0f);
	}


	if (g_pKeyManager->isOnceKeyDown(VK_SPACE)) // 스페이스 누를때
	{
	

		if (m_isJumpping && !m_isJumpping2)// 1단 점프중이면 
		{

			m_fGravity = 0.0f; // 현재 중력은 0으로 바꿔준다 (1단 점프 끝 )
			m_isJumpping2 = true; // 2단 점프를 트루로 
		}

		m_isJumpping = true; // 1단 점프 트루

		m_isSlide = false;

	}

	isJumping();





	if (g_pKeyManager->isStayKeyDown(VK_DOWN))
	{
		m_isSlide = true;

		if (m_isSlide)
		{
			m_nFrameX = 6;
			m_nFrameY = 1;

			m_nMaxFrameX = 11;
			m_nMaxFrameY = 1;
		}
		
	
	}
	else
	{
		m_isSlide = false;
		m_nFrameX = 1;
		m_nFrameY = 0;

		m_nMaxFrameX = 8;
		m_nMaxFrameY = 0;
	}

	if (m_nDamageDelay > 0)
		--m_nDamageDelay;


	
}

void cPlayer::Render()
{
	BoundingLineMake(g_hDC, m_pPlayerImage->GetPosX() - m_pPlayerImage->GetFrameWidth() / 2 + 10
		, m_pPlayerImage->GetPosY() - m_pPlayerImage->GetFrameHeight() / 2 + 5 ,
		m_pPlayerImage->GetFrameWidth() - 30, m_pPlayerImage->GetFrameHeight() - 20);


	
	if (m_nDamageDelay % 2 == 0)
	{
		m_pPlayerImage->FrameRender(g_hDC,
			(m_pPlayerImage->GetPosX() - m_pPlayerImage->GetFrameWidth() / 2),
			(m_pPlayerImage->GetPosY() - m_pPlayerImage->GetFrameHeight() / 2),
			m_nFrameX, m_nFrameY, m_nMaxFrameX, m_nMaxFrameY, 5);
	}

}

void cPlayer::SetLanding()
{
	m_pPlayerImage->SetCenterY(m_nMapYPos);
	m_fGravity = 0.0f;
	m_isJumpping = false;
}

void cPlayer::isJumping()
{
	if (m_isJumpping) // 1단 점프 중일때 
	{

		m_isSlide = false;

		m_pPlayerImage->SetPosY(m_pPlayerImage->GetPosY() - m_fJumpPower + m_fGravity);
		m_fGravity += GRAVITY;

		if (m_fGravity > m_fJumpPower &&
			m_pPlayerImage->GetPosY() > m_nMapYPos - m_pPlayerImage->GetFrameHeight() / 2)
		{
			SetLanding();

			m_isJumpping = false;
			m_isJumpping2 = false;

		}

	}

}
