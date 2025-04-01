#ifndef ZIP_MANAGER_H
#define ZIP_MANAGER_H

#include <wx/string.h>

class ZipManager {
public:
    static bool CreateZip(const wxString& zipFilename, const wxString& directory);
};

#endif
