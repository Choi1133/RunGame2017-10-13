#pragma once
#include "cImage.h"

class cTitle
{
private:
	cImage*		m_pStartImage;
	
		

public:
	cTitle();
	~cTitle();


	void Setup();
	void Update();
	void Render();

};

