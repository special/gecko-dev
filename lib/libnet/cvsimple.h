/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
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
/**********************************************************************
 cvsimple.h
 By Daniel Malmer <malmer@netscape.com>
 1/14/98

 Simple converter that just saves the data in a buffer.
 
**********************************************************************/


#ifndef __cvsimple_h
#define __cvsimple_h

#include "net.h"

MODULE_PRIVATE NET_StreamClass*
NET_SimpleStream(int fmt, void* data_obj, URL_Struct* URL_s, MWContext* w);

#endif
