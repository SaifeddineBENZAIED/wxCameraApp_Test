#include "ScreenshotManager.h"
#include <wx/wx.h>

bool ScreenshotManager::SaveScreenshot(const std::string& filePath) {
    wxScreenDC screenDC;
    wxSize screenSize = wxGetDisplaySize();
    wxBitmap screenshot(screenSize.x, screenSize.y);
    wxMemoryDC memDC(screenshot);
    memDC.Blit(0, 0, screenSize.x, screenSize.y, &screenDC, 0, 0);
    memDC.SelectObject(wxNullBitmap);

    return screenshot.SaveFile(filePath, wxBITMAP_TYPE_PNG);
}
