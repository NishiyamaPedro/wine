/*
 * Register related wintrust functions
 *
 * Copyright 2006 Paul Vriens
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include <stdarg.h>

#include "windef.h"
#include "winbase.h"
#include "winerror.h"

#include "guiddef.h"
#include "wintrust.h"
#include "softpub.h"

#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(wintrust);

/***********************************************************************
 *		WintrustAddActionID (WINTRUST.@)
 *
 * Add the definitions of the actions a Trust provider can perform to
 * the registry.
 *
 * PARAMS
 *   pgActionID [I] Pointer to a GUID for the Trust provider.
 *   fdwFlags   [I] Flag to indicate whether registry errors are passed on.
 *   psProvInfo [I] Pointer to a structure with information about DLL
 *                  name and functions.
 *
 * RETURNS
 *   Success: TRUE.
 *   Failure: FALSE. (Use GetLastError() for more information)
 *
 * NOTES
 *   Adding a Trust provider is basically only adding relevant information
 *   to the registry. No verification takes place whether a DLL or it's
 *   entrypoints exist.
 *   Information in the registry will always be overwritten.
 */
BOOL WINAPI WintrustAddActionID( GUID* pgActionID, DWORD fdwFlags,
                                 CRYPT_REGISTER_ACTIONID* psProvInfo)
{
    FIXME("%p %lx %p\n", pgActionID, fdwFlags, psProvInfo);
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return FALSE;
}

/***********************************************************************
 *              WintrustRemoveActionID (WINTRUST.@)
 *
 * Remove the definitions of the actions a Trust provider can perform
 * from the registry.
 *
 * PARAMS
 *   pgActionID [I] Pointer to a GUID for the Trust provider.
 *
 * RETURNS
 *   Success: TRUE. (Use GetLastError() for more information)
 *   Failure: FALSE. (Use GetLastError() for more information)
 *
 * NOTES
 *   Testing shows that WintrustRemoveActionID always returns TRUE and
 *   that a possible error should be retrieved via GetLastError().
 *   There are no checks if the definitions are in the registry.
 */
BOOL WINAPI WintrustRemoveActionID( GUID* pgActionID )
{
    FIXME("(%s)\n", debugstr_guid(pgActionID));
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return FALSE;
}

/***********************************************************************
 *              DllRegisterServer (WINTRUST.@)
 */
HRESULT WINAPI DllRegisterServer(void)
{
     FIXME("stub\n");
     return S_OK;
}

/***********************************************************************
 *              DllUnregisterServer (WINTRUST.@)
 */
HRESULT WINAPI DllUnregisterServer(void)
{
     FIXME("stub\n");
     return S_OK;
}

/***********************************************************************
 *              SoftpubDllRegisterServer (WINTRUST.@)
 */
HRESULT WINAPI SoftpubDllRegisterServer(void)
{
     FIXME("stub\n");
     return S_OK;
}

/***********************************************************************
 *              SoftpubDllUnregisterServer (WINTRUST.@)
 */
HRESULT WINAPI SoftpubDllUnregisterServer(void)
{
     FIXME("stub\n");
     return S_OK;
}

/***********************************************************************
 *              mscat32DllRegisterServer (WINTRUST.@)
 */
HRESULT WINAPI mscat32DllRegisterServer(void)
{
     FIXME("stub\n");
     return S_OK;
}

/***********************************************************************
 *              mscat32DllUnregisterServer (WINTRUST.@)
 */
HRESULT WINAPI mscat32DllUnregisterServer(void)
{
     FIXME("stub\n");
     return S_OK;
}

/***********************************************************************
 *              mssip32DllRegisterServer (WINTRUST.@)
 */
HRESULT WINAPI mssip32DllRegisterServer(void)
{
     FIXME("stub\n");
     return S_OK;
}

/***********************************************************************
 *              mssip32DllUnregisterServer (WINTRUST.@)
 */
HRESULT WINAPI mssip32DllUnregisterServer(void)
{
     FIXME("stub\n");
     return S_OK;
}
