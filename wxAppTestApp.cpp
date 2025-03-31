/***************************************************************
 * Name:      wxAppTestApp.cpp
 * Purpose:   Code for Application Class
 * Author:    saif ()
 * Created:   2025-03-31
 * Copyright: saif ()
 * License:
 **************************************************************/

#include "wxAppTestApp.h"

//(*AppHeaders
#include "wxAppTestMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxAppTestApp);

bool wxAppTestApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxAppTestFrame* Frame = new wxAppTestFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
