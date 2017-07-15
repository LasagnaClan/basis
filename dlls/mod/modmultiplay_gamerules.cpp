/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/
//
// modmultiplay_gamerules.cpp
//
#include	"extdll.h"
#include	"util.h"
#include	"cbase.h"
#include	"player.h"
#include	"mod/modplayer.h"
#include	"weapons.h"
#include	"gamerules.h"
#include	"modmultiplay_gamerules.h"
#include	"game.h"

extern int gmsgVGUIMenu;

//=========================================================
//=========================================================
BOOL CModMultiplay::IsCoOp( void )
{
	return FALSE;
}

//=========================================================
//=========================================================
BOOL CModMultiplay::FShouldSwitchWeapon( CBasePlayer *pPlayer, CBasePlayerItem *pWeapon )
{
	if ( atof(g_engfuncs.pfnInfoKeyValue( g_engfuncs.pfnGetInfoKeyBuffer( pPlayer->edict() ), "cl_autowepswitch" )) )
	{
		return TRUE;
	}
	else
	{
		return CHalfLifeMultiplay::FShouldSwitchWeapon( pPlayer, pWeapon );
	}
}

BOOL CModMultiplay::ClientCommand( CBasePlayer *pPlayer, const char *pcmd )
{
	entvars_t *pev = &pPlayer->edict()->v;

	if ( FStrEq(pcmd, "menu" ) )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgVGUIMenu, NULL, pPlayer->pev );
			WRITE_BYTE( 20 );
		MESSAGE_END();

		return true;
	}
	else if ( FStrEq(pcmd, "+modmenu" ) && pPlayer->IsAlive() )
	{
		CBasePlayer *pPlayer = GetClassPtr((CBasePlayer *)pev);

		// open the menu on the client
		MESSAGE_BEGIN( MSG_ONE, gmsgVGUIMenu, NULL, pPlayer->pev );
			WRITE_BYTE( 20 );
		MESSAGE_END();

		// freeze the player while it is open
		pPlayer->EnableControl( false );

		return true;
	}
	else if ( FStrEq(pcmd, "-modmenu") && pPlayer->IsAlive() )
	{
		CBasePlayer *pPlayer = GetClassPtr((CBasePlayer *)pev);

		// close the menu on the client
		MESSAGE_BEGIN( MSG_ONE, gmsgVGUIMenu, NULL, pPlayer->pev );
			WRITE_BYTE( 0 );
		MESSAGE_END();

		// re-enable player control
		pPlayer->EnableControl( true );

		return true;
	}

	return CHalfLifeMultiplay::ClientCommand(pPlayer, pcmd);
}