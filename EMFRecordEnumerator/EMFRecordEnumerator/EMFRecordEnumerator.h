/*++

     /$$$$$$$                                               /$$
    | $$__  $$                                             | $$
    | $$  \ $$ /$$$$$$   /$$$$$$  /$$  /$$$$$$   /$$$$$$$ /$$$$$$
    | $$$$$$$//$$__  $$ /$$__  $$|__/ /$$__  $$ /$$_____/|_  $$_/
    | $$____/| $$  \__/| $$  \ $$ /$$| $$$$$$$$| $$        | $$
    | $$     | $$      | $$  | $$| $$| $$_____/| $$        | $$ /$$
    | $$     | $$      |  $$$$$$/| $$|  $$$$$$$|  $$$$$$$  |  $$$$/
    |__/     |__/       \______/ | $$ \_______/ \_______/   \___/
                            /$$  | $$
                           |  $$$$$$/
                            \______/
      /$$$$$$            /$$           /$$         /$$     /$$
     /$$__  $$          |__/          | $$        | $$    |__/
    | $$  \__/  /$$$$$$  /$$  /$$$$$$$| $$$$$$$  /$$$$$$   /$$
    |  $$$$$$  /$$__  $$| $$ /$$_____/| $$__  $$|_  $$_/  | $$
     \____  $$| $$  \__/| $$|  $$$$$$ | $$  \ $$  | $$    | $$
     /$$  \ $$| $$      | $$ \____  $$| $$  | $$  | $$ /$$| $$
    |  $$$$$$/| $$      | $$ /$$$$$$$/| $$  | $$  |  $$$$/| $$
     \______/ |__/      |__/|_______/ |__/  |__/   \___/  |__/

Author : Ashfaq Ansari
Contact: ashfaq[at]payatu[dot]com
Website: http://www.payatu.com/

Copyright (C) 2011-2017 Payatu Technologies Pvt. Ltd. All rights reserved.

This program is free software: you can redistribute it and/or modify it under the terms of
the GNU General Public License as published by the Free Software Foundation, either version
3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

See the file 'LICENSE' for complete copying permission.

Module Name:
    EMFRecordEnumerator.h

Abstract:
    This header file describes function prototypes and data structures
    required by the EMF Record Enumerator.

--*/

#ifndef __EMF_RECORD_ENUMERATOR_H__
    #define __EMF_RECORD_ENUMERATOR_H__

    #pragma once

    #include <stdio.h>
    #include <windows.h>

    const char *EMFRECORDS[] = {"EMR_NONE",
                                "EMR_HEADER",
                                "EMR_POLYBEZIER",
                                "EMR_POLYGON",
                                "EMR_POLYLINE",
                                "EMR_POLYBEZIERTO",
                                "EMR_POLYLINETO",
                                "EMR_POLYPOLYLINE",
                                "EMR_POLYPOLYGON",
                                "EMR_SETWINDOWEXTEX",
                                "EMR_SETWINDOWORGEX",
                                "EMR_SETVIEWPORTEXTEX",
                                "EMR_SETVIEWPORTORGEX",
                                "EMR_SETBRUSHORGEX",
                                "EMR_EOF",
                                "EMR_SETPIXELV",
                                "EMR_SETMAPPERFLAGS",
                                "EMR_SETMAPMODE",
                                "EMR_SETBKMODE",
                                "EMR_SETPOLYFILLMODE",
                                "EMR_SETROP2",
                                "EMR_SETSTRETCHBLTMODE",
                                "EMR_SETTEXTALIGN",
                                "EMR_SETCOLORADJUSTMENT",
                                "EMR_SETTEXTCOLOR",
                                "EMR_SETBKCOLOR",
                                "EMR_OFFSETCLIPRGN",
                                "EMR_MOVETOEX",
                                "EMR_SETMETARGN",
                                "EMR_EXCLUDECLIPRECT",
                                "EMR_INTERSECTCLIPRECT",
                                "EMR_SCALEVIEWPORTEXTEX",
                                "EMR_SCALEWINDOWEXTEX",
                                "EMR_SAVEDC",
                                "EMR_RESTOREDC",
                                "EMR_SETWORLDTRANSFORM",
                                "EMR_MODIFYWORLDTRANSFORM",
                                "EMR_SELECTOBJECT",
                                "EMR_CREATEPEN",
                                "EMR_CREATEBRUSHINDIRECT",
                                "EMR_DELETEOBJECT",
                                "EMR_ANGLEARC",
                                "EMR_ELLIPSE",
                                "EMR_RECTANGLE",
                                "EMR_ROUNDRECT",
                                "EMR_ARC",
                                "EMR_CHORD",
                                "EMR_PIE",
                                "EMR_SELECTPALETTE",
                                "EMR_CREATEPALETTE",
                                "EMR_SETPALETTEENTRIES",
                                "EMR_RESIZEPALETTE",
                                "EMR_REALIZEPALETTE",
                                "EMR_EXTFLOODFILL",
                                "EMR_LINETO",
                                "EMR_ARCTO",
                                "EMR_POLYDRAW",
                                "EMR_SETARCDIRECTION",
                                "EMR_SETMITERLIMIT",
                                "EMR_BEGINPATH",
                                "EMR_ENDPATH",
                                "EMR_CLOSEFIGURE",
                                "EMR_FILLPATH",
                                "EMR_STROKEANDFILLPATH",
                                "EMR_STROKEPATH",
                                "EMR_FLATTENPATH",
                                "EMR_WIDENPATH",
                                "EMR_SELECTCLIPPATH",
                                "EMR_ABORTPATH",
                                "EMR_NONE",
                                "EMR_GDICOMMENT",
                                "EMR_FILLRGN",
                                "EMR_FRAMERGN",
                                "EMR_INVERTRGN",
                                "EMR_PAINTRGN",
                                "EMR_EXTSELECTCLIPRGN",
                                "EMR_BITBLT",
                                "EMR_STRETCHBLT",
                                "EMR_MASKBLT",
                                "EMR_PLGBLT",
                                "EMR_SETDIBITSTODEVICE",
                                "EMR_STRETCHDIBITS",
                                "EMR_EXTCREATEFONTINDIRECTW",
                                "EMR_EXTTEXTOUTA",
                                "EMR_EXTTEXTOUTW",
                                "EMR_POLYBEZIER16",
                                "EMR_POLYGON16",
                                "EMR_POLYLINE16",
                                "EMR_POLYBEZIERTO16",
                                "EMR_POLYLINETO16",
                                "EMR_POLYPOLYLINE16",
                                "EMR_POLYPOLYGON16",
                                "EMR_POLYDRAW16",
                                "EMR_CREATEMONOBRUSH",
                                "EMR_CREATEDIBPATTERNBRUSHPT",
                                "EMR_EXTCREATEPEN",
                                "EMR_POLYTEXTOUTA",
                                "EMR_POLYTEXTOUTW",
                                "EMR_SETICMMODE",
                                "EMR_CREATECOLORSPACE",
                                "EMR_SETCOLORSPACE",
                                "EMR_DELETECOLORSPACE",
                                "EMR_GLSRECORD",
                                "EMR_GLSBOUNDEDRECORD",
                                "EMR_PIXELFORMAT",
                                "EMR_DRAWESCAPE",
                                "EMR_EXTESCAPE",
                                "EMR_RESERVED_107",
                                "EMR_SMALLTEXTOUT",
                                "EMR_FORCEUFIMAPPING",
                                "EMR_NAMEDESCAPE",
                                "EMR_COLORCORRECTPALETTE",
                                "EMR_SETICMPROFILEA",
                                "EMR_SETICMPROFILEW",
                                "EMR_ALPHABLEND",
                                "EMR_SETLAYOUT",
                                "EMR_TRANSPARENTBLT",
                                "EMR_RESERVED_117",
                                "EMR_GRADIENTFILL",
                                "EMR_SETLINKEDUFIS",
                                "EMR_SETTEXTJUSTIFICATION",
                                "EMR_COLORMATCHTOTARGETW",
                                "EMR_CREATECOLORSPACEW"};

    LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
    LRESULT CALLBACK EnhMetaFileProc(HDC hdc, HANDLETABLE *pHandleTable, CONST ENHMETARECORD *pEmfRecord, INT Handles, LPARAM pData);

#endif  //__EMF_RECORD_ENUMERATOR_H__