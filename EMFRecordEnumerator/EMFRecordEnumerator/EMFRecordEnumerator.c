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
    EMFRecordEnumerator.c

Abstract:
    This module implements the functions to enumerate EMF records
    using EnhMetaFileProc.

--*/

#include "EMFRecordEnumerator.h"

LRESULT CALLBACK EnhMetaFileProc(HDC hdc, HANDLETABLE *pHandleTable, CONST ENHMETARECORD *pEmfRecord, INT Handles, LPARAM pData)
{
    CHAR recordName[1024];

    sprintf_s(recordName, sizeof(recordName), "%s", EMFRECORDS[pEmfRecord->iType]);
    printf("%s\n", recordName);
    
    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return EXIT_SUCCESS;
}


INT main(UINT argc, PTCHAR argv[])
{
    RECT         rect;
    HWND         hwnd;
    HENHMETAFILE hemf;
    WNDCLASS     wndclass = { 0 };
    static PTCHAR szAppName = "HackSysTeam";

    wndclass.lpfnWndProc = WndProc;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("Unable to register class"), szAppName, MB_ICONERROR);
        return EXIT_FAILURE;
    }

    hwnd = CreateWindowEx(0, szAppName, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0);

    GetClientRect(hwnd, &rect);

    hemf = GetEnhMetaFile(TEXT(argv[1]));

    if (hemf)
    {
        EnumEnhMetaFile(NULL, hemf, EnhMetaFileProc, NULL, &rect);
        DeleteEnhMetaFile(hemf);
    }

    return EXIT_SUCCESS;
}