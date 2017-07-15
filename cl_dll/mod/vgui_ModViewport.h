#ifndef MODVIEWPORT_H
#define MODVIEWPORT_H

#include<VGUI_Panel.h>
#include<VGUI_Frame.h>
#include<VGUI_TextPanel.h>
#include<VGUI_Label.h>
#include<VGUI_Button.h>
#include<VGUI_ActionSignal.h>
#include<VGUI_InputSignal.h>
#include<VGUI_Scheme.h>
#include<VGUI_Image.h>
#include<VGUI_FileInputStream.h>
#include<VGUI_BitmapTGA.h>
#include<VGUI_DesktopIcon.h>
#include<VGUI_App.h>
#include<VGUI_MiniApp.h>
#include<VGUI_LineBorder.h>
#include<VGUI_String.h>
#include<VGUI_ScrollPanel.h>
#include<VGUI_ScrollBar.h>
#include<VGUI_Slider.h>

#include "vgui_TeamFortressViewport.h"

#define MENU_MENU				20

class CModPanel;

//==============================================================================
class ModViewport : public TeamFortressViewport
{
private:
	CMenuPanel*  ShowModMenu(void);
	void         CreateModMenu(void);

public:
	ModViewport(int x,int y,int wide,int tall);
	void Initialize(void);

	virtual void SetCurrentMenu( CMenuPanel *pMenu );

	virtual void ShowVGUIMenu( int iMenu );

	CModPanel	*m_pModPanel;

	const static int VIEWPORT_WIDTH = 640;
	const static int VIEWPORT_HEIGHT = 480;
};

//================================================================
// Mod Panel
//============================================================
class CModPanel : public CMenuPanel
{
private:
	CTransparentPanel   *m_pPanel;
	Label               *m_pTitle;
	CommandButton       *m_pCancelButton;

public:
	CModPanel( int iTrans, int iRemoveMe, int x, int y, int wide, int tall );
};

#endif