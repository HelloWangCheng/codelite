//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : menu_event_handlers.cpp
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#include "menu_event_handlers.h"
#include "manager.h"
#include "cl_editor.h"
#include "frame.h"

//------------------------------------
// Handle copy events
//------------------------------------
void EditHandler::ProcessCommandEvent(wxWindow *owner, wxCommandEvent &event)
{
    wxUnusedVar(event);
    LEditor *editor = (LEditor*)owner;

    // hide completion box
    editor->HideCompletionBox();

    if (event.GetId() == wxID_COPY) {
        
        // reset the 'full line' copy/cut flag
        editor->SetFullLineCopyCut(false);
        
        // if the selection is empty, copy the line content
        if(editor->GetSelectedText().IsEmpty()) {
            editor->CopyAllowLine();
            editor->SetFullLineCopyCut(true);
            
        } else {
            editor->Copy();
        }

    } else if (event.GetId() == wxID_CUT) {
        
        // reset the 'full line' copy/cut flag
        editor->SetFullLineCopyCut(false);
        
        if(editor->GetSelectedText().IsEmpty()) {
            // If the selection is empty, copy the line.
            editor->CopyAllowLine();
            editor->LineDelete();
            editor->SetFullLineCopyCut(true);
            
        } else {
            // If the text is selected, cut the selected text.
            editor->Cut();
        }

    } else if (event.GetId() == wxID_PASTE) {
        if ( editor->IsFullLineCopyCut() ) {
            // paste one line above the caret
            editor->PasteLineAbove();
            
        } else {
            // paste at caret position
            editor->Paste();
            
        }

    } else if (event.GetId() == wxID_UNDO) {
        editor->Undo();

    } else if (event.GetId() == wxID_REDO) {
        editor->Redo();

    } else if (event.GetId() == wxID_SELECTALL) {
        editor->SelectAll();

    } else if (event.GetId() == wxID_DUPLICATE) {
        editor->SelectionDuplicate();

    } else if (event.GetId() == XRCID("delete_line_end")) {
        editor->DelLineRight();

    } else if (event.GetId() == XRCID("delete_line_start")) {
        editor->DelLineLeft();

    } else if (event.GetId() == XRCID("delete_line")) {
        editor->LineDelete();

    } else if (event.GetId() == XRCID("trim_trailing")) {
        editor->TrimText(true, false);

    } else if (event.GetId() == XRCID("to_lower")) {
        editor->ChangeCase(true);

    } else if (event.GetId() == XRCID("to_upper")) {
        editor->ChangeCase(false);

    } else if (event.GetId() == XRCID("transpose_lines")) {
        editor->LineTranspose();

    } else if (event.GetId() == wxID_DELETE) {
        editor->DeleteBack();

    } else if (event.GetId() == XRCID("move_line_down")) {

        int curline  = editor->GetCurrentLine();
        int lastline = editor->LineFromPosition(editor->GetLength()-1);
        // Dont transpose if we reached end of the document
        if(curline == lastline)
            return;

        editor->LineDown();
        editor->LineTranspose();

    } else if (event.GetId() == XRCID("move_line_up")) {
        editor->LineTranspose();
        editor->LineUp();

    } else if (event.GetId() == XRCID("center_line")) {
        //editor->VerticalCentreCaret();

    } else if (event.GetId() == XRCID("center_line_roll")) {
        int here    = editor->GetCurrentLine();
        int top     = editor->GetFirstVisibleLine();
        int count   = editor->LinesOnScreen();
        int center  = top + (count / 2);
        if (here < center) {
            for (int lnIterator = 0; lnIterator < center - here; lnIterator++)
                editor->LineScrollUp();   //roll up until we get to center
        } else if (here > center) {
            for (int lnIterator = 0; lnIterator < here - center; lnIterator++)
                editor->LineScrollDown(); //roll down until we get to center
        }

    }
}

void EditHandler::ProcessUpdateUIEvent(wxWindow *owner, wxUpdateUIEvent &event)
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);

    if (event.GetId() == wxID_COPY || event.GetId() == XRCID("trim_trailing") || event.GetId() == XRCID("to_lower") || event.GetId() == XRCID("to_upper")) {
        event.Enable(editor);

    } else if (event.GetId() == wxID_CUT) {
        event.Enable(editor);

    } else if (event.GetId() == wxID_PASTE) {
#ifdef __WXGTK__
        event.Enable(editor);
#else
        event.Enable(editor && editor->CanPaste());
#endif
    } else if (event.GetId() == wxID_UNDO) {
        event.Enable(editor && editor->CanUndo());
    } else if (event.GetId() == wxID_REDO) {
        event.Enable(editor && editor->CanRedo());
    } else if (event.GetId() == wxID_SELECTALL) {
        event.Enable(editor && editor->GetLength() > 0);
    } else if (event.GetId() == wxID_DUPLICATE || event.GetId() == wxID_DELETE) {
        event.Enable(true);
    } else {
        event.Enable(false);
    }
    event.Skip(false);
}

//------------------------------------
// brace matching
//------------------------------------
void BraceMatchHandler::ProcessCommandEvent(wxWindow *owner, wxCommandEvent &event)
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if ( !editor ) {
        return;
    }

    if (event.GetId() == XRCID("select_to_brace")) {
        editor->MatchBraceAndSelect(true);
    } else {
        editor->MatchBraceAndSelect(false);
    }
}

void BraceMatchHandler::ProcessUpdateUIEvent(wxWindow *owner, wxUpdateUIEvent &event)
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    event.Enable(editor &&editor->GetLength() > 0);
}


//------------------------------------
// Find / Replace
//------------------------------------
void FindReplaceHandler::ProcessCommandEvent(wxWindow *owner, wxCommandEvent &event)
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if ( editor ) {
        if ( event.GetId() == wxID_FIND ) {
            clMainFrame::Get()->GetMainBook()->ShowQuickBar( editor ? editor->GetSelectedText() : "" );

        } else if ( event.GetId() == wxID_REPLACE ) {
            editor->DoFindAndReplace(true);

        }

    } else if ( event.GetId() == wxID_FIND ) {
        clMainFrame::Get()->GetMainBook()->ShowQuickBarForPlugins();
    }
}

void FindReplaceHandler::ProcessUpdateUIEvent(wxWindow *owner, wxUpdateUIEvent &event)
{
    wxUnusedVar(owner);
    wxUnusedVar(event);
}

//----------------------------------
// goto linenumber
//----------------------------------

void GotoHandler::ProcessCommandEvent(wxWindow *owner, wxCommandEvent &event)
{
    wxUnusedVar(event);
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if ( !editor ) {
        return;
    }

    wxString msg;
    msg.Printf(_("Go to line number (1 - %d):"), editor->GetLineCount());

    while ( 1 ) {
        wxTextEntryDialog dlg(editor, msg, _("Go To Line"));
        dlg.SetTextValidator(wxFILTER_NUMERIC);

        if (dlg.ShowModal() == wxID_OK) {
            wxString val = dlg.GetValue();
            long line;
            if (!val.ToLong(&line)) {
                wxString err;
                err.Printf(_("'%s' is not a valid line number"), val.GetData());
                wxMessageBox (err, _("Go To Line"), wxOK | wxICON_INFORMATION);
                continue;
            }

            if (line > editor->GetLineCount()) {
                wxString err;
                err.Printf(_("Please insert a line number in the range of (1 - %ld)"), editor->GetLineCount());
                wxMessageBox (err, _("Go To Line"), wxOK | wxICON_INFORMATION);
                continue;
            }

            if (line > 0) {
                int pos = editor->PositionFromLine(line - 1);
                // Clear any existing selection, which otherwise becomes the Goto target
                editor->SetSelectionStart(pos);
                editor->SetSelectionEnd(pos);
                editor->SetEnsureCaretIsVisible(pos);
                break;
            } else {
                editor->GotoLine(0);
                break;
            }
        } else {
            // wxID_CANCEL
            return;
        }
    }
    editor->SetActive();
}

void GotoHandler::ProcessUpdateUIEvent(wxWindow *owner, wxUpdateUIEvent &event)
{
    wxUnusedVar(event);
    wxUnusedVar(owner);
}

//------------------------------------
// Bookmarks
//------------------------------------
void BookmarkHandler::ProcessCommandEvent(wxWindow *owner, wxCommandEvent &event)
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if ( !editor ) {
        return;
    }

    if		 (event.GetId() == XRCID("toggle_bookmark")) {
        editor->ToggleMarker();
    } else if (event.GetId() == XRCID("next_bookmark")) {
        editor->FindNextMarker();
    } else if (event.GetId() == XRCID("previous_bookmark")) {
        editor->FindPrevMarker();
    } else if (event.GetId() == XRCID("removeall_bookmarks")) {
        editor->DelAllMarkers();
    }
}

void BookmarkHandler::ProcessUpdateUIEvent(wxWindow *owner, wxUpdateUIEvent &event)
{
    wxUnusedVar(owner);
    wxUnusedVar(event);
}


//------------------------------------
// Go to definition
//------------------------------------
void GotoDefinitionHandler::ProcessCommandEvent(wxWindow *owner, wxCommandEvent &event)
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if ( !editor ) {
        return;
    }
    if (event.GetId() == XRCID("goto_definition")) {
        editor->GotoDefinition();
    }
}

void GotoDefinitionHandler::ProcessUpdateUIEvent(wxWindow *owner, wxUpdateUIEvent &event)
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if (event.GetId() == XRCID("goto_previous_definition")) {
        event.Enable(editor && editor->CanGotoPreviousDefintion());
    } else {
        event.Enable(editor != NULL);
    }
}

//-------------------------------------------------
// View As
//-------------------------------------------------

void ViewAsHandler::ProcessCommandEvent(wxWindow *owner, wxCommandEvent &event)
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if ( !editor ) {
        return;
    }

    wxString lexName = clMainFrame::Get()->GetViewAsLanguageById(event.GetInt());
    if (lexName.IsEmpty() == false) {
        editor->SetSyntaxHighlight(lexName);
    }
}

void ViewAsHandler::ProcessUpdateUIEvent(wxWindow *owner, wxUpdateUIEvent &event)
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if ( !editor ) {
        return;
    }

    event.Enable(true);
    wxString lexName = clMainFrame::Get()->GetViewAsLanguageById(event.GetInt());
    event.Check(editor->GetContext()->GetName() == lexName);
}

//----------------------------------------------------
// Word wrap handler
//----------------------------------------------------

void WordWrapHandler::ProcessUpdateUIEvent(wxWindow *owner, wxUpdateUIEvent &event)
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if ( !editor ) {
        event.Enable(false);
        return;
    }

    event.Enable(true);
    event.Check(editor->GetWrapMode() != wxSTC_WRAP_NONE);
}

void WordWrapHandler::ProcessCommandEvent(wxWindow *owner, wxCommandEvent &event)
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if ( !editor ) {
        return;
    }

    editor->SetWrapMode(event.IsChecked() ? wxSTC_WRAP_WORD : wxSTC_WRAP_NONE);
}
//----------------------------------------------------
// Fold handler
//----------------------------------------------------

void FoldHandler::ProcessCommandEvent(wxWindow *owner, wxCommandEvent &event)
{
    wxUnusedVar(event);
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if ( !editor ) {
        return;
    }

    if (event.GetId() == XRCID("toggle_fold")) editor->ToggleCurrentFold();
     else if (event.GetId() == XRCID("fold_all_in_selection")) editor->ToggleAllFoldsInSelection();
     else editor->FoldAll();
}

void FoldHandler::ProcessUpdateUIEvent(wxWindow *owner, wxUpdateUIEvent &event) // Used for ToggleAllFoldsInSelection()
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if ( !editor ) {
        event.Enable(false);
        return;
    }

    bool hasSelection = !editor->GetSelection().empty();
    if (hasSelection) {
        // Even if there is a selection, check it's not a trivial amount i.e. spans at least 2 lines
        hasSelection = editor->LineFromPos(editor->GetSelectionStart()) != editor->LineFromPos(editor->GetSelectionEnd());
    }
    event.Enable(hasSelection);
}

void DebuggerMenuHandler::ProcessCommandEvent(wxWindow *owner, wxCommandEvent &event)
{
    LEditor *editor = dynamic_cast<LEditor*>(owner);
    if ( !editor ) {
        return;
    }

    if (event.GetId() == XRCID("add_breakpoint")) {
        editor->AddBreakpoint();
    }
    if (event.GetId() == XRCID("insert_breakpoint")) {
        editor->ToggleBreakpoint();
    }
    if ((event.GetId() == XRCID("insert_temp_breakpoint"))
        || (event.GetId() == XRCID("insert_cond_breakpoint"))) {
        editor->AddOtherBreakpointType(event);
    }
    if (event.GetId() == XRCID("delete_breakpoint")) {
        editor->DelBreakpoint();
    }

    if (event.GetId() == XRCID("toggle_breakpoint_enabled_status")) {
        editor->ToggleBreakpointEnablement();
    }

    if (event.GetId() == XRCID("ignore_breakpoint")) {
        editor->OnIgnoreBreakpoint();
    }

    if (event.GetId() == XRCID("edit_breakpoint")) {
        editor->OnEditBreakpoint();
    }

    if (event.GetId() == XRCID("disable_all_breakpoints")) {
        ManagerST::Get()->GetBreakpointsMgr()->SetAllBreakpointsEnabledState(false);
    }

    if (event.GetId() == XRCID("enable_all_breakpoints")) {
        ManagerST::Get()->GetBreakpointsMgr()->SetAllBreakpointsEnabledState(true);
    }

    if (event.GetId() == XRCID("delete_all_breakpoints")) {
        ManagerST::Get()->GetBreakpointsMgr()->DelAllBreakpoints();
    }
}

void DebuggerMenuHandler::ProcessUpdateUIEvent(wxWindow *owner, wxUpdateUIEvent &event)
{
    wxUnusedVar(owner);
    wxUnusedVar(event);
}
