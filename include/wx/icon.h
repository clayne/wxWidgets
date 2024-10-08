/////////////////////////////////////////////////////////////////////////////
// Name:        wx/icon.h
// Purpose:     wxIcon base header
// Author:      Julian Smart
// Created:
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_ICON_H_BASE_
#define _WX_ICON_H_BASE_

#include "wx/iconloc.h"
#include "wx/variant.h"

// a more readable way to tell
#define wxICON_SCREEN_DEPTH     (-1)


// the wxICON_DEFAULT_TYPE (the wxIcon equivalent of wxBITMAP_DEFAULT_TYPE)
// constant defines the default argument value for wxIcon ctor and wxIcon::LoadFile()
// functions.

#if defined(__WXMSW__)
  #define wxICON_DEFAULT_TYPE   wxBITMAP_TYPE_ICO_RESOURCE
  #include "wx/msw/icon.h"

  #define wxICON_DIFFERENT_FROM_BITMAP
#elif defined(__WXGTK__)
  #ifdef __WINDOWS__
    #define wxICON_DEFAULT_TYPE   wxBITMAP_TYPE_ICO_RESOURCE
  #else
    #define wxICON_DEFAULT_TYPE   wxBITMAP_TYPE_XPM
  #endif
  #include "wx/generic/icon.h"
#elif defined(__WXX11__)
  #define wxICON_DEFAULT_TYPE   wxBITMAP_TYPE_XPM
  #include "wx/generic/icon.h"
#elif defined(__WXDFB__)
  #define wxICON_DEFAULT_TYPE   wxBITMAP_TYPE_XPM
  #include "wx/generic/icon.h"
#elif defined(__WXMAC__)
#if wxOSX_USE_COCOA_OR_CARBON
  #define wxICON_DEFAULT_TYPE   wxBITMAP_TYPE_ICON_RESOURCE
  #include "wx/generic/icon.h"
#else
  // iOS and others
  #define wxICON_DEFAULT_TYPE   wxBITMAP_TYPE_PNG_RESOURCE
  #include "wx/generic/icon.h"
#endif
#elif defined(__WXQT__)
  #ifdef __WINDOWS__
    #define wxICON_DEFAULT_TYPE   wxBITMAP_TYPE_ICO_RESOURCE
  #else
    #define wxICON_DEFAULT_TYPE   wxBITMAP_TYPE_XPM
  #endif
  #include "wx/generic/icon.h"
#endif

#ifndef wxICON_DIFFERENT_FROM_BITMAP
    #define wxICON_IS_BITMAP
#endif

#endif
    // _WX_ICON_H_BASE_
