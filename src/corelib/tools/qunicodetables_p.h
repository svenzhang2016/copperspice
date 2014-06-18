/***********************************************************************
*
* Copyright (c) 2012-2014 Barbara Geller
* Copyright (c) 2012-2014 Ansel Sermersheim
* Copyright (c) 2012-2014 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
*
* This file is part of CopperSpice.
*
* CopperSpice is free software: you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with CopperSpice.  If not, see
* <http://www.gnu.org/licenses/>.
*
***********************************************************************/

/* This file is autogenerated from the Unicode 5.0 database. Do not edit */

#ifndef QUNICODETABLES_P_H
#define QUNICODETABLES_P_H

#include <qchar.h>

QT_BEGIN_NAMESPACE

#define UNICODE_DATA_VERSION QChar::Unicode_5_0
#define UNICODE_LAST_CODEPOINT 0x10ffff

namespace QUnicodeTables {

struct Properties {
   ushort category         : 8; /* 5 needed */
   ushort line_break_class : 8; /* 6 needed */
   ushort direction        : 8; /* 5 needed */
   ushort combiningClass   : 8;
   ushort joining          : 2;
   signed short digitValue : 6; /* 5 needed */
   ushort unicodeVersion   : 4;
   ushort lowerCaseSpecial : 1;
   ushort upperCaseSpecial : 1;
   ushort titleCaseSpecial : 1;
   ushort caseFoldSpecial  : 1; /* currently unused */
   signed short mirrorDiff    : 16;
   signed short lowerCaseDiff : 16;
   signed short upperCaseDiff : 16;
   signed short titleCaseDiff : 16;
   signed short caseFoldDiff  : 16;
   ushort graphemeBreak    : 8; /* 4 needed */
   ushort wordBreak        : 8; /* 4 needed */
   ushort sentenceBreak    : 8; /* 4 needed */
};
Q_CORE_EXPORT const Properties *QT_FASTCALL properties(uint ucs4);
Q_CORE_EXPORT const Properties *QT_FASTCALL properties(ushort ucs2);

// See http://www.unicode.org/reports/tr24/tr24-5.html
enum Script {
   Common,
   Greek,
   Cyrillic,
   Armenian,
   Hebrew,
   Arabic,
   Syriac,
   Thaana,
   Devanagari,
   Bengali,
   Gurmukhi,
   Gujarati,
   Oriya,
   Tamil,
   Telugu,
   Kannada,
   Malayalam,
   Sinhala,
   Thai,
   Lao,
   Tibetan,
   Myanmar,
   Georgian,
   Hangul,
   Ogham,
   Runic,
   Khmer,
   Nko,
   Inherited,
   ScriptCount = Inherited,
   Latin = Common,
   Ethiopic = Common,
   Cherokee = Common,
   CanadianAboriginal = Common,
   Mongolian = Common,
   Hiragana = Common,
   Katakana = Common,
   Bopomofo = Common,
   Han = Common,
   Yi = Common,
   OldItalic = Common,
   Gothic = Common,
   Deseret = Common,
   Tagalog = Common,
   Hanunoo = Common,
   Buhid = Common,
   Tagbanwa = Common,
   Limbu = Common,
   TaiLe = Common,
   LinearB = Common,
   Ugaritic = Common,
   Shavian = Common,
   Osmanya = Common,
   Cypriot = Common,
   Braille = Common,
   Buginese = Common,
   Coptic = Common,
   NewTaiLue = Common,
   Glagolitic = Common,
   Tifinagh = Common,
   SylotiNagri = Common,
   OldPersian = Common,
   Kharoshthi = Common,
   Balinese = Common,
   Cuneiform = Common,
   Phoenician = Common,
   PhagsPa = Common
};
enum { ScriptSentinel = 32 };


enum GraphemeBreak {
   GraphemeBreakOther,
   GraphemeBreakCR,
   GraphemeBreakLF,
   GraphemeBreakControl,
   GraphemeBreakExtend,
   GraphemeBreakL,
   GraphemeBreakV,
   GraphemeBreakT,
   GraphemeBreakLV,
   GraphemeBreakLVT
};


enum WordBreak {
   WordBreakOther,
   WordBreakFormat,
   WordBreakKatakana,
   WordBreakALetter,
   WordBreakMidLetter,
   WordBreakMidNum,
   WordBreakNumeric,
   WordBreakExtendNumLet
};


enum SentenceBreak {
   SentenceBreakOther,
   SentenceBreakSep,
   SentenceBreakFormat,
   SentenceBreakSp,
   SentenceBreakLower,
   SentenceBreakUpper,
   SentenceBreakOLetter,
   SentenceBreakNumeric,
   SentenceBreakATerm,
   SentenceBreakSTerm,
   SentenceBreakClose
};


// see http://www.unicode.org/reports/tr14/tr14-19.html
// we don't use the XX, AI and CB properties and map them to AL instead.
// as we don't support any EBDIC based OS'es, NL is ignored and mapped to AL as well.
enum LineBreakClass {
   LineBreak_OP, LineBreak_CL, LineBreak_QU, LineBreak_GL, LineBreak_NS,
   LineBreak_EX, LineBreak_SY, LineBreak_IS, LineBreak_PR, LineBreak_PO,
   LineBreak_NU, LineBreak_AL, LineBreak_ID, LineBreak_IN, LineBreak_HY,
   LineBreak_BA, LineBreak_BB, LineBreak_B2, LineBreak_ZW, LineBreak_CM,
   LineBreak_WJ, LineBreak_H2, LineBreak_H3, LineBreak_JL, LineBreak_JV,
   LineBreak_JT, LineBreak_SA, LineBreak_SG,
   LineBreak_SP, LineBreak_CR, LineBreak_LF, LineBreak_BK
};


Q_CORE_EXPORT QUnicodeTables::LineBreakClass QT_FASTCALL lineBreakClass(uint ucs4);
inline int lineBreakClass(QChar ch)
{
   return lineBreakClass(ch.unicode());
}

Q_CORE_EXPORT int QT_FASTCALL script(uint ucs4);
inline int script(QChar ch)
{
   return script(ch.unicode());
}

} // namespace QUnicodeTables

QT_END_NAMESPACE

#endif // QUNICODETABLES_P_H
