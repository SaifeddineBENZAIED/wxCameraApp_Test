#include "ZipManager.h"
#include <zip.h>
#include <wx/dir.h>
#include <wx/filename.h>

bool ZipManager::CreateZip(const wxString& zipFilename, const wxString& directory) {
    int error = 0;
    zip_t* zip = zip_open(zipFilename.ToStdString().c_str(), ZIP_CREATE | ZIP_TRUNCATE, &error);
    if (!zip) {
        wxMessageBox("Erreur lors de la création du fichier ZIP.", "Erreur", wxICON_ERROR);
        return false;
    }

    wxDir dir(directory);
    if (!dir.IsOpened()) {
        wxMessageBox("Dossier introuvable.", "Erreur", wxICON_ERROR);
        zip_close(zip);
        return false;
    }

    wxString filename;
    bool cont = dir.GetFirst(&filename, "*.png", wxDIR_FILES);
    while (cont) {
        wxString filepath = directory + "/" + filename;
        zip_source_t* source = zip_source_file(zip, filepath.ToStdString().c_str(), 0, 0);
        if (source) {
            zip_file_add(zip, filename.ToStdString().c_str(), source, ZIP_FL_ENC_UTF_8);
        } else {
            wxMessageBox("Erreur d'ajout : " + filename, "Erreur", wxICON_ERROR);
        }
        cont = dir.GetNext(&filename);
    }

    zip_close(zip);
    wxMessageBox("ZIP créé avec succès !", "Succès", wxICON_INFORMATION);
    return true;
}
