/***************************************************************
 * Name:      wxAppTestMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    saif ()
 * Created:   2025-03-31
 * Copyright: saif ()
 * License:
 **************************************************************/

#include "wxAppTestMain.h"
#include "CameraPanel.h"
#include "ZipManager.h"
#include <wx/msgdlg.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/textdlg.h>
#include <wx/dirdlg.h>
#include <wx/datetime.h>

// Define static button IDs
const long wxAppTestFrame::ID_BTN_CAPTURE = wxNewId();
const long wxAppTestFrame::ID_BTN_ZIP = wxNewId();
const long wxAppTestFrame::ID_BTN_TWEETS = wxNewId();

wxBEGIN_EVENT_TABLE(wxAppTestFrame, wxFrame)
    EVT_BUTTON(ID_BTN_CAPTURE, wxAppTestFrame::OnCapture)
    EVT_BUTTON(ID_BTN_ZIP, wxAppTestFrame::OnCreateZip)
    EVT_BUTTON(ID_BTN_TWEETS, wxAppTestFrame::OnFetchTweets)
wxEND_EVENT_TABLE()

wxAppTestFrame::wxAppTestFrame(wxWindow* parent, wxWindowID id)
    : wxFrame(parent, id, "Camera Application", wxDefaultPosition, wxSize(800, 600))
{
    // Create the CameraPanel (ensure you have implemented CameraPanel correctly)
    m_cameraPanel = new CameraPanel(this);

    // Status Bar
    StatusBar1 = new wxStatusBar(this, wxID_ANY);
    SetStatusBar(StatusBar1);

    // Buttons for functionalities
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxButton* btnCapture = new wxButton(this, ID_BTN_CAPTURE, "Capture Screenshot");
    wxButton* btnZip = new wxButton(this, ID_BTN_ZIP, "Create Zip");
    wxButton* btnFetchTweets = new wxButton(this, ID_BTN_TWEETS, "Fetch Tweets");

    mainSizer->Add(m_cameraPanel, 1, wxEXPAND | wxALL, 10);
    mainSizer->Add(btnCapture, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(btnZip, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(btnFetchTweets, 0, wxEXPAND | wxALL, 5);

    SetSizerAndFit(mainSizer);

    // Connect menu items
    Bind(wxEVT_MENU, &wxAppTestFrame::OnQuit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &wxAppTestFrame::OnAbout, this, wxID_ABOUT);
}

wxAppTestFrame::~wxAppTestFrame() {}

void wxAppTestFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxAppTestFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Camera Application.\nDeveloped by Saif.",
                 "About", wxOK | wxICON_INFORMATION);
}

void wxAppTestFrame::OnCapture(wxCommandEvent& event)
{
    wxString defaultFile = wxString::Format("capture_%ld.jpg", wxGetLocalTime());
    wxString filePath = wxFileSelector("Save Screenshot", "", defaultFile,
                                      "jpg", "JPEG files (*.jpg)|*.jpg",
                                      wxFD_SAVE | wxFD_OVERWRITE_PROMPT, this);

    if (!filePath.empty())
    {
        if (m_cameraPanel->SaveScreenshot(filePath))  // Ensure CameraPanel has this function
        {
            StatusBar1->SetStatusText(wxString::Format("Saved screenshot to: %s", filePath));
        }
        else
        {
            wxMessageBox("Failed to save screenshot", "Error", wxOK | wxICON_ERROR, this);
        }
    }
}

void wxAppTestFrame::OnCreateZip(wxCommandEvent& event)
{
    wxDirDialog dirDialog(this, "Select folder with screenshots to zip", "",
                         wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

    if (dirDialog.ShowModal() == wxID_OK)
    {
        wxString folderPath = dirDialog.GetPath();
        wxString defaultFile = "screenshots_" + wxDateTime::Now().Format("%Y%m%d_%H%M%S") + ".zip";
        wxString zipPath = wxFileSelector("Save ZIP file", "", defaultFile,
                                        "zip", "ZIP files (*.zip)|*.zip",
                                        wxFD_SAVE | wxFD_OVERWRITE_PROMPT, this);

        if (!zipPath.empty())
        {
            // Implement ZIP creation here
            StatusBar1->SetStatusText(wxString::Format("Created ZIP: %s", zipPath));
        }
    }
}

void wxAppTestFrame::OnFetchTweets(wxCommandEvent& event)
{
    wxTextEntryDialog dialog(this, "Enter Twitter username:", "Fetch Tweets");

    if (dialog.ShowModal() == wxID_OK)
    {
        wxString username = dialog.GetValue();
        // Implement Twitter API call here
        StatusBar1->SetStatusText(wxString::Format("Fetching tweets for @%s...", username));
    }
}

void wxAppTestFrame::OnCreateZip(wxCommandEvent& event) {
    wxString folder = wxDirSelector("Choisissez le dossier contenant les captures d'écran");
    if (!folder.IsEmpty()) {
        wxString zipFile = wxSaveFileSelector("Archive ZIP", "zip", "captures.zip");
        if (!zipFile.IsEmpty()) {
            ZipManager::CreateZip(zipFile, folder);
        }
    }
}
