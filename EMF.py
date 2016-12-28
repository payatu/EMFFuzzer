# -*- coding: utf-8 -*-

"""

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
    EMF.py

Abstract:
    This is the fix up module for EMF Fuzzer.

"""

__author__ = 'Ashfaq Ansari'
__version__ = '1.0'

#import code
#code.InteractiveConsole(locals=locals()).interact()


def is_header_extension_used(element, header_type):
    header_size = 88

    root_element = element.getRoot()
    size = int(root_element.find('Size').DefaultValue)
    n_description = int(root_element.find('nDescription').DefaultValue)
    off_description = int(root_element.find('offDescription').DefaultValue)
    off_pixel_format = int(root_element.find('offPixelFormat').DefaultValue)
    cb_pixel_format = int(root_element.find('cbPixelFormat').DefaultValue)

    if size >= 88:
        header_size = size

        if (off_description >= 88) and ((off_description + (n_description * 2)) <= size):
            header_size = off_description
        else:
            if header_size >= 100:
                if (off_pixel_format >= 100) and ((off_pixel_format + cb_pixel_format) <= size):
                    if off_pixel_format < header_size:
                        header_size = off_pixel_format

    if header_type == "HeaderExtension1":
        if header_size >= 100:
            return True
    elif header_type == "HeaderExtension2":
        if header_size >= 108:
            return True
    return False


def get_utf16_string_length(size):
    length = (size * 2) + 2

    if length <= 2:
        length = 0
    return length


def set_utf16_string_length(size):
    length = (size / 2) - 1

    if length <= 0:
        length = 0
    return length
