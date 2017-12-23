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
/*

===== modutil.cpp ========================================================

Utility code.

*/

#include "extdll.h"
#include "util.h"
#include "mod/modutil.h"
#include "mod/modgame.h"

int UTIL_PrecacheSafe( char *szModel )
{
	if( g_pFileSystem && !g_pFileSystem->FileExists( szModel ) )
	{
		ALERT( at_warning, "%s doesn't exist - precaching models/null.mdl instead\n", szModel );
		return (*g_engfuncs.pfnPrecacheModel)("models/null.mdl");
	}
	return (*g_engfuncs.pfnPrecacheModel)( szModel );
}
