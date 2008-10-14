; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=CodeLite
AppVerName=CodeLite
AppPublisherURL=http://codelite.sourceforge.net
AppSupportURL=http://codelite.sourceforge.net
AppUpdatesURL=http://codelite.sourceforge.net
DefaultDirName={pf}\CodeLite
DefaultGroupName=CodeLite
LicenseFile=license.txt
OutputDir=output
OutputBaseFilename=codelite-mingw3.4.5
ChangesEnvironment=yes
FlatComponentsList=yes
SetupIconFile=box_software.ico
Compression=lzma/ultra
SolidCompression=true
InternalCompressLevel=ultra

[Languages]
Name: "eng"; MessagesFile: "compiler:Default.isl"

[Components]
Name: "Editor"; Description: "CodeLite IDE (Editor + Plugins)"; Types: full custom; Flags: fixed;
Name: "MinGW"; Description: "MinGW 3.4.5 full (gcc/g++/gdb/WinAPI)"; Types: full;

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\Development\C++\codelite\trunk\Runtime\CodeLite.exe"; DestDir: "{app}"; Flags: ignoreversion; Components: Editor
Source: "C:\Development\C++\codelite\trunk\LICENSE"; DestDir: "{app}"; Flags: ignoreversion; Components: Editor
Source: "C:\wxWidgets-2.8.7\lib\gcc_dll\wxmsw28u_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion; Components: Editor
Source: "C:\Development\C++\codelite\trunk\InnoSetup\license.txt"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\Program Files\CodeLite\common.tags"; DestDir: "{app}"; Components: Editor
Source: "C:\Development\C++\codelite\trunk\sdk\wxconfig\wx-config.exe"; DestDir: "{app}"; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\config\codelite.xml.default"; DestDir: "{app}\config"; Components: Editor;
Source: "C:\Development\C++\codelite\trunk\Runtime\config\plugins.xml.default"; DestDir: "{app}\config";  Components: Editor;
Source: "C:\Development\C++\codelite\trunk\Runtime\config\accelerators.conf.default"; DestDir: "{app}\config"; Components: Editor;
Source: "C:\Development\C++\codelite\trunk\Runtime\config\debuggers.xml.default"; DestDir: "{app}\config"; Components: Editor;
Source: "C:\Development\C++\codelite\trunk\Runtime\config\build_settings.xml.default.win"; DestDir: "{app}\config"; DestName: "build_settings.xml.default"; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\rc\*"; DestDir: "{app}\rc"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\astyle.sample"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\config\codelite.layout.default"; DestDir: "{app}\config"; DestName: codelite.layout; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\templates\*"; DestDir: "{app}\templates"; Flags: recursesubdirs ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\lexers\Default\*.xml"; DestDir: "{app}\lexers\Default\"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\lexers\BlackTheme\*.xml"; DestDir: "{app}\lexers\BlackTheme\"; Excludes: "*.svn*"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\debuggers\Debugger.dll"; DestDir: "{app}\debuggers"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\plugins\*.dll"; DestDir: "{app}\plugins"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\plugins\resources\*"; DestDir: "{app}\plugins\resources\"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\ctags-le.exe"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\le_exec.exe"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\makedir.exe"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\patch.exe"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\*.html"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\images\*"; DestDir: "{app}\images"; Flags: ignoreversion ; Components: Editor
Source: "C:\Development\C++\codelite\trunk\Runtime\src\*"; DestDir: "{app}\src"; Flags: ignoreversion ; Components: Editor
Source: "C:\MinGW\bin\mingwm10.dll"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\MinGW\bin\exchndl.dll"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\MinGW\bin\which.exe"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\MinGW\bin\rm.exe"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\MinGW\bin\cscope.exe"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\MinGW\bin\cygncurses-8.dll"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\MinGW\bin\cygwin1.dll"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\MinGW\bin\libintl3.dll"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\MinGW\bin\libiconv2.dll"; DestDir: "{app}"; Flags: ignoreversion ; Components: Editor
Source: "C:\MinGW\*"; DestDir: "{code:GetMinGWInstallDir}"; Flags: recursesubdirs ; Components: MinGW

[Icons]
Name: "{group}\CodeLite "; Filename: "{app}\CodeLite.exe"; WorkingDir: "{app}"
Name: "{group}\{cm:UninstallProgram, CodeLite}"; Filename: "{uninstallexe}"
Name: "{userdesktop}\CodeLite "; Filename: "{app}\CodeLite.exe"; WorkingDir: "{app}" ;Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\CodeLite "; WorkingDir: "{app}"; Filename: "{app}\CodeLite.exe"; Tasks: quicklaunchicon

[Registry]
Root: HKCR	; Subkey: "*\shell\Open With CodeLite\command"; ValueType: string; ValueName: ""; ValueData: "{app}\CodeLite.exe -b ""{app}"" ""%1"""

[Code]
var
  MinGW_Page: TInputDirWizardPage;

procedure CreateMinGWPage();
begin
  MinGW_Page := CreateInputDirPage(wpSelectComponents,
          'Select MinGW Installation Folder', 'Where should setup place MinGW?',
          'MinGW will be stored in the following folder.'#13#10#13#10 +
          'To continue, click Next. If you would like to select a different folder, click Browse.',
          False, 'New Folder');

  // Add item (with an empty caption)
  MinGW_Page.Add('');

  // Set initial value (optional)
  MinGW_Page.Values[0] := ExpandConstant('{sd}\MinGW-3.4.5\');
end;

function GetMinGWInstallDir(Param: String): String;
begin
  Result := MinGW_Page.Values[0];
end;

procedure InitializeWizard();
begin
  CreateMinGWPage();
end;

// Uninstall
procedure CurUninstallStepChanged(CurUninstallStep: TUninstallStep);
begin
  case CurUninstallStep of
    usUninstall:
      begin
        RegDeleteKeyIncludingSubkeys(HKCR, '*\shell\Open With CodeLite');
      end;
    usPostUninstall:
      begin
      end;
  end;
end;

function ShouldSkipPage(PageID: Integer): Boolean;
begin
  // by default dont skip the page
  Result := False;

  if PageID = MinGW_Page.ID then begin
    if IsComponentSelected('MinGW') = False then
      Result := True;
  end
end;

