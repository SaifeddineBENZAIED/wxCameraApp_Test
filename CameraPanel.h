#ifndef CAMERAPANEL_H
#define CAMERAPANEL_H

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/dcclient.h>
#include <wx/bitmap.h>
#include <opencv2/opencv.hpp>

class CameraPanel : public wxPanel {
public:
    CameraPanel(wxWindow* parent);
    void OnPaint(wxPaintEvent& event);
    void CaptureFrame();
    bool SaveScreenshot(const wxString& filePath);

private:
    cv::VideoCapture cap;
    cv::Mat frame;
    wxBitmap wxFrameBitmap;

    void ConvertMatToBitmap(const cv::Mat& mat, wxBitmap& bitmap);
    void OnTimer(wxTimerEvent& event);

    wxTimer timer;
    wxDECLARE_EVENT_TABLE();
};

#endif // CAMERAPANEL_H
