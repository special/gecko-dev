/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */
/*******************************************************************************
 * Source date: 26 Feb 1998 01:03:40 GMT
 * netscape/fonts/winrf module C stub file
 * Generated by jmc version 1.8 -- DO NOT EDIT
 ******************************************************************************/

#include <stdlib.h>
#include <string.h>
#include "xp_mem.h"

/* Include the implementation-specific header: */
#include "Pwinrf.h"

/* Include other interface headers: */

/*******************************************************************************
 * winrf Methods
 ******************************************************************************/

#ifndef OVERRIDE_winrf_getInterface
JMC_PUBLIC_API(void*)
_winrf_getInterface(struct winrf* self, jint op, const JMCInterfaceID* iid, JMCException* *exc)
{
	if (memcmp(iid, &winrf_ID, sizeof(JMCInterfaceID)) == 0)
		return winrfImpl2winrf(winrf2winrfImpl(self));
	return _winrf_getBackwardCompatibleInterface(self, iid, exc);
}
#endif

#ifndef OVERRIDE_winrf_addRef
JMC_PUBLIC_API(void)
_winrf_addRef(struct winrf* self, jint op, JMCException* *exc)
{
	winrfImplHeader* impl = (winrfImplHeader*)winrf2winrfImpl(self);
	impl->refcount++;
}
#endif

#ifndef OVERRIDE_winrf_release
JMC_PUBLIC_API(void)
_winrf_release(struct winrf* self, jint op, JMCException* *exc)
{
	winrfImplHeader* impl = (winrfImplHeader*)winrf2winrfImpl(self);
	if (--impl->refcount == 0) {
		winrf_finalize(self, exc);
	}
}
#endif

#ifndef OVERRIDE_winrf_hashCode
JMC_PUBLIC_API(jint)
_winrf_hashCode(struct winrf* self, jint op, JMCException* *exc)
{
	return (jint)self;
}
#endif

#ifndef OVERRIDE_winrf_equals
JMC_PUBLIC_API(jbool)
_winrf_equals(struct winrf* self, jint op, void* obj, JMCException* *exc)
{
	return self == obj;
}
#endif

#ifndef OVERRIDE_winrf_clone
JMC_PUBLIC_API(void*)
_winrf_clone(struct winrf* self, jint op, JMCException* *exc)
{
	winrfImpl* impl = winrf2winrfImpl(self);
	winrfImpl* newImpl = (winrfImpl*)malloc(sizeof(winrfImpl));
	if (newImpl == NULL) return NULL;
	memcpy(newImpl, impl, sizeof(winrfImpl));
	((winrfImplHeader*)newImpl)->refcount = 1;
	return newImpl;
}
#endif

#ifndef OVERRIDE_winrf_toString
JMC_PUBLIC_API(const char*)
_winrf_toString(struct winrf* self, jint op, JMCException* *exc)
{
	return NULL;
}
#endif

#ifndef OVERRIDE_winrf_finalize
JMC_PUBLIC_API(void)
_winrf_finalize(struct winrf* self, jint op, JMCException* *exc)
{
	/* Override this method and add your own finalization here. */
	XP_FREEIF(self);
}
#endif

/*******************************************************************************
 * Jump Tables
 ******************************************************************************/

const struct winrfInterface winrfVtable = {
	_winrf_getInterface,
	_winrf_addRef,
	_winrf_release,
	_winrf_hashCode,
	_winrf_equals,
	_winrf_clone,
	_winrf_toString,
	_winrf_finalize,
	_winrf_GetMatchInfo,
	_winrf_GetPointSize,
	_winrf_GetMaxWidth,
	_winrf_GetFontAscent,
	_winrf_GetFontDescent,
	_winrf_GetMaxLeftBearing,
	_winrf_GetMaxRightBearing,
	_winrf_SetTransformMatrix,
	_winrf_GetTransformMatrix,
	_winrf_MeasureText,
	_winrf_MeasureBoundingBox,
	_winrf_DrawText,
	_winrf_PrepareDraw,
	_winrf_EndDraw
};

/*******************************************************************************
 * Factory Operations
 ******************************************************************************/

JMC_PUBLIC_API(winrf*)
winrfFactory_Create(JMCException* *exception)
{
	winrfImplHeader* impl = (winrfImplHeader*)XP_NEW_ZAP(winrfImpl);
	winrf* self;
	if (impl == NULL) {
		JMC_EXCEPTION(exception, JMCEXCEPTION_OUT_OF_MEMORY);
		return NULL;
	}
	self = winrfImpl2winrf(impl);
	impl->vtablewinrf = &winrfVtable;
	impl->refcount = 1;
	_winrf_init(self, exception);
	if (JMC_EXCEPTION_RETURNED(exception)) {
		XP_FREE(impl);
		return NULL;
	}
	return self;
}

