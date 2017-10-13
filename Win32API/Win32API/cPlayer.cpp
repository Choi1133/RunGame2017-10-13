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
}

void cPlayer::Setup()
{
	m_nMapYPos = MAP1_Y;
	m_fJumpPower = 7.0f;

	m_nFrameX = 1;
	m_nFrameY = 0;

	m_nMaxFrameX = 8;
	m_nMaxFrameY = 0;

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


	if (g_pKeyManager->isOnceKeyDown(VK_SPACE)) // �����̽� ������
	{

		if (m_isJumpping && !m_isJumpping2)// 1�� �������̸� 
		{
			

			m_fGravity = 0.0f; // ���� �߷��� 0���� �ٲ��ش� (1�� ���� �� )
			m_isJumpping2 = true; // 2�� ������ Ʈ��� 
		}

		m_isJumpping = true; // 1�� ���� Ʈ��

		

	}

	isJumping();





	if (g_pKeyManager->isStayKeyDown(VK_DOWN))
	{
		m_nFrameX = 6;
		m_nFrameY = 1;

		m_nMaxFrameX = 11;
		m_nMaxFrameY = 1;
	}
	else
	{
		m_nFrameX = 1;
		m_nFrameY = 0;

		m_nMaxFrameX = 8;
		m_nMaxFrameY = 0;
	}

	



	
}

void cPlayer::Render()
{

	RectangleMake(g_hDC, m_pPlayerImage->GetBoundingBox());

		m_pPlayerImage->FrameRender(g_hDC,
			(m_pPlayerImage->GetPosX() - m_pPlayerImage->GetFrameWidth() / 2),
			(m_pPlayerImage->GetPosY() - m_pPlayerImage->GetFrameHeight() / 2),
			m_nFrameX, m_nFrameY, m_nMaxFrameX, m_nMaxFrameY, 5);

	
}

void cPlayer::SetLanding()
{
	m_pPlayerImage->SetCenterY(m_nMapYPos);
	m_fGravity = 0.0f;
	m_isJumpping = false;
}

void cPlayer::isJumping()
{
	if (m_isJumpping) // 1�� ���� ���϶� 
	{

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
