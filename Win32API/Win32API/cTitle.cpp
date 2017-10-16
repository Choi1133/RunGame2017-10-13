#include "stdafx.h"
#include "cTitle.h"


cTitle::cTitle()
{
	m_pStartImage = new cImage;
	m_pStartImage->Setup("images/start.bmp", 200, 215, 1, 3, WINSIZEX / 2 + 100, WINSIZEY / 3, true, RGB(255, 0, 255));




}


cTitle::~cTitle()
{
	delete	m_pStartImage;
}

void cTitle::Setup()
{
}

void cTitle::Update()
{
	

}

void cTitle::Render()
{

	

	m_pStartImage->FrameRender(g_hDC,
		(int)(m_pStartImage->GetPosX() - m_pStartImage->GetFrameWidth() / 2),
		(int)(m_pStartImage->GetPosY() - m_pStartImage->GetFrameHeight() / 2),
		0, 0, 0, 2, 5);
	

}
