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
 * Source date: 16 Apr 1997 08:37:58 GMT
 * netscape/fonts/nffbu interface description
 * Generated by jmc version 1.8 -- DO NOT EDIT
 ******************************************************************************/

#include "Mnffbu.h"

const char* nffbuDescriptor[] = {
	"getInterface(Lnetscape/jmc/JMCInterfaceID;)Ljava/lang/Object;",
	"addRef()V",
	"release()V",
	"hashCode()I",
	"equals(Ljava/lang/Object;)Z",
	"clone()Ljava/lang/Object;",
	"toString()Ljava/lang/String;",
	"finalize()V",
	"CreateFontMatchInfo(Lnetscape/jmc/ConstCString;Lnetscape/jmc/ConstCString;Lnetscape/jmc/ConstCString;IIIIIII)Lnetscape/fonts/nffmi;",
	"CreateRenderingContext(II[Ljava/lang/Object;)Lnetscape/fonts/nfrc;",
	"CreateFontObserver(Lnetscape/fonts/nfFontObserverCallback;Ljava/lang/Object;)Lnetscape/fonts/nfdoer;",
	"malloc(I)Ljava/lang/Object;",
	"free(Ljava/lang/Object;)V",
	"realloc(Ljava/lang/Object;I)Ljava/lang/Object;",
	"IsWebfontsEnabled()I",
	"EnableWebfonts()I",
	"DisableWebfonts()I",
	"ListFontDisplayers()[Lnetscape/jmc/ConstCString;",
	"IsFontDisplayerEnabled(Lnetscape/jmc/ConstCString;)I",
	"ListFontDisplayersForMimetype(Lnetscape/jmc/ConstCString;)[Lnetscape/jmc/ConstCString;",
	"FontDisplayerForMimetype(Lnetscape/jmc/ConstCString;)Lnetscape/jmc/ConstCString;",
	"EnableFontDisplayer(Lnetscape/jmc/ConstCString;)I",
	"DisableFontDisplayer(Lnetscape/jmc/ConstCString;)I",
	"EnableMimetype(Lnetscape/jmc/ConstCString;Lnetscape/jmc/ConstCString;)I",
	"DisableMimetype(Lnetscape/jmc/ConstCString;Lnetscape/jmc/ConstCString;)I",
	"LoadCatalog(Lnetscape/jmc/ConstCString;)I",
	"SaveCatalog(Lnetscape/jmc/ConstCString;)I",
	"LoadWebfont(Lnetscape/fonts/MWContextStar;Lnetscape/jmc/ConstCString;I)I",
	"ReleaseWebfonts(Lnetscape/fonts/MWContextStar;)I",
	"WebfontsNeedReload(Lnetscape/fonts/MWContextStar;)I",
	"LookupFailed(Lnetscape/fonts/MWContextStar;Lnetscape/fonts/nfrc;Lnetscape/fonts/nffmi;)I",
	"ToUnicode(Lnetscape/jmc/ConstCString;[B[S)I",
	"UnicodeLen(Lnetscape/jmc/ConstCString;[B)I"
};

