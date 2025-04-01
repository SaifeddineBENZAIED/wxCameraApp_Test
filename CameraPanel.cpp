#include "CameraPanel.h"
#include <wx/filename.h>
#include <wx/image.h>
#include <wx/wfstream.h>
#include <opencv2/imgcodecs.hpp>

wxBEGIN_EVENT_TABLE(CameraPanel, wxPanel)
    EVT_PAINT(CameraPanel::OnPaint)
    EVT_TIMER(wxID_ANY, CameraPanel::OnTimer)
wxEND_EVENT_TABLE()

CameraPanel::CameraPanel(wxWindow* parent)
    : wxPanel(parent), timer(this, wxID_ANY) {
    cap.open(0);  // Ouvre la webcam
    if (!cap.isOpened()) {
        wxLogError("Erreur: Impossible d'ouvrir la caméra.");
        return;
    }
    timer.Start(30);
}

void CameraPanel::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);
    if (wxFrameBitmap.IsOk()) {
        dc.DrawBitmap(wxFrameBitmap, 0, 0);
    }
}

void CameraPanel::CaptureFrame() {
    if (cap.read(frame)) {
        ConvertMatToBitmap(frame, wxFrameBitmap);
        Refresh();
    }
}

void CameraPanel::ConvertMatToBitmap(const cv::Mat& mat, wxBitmap& bitmap) {
    cv::Mat temp;
    cvtColor(mat, temp, cv::COLOR_BGR2RGB);
    wxImage image(temp.cols, temp.rows, temp.data, true);
    bitmap = wxBitmap(image);
}

void CameraPanel::OnTimer(wxTimerEvent& event) {
    CaptureFrame();
}

bool CameraPanel::SaveScreenshot(const wxString& filePath) {
    if (frame.empty()) {
        wxMessageBox("Aucune image capturée.", "Erreur", wxICON_ERROR);
        return false;
    }

    if (!cv::imwrite(filePath.ToStdString(), frame)) {
        wxMessageBox("Échec de l'enregistrement de l'image.", "Erreur", wxICON_ERROR);
        return false;
    }

    wxMessageBox("Capture d'écran enregistrée avec succès !", "Succès", wxICON_INFORMATION);
    return true;
}
