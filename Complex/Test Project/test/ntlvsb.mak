
# Deal with optional defines

!ifdef codeDir
codeDirParm = -d $(codeDir)
!endif

!ifdef rsrcFile
rsrcFileParm = -r $(rsrcFile)
!endif

!ifndef type
type=CIN
!endif

!if "$(type)" == "LVSB"
!error External subroutines are not supported by this version of cintools.
!else
!if "$(type)" != "CIN"
!error This version of cintools does not support generation of $(type) resources.
!endif
!endif

!ifndef cinToolsDir
!	ifdef cintoolsdir
cinToolsDir=$(cintoolsdir)
!	else ifdef CINTOOLSDIR
cinToolsDir=$(CINTOOLSDIR)
!	else
!		error cinToolsDir not defined in makefile or environment variable
!	endif
!endif

!include <ntwin32.mak>

ASM = masm386 -Mx -Zi -Zd -c -w1 -t -DWIN32 $(ASMINCLUDES)

!if "$(CC)" == "cl"

!ifndef FRAMEWORKVERSION
MANIFEST_ACTION = 
CCOMP = $(CC) -nologo -c -G3 -W3 -Zi -Zp1 -MD $(CINCLUDES)
!else
!if ("$(FRAMEWORKVERSION)" == "v1.0.3300") || ("$(FRAMEWORKVERSION)" == "v1.0.3705") || ("$(FRAMEWORKVERSION)" == "v1.1.4322")
MANIFEST_ACTION = 
CCOMP = $(CC) -nologo -c -G3 -W3 -Zi -Zp1 -MD $(CINCLUDES)
!else
MANIFEST_ACTION = mt /manifest $(name).dll.manifest /outputresource:$(name).dll;^#2
CCOMP = $(CC) -nologo -c -W3 -Zi -Zp1 -MD $(CINCLUDES)
!endif 
!endif

ExportFile = $(OBJDIR)\lvsbmain.exp
CPPOpt= -GX
!ifdef DEBUG
CCOpt= -Od
DebugLink= -debug:full -debugtype:cv
!else
CCOpt= -O2
!endif

!else

!if "$(CC)" == "sc"
!error Symantec C not supported by this version of cintools
!else
!error What compiler are we using?
!endif

!endif

CINCLUDES= $(CINCLUDES) -I$(cinToolsDir)

OBJDIR = $(cinToolsDir)
BINDIR = $(cinToolsDir)
OBJS   = $(name).obj $(objFiles) $(OBJDIR)\labview.lib $(OBJDIR)\lvsb.lib $(OBJDIR)\$(type).obj

$(name).lsb : $(name).map
	@$(MANIFEST_ACTION)
	@$(BINDIR)\lvsbutil $(name) -t $(type) \
		$(codeDirParm) $(rsrcFileParm)
	@del $(name).dll >NUL

clean :
	@-del $(name).map
	@-del $(name).obj
	@-del $(name).lsb
	@-del $(name).dll
	@-del $(name).dll.manifest

$(name).map : $(OBJS) $(ExportFile)
	@$(link) -dll -out:$(name).dll -map:$(name).map $(DebugLink) \
             $(ExportFile) $(OBJS) $(LVSBINP) $(cinLibraries) $(olelibsdll)

.c.obj :
	@$(CCOMP) $(CCOpt) $<

.cpp.obj :
	@$(CCOMP) $(CPPOpt) $(CCOpt) $<
