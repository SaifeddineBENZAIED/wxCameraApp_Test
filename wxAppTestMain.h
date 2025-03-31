/***************************************************************
 * Name:      wxAppTestMain.h
 * Purpose:   Defines Application Frame
 * Author:    saif ()
 * Created:   2025-03-31
 * Copyright: saif ()
 * License:
 **************************************************************/

#ifndef WXAPPTESTMAIN_H
#define WXAPPTESTMAIN_H

#include <wx/frame.h>
#include <wx/statusbr.h>
#include <wx/panel.h>

class CameraPanel;  // Forward declaration

class wxAppTestFrame : public wxFrame {
public:
    wxAppTestFrame(wxWindow* parent, wxWindowID id = wxID_ANY);
    virtual ~wxAppTestFrame();

private:
    // Event handlers
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnCapture(wxCommandEvent& event);
    void OnCreateZip(wxCommandEvent& event);
    void OnFetchTweets(wxCommandEvent& event);

    wxStatusBar* StatusBar1;
    CameraPanel* m_cameraPanel;  // Pointer to camera panel

    // Declare button IDs as static constants
    static const long ID_BTN_CAPTURE;
    static const long ID_BTN_ZIP;
    static const long ID_BTN_TWEETS;

    wxDECLARE_EVENT_TABLE();
};

#endif // WXAPPTESTMAIN_H
