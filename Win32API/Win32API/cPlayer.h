#pragma once
#include "cImage.h"

#define MAP1_Y (WINSIZEY - 110)



class cPlayer
{
private:
	cImage*			m_pPlayerImage;
	float			m_fGravity;
	bool			m_isJumpping;
	bool			m_isJumpping2;
	bool			m_isSlide;

	float			m_fJumpPower;

	int				m_nMapYPos;

	int				m_nFrameX;
	int				m_nFrameY;

	int				m_nMaxFrameX;
	int				m_nMaxFrameY;



public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();

	void SetLanding();

	cImage* GetPlayerImage() { return m_pPlayerImage; }

	void isJumping();
};

