//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "wxcrafter.h"


// Declare the bitmap loading function
extern void wxC9ED9InitBitmapResources();

static bool bBitmapLoaded = false;


MainFrameBaseClass::MainFrameBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }
    // Set icon(s) to the application/dialog
    wxIconBundle app_icons;
    {
        wxBitmap iconBmp = wxXmlResource::Get()->LoadBitmap(wxT("terminal-16"));
        wxIcon icn;
        icn.CopyFromBitmap(iconBmp);
        app_icons.AddIcon( icn );
    }
    {
        wxBitmap iconBmp = wxXmlResource::Get()->LoadBitmap(wxT("terminal-32"));
        wxIcon icn;
        icn.CopyFromBitmap(iconBmp);
        app_icons.AddIcon( icn );
    }
    SetIcons( app_icons );

    
    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer1);
    
    m_mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800,600), wxTAB_TRAVERSAL);
    
    boxSizer1->Add(m_mainPanel, 1, wxEXPAND, 5);
    
    wxBoxSizer* boxSizer11 = new wxBoxSizer(wxVERTICAL);
    m_mainPanel->SetSizer(boxSizer11);
    
    m_stc = new wxStyledTextCtrl(m_mainPanel, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), 0);
    #ifdef __WXMSW__
    // To get the newer version of the font on MSW, we use font wxSYS_DEFAULT_GUI_FONT with family set to wxFONTFAMILY_TELETYPE
    wxFont m_stcFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_stcFont.SetFamily(wxFONTFAMILY_TELETYPE);
    #else
    wxFont m_stcFont = wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT);
    m_stcFont.SetFamily(wxFONTFAMILY_TELETYPE);
    #endif
    m_stc->SetFont(m_stcFont);
    m_stc->SetFocus();
    // Configure the fold margin
    m_stc->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_stc->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_stc->SetMarginSensitive(4, true);
    m_stc->SetMarginWidth    (4, 0);
    
    // Configure the tracker margin
    m_stc->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_stc->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_stc->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_stc->SetMarginWidth(2, 16);
    m_stc->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    m_stc->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stc->SetMarginWidth(0,0);
    
    // Configure the line symbol margin
    m_stc->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stc->SetMarginMask(3, 0);
    m_stc->SetMarginWidth(3,0);
    // Select the lexer
    m_stc->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stc->StyleClearAll();
    for(int i=0; i<wxSTC_STYLE_MAX; ++i) {
        m_stc->StyleSetFont(i, m_stcFont);
    }
    m_stc->SetWrapMode(0);
    m_stc->SetIndentationGuides(0);
    m_stc->SetKeyWords(0, wxT(""));
    m_stc->SetKeyWords(1, wxT(""));
    m_stc->SetKeyWords(2, wxT(""));
    m_stc->SetKeyWords(3, wxT(""));
    m_stc->SetKeyWords(4, wxT(""));
    
    boxSizer11->Add(m_stc, 1, wxALL|wxEXPAND, 0);
    
    m_menuBar = new wxMenuBar(0);
    this->SetMenuBar(m_menuBar);
    
    m_File = new wxMenu();
    m_menuBar->Append(m_File, _("File"));
    
    m_menuItemSave = new wxMenuItem(m_File, wxID_SAVE, _("Save...\tCtrl-S"), wxT(""), wxITEM_NORMAL);
    m_File->Append(m_menuItemSave);
    
    m_menuItemClear = new wxMenuItem(m_File, wxID_CLEAR, _("Clear View\tCtrl-L"), wxT(""), wxITEM_NORMAL);
    m_File->Append(m_menuItemClear);
    
    m_File->AppendSeparator();
    
    m_menuItemPreferences = new wxMenuItem(m_File, wxID_PREFERENCES, _("Preferences..."), wxT(""), wxITEM_NORMAL);
    m_File->Append(m_menuItemPreferences);
    
    m_File->AppendSeparator();
    
    m_menuItem7 = new wxMenuItem(m_File, wxID_EXIT, _("Exit\tAlt-X"), _("Quit"), wxITEM_NORMAL);
    m_File->Append(m_menuItem7);
    
    m_Signals = new wxMenu();
    m_menuBar->Append(m_Signals, _("Signals"));
    
    m_menuItemINT = new wxMenuItem(m_Signals, ID_SIGINT, _("SIGINT"), wxT(""), wxITEM_NORMAL);
    m_Signals->Append(m_menuItemINT);
    
    m_menuItemTERM = new wxMenuItem(m_Signals, ID_SIGTERM, _("SIGTERM"), wxT(""), wxITEM_NORMAL);
    m_Signals->Append(m_menuItemTERM);
    
    m_menuItemKILL = new wxMenuItem(m_Signals, ID_SIGKILL, _("SIGKILL"), wxT(""), wxITEM_NORMAL);
    m_Signals->Append(m_menuItemKILL);
    
    m_menuItemHUP = new wxMenuItem(m_Signals, ID_SIGHUP, _("SIGHUP"), wxT(""), wxITEM_NORMAL);
    m_Signals->Append(m_menuItemHUP);
    
    m_Help = new wxMenu();
    m_menuBar->Append(m_Help, _("Help"));
    
    m_menuItem9 = new wxMenuItem(m_Help, wxID_ABOUT, _("About..."), wxT(""), wxITEM_NORMAL);
    m_Help->Append(m_menuItem9);
    
    m_timerMarker = new wxTimer;
    m_timerMarker->Start(50, false);
    
    SetName(wxT("MainFrameBaseClass"));
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    CentreOnParent(wxBOTH);
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    this->Connect(wxEVT_IDLE, wxIdleEventHandler(MainFrameBaseClass::OnIdle), NULL, this);
    m_stc->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MainFrameBaseClass::OnKeyDown), NULL, this);
    m_stc->Connect(wxEVT_STC_UPDATEUI, wxStyledTextEventHandler(MainFrameBaseClass::OnStcUpdateUI), NULL, this);
    this->Connect(m_menuItemClear->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnClearView), NULL, this);
    this->Connect(m_menuItemPreferences->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnSettings), NULL, this);
    this->Connect(m_menuItem7->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnExit), NULL, this);
    this->Connect(m_menuItemINT->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnSignal), NULL, this);
    this->Connect(m_menuItemTERM->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnSignal), NULL, this);
    this->Connect(m_menuItemKILL->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnSignal), NULL, this);
    this->Connect(m_menuItemHUP->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnSignal), NULL, this);
    this->Connect(m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnAbout), NULL, this);
    m_timerMarker->Connect(wxEVT_TIMER, wxTimerEventHandler(MainFrameBaseClass::OnAddMarker), NULL, this);
    
}

MainFrameBaseClass::~MainFrameBaseClass()
{
    this->Disconnect(wxEVT_IDLE, wxIdleEventHandler(MainFrameBaseClass::OnIdle), NULL, this);
    m_stc->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(MainFrameBaseClass::OnKeyDown), NULL, this);
    m_stc->Disconnect(wxEVT_STC_UPDATEUI, wxStyledTextEventHandler(MainFrameBaseClass::OnStcUpdateUI), NULL, this);
    this->Disconnect(m_menuItemClear->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnClearView), NULL, this);
    this->Disconnect(m_menuItemPreferences->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnSettings), NULL, this);
    this->Disconnect(m_menuItem7->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnExit), NULL, this);
    this->Disconnect(m_menuItemINT->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnSignal), NULL, this);
    this->Disconnect(m_menuItemTERM->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnSignal), NULL, this);
    this->Disconnect(m_menuItemKILL->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnSignal), NULL, this);
    this->Disconnect(m_menuItemHUP->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnSignal), NULL, this);
    this->Disconnect(m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrameBaseClass::OnAbout), NULL, this);
    m_timerMarker->Disconnect(wxEVT_TIMER, wxTimerEventHandler(MainFrameBaseClass::OnAddMarker), NULL, this);
    
    m_timerMarker->Stop();
    wxDELETE( m_timerMarker );

}

SettingsDlgBase::SettingsDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer27 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer27);
    
    wxFlexGridSizer* flexGridSizer29 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer29->SetFlexibleDirection( wxBOTH );
    flexGridSizer29->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer29->AddGrowableCol(1);
    
    boxSizer27->Add(flexGridSizer29, 1, wxALL|wxEXPAND, 5);
    
    m_staticText31 = new wxStaticText(this, wxID_ANY, _("Text Colour:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer29->Add(m_staticText31, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_colourPickerFG = new wxColourPickerCtrl(this, wxID_ANY, wxColour(wxT("rgb(255,255,255)")), wxDefaultPosition, wxSize(-1,-1), wxCLRP_DEFAULT_STYLE);
    
    flexGridSizer29->Add(m_colourPickerFG, 0, wxALL|wxEXPAND, 5);
    
    m_staticText35 = new wxStaticText(this, wxID_ANY, _("Background Colour:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer29->Add(m_staticText35, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_colourPickerBG = new wxColourPickerCtrl(this, wxID_ANY, wxColour(wxT("rgb(32,32,32)")), wxDefaultPosition, wxSize(-1,-1), wxCLRP_DEFAULT_STYLE);
    
    flexGridSizer29->Add(m_colourPickerBG, 0, wxALL|wxEXPAND, 5);
    
    m_staticText39 = new wxStaticText(this, wxID_ANY, _("Font:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer29->Add(m_staticText39, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    #ifdef __WXMSW__
    // To get the newer version of the font on MSW, we use font wxSYS_DEFAULT_GUI_FONT with family set to wxFONTFAMILY_TELETYPE
    wxFont m_fontPickerFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_fontPickerFont.SetFamily(wxFONTFAMILY_TELETYPE);
    #else
    wxFont m_fontPickerFont = wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT);
    m_fontPickerFont.SetFamily(wxFONTFAMILY_TELETYPE);
    #endif
    m_fontPicker = new wxFontPickerCtrl(this, wxID_ANY, m_fontPickerFont, wxDefaultPosition, wxSize(-1,-1), wxFNTP_DEFAULT_STYLE);
    
    flexGridSizer29->Add(m_fontPicker, 0, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer43 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer27->Add(boxSizer43, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button45 = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer43->Add(m_button45, 0, wxALL, 5);
    
    m_button47 = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_button47->SetFocus();
    
    boxSizer43->Add(m_button47, 0, wxALL, 5);
    
    SetName(wxT("SettingsDlgBase"));
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    CentreOnParent(wxBOTH);
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_colourPickerFG->Connect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(SettingsDlgBase::OnFGColour), NULL, this);
    m_colourPickerBG->Connect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(SettingsDlgBase::OnBGColour), NULL, this);
    m_fontPicker->Connect(wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler(SettingsDlgBase::OnFontSelected), NULL, this);
    
}

SettingsDlgBase::~SettingsDlgBase()
{
    m_colourPickerFG->Disconnect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(SettingsDlgBase::OnFGColour), NULL, this);
    m_colourPickerBG->Disconnect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(SettingsDlgBase::OnBGColour), NULL, this);
    m_fontPicker->Disconnect(wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler(SettingsDlgBase::OnFontSelected), NULL, this);
    
}
