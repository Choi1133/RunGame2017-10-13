#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
	: m_isSlide(false)
	
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

void cPlayer::Render()
{
		m_pPlayerImage->FrameRender(g_hDC,
			(m_pPlayerImage->GetPosX() - m_pPlayerImage->GetFrameWidth() / 2),
			(m_pPlayerImage->GetPosY() - m_pPlayerImage->GetFrameHeight() / 2),
			1, 0, 8, 0, 5);

	
}

void cPlayer::SetLanding()
{
	m_pPlayerImage->SetCenterY(m_nMapYPos);
	m_fGravity = 0.0f;
	m_isJumpping = false;
}