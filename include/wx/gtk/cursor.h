/////////////////////////////////////////////////////////////////////////////
// Name:        wx/gtk/cursor.h
// Purpose:
// Author:      Robert Roebling
// Copyright:   (c) 1998 Robert Roebling
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_GTK_CURSOR_H_
#define _WX_GTK_CURSOR_H_

class WXDLLIMPEXP_FWD_CORE wxImage;

//-----------------------------------------------------------------------------
// wxCursor
//-----------------------------------------------------------------------------

class WXDLLIMPEXP_CORE wxCursor : public wxCursorBase
{
public:
    wxCursor();
    wxCursor(wxStockCursor id) { InitFromStock(id); }
    wxCursor(const wxBitmap& bitmap, const wxPoint& hotSpot)
        : wxCursor(bitmap, hotSpot.x, hotSpot.y) { }
    wxCursor(const wxBitmap& bitmap, int hotSpotX = 0, int hotSpotY = 0);
#if wxUSE_IMAGE
    wxCursor( const wxImage & image );
    wxCursor(const char* const* xpmData);
#endif // wxUSE_IMAGE
    wxCursor(const wxString& name, wxBitmapType type, const wxPoint& hotSpot)
        : wxCursor(name, type, hotSpot.x, hotSpot.y) { }
    wxCursor(const wxString& name,
             wxBitmapType type = wxCURSOR_DEFAULT_TYPE,
             int hotSpotX = 0, int hotSpotY = 0);

    // Non-portable wxGTK-specific ctor.
    wxCursor( const char bits[], int width, int height,
              int hotSpotX = -1, int hotSpotY = -1,
              const char maskBits[] = nullptr,
              const wxColour* fg = nullptr, const wxColour* bg = nullptr);

    virtual wxPoint GetHotSpot() const override;

    // implementation

    GdkCursor *GetCursor() const;

protected:
    void InitFromStock(wxStockCursor);
#if wxUSE_IMAGE
    void InitFromImage(const wxImage& image);
#endif
    void
    InitFromBitmap(const wxBitmap& bitmap, int hotSpotX, int hotSpotY,
                   const wxColour *fg = nullptr, const wxColour *bg = nullptr);

    virtual wxGDIRefData *CreateGDIRefData() const override;
    wxNODISCARD virtual wxGDIRefData *CloneGDIRefData(const wxGDIRefData *data) const override;

private:
    wxDECLARE_DYNAMIC_CLASS(wxCursor);
};

#endif // _WX_GTK_CURSOR_H_
