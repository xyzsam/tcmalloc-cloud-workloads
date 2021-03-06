/** @file my-html-tok.h
 *  @brief Map string to html tag code
 */
/* Warning: This file is generated by /data/home/olly/tmp/xapian-git-snapshot/tags/v1.4.0/xapian/xapian-applications/omega/gen-myhtmltags - do not modify directly! */
/* Copyright (C) 2012,2013 Olly Betts
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef XAPIAN_INCLUDED_MY_HTML_TOK_H
#define XAPIAN_INCLUDED_MY_HTML_TOK_H

enum html_tag {
    ADDRESS = 0,
    APPLET = 1,
    BLOCKQUOTE = 2,
    BR = 3,
    CENTER = 4,
    DD = 5,
    DIR = 6,
    DIV = 7,
    DL = 8,
    DT = 9,
    EMBED = 10,
    FIELDSET = 11,
    FORM = 12,
    H1 = 13,
    H2 = 14,
    H3 = 15,
    H4 = 16,
    H5 = 17,
    H6 = 18,
    HR = 19,
    IFRAME = 20,
    IMG = 21,
    INPUT = 22,
    ISINDEX = 23,
    KEYGEN = 24,
    LEGEND = 25,
    LI = 26,
    LISTING = 27,
    MARQUEE = 28,
    MENU = 29,
    META = 30,
    MULTICOL = 31,
    OBJECT = 32,
    OL = 33,
    OPTION = 34,
    P = 35,
    PLAINTEXT = 36,
    PRE = 37,
    Q = 38,
    SCRIPT = 39,
    SELECT = 40,
    STYLE = 41,
    TABLE = 42,
    TD = 43,
    TEXTAREA = 44,
    TH = 45,
    TITLE = 46,
    TR = 47,
    UL = 48,
    XMP = 49
};

static const unsigned char tab[] = {
    10,

      0, 157,  44,  28,  93, 209, 124,  65,
      5,  16,

    (2 - 1),
    P, 'p',
    Q, 'q',

    (1 - 1),
    PLAINTEXT, 'p','l','a','i','n','t','e','x','t',

    (1 - 1),
    BLOCKQUOTE, 'b','l','o','c','k','q','u','o','t','e',

    (3 - 1),
    FORM, 'f','o','r','m',
    MENU, 'm','e','n','u',
    META, 'm','e','t','a',

    (5 - 1),
    DIR, 'd','i','r',
    DIV, 'd','i','v',
    IMG, 'i','m','g',
    PRE, 'p','r','e',
    XMP, 'x','m','p',

    (3 - 1),
    FIELDSET, 'f','i','e','l','d','s','e','t',
    MULTICOL, 'm','u','l','t','i','c','o','l',
    TEXTAREA, 't','e','x','t','a','r','e','a',

    (5 - 1),
    EMBED, 'e','m','b','e','d',
    INPUT, 'i','n','p','u','t',
    STYLE, 's','t','y','l','e',
    TABLE, 't','a','b','l','e',
    TITLE, 't','i','t','l','e',

    (4 - 1),
    ADDRESS, 'a','d','d','r','e','s','s',
    ISINDEX, 'i','s','i','n','d','e','x',
    LISTING, 'l','i','s','t','i','n','g',
    MARQUEE, 'm','a','r','q','u','e','e',

    (17 - 1),
    BR, 'b','r',
    DD, 'd','d',
    DL, 'd','l',
    DT, 'd','t',
    H1, 'h','1',
    H2, 'h','2',
    H3, 'h','3',
    H4, 'h','4',
    H5, 'h','5',
    H6, 'h','6',
    HR, 'h','r',
    LI, 'l','i',
    OL, 'o','l',
    TD, 't','d',
    TH, 't','h',
    TR, 't','r',
    UL, 'u','l',

    (9 - 1),
    APPLET, 'a','p','p','l','e','t',
    CENTER, 'c','e','n','t','e','r',
    IFRAME, 'i','f','r','a','m','e',
    KEYGEN, 'k','e','y','g','e','n',
    LEGEND, 'l','e','g','e','n','d',
    OBJECT, 'o','b','j','e','c','t',
    OPTION, 'o','p','t','i','o','n',
    SCRIPT, 's','c','r','i','p','t',
    SELECT, 's','e','l','e','c','t'
};

enum { SPACE = 1, COLUMN = 2, BREAK = 3, BLOCK = 4, PAGE = 5, NOCLOSE = 8, TOKEN_SPACE_MASK = 7 };

static const unsigned char token_space[] = {
    BLOCK,
    SPACE | NOCLOSE,
    BLOCK,
    BREAK | NOCLOSE,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    SPACE | NOCLOSE,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    SPACE | NOCLOSE,
    SPACE | NOCLOSE,
    BLOCK | NOCLOSE,
    SPACE | NOCLOSE,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    0 | NOCLOSE,
    BLOCK,
    SPACE | NOCLOSE,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    BLOCK,
    SPACE,
    0,
    BLOCK,
    0,
    BLOCK,
    COLUMN,
    BLOCK,
    COLUMN,
    0,
    BLOCK,
    BLOCK,
    SPACE,
};

#endif
