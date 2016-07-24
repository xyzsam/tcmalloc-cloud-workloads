/** @file mimemap.h
 *  @brief Map extension to MIME Content-Type
 */
/* Warning: This file is generated by /data/home/olly/tmp/xapian-git-snapshot/tags/v1.4.0/xapian/xapian-applications/omega/gen-mimemap - do not modify directly! */
/* Copyright (C) 2012,2013,2015 Olly Betts
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

#ifndef OMEGA_INCLUDED_MIMEMAP_H
#define OMEGA_INCLUDED_MIMEMAP_H

enum mime_type {
    TEXT_PLAIN = 0,
    TEXT_HTML = 1,
    APPLICATION_X_MAFF = 2,
    APPLICATION_X_MIMEARCHIVE = 3,
    TEXT_X_RST = 4,
    TEXT_CSV = 5,
    APPLICATION_PDF = 6,
    APPLICATION_POSTSCRIPT = 7,
    APPLICATION_VND_OASIS_OPENDOCUMENT_TEXT = 8,
    APPLICATION_VND_OASIS_OPENDOCUMENT_SPREADSHEET = 9,
    APPLICATION_VND_OASIS_OPENDOCUMENT_PRESENTATION = 10,
    APPLICATION_VND_OASIS_OPENDOCUMENT_GRAPHICS = 11,
    APPLICATION_VND_OASIS_OPENDOCUMENT_CHART = 12,
    APPLICATION_VND_OASIS_OPENDOCUMENT_FORMULA = 13,
    APPLICATION_VND_OASIS_OPENDOCUMENT_DATABASE = 14,
    APPLICATION_VND_OASIS_OPENDOCUMENT_IMAGE = 15,
    APPLICATION_VND_OASIS_OPENDOCUMENT_TEXT_MASTER = 16,
    APPLICATION_VND_OASIS_OPENDOCUMENT_TEXT_TEMPLATE = 17,
    APPLICATION_VND_OASIS_OPENDOCUMENT_SPREADSHEET_TEMPLATE = 18,
    APPLICATION_VND_OASIS_OPENDOCUMENT_PRESENTATION_TEMPLATE = 19,
    APPLICATION_VND_OASIS_OPENDOCUMENT_GRAPHICS_TEMPLATE = 20,
    APPLICATION_VND_OASIS_OPENDOCUMENT_CHART_TEMPLATE = 21,
    APPLICATION_VND_OASIS_OPENDOCUMENT_FORMULA_TEMPLATE = 22,
    APPLICATION_VND_OASIS_OPENDOCUMENT_IMAGE_TEMPLATE = 23,
    APPLICATION_VND_OASIS_OPENDOCUMENT_TEXT_WEB = 24,
    APPLICATION_VND_SUN_XML_CALC = 25,
    APPLICATION_VND_SUN_XML_CALC_TEMPLATE = 26,
    APPLICATION_VND_SUN_XML_DRAW = 27,
    APPLICATION_VND_SUN_XML_DRAW_TEMPLATE = 28,
    APPLICATION_VND_SUN_XML_IMPRESS = 29,
    APPLICATION_VND_SUN_XML_IMPRESS_TEMPLATE = 30,
    APPLICATION_VND_SUN_XML_MATH = 31,
    APPLICATION_VND_SUN_XML_WRITER = 32,
    APPLICATION_VND_SUN_XML_WRITER_GLOBAL = 33,
    APPLICATION_VND_SUN_XML_WRITER_TEMPLATE = 34,
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_WORDPROCESSINGML_DOCUMENT = 35,
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_WORDPROCESSINGML_TEMPLATE = 36,
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_SPREADSHEETML_SHEET = 37,
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_SPREADSHEETML_TEMPLATE = 38,
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_PRESENTATIONML_PRESENTATION = 39,
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_PRESENTATIONML_SLIDESHOW = 40,
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_PRESENTATIONML_TEMPLATE = 41,
    APPLICATION_VND_MS_XPSDOCUMENT = 42,
    APPLICATION_MSWORD = 43,
    APPLICATION_VND_WORDPERFECT = 44,
    APPLICATION_VND_MS_WORKS = 45,
    APPLICATION_X_ABIWORD = 46,
    APPLICATION_X_ABIWORD_COMPRESSED = 47,
    TEXT_RTF = 48,
    APPLICATION_VND_MS_EXCEL = 49,
    APPLICATION_VND_MS_POWERPOINT = 50,
    APPLICATION_X_MSPUBLISHER = 51,
    APPLICATION_VND_MS_OUTLOOK = 52,
    MESSAGE_RFC822 = 53,
    TEXT_X_PERL = 54,
    APPLICATION_X_DVI = 55,
    IMAGE_VND_DJVU = 56,
    IMAGE_SVG_XML = 57,
    APPLICATION_X_DEBIAN_PACKAGE = 58,
    APPLICATION_X_REDHAT_PACKAGE_MANAGER = 59,
    APPLICATION_ATOM_XML = 60,
    IGNORE = 61
};

static const unsigned char tab[] = {
    14,

      0,  57, 190,  79,  38,   5,  13,   1,
      1,   1,   1,   1,   1,  22,

    (2 - 1),
    IGNORE, 'a',
    IGNORE, 'o',

    (1 - 1),
    IGNORE, 's','q','l','i','t','e',

    (1 - 1),
    IGNORE, 's','q','l','i','t','e','3',

    (1 - 1),
    IGNORE, 's','q','l','i','t','e','-','j','o','u','r','n','a','l',

    (3 - 1),
    IGNORE, 'd','y','l','i','b',
    APPLICATION_X_MIMEARCHIVE, 'm','h','t','m','l',
    TEXT_HTML, 's','h','t','m','l',

    (7 - 1),
    APPLICATION_POSTSCRIPT, 'a','i',
    IGNORE, 'd','b',
    IGNORE, 'j','s',
    TEXT_X_PERL, 'p','l',
    TEXT_X_PERL, 'p','m',
    APPLICATION_POSTSCRIPT, 'p','s',
    IGNORE, 's','o',

    (22 - 1),
    APPLICATION_ATOM_XML, 'a','t','o','m',
    IMAGE_VND_DJVU, 'd','j','v','u',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_WORDPROCESSINGML_DOCUMENT, 'd','o','c','m',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_WORDPROCESSINGML_DOCUMENT, 'd','o','c','x',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_WORDPROCESSINGML_TEMPLATE, 'd','o','t','m',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_WORDPROCESSINGML_TEMPLATE, 'd','o','t','x',
    TEXT_HTML, 'h','t','m','l',
    APPLICATION_X_MAFF, 'm','a','f','f',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_PRESENTATIONML_TEMPLATE, 'p','o','t','m',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_PRESENTATIONML_TEMPLATE, 'p','o','t','x',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_PRESENTATIONML_SLIDESHOW, 'p','p','s','m',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_PRESENTATIONML_SLIDESHOW, 'p','p','s','x',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_PRESENTATIONML_PRESENTATION, 'p','p','t','m',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_PRESENTATIONML_PRESENTATION, 'p','p','t','x',
    TEXT_X_RST, 'r','e','s','t',
    TEXT_PLAIN, 't','e','x','t',
    APPLICATION_X_DEBIAN_PACKAGE, 'u','d','e','b',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_SPREADSHEETML_SHEET, 'x','l','s','m',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_SPREADSHEETML_SHEET, 'x','l','s','x',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_SPREADSHEETML_TEMPLATE, 'x','l','t','m',
    APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_SPREADSHEETML_TEMPLATE, 'x','l','t','x',
    APPLICATION_X_ABIWORD_COMPRESSED, 'z','a','b','w',

    (80 - 1),
    APPLICATION_X_ABIWORD, 'a','b','w',
    IGNORE, 'a','d','m',
    IGNORE, 'b','i','n',
    IGNORE, 'c','o','m',
    IGNORE, 'c','s','s',
    TEXT_CSV, 'c','s','v',
    IGNORE, 'c','u','r',
    IGNORE, 'd','a','t',
    APPLICATION_X_DEBIAN_PACKAGE, 'd','e','b',
    IMAGE_VND_DJVU, 'd','j','v',
    IGNORE, 'd','l','l',
    APPLICATION_MSWORD, 'd','o','t',
    APPLICATION_X_DVI, 'd','v','i',
    MESSAGE_RFC822, 'e','m','l',
    APPLICATION_POSTSCRIPT, 'e','p','s',
    IGNORE, 'e','x','e',
    IGNORE, 'f','o','n',
    TEXT_HTML, 'h','t','m',
    IGNORE, 'i','c','o',
    IGNORE, 'j','a','r',
    IGNORE, 'l','i','b',
    IGNORE, 'l','n','k',
    APPLICATION_X_MIMEARCHIVE, 'm','h','t',
    APPLICATION_VND_MS_OUTLOOK, 'm','s','g',
    IGNORE, 'm','s','i',
    IGNORE, 'm','s','p',
    IGNORE, 'o','b','j',
    APPLICATION_VND_OASIS_OPENDOCUMENT_DATABASE, 'o','d','b',
    APPLICATION_VND_OASIS_OPENDOCUMENT_CHART, 'o','d','c',
    APPLICATION_VND_OASIS_OPENDOCUMENT_FORMULA, 'o','d','f',
    APPLICATION_VND_OASIS_OPENDOCUMENT_GRAPHICS, 'o','d','g',
    APPLICATION_VND_OASIS_OPENDOCUMENT_IMAGE, 'o','d','i',
    APPLICATION_VND_OASIS_OPENDOCUMENT_TEXT_MASTER, 'o','d','m',
    APPLICATION_VND_OASIS_OPENDOCUMENT_PRESENTATION, 'o','d','p',
    APPLICATION_VND_OASIS_OPENDOCUMENT_SPREADSHEET, 'o','d','s',
    APPLICATION_VND_OASIS_OPENDOCUMENT_TEXT, 'o','d','t',
    APPLICATION_VND_MS_OUTLOOK, 'o','f','t',
    APPLICATION_VND_OASIS_OPENDOCUMENT_CHART_TEMPLATE, 'o','t','c',
    APPLICATION_VND_OASIS_OPENDOCUMENT_FORMULA_TEMPLATE, 'o','t','f',
    APPLICATION_VND_OASIS_OPENDOCUMENT_GRAPHICS_TEMPLATE, 'o','t','g',
    APPLICATION_VND_OASIS_OPENDOCUMENT_TEXT_WEB, 'o','t','h',
    APPLICATION_VND_OASIS_OPENDOCUMENT_IMAGE_TEMPLATE, 'o','t','i',
    APPLICATION_VND_OASIS_OPENDOCUMENT_PRESENTATION_TEMPLATE, 'o','t','p',
    APPLICATION_VND_OASIS_OPENDOCUMENT_SPREADSHEET_TEMPLATE, 'o','t','s',
    APPLICATION_VND_OASIS_OPENDOCUMENT_TEXT_TEMPLATE, 'o','t','t',
    APPLICATION_PDF, 'p','d','f',
    TEXT_HTML, 'p','h','p',
    TEXT_X_PERL, 'p','o','d',
    APPLICATION_VND_MS_POWERPOINT, 'p','p','s',
    APPLICATION_VND_MS_POWERPOINT, 'p','p','t',
    APPLICATION_X_MSPUBLISHER, 'p','u','b',
    IGNORE, 'p','y','c',
    IGNORE, 'p','y','d',
    IGNORE, 'p','y','o',
    APPLICATION_X_REDHAT_PACKAGE_MANAGER, 'r','p','m',
    TEXT_X_RST, 'r','s','t',
    TEXT_RTF, 'r','t','f',
    APPLICATION_VND_SUN_XML_CALC_TEMPLATE, 's','t','c',
    APPLICATION_VND_SUN_XML_DRAW_TEMPLATE, 's','t','d',
    APPLICATION_VND_SUN_XML_IMPRESS_TEMPLATE, 's','t','i',
    APPLICATION_VND_SUN_XML_WRITER_TEMPLATE, 's','t','w',
    IMAGE_SVG_XML, 's','v','g',
    APPLICATION_VND_SUN_XML_CALC, 's','x','c',
    APPLICATION_VND_SUN_XML_DRAW, 's','x','d',
    APPLICATION_VND_SUN_XML_WRITER_GLOBAL, 's','x','g',
    APPLICATION_VND_SUN_XML_IMPRESS, 's','x','i',
    APPLICATION_VND_SUN_XML_MATH, 's','x','m',
    APPLICATION_VND_SUN_XML_WRITER, 's','x','w',
    IGNORE, 't','m','p',
    IGNORE, 't','t','f',
    TEXT_PLAIN, 't','x','t',
    APPLICATION_VND_WORDPERFECT, 'w','p','d',
    APPLICATION_VND_MS_WORKS, 'w','p','s',
    APPLICATION_VND_MS_WORKS, 'w','p','t',
    APPLICATION_VND_MS_EXCEL, 'x','l','a',
    APPLICATION_VND_MS_EXCEL, 'x','l','b',
    APPLICATION_VND_MS_EXCEL, 'x','l','r',
    APPLICATION_VND_MS_EXCEL, 'x','l','s',
    APPLICATION_VND_MS_EXCEL, 'x','l','t',
    APPLICATION_VND_MS_XPSDOCUMENT, 'x','p','s'
};

static const char * const default_mime_map[] = {
    "text/plain",
    "text/html",
    "application/x-maff",
    "application/x-mimearchive",
    "text/x-rst",
    "text/csv",
    "application/pdf",
    "application/postscript",
    "application/vnd.oasis.opendocument.text",
    "application/vnd.oasis.opendocument.spreadsheet",
    "application/vnd.oasis.opendocument.presentation",
    "application/vnd.oasis.opendocument.graphics",
    "application/vnd.oasis.opendocument.chart",
    "application/vnd.oasis.opendocument.formula",
    "application/vnd.oasis.opendocument.database",
    "application/vnd.oasis.opendocument.image",
    "application/vnd.oasis.opendocument.text-master",
    "application/vnd.oasis.opendocument.text-template",
    "application/vnd.oasis.opendocument.spreadsheet-template",
    "application/vnd.oasis.opendocument.presentation-template",
    "application/vnd.oasis.opendocument.graphics-template",
    "application/vnd.oasis.opendocument.chart-template",
    "application/vnd.oasis.opendocument.formula-template",
    "application/vnd.oasis.opendocument.image-template",
    "application/vnd.oasis.opendocument.text-web",
    "application/vnd.sun.xml.calc",
    "application/vnd.sun.xml.calc.template",
    "application/vnd.sun.xml.draw",
    "application/vnd.sun.xml.draw.template",
    "application/vnd.sun.xml.impress",
    "application/vnd.sun.xml.impress.template",
    "application/vnd.sun.xml.math",
    "application/vnd.sun.xml.writer",
    "application/vnd.sun.xml.writer.global",
    "application/vnd.sun.xml.writer.template",
    "application/vnd.openxmlformats-officedocument.wordprocessingml.document",
    "application/vnd.openxmlformats-officedocument.wordprocessingml.template",
    "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet",
    "application/vnd.openxmlformats-officedocument.spreadsheetml.template",
    "application/vnd.openxmlformats-officedocument.presentationml.presentation",
    "application/vnd.openxmlformats-officedocument.presentationml.slideshow",
    "application/vnd.openxmlformats-officedocument.presentationml.template",
    "application/vnd.ms-xpsdocument",
    "application/msword",
    "application/vnd.wordperfect",
    "application/vnd.ms-works",
    "application/x-abiword",
    "application/x-abiword-compressed",
    "text/rtf",
    "application/vnd.ms-excel",
    "application/vnd.ms-powerpoint",
    "application/x-mspublisher",
    "application/vnd.ms-outlook",
    "message/rfc822",
    "text/x-perl",
    "application/x-dvi",
    "image/vnd.djvu",
    "image/svg+xml",
    "application/x-debian-package",
    "application/x-redhat-package-manager",
    "application/atom+xml",
    "ignore",
};

const size_t MAX_BUILTIN_MIMEMAP_EXTENSION_LEN = 14;

#endif