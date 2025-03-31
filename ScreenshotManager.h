#ifndef SCREENSHOTMANAGER_H
#define SCREENSHOTMANAGER_H

#include <string>

class ScreenshotManager {
public:
    static bool SaveScreenshot(const std::string& filePath);
};

#endif // SCREENSHOTMANAGER_H
