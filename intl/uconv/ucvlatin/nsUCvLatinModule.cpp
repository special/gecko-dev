/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: NPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla Communicator client code.
 *
 * The Initial Developer of the Original Code is 
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Pierre Phaneuf <pp@ludusdesign.com>
 *
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the NPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the NPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "pratom.h"
#include "nspr.h"
#include "nsString.h"
#include "nsCOMPtr.h"
#include "nsIFactory.h"
#include "nsIRegistry.h"
#include "nsIGenericFactory.h"
#include "nsIServiceManager.h"
#include "nsICharsetConverterManager.h"
#include "nsIModule.h"
#include "nsUCvLatinCID.h"
#include "nsUCvLatinDll.h"
#include "nsCRT.h"

#include "nsUEscapeToUnicode.h"
#include "nsUnicodeToUEscape.h"
#include "nsAsciiToUnicode.h"
#include "nsISO88592ToUnicode.h"
#include "nsISO88593ToUnicode.h"
#include "nsISO88594ToUnicode.h"
#include "nsISO88595ToUnicode.h"
#include "nsISO88596ToUnicode.h"
#include "nsISO88596EToUnicode.h"
#include "nsISO88596IToUnicode.h"
#include "nsISO88597ToUnicode.h"
#include "nsISO88598ToUnicode.h"
#include "nsISO88598EToUnicode.h"
#include "nsISO88598IToUnicode.h"
#include "nsISO88599ToUnicode.h"
#include "nsISO885910ToUnicode.h"
#include "nsISO885913ToUnicode.h"
#include "nsISO885914ToUnicode.h"
#include "nsISO885915ToUnicode.h"
#include "nsISO885916ToUnicode.h"
#include "nsISOIR111ToUnicode.h"
#include "nsCP1250ToUnicode.h"
#include "nsCP1251ToUnicode.h"
#include "nsCP1253ToUnicode.h"
#include "nsCP1254ToUnicode.h"
#include "nsCP1255ToUnicode.h"
#include "nsCP1256ToUnicode.h"
#include "nsCP1257ToUnicode.h"
#include "nsCP1258ToUnicode.h"
#include "nsCP874ToUnicode.h"
#include "nsCP866ToUnicode.h"
#include "nsKOI8RToUnicode.h"
#include "nsKOI8UToUnicode.h"
#include "nsMacCEToUnicode.h"
#include "nsMacGreekToUnicode.h"
#include "nsMacTurkishToUnicode.h"
#include "nsMacCroatianToUnicode.h"
#include "nsMacRomanianToUnicode.h"
#include "nsMacCyrillicToUnicode.h"
#include "nsMacUkrainianToUnicode.h"
#include "nsMacIcelandicToUnicode.h"
#include "nsGEOSTD8ToUnicode.h"
#include "nsARMSCII8ToUnicode.h"
#include "nsTCVN5712ToUnicode.h"
#include "nsVISCIIToUnicode.h"
#include "nsVPSToUnicode.h"
#include "nsUTF7ToUnicode.h"
#include "nsMUTF7ToUnicode.h"
#include "nsUCS4BEToUnicode.h"
#include "nsUCS4LEToUnicode.h"
#include "nsUCS2BEToUnicode.h"
#include "nsUCS2LEToUnicode.h"
#include "nsT61ToUnicode.h"
#include "nsUserDefinedToUnicode.h"
#include "nsUnicodeToAscii.h"
#include "nsUnicodeToISO88592.h"
#include "nsUnicodeToISO88593.h"
#include "nsUnicodeToISO88594.h"
#include "nsUnicodeToISO88595.h"
#include "nsUnicodeToISO88596.h"
#include "nsUnicodeToISO88596E.h"
#include "nsUnicodeToISO88596I.h"
#include "nsUnicodeToISO88597.h"
#include "nsUnicodeToISO88598.h"
#include "nsUnicodeToISO88598E.h"
#include "nsUnicodeToISO88598I.h"
#include "nsUnicodeToISO88599.h"
#include "nsUnicodeToISO885910.h"
#include "nsUnicodeToISO885913.h"
#include "nsUnicodeToISO885914.h"
#include "nsUnicodeToISO885915.h"
#include "nsUnicodeToISO885916.h"
#include "nsUnicodeToISOIR111.h"
#include "nsUnicodeToCP1250.h"
#include "nsUnicodeToCP1251.h"
#include "nsUnicodeToCP1253.h"
#include "nsUnicodeToCP1254.h"
#include "nsUnicodeToCP1255.h"
#include "nsUnicodeToCP1256.h"
#include "nsUnicodeToCP1257.h"
#include "nsUnicodeToCP1258.h"
#include "nsUnicodeToCP874.h"
#include "nsUnicodeToCP866.h"
#include "nsUnicodeToKOI8R.h"
#include "nsUnicodeToKOI8U.h"
#include "nsUnicodeToMacCE.h"
#include "nsUnicodeToMacGreek.h"
#include "nsUnicodeToMacTurkish.h"
#include "nsUnicodeToMacCroatian.h"
#include "nsUnicodeToMacRomanian.h"
#include "nsUnicodeToMacCyrillic.h"
#include "nsUnicodeToMacUkrainian.h"
#include "nsUnicodeToMacIcelandic.h"
#include "nsUnicodeToGEOSTD8.h"
#include "nsUnicodeToARMSCII8.h"
#include "nsUnicodeToTCVN5712.h"
#include "nsUnicodeToVISCII.h"
#include "nsUnicodeToVPS.h"
#include "nsUnicodeToUTF7.h"
#include "nsUnicodeToMUTF7.h"
#include "nsUnicodeToUCS2BE.h"
#include "nsUnicodeToUCS2LE.h"
#include "nsUnicodeToUCS4BE.h"
#include "nsUnicodeToUCS4LE.h"
#include "nsUnicodeToT61.h"
#include "nsUnicodeToUserDefined.h"
#include "nsUnicodeToSymbol.h"
#include "nsUnicodeToZapfDingbat.h"
#include "nsMacArabicToUnicode.h"
#include "nsMacDevanagariToUnicode.h"
#include "nsMacFarsiToUnicode.h"
#include "nsMacGujaratiToUnicode.h"
#include "nsMacGurmukhiToUnicode.h"
#include "nsMacHebrewToUnicode.h"
#include "nsUnicodeToMacArabic.h"
#include "nsUnicodeToMacDevanagari.h"
#include "nsUnicodeToMacFarsi.h"
#include "nsUnicodeToMacGujarati.h"
#include "nsUnicodeToMacGurmukhi.h"
#include "nsUnicodeToMacHebrew.h"


//----------------------------------------------------------------------------
// Global functions and data [declaration]

static NS_DEFINE_CID(kComponentManagerCID, NS_COMPONENTMANAGER_CID);

#define DECODER_NAME_BASE "Unicode Decoder-"
#define ENCODER_NAME_BASE "Unicode Encoder-"

NS_CONVERTER_REGISTRY_START
NS_UCONV_REG_UNREG("us-ascii", NS_ASCIITOUNICODE_CID, NS_UNICODETOASCII_CID)
NS_UCONV_REG_UNREG("x-u-escaped", NS_UESCAPETOUNICODE_CID, NS_UNICODETOUESCAPE_CID)
NS_UCONV_REG_UNREG("ISO-8859-2", NS_ISO88592TOUNICODE_CID, NS_UNICODETOISO88592_CID)
NS_UCONV_REG_UNREG("ISO-8859-3", NS_ISO88593TOUNICODE_CID, NS_UNICODETOISO88593_CID)
NS_UCONV_REG_UNREG("ISO-8859-4", NS_ISO88594TOUNICODE_CID, NS_UNICODETOISO88594_CID)
NS_UCONV_REG_UNREG("ISO-8859-5", NS_ISO88595TOUNICODE_CID, NS_UNICODETOISO88595_CID)
NS_UCONV_REG_UNREG("ISO-8859-6", NS_ISO88596TOUNICODE_CID, NS_UNICODETOISO88596_CID)
NS_UCONV_REG_UNREG("ISO-8859-6-I", NS_ISO88596ITOUNICODE_CID, NS_UNICODETOISO88596I_CID)
NS_UCONV_REG_UNREG("ISO-8859-6-E", NS_ISO88596ETOUNICODE_CID, NS_UNICODETOISO88596E_CID)
NS_UCONV_REG_UNREG("ISO-8859-7", NS_ISO88597TOUNICODE_CID, NS_UNICODETOISO88597_CID)
NS_UCONV_REG_UNREG("ISO-8859-8", NS_ISO88598TOUNICODE_CID, NS_UNICODETOISO88598_CID)
NS_UCONV_REG_UNREG("ISO-8859-8-I", NS_ISO88598ITOUNICODE_CID, NS_UNICODETOISO88598I_CID)
NS_UCONV_REG_UNREG("ISO-8859-8-E", NS_ISO88598ETOUNICODE_CID, NS_UNICODETOISO88598E_CID)
NS_UCONV_REG_UNREG("ISO-8859-9", NS_ISO88599TOUNICODE_CID, NS_UNICODETOISO88599_CID)
NS_UCONV_REG_UNREG("ISO-8859-10", NS_ISO885910TOUNICODE_CID, NS_UNICODETOISO885910_CID)
NS_UCONV_REG_UNREG("ISO-8859-13", NS_ISO885913TOUNICODE_CID, NS_UNICODETOISO885913_CID)
NS_UCONV_REG_UNREG("ISO-8859-14", NS_ISO885914TOUNICODE_CID, NS_UNICODETOISO885914_CID)
NS_UCONV_REG_UNREG("ISO-8859-15", NS_ISO885915TOUNICODE_CID, NS_UNICODETOISO885915_CID)
NS_UCONV_REG_UNREG("ISO-8859-16", NS_ISO885916TOUNICODE_CID, NS_UNICODETOISO885916_CID)
NS_UCONV_REG_UNREG("ISO-IR-111", NS_ISOIR111TOUNICODE_CID, NS_UNICODETOISOIR111_CID)
NS_UCONV_REG_UNREG("windows-1250", NS_CP1250TOUNICODE_CID, NS_UNICODETOCP1250_CID)
NS_UCONV_REG_UNREG("windows-1251", NS_CP1251TOUNICODE_CID, NS_UNICODETOCP1251_CID)
NS_UCONV_REG_UNREG("windows-1253", NS_CP1253TOUNICODE_CID, NS_UNICODETOCP1253_CID)
NS_UCONV_REG_UNREG("windows-1254", NS_CP1254TOUNICODE_CID, NS_UNICODETOCP1254_CID)
NS_UCONV_REG_UNREG("windows-1255", NS_CP1255TOUNICODE_CID, NS_UNICODETOCP1255_CID)
NS_UCONV_REG_UNREG("windows-1256", NS_CP1256TOUNICODE_CID, NS_UNICODETOCP1256_CID)
NS_UCONV_REG_UNREG("windows-1257", NS_CP1257TOUNICODE_CID, NS_UNICODETOCP1257_CID)
NS_UCONV_REG_UNREG("windows-1258", NS_CP1258TOUNICODE_CID, NS_UNICODETOCP1258_CID)
NS_UCONV_REG_UNREG("TIS-620", NS_CP874TOUNICODE_CID, NS_UNICODETOCP874_CID)
NS_UCONV_REG_UNREG("IBM866", NS_CP866TOUNICODE_CID, NS_UNICODETOCP866_CID)
NS_UCONV_REG_UNREG("KOI8-R", NS_KOI8RTOUNICODE_CID, NS_UNICODETOKOI8R_CID)
NS_UCONV_REG_UNREG("KOI8-U", NS_KOI8UTOUNICODE_CID, NS_UNICODETOKOI8U_CID)
NS_UCONV_REG_UNREG("x-mac-ce", NS_MACCETOUNICODE_CID, NS_UNICODETOMACCE_CID)
NS_UCONV_REG_UNREG("x-mac-greek", NS_MACGREEKTOUNICODE_CID, NS_UNICODETOMACGREEK_CID)
NS_UCONV_REG_UNREG("x-mac-turkish", NS_MACTURKISHTOUNICODE_CID, NS_UNICODETOMACTURKISH_CID)
NS_UCONV_REG_UNREG("x-mac-croatian", NS_MACCROATIANTOUNICODE_CID, NS_UNICODETOMACCROATIAN_CID)
NS_UCONV_REG_UNREG("x-mac-romanian", NS_MACROMANIANTOUNICODE_CID, NS_UNICODETOMACROMANIAN_CID)
NS_UCONV_REG_UNREG("x-mac-cyrillic", NS_MACCYRILLICTOUNICODE_CID, NS_UNICODETOMACCYRILLIC_CID)
NS_UCONV_REG_UNREG("x-mac-ukrainian", NS_MACUKRAINIANTOUNICODE_CID, NS_UNICODETOMACUKRAINIAN_CID)
NS_UCONV_REG_UNREG("x-mac-icelandic", NS_MACICELANDICTOUNICODE_CID, NS_UNICODETOMACICELANDIC_CID)
NS_UCONV_REG_UNREG("GEOSTD8", NS_GEOSTD8TOUNICODE_CID, NS_UNICODETOGEOSTD8_CID)
NS_UCONV_REG_UNREG("armscii-8", NS_ARMSCII8TOUNICODE_CID, NS_UNICODETOARMSCII8_CID)
NS_UCONV_REG_UNREG("x-viet-tcvn5712", NS_TCVN5712TOUNICODE_CID, NS_UNICODETOTCVN5712_CID)
NS_UCONV_REG_UNREG("VISCII", NS_VISCIITOUNICODE_CID, NS_UNICODETOVISCII_CID)
NS_UCONV_REG_UNREG("x-viet-vps", NS_VPSTOUNICODE_CID, NS_UNICODETOVPS_CID)
NS_UCONV_REG_UNREG("UTF-7", NS_UTF7TOUNICODE_CID, NS_UNICODETOUTF7_CID)
NS_UCONV_REG_UNREG("x-imap4-modified-utf7", NS_MUTF7TOUNICODE_CID, NS_UNICODETOMUTF7_CID)
NS_UCONV_REG_UNREG("UTF-16BE", NS_UTF16BETOUNICODE_CID, NS_UNICODETOUTF16BE_CID)
NS_UCONV_REG_UNREG("UTF-16LE", NS_UTF16LETOUNICODE_CID, NS_UNICODETOUTF16LE_CID)
NS_UCONV_REG_UNREG("UTF-32BE", NS_UTF32BETOUNICODE_CID, NS_UNICODETOUTF32BE_CID)
NS_UCONV_REG_UNREG("UTF-32LE", NS_UTF32LETOUNICODE_CID, NS_UNICODETOUTF32LE_CID)
NS_UCONV_REG_UNREG("T.61-8bit", NS_T61TOUNICODE_CID, NS_UNICODETOT61_CID)
NS_UCONV_REG_UNREG("x-user-defined", NS_USERDEFINEDTOUNICODE_CID, NS_UNICODETOUSERDEFINED_CID)
NS_UCONV_REG_UNREG("x-mac-arabic" , NS_MACARABICTOUNICODE_CID, NS_UNICODETOMACARABIC_CID)
NS_UCONV_REG_UNREG("x-mac-devanagari" , NS_MACDEVANAGARITOUNICODE_CID, NS_UNICODETOMACDEVANAGARI_CID)
NS_UCONV_REG_UNREG("x-mac-farsi" , NS_MACFARSITOUNICODE_CID, NS_UNICODETOMACFARSI_CID)
NS_UCONV_REG_UNREG("x-mac-gurmukhi" , NS_MACGURMUKHITOUNICODE_CID, NS_UNICODETOMACGURMUKHI_CID)
NS_UCONV_REG_UNREG("x-mac-gujarati" , NS_MACGUJARATITOUNICODE_CID, NS_UNICODETOMACGUJARATI_CID)
NS_UCONV_REG_UNREG("x-mac-hebrew" , NS_MACHEBREWTOUNICODE_CID, NS_UNICODETOMACHEBREW_CID)

NS_UCONV_REG_UNREG_ENCODER("UTF-16" , NS_UNICODETOUTF16_CID)
NS_UCONV_REG_UNREG_ENCODER("Adobe-Symbol-Encoding" , NS_UNICODETOSYMBOL_CID)
NS_UCONV_REG_UNREG_ENCODER("x-zapf-dingbats" , NS_UNICODETOZAPFDINGBATS_CID)
NS_CONVERTER_REGISTRY_END

NS_IMPL_NSUCONVERTERREGSELF


NS_GENERIC_FACTORY_CONSTRUCTOR(nsAsciiToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUEscapeToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO88592ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO88593ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO88594ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO88595ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO88596ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO88596EToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO88596IToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO88597ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO88598ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO88598EToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO88598IToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO88599ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO885910ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO885913ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO885914ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO885915ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISO885916ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsISOIR111ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsCP1250ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsCP1251ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsCP1253ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsCP1254ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsCP1255ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsCP1256ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsCP1257ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsCP1258ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsCP874ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsCP866ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsKOI8RToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsKOI8UToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacCEToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacGreekToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacTurkishToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacCroatianToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacRomanianToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacCyrillicToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacUkrainianToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacIcelandicToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsGEOSTD8ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsARMSCII8ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsTCVN5712ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsVISCIIToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsVPSToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUTF7ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMUTF7ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUTF16BEToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUTF16LEToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUCS4BEToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUCS4LEToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsT61ToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUserDefinedToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToAscii);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToUEscape);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO88592);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO88593);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO88594);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO88595);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO88596);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO88596E);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO88596I);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO88597);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO88598);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO88598E);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO88598I);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO88599);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO885910);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO885913);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO885914);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO885915);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISO885916);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToISOIR111);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToCP1250);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToCP1251);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToCP1253);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToCP1254);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToCP1255);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToCP1256);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToCP1257);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToCP1258);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToCP874);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToCP866);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToKOI8R);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToKOI8U);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacCE);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacGreek);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacTurkish);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacCroatian);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacRomanian);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacCyrillic);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacUkrainian);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacIcelandic);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToGEOSTD8);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToARMSCII8);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToTCVN5712);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToVISCII);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToVPS);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToUTF7);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMUTF7);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToUTF16BE);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToUTF16LE);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToUTF16);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToUCS4BE);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToUCS4LE);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToT61);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToUserDefined);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToSymbol);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToZapfDingbat);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacArabicToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacDevanagariToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacFarsiToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacGurmukhiToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacGujaratiToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacHebrewToUnicode);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacArabic);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacDevanagari);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacFarsi);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacGurmukhi);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacGujarati);
NS_GENERIC_FACTORY_CONSTRUCTOR(nsUnicodeToMacHebrew);

static const nsModuleComponentInfo components[] = 
{
  { 
    DECODER_NAME_BASE "us-ascii" , NS_ASCIITOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "us-ascii",
    nsAsciiToUnicodeConstructor ,
    // global converter registration
    nsUConverterRegSelf, nsUConverterUnregSelf,
  },
  { 
    DECODER_NAME_BASE "x-u-escaped" , NS_UESCAPETOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-u-escaped",
    nsUEscapeToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-2" , NS_ISO88592TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-2",
    nsISO88592ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-3" , NS_ISO88593TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-3",
    nsISO88593ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-4" , NS_ISO88594TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-4",
    nsISO88594ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-5" , NS_ISO88595TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-5",
    nsISO88595ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-6" , NS_ISO88596TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-6",
    nsISO88596ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-6-I" , NS_ISO88596ITOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-6-I",
    nsISO88596IToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-6-E" , NS_ISO88596ETOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-6-E",
    nsISO88596EToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-7" , NS_ISO88597TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-7",
    nsISO88597ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-8" , NS_ISO88598TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-8",
    nsISO88598ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-8-I" , NS_ISO88598ITOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-8-I",
    nsISO88598IToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-8-E" , NS_ISO88598ETOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-8-E",
    nsISO88598EToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-9" , NS_ISO88599TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-9",
    nsISO88599ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-10" , NS_ISO885910TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-10",
    nsISO885910ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-13" , NS_ISO885913TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-13",
    nsISO885913ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-14" , NS_ISO885914TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-14",
    nsISO885914ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-15" , NS_ISO885915TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-15",
    nsISO885915ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-8859-16" , NS_ISO885916TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-8859-16",
    nsISO885916ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "ISO-IR-111" , NS_ISOIR111TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "ISO-IR-111",
    nsISOIR111ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "windows-1250" , NS_CP1250TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "windows-1250",
    nsCP1250ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "windows-1251" , NS_CP1251TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "windows-1251",
    nsCP1251ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "windows-1253" , NS_CP1253TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "windows-1253",
    nsCP1253ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "windows-1254" , NS_CP1254TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "windows-1254",
    nsCP1254ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "windows-1255" , NS_CP1255TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "windows-1255",
    nsCP1255ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "windows-1256" , NS_CP1256TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "windows-1256",
    nsCP1256ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "windows-1257" , NS_CP1257TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "windows-1257",
    nsCP1257ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "windows-1258" , NS_CP1258TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "windows-1258",
    nsCP1258ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "TIS-620" , NS_CP874TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "TIS-620",
    nsCP874ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "IBM866" , NS_CP866TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "IBM866",
    nsCP866ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "KOI8-R" , NS_KOI8RTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "KOI8-R",
    nsKOI8RToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "KOI8-U" , NS_KOI8UTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "KOI8-U",
    nsKOI8UToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-ce" , NS_MACCETOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-ce",
    nsMacCEToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-greek" , NS_MACGREEKTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-greek",
    nsMacGreekToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-turkish" , NS_MACTURKISHTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-turkish",
    nsMacTurkishToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-croatian" , NS_MACCROATIANTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-croatian",
    nsMacCroatianToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-romanian" , NS_MACROMANIANTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-romanian",
    nsMacRomanianToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-cyrillic" , NS_MACCYRILLICTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-cyrillic",
    nsMacCyrillicToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-ukrainian" , NS_MACUKRAINIANTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-ukrainian",
    nsMacUkrainianToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-icelandic" , NS_MACICELANDICTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-icelandic",
    nsMacIcelandicToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "GEOSTD8" , NS_GEOSTD8TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "GEOSTD8",
    nsGEOSTD8ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "armscii-8" , NS_ARMSCII8TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "armscii-8",
    nsARMSCII8ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-viet-tcvn5712" , NS_TCVN5712TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-viet-tcvn5712",
    nsTCVN5712ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "VISCII" , NS_VISCIITOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "VISCII",
    nsVISCIIToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-viet-vps" , NS_VPSTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-viet-vps",
    nsVPSToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "UTF-7" , NS_UTF7TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "UTF-7",
    nsUTF7ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-imap4-modified-utf7" , NS_MUTF7TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-imap4-modified-utf7",
    nsMUTF7ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "UTF-16BE" , NS_UTF16BETOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "UTF-16BE",
    nsUTF16BEToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "UTF-16LE" , NS_UTF16LETOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "UTF-16LE",
    nsUTF16LEToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "UTF-32BE" , NS_UTF32BETOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "UTF-32BE",
    nsUCS4BEToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "UTF-32LE" , NS_UTF32LETOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "UTF-32LE",
    nsUCS4LEToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "T.61-8bit" , NS_T61TOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "T.61-8bit",
    nsT61ToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-user-defined" , NS_USERDEFINEDTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-user-defined",
    nsUserDefinedToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-arabic" , NS_MACARABICTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-arabic",
    nsMacArabicToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-devanagari" , NS_MACDEVANAGARITOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-devanagari",
    nsMacDevanagariToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-farsi" , NS_MACFARSITOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-farsi",
    nsMacFarsiToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-gurmukhi" , NS_MACGURMUKHITOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-gurmukhi",
    nsMacGurmukhiToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-gujarati" , NS_MACGUJARATITOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-gujarati",
    nsMacGujaratiToUnicodeConstructor ,
  },
  { 
    DECODER_NAME_BASE "x-mac-hebrew" , NS_MACHEBREWTOUNICODE_CID, 
    NS_UNICODEDECODER_CONTRACTID_BASE "x-mac-hebrew",
    nsMacHebrewToUnicodeConstructor ,
  },
  { 
    ENCODER_NAME_BASE "us-ascii" , NS_UNICODETOASCII_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "us-ascii",
    nsUnicodeToAsciiConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-u-escaped" , NS_UNICODETOUESCAPE_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-u-escaped",
    nsUnicodeToUEscapeConstructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-2" , NS_UNICODETOISO88592_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-2",
    nsUnicodeToISO88592Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-3" , NS_UNICODETOISO88593_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-3",
    nsUnicodeToISO88593Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-4" , NS_UNICODETOISO88594_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-4",
    nsUnicodeToISO88594Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-5" , NS_UNICODETOISO88595_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-5",
    nsUnicodeToISO88595Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-6" , NS_UNICODETOISO88596_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-6",
    nsUnicodeToISO88596Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-6-I" , NS_UNICODETOISO88596I_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-6-I",
    nsUnicodeToISO88596IConstructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-6-E" , NS_UNICODETOISO88596E_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-6-E",
    nsUnicodeToISO88596EConstructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-7" , NS_UNICODETOISO88597_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-7",
    nsUnicodeToISO88597Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-8" , NS_UNICODETOISO88598_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-8",
    nsUnicodeToISO88598Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-8-I" , NS_UNICODETOISO88598I_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-8-I",
    nsUnicodeToISO88598IConstructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-8-E" , NS_UNICODETOISO88598E_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-8-E",
    nsUnicodeToISO88598EConstructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-9" , NS_UNICODETOISO88599_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-9",
    nsUnicodeToISO88599Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-10" , NS_UNICODETOISO885910_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-10",
    nsUnicodeToISO885910Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-13" , NS_UNICODETOISO885913_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-13",
    nsUnicodeToISO885913Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-14" , NS_UNICODETOISO885914_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-14",
    nsUnicodeToISO885914Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-15" , NS_UNICODETOISO885915_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-15",
    nsUnicodeToISO885915Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-8859-16" , NS_UNICODETOISO885916_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-8859-16",
    nsUnicodeToISO885916Constructor, 
  },
  { 
    ENCODER_NAME_BASE "ISO-IR-111" , NS_UNICODETOISOIR111_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "ISO-IR-111",
    nsUnicodeToISOIR111Constructor, 
  },
  { 
    ENCODER_NAME_BASE "windows-1250" , NS_UNICODETOCP1250_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "windows-1250",
    nsUnicodeToCP1250Constructor, 
  },
  { 
    ENCODER_NAME_BASE "windows-1251" , NS_UNICODETOCP1251_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "windows-1251",
    nsUnicodeToCP1251Constructor, 
  },
  { 
    ENCODER_NAME_BASE "windows-1253" , NS_UNICODETOCP1253_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "windows-1253",
    nsUnicodeToCP1253Constructor, 
  },
  { 
    ENCODER_NAME_BASE "windows-1254" , NS_UNICODETOCP1254_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "windows-1254",
    nsUnicodeToCP1254Constructor, 
  },
  { 
    ENCODER_NAME_BASE "windows-1255" , NS_UNICODETOCP1255_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "windows-1255",
    nsUnicodeToCP1255Constructor, 
  },
  { 
    ENCODER_NAME_BASE "windows-1256" , NS_UNICODETOCP1256_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "windows-1256",
    nsUnicodeToCP1256Constructor, 
  },
  { 
    ENCODER_NAME_BASE "windows-1257" , NS_UNICODETOCP1257_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "windows-1257",
    nsUnicodeToCP1257Constructor, 
  },
  { 
    ENCODER_NAME_BASE "windows-1258" , NS_UNICODETOCP1258_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "windows-1258",
    nsUnicodeToCP1258Constructor, 
  },
  { 
    ENCODER_NAME_BASE "TIS-620" , NS_UNICODETOCP874_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "TIS-620",
    nsUnicodeToCP874Constructor, 
  },
  { 
    ENCODER_NAME_BASE "IBM866" , NS_UNICODETOCP866_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "IBM866",
    nsUnicodeToCP866Constructor, 
  },
  { 
    ENCODER_NAME_BASE "KOI8-R" , NS_UNICODETOKOI8R_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "KOI8-R",
    nsUnicodeToKOI8RConstructor, 
  },
  { 
    ENCODER_NAME_BASE "KOI8-U" , NS_UNICODETOKOI8U_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "KOI8-U",
    nsUnicodeToKOI8UConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-ce" , NS_UNICODETOMACCE_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-ce",
    nsUnicodeToMacCEConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-greek" , NS_UNICODETOMACGREEK_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-greek",
    nsUnicodeToMacGreekConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-turkish" , NS_UNICODETOMACTURKISH_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-turkish",
    nsUnicodeToMacTurkishConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-croatian" , NS_UNICODETOMACCROATIAN_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-croatian",
    nsUnicodeToMacCroatianConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-romanian" , NS_UNICODETOMACROMANIAN_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-romanian",
    nsUnicodeToMacRomanianConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-cyrillic" , NS_UNICODETOMACCYRILLIC_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-cyrillic",
    nsUnicodeToMacCyrillicConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-ukrainian" , NS_UNICODETOMACUKRAINIAN_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-ukrainian",
    nsUnicodeToMacUkrainianConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-icelandic" , NS_UNICODETOMACICELANDIC_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-icelandic",
    nsUnicodeToMacIcelandicConstructor, 
  },
  { 
    ENCODER_NAME_BASE "GEOSTD8" , NS_UNICODETOGEOSTD8_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "GEOSTD8",
    nsUnicodeToGEOSTD8Constructor, 
  },
  { 
    ENCODER_NAME_BASE "armscii-8" , NS_UNICODETOARMSCII8_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "armscii-8",
    nsUnicodeToARMSCII8Constructor, 
  },
  { 
    ENCODER_NAME_BASE "x-viet-tcvn5712" , NS_UNICODETOTCVN5712_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-viet-tcvn5712",
    nsUnicodeToTCVN5712Constructor, 
  },
  { 
    ENCODER_NAME_BASE "VISCII" , NS_UNICODETOVISCII_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "VISCII",
    nsUnicodeToVISCIIConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-viet-vps" , NS_UNICODETOVPS_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-viet-vps",
    nsUnicodeToVPSConstructor, 
  },
  { 
    ENCODER_NAME_BASE "UTF-7" , NS_UNICODETOUTF7_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "UTF-7",
    nsUnicodeToUTF7Constructor, 
  },
  { 
    ENCODER_NAME_BASE "x-imap4-modified-utf7" , NS_UNICODETOMUTF7_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-imap4-modified-utf7",
    nsUnicodeToMUTF7Constructor, 
  },
  { 
    ENCODER_NAME_BASE "UTF-16BE" , NS_UNICODETOUTF16BE_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "UTF-16BE",
    nsUnicodeToUTF16BEConstructor, 
  },
  { 
    ENCODER_NAME_BASE "UTF-16LE" , NS_UNICODETOUTF16LE_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "UTF-16LE",
    nsUnicodeToUTF16LEConstructor, 
  },
  { 
    ENCODER_NAME_BASE "UTF-16" , NS_UNICODETOUTF16_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "UTF-16",
    nsUnicodeToUTF16Constructor, 
  },
  { 
    ENCODER_NAME_BASE "UTF-32BE" , NS_UNICODETOUTF32BE_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "UTF-32BE",
    nsUnicodeToUCS4BEConstructor, 
  },
  { 
    ENCODER_NAME_BASE "UTF-32LE" , NS_UNICODETOUTF32LE_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "UTF-32LE",
    nsUnicodeToUCS4LEConstructor, 
  },
    { 
    ENCODER_NAME_BASE "T.61-8bit" , NS_UNICODETOT61_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "T.61-8bit",
    nsUnicodeToT61Constructor, 
  },
  { 
    ENCODER_NAME_BASE "x-user-defined" , NS_UNICODETOUSERDEFINED_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-user-defined",
    nsUnicodeToUserDefinedConstructor, 
  },
  { 
    ENCODER_NAME_BASE "Adobe-Symbol-Encoding" , NS_UNICODETOSYMBOL_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "Adobe-Symbol-Encoding",
    nsUnicodeToSymbolConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-zapf-dingbats" , NS_UNICODETOZAPFDINGBATS_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-zapf-dingbats",
    nsUnicodeToZapfDingbatConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-arabic" , NS_UNICODETOMACARABIC_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-arabic",
    nsUnicodeToMacArabicConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-devanagari" , NS_UNICODETOMACDEVANAGARI_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-devanagari",
    nsUnicodeToMacDevanagariConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-farsi" , NS_UNICODETOMACFARSI_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-farsi",
    nsUnicodeToMacFarsiConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-gurmukhi" , NS_UNICODETOMACGURMUKHI_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-gurmukhi",
    nsUnicodeToMacGurmukhiConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-gujarati" , NS_UNICODETOMACGUJARATI_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-gujarati",
    nsUnicodeToMacGujaratiConstructor, 
  },
  { 
    ENCODER_NAME_BASE "x-mac-hebrew" , NS_UNICODETOMACHEBREW_CID, 
    NS_UNICODEENCODER_CONTRACTID_BASE "x-mac-hebrew",
    nsUnicodeToMacHebrewConstructor, 
  }
};

NS_IMPL_NSGETMODULE(nsUCvLatinModule, components);

