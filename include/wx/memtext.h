///////////////////////////////////////////////////////////////////////////////
// Name:        wx/memtext.h
// Purpose:     wxMemoryText allows to use wxTextBuffer without a file
// Created:     14.11.01
// Author:      Morten Hanssen
// Copyright:   (c) 2001 Morten Hanssen
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_MEMTEXT_H
#define _WX_MEMTEXT_H

#include "wx/defs.h"

// there is no separate setting for wxMemoryText, it's smallish anyhow
#if wxUSE_TEXTBUFFER

#include "wx/strconv.h"
#include "wx/textbuf.h"

// ----------------------------------------------------------------------------
// wxMemoryText
// ----------------------------------------------------------------------------

class WXDLLIMPEXP_BASE wxMemoryText : public wxTextBuffer
{
public:
    // Constructors.
    wxMemoryText() = default;
    wxMemoryText(const wxString& name) : wxTextBuffer(name) { }

protected:
    virtual bool OnExists() const override
        { return false; }

    virtual bool OnOpen(const wxString & WXUNUSED(strBufferName),
                        wxTextBufferOpenMode WXUNUSED(OpenMode)) override
        { return true; }

    virtual bool OnClose() override
        { return true; }

    virtual bool OnRead(const wxMBConv& WXUNUSED(conv)) override
        { return true; }

    virtual bool OnWrite(wxTextFileType WXUNUSED(typeNew),
                         const wxMBConv& WXUNUSED(conv) = wxMBConvUTF8()) override
        { return true; }

private:
    wxDECLARE_NO_COPY_CLASS(wxMemoryText);
};

#endif // wxUSE_TEXTBUFFER

#endif // _WX_MEMTEXT_H

