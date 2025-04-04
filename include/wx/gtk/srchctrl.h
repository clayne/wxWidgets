/////////////////////////////////////////////////////////////////////////////
// Name:        wx/gtk/srchctrl.h
// Purpose:     wxSearchCtrl class - native
// Author:      Kettab Ali
// Created:     2019-12-23
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_GTK_SEARCHCTRL_H_
#define _WX_GTK_SEARCHCTRL_H_

#if wxUSE_SEARCHCTRL

// ----------------------------------------------------------------------------
// wxSearchCtrl
// ----------------------------------------------------------------------------

class WXDLLIMPEXP_CORE wxSearchCtrl : public wxSearchCtrlBase
{
public:
    // creation
    // --------

    wxSearchCtrl() : wxSearchCtrlBase()
    {
        Init();
    }

    wxSearchCtrl(wxWindow *parent, wxWindowID id,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxASCII_STR(wxSearchCtrlNameStr))
        : wxSearchCtrlBase()
    {
        Init();
        Create(parent, id, value, pos, size, style, validator, name);
    }

    virtual ~wxSearchCtrl();

    bool Create(wxWindow *parent, wxWindowID id,
                const wxString& value = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxASCII_STR(wxSearchCtrlNameStr));

#if wxUSE_MENUS
    // get/set search button menu
    // --------------------------
    virtual void SetMenu( wxMenu* menu ) override;
    virtual wxMenu* GetMenu() override;
#endif // wxUSE_MENUS

    // get/set search options
    // ----------------------
    virtual void ShowSearchButton( bool show ) override;
    virtual bool IsSearchButtonVisible() const override;

    virtual void ShowCancelButton( bool show ) override;
    virtual bool IsCancelButtonVisible() const override;

    virtual void SetDescriptiveText(const wxString& text) override;
    virtual wxString GetDescriptiveText() const override;

    virtual void Clear() override;

#if wxUSE_MENUS
    void PopupSearchMenu();
#endif // wxUSE_MENUS

private:
    // From wxTextEntry:
    virtual GtkEditable *GetEditable() const override;


    void Init();

    void GTKCreateSearchEntryWidget();

    // Event handlers
    void OnChar(wxKeyEvent& event);
    void OnText(wxCommandEvent& event);
    void OnTextEnter(wxCommandEvent& event);

    bool HasMenu() const
    {
#if wxUSE_MENUS
        return m_menu != nullptr;
#else // !wxUSE_MENUS
        return false;
#endif // wxUSE_MENUS/!wxUSE_MENUS
    }

protected:
    virtual wxSize DoGetBestSize() const override;
    virtual wxSize DoGetSizeFromTextSize(int xlen, int ylen = -1) const override;
    virtual GdkWindow* GTKGetWindow(wxArrayGdkWindows& windows) const override;

private:
    virtual GtkEntry *GetEntry() const override
        { return m_entry; }

    GtkEntry *m_entry;

#if wxUSE_MENUS
    wxMenu *m_menu;
#endif // wxUSE_MENUS

    bool m_cancelButtonVisible;

    wxDECLARE_DYNAMIC_CLASS(wxSearchCtrl);
    wxDECLARE_EVENT_TABLE();
};

#endif // wxUSE_SEARCHCTRL

#endif // _WX_GTK_SEARCHCTRL_H_
