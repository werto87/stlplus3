# Microsoft Developer Studio Project File - Name="subsystems" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=subsystems - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "subsystems.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "subsystems.mak" CFG="subsystems - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "subsystems - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "subsystems - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "subsystems - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GR /GX /O2 /I "..\portability" /I "..\containers" /D "WIN32" /D "NDEBUG" /D "_LIB" /D "_MBCS" /Fr /c
# ADD CPP /nologo /MD /GR /GX /O2 /I "..\portability" /I "..\containers" /D "WIN32" /D "NDEBUG" /D "_LIB" /D "_MBCS" /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "subsystems - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /GR /GX /Od /I "..\portability" /I "..\containers" /D "WIN32" /D "_DEBUG" /D "_LIB" /D "_MBCS" /Fr /c
# ADD CPP /nologo /MDd /GR /GX /Od /I "..\portability" /I "..\containers" /D "WIN32" /D "_DEBUG" /D "_LIB" /D "_MBCS" /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "subsystems - Win32 Release"
# Name "subsystems - Win32 Debug"
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx"
# Begin Source File

SOURCE=.\cli_parser.hpp
# End Source File
# Begin Source File

SOURCE=.\ini_manager.hpp
# End Source File
# Begin Source File

SOURCE=.\library_manager.hpp
# End Source File
# Begin Source File

SOURCE=.\message_handler.hpp
# End Source File
# Begin Source File

SOURCE=.\subsystems.hpp
# End Source File
# Begin Source File

SOURCE=.\timer.hpp
# End Source File
# End Group
# Begin Group "Source Files"

# PROP Default_Filter "c;cpp;cxx"
# Begin Source File

SOURCE=.\cli_parser.cpp
DEP_CPP_CLI_P=\
	"..\containers\exceptions.hpp"\
	"..\containers\smart_ptr.hpp"\
	"..\containers\smart_ptr.tpp"\
	"..\containers\template_fixes.hpp"\
	"..\portability\file_system.hpp"\
	"..\portability\os_fixes.hpp"\
	".\cli_parser.hpp"\
	".\ini_manager.hpp"\
	".\message_handler.hpp"\
	
# End Source File
# Begin Source File

SOURCE=.\ini_manager.cpp
DEP_CPP_INI_M=\
	"..\portability\file_system.hpp"\
	"..\portability\os_fixes.hpp"\
	".\ini_manager.hpp"\
	
# End Source File
# Begin Source File

SOURCE=.\library_manager.cpp
DEP_CPP_LIBRA=\
	"..\containers\exceptions.hpp"\
	"..\containers\smart_ptr.hpp"\
	"..\containers\smart_ptr.tpp"\
	"..\containers\template_fixes.hpp"\
	"..\portability\file_system.hpp"\
	"..\portability\os_fixes.hpp"\
	".\ini_manager.hpp"\
	".\library_manager.hpp"\
	
# End Source File
# Begin Source File

SOURCE=.\message_handler.cpp
DEP_CPP_MESSA=\
	"..\portability\os_fixes.hpp"\
	".\message_handler.hpp"\
	
# End Source File
# Begin Source File

SOURCE=.\timer.cpp
DEP_CPP_TIMER=\
	"..\portability\dprintf.hpp"\
	"..\portability\os_fixes.hpp"\
	"..\portability\time.hpp"\
	".\timer.hpp"\
	
# End Source File
# End Group
# End Target
# End Project
