cmake_minimum_required(VERSION 3.21)

project(FreeMajor
  VERSION 1.0.1
  LANGUAGES CXX
)

# ------------------------------------------------------------------------------
# Global C++ configuration
# ------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(GNUInstallDirs)

# ------------------------------------------------------------------------------
# Options
# ------------------------------------------------------------------------------
option(ENABLE_GETTEXT "Enable internationalization with gettext" ON)

if(WIN32 OR APPLE)
  set(ENABLE_GETTEXT OFF CACHE BOOL "" FORCE)
endif()

# ------------------------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------------------------

# ---- Threads ---------------------------------------------------------------
find_package(Threads REQUIRED)

# ---- FLTK ------------------------------------------------------------------
set(FLTK_SKIP_OPENGL ON)
set(FLTK_SKIP_FORMS ON)
set(FLTK_SKIP_IMAGES ON)
set(FLTK_SKIP_FLUID ON)

find_package(FLTK REQUIRED)

# ---- Gettext --------------------------------------------------------------
if(ENABLE_GETTEXT)
  find_package(Intl REQUIRED)
  find_package(Gettext REQUIRED)
endif()

# ------------------------------------------------------------------------------
# RtMidi (vendored / submodule)
# ------------------------------------------------------------------------------
add_subdirectory(thirdparty/rtmidi EXCLUDE_FROM_ALL)

if(TARGET rtmidi)
  add_library(RtMidi::rtmidi ALIAS rtmidi)
elseif(TARGET RtMidi)
  add_library(RtMidi::rtmidi ALIAS RtMidi)
endif()

target_link_libraries(FreeMajor PRIVATE RtMidi::rtmidi)

# ------------------------------------------------------------------------------
# Executable
# ------------------------------------------------------------------------------
add_executable(FreeMajor
  sources/main.cc
  sources/app_i18n.cc
  sources/utility/misc.cc
  sources/device/midi.cc
  sources/device/midi_apis.cc
  sources/model/parameter.cc
  sources/model/patch_loader.cc
  sources/model/patch_writer.cc
  sources/model/patch.cc
  sources/ui/main_window.cc
  sources/ui/main_component.cxx
  sources/ui/main_component_impl.cc
  sources/ui/patch_chooser.cxx
  sources/ui/modifiers_editor.cxx
  sources/ui/modifiers_editor_impl.cc
  sources/ui/singlemod_editor.cxx
  sources/ui/receive_dialog.cxx
  sources/ui/receive_dialog_impl.cc
  sources/ui/eq_display.cc
  sources/ui/matrix_display.cc
  sources/ui/hyperlink_button.cc
  sources/ui/association.cc
  sources/ui/midi_out_queue.cc
)

# Windows resources
if(WIN32)
  target_sources(FreeMajor PRIVATE sources/app_win32.rc)
  set_target_properties(FreeMajor PROPERTIES WIN32_EXECUTABLE ON)
endif()

# macOS bundle
if(APPLE)
  set_target_properties(FreeMajor PROPERTIES MACOSX_BUNDLE ON)
  set(MACOSX_BUNDLE_ICON_FILE "FreeMajor.icns")
endif()

# ------------------------------------------------------------------------------
# Include directories
# ------------------------------------------------------------------------------
target_include_directories(FreeMajor
  PRIVATE
    ${PROJECT_SOURCE_DIR}/sources
)

# ------------------------------------------------------------------------------
# Compile definitions
# ------------------------------------------------------------------------------
target_compile_definitions(FreeMajor PRIVATE
  PROJECT_VERSION="${PROJECT_VERSION}"
  LOCALE_DIRECTORY="${CMAKE_INSTALL_FULL_LOCALEDIR}"
)

if(WIN32)
  target_compile_definitions(FreeMajor PRIVATE FM_WINDOWS)
elseif(APPLE)
  target_compile_definitions(FreeMajor PRIVATE FM_MACOS)
else()
  target_compile_definitions(FreeMajor PRIVATE FM_LINUX)
endif()

# ------------------------------------------------------------------------------
# Compile options / warnings
# ------------------------------------------------------------------------------
if(MSVC)
  target_compile_options(FreeMajor PRIVATE /W4 /permissive-)
else()
  target_compile_options(FreeMajor PRIVATE -Wall -Wextra -Wpedantic)
endif()

# ------------------------------------------------------------------------------
# Linking
# ------------------------------------------------------------------------------
target_link_libraries(FreeMajor
  PRIVATE
    Threads::Threads
)

# ---- FLTK linking ----------------------------------------------------------
if(TARGET fltk::fltk)
  target_link_libraries(FreeMajor PRIVATE fltk::fltk)
else()
  target_include_directories(FreeMajor PRIVATE ${FLTK_INCLUDE_DIR})
  target_link_libraries(FreeMajor PRIVATE ${FLTK_LIBRARIES})
endif()

# ---- RtMidi linking --------------------------------------------------------
if(TARGET RtMidi::rtmidi)
  target_link_libraries(FreeMajor PRIVATE RtMidi::rtmidi)
else()
  target_link_libraries(FreeMajor PRIVATE RtMidi)
endif()

# ---- Gettext linking -------------------------------------------------------
if(ENABLE_GETTEXT)
  target_compile_definitions(FreeMajor PRIVATE ENABLE_NLS=1)
  target_link_libraries(FreeMajor PRIVATE Intl::Intl Gettext::Gettext)
endif()

# ------------------------------------------------------------------------------
# macOS RPATH fix
# ------------------------------------------------------------------------------
if(APPLE)
  add_custom_command(TARGET FreeMajor POST_BUILD
    COMMAND "${CMAKE_INSTALL_NAME_TOOL}"
            -add_rpath "@executable_path/../Frameworks"
            "$<TARGET_FILE:FreeMajor>"
  )
endif()

# ------------------------------------------------------------------------------
# Installation
# ------------------------------------------------------------------------------
if(APPLE)
  install(TARGETS FreeMajor DESTINATION ".")
  install(FILES resources/application/FreeMajor.icns
          DESTINATION "FreeMajor.app/Contents/Resources")
else()
  install(TARGETS FreeMajor DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

if(UNIX AND NOT APPLE)
  install(FILES
    resources/application/FreeMajor.png
    resources/application/FreeMajor.svg
    DESTINATION ${CMAKE_INSTALL_DATADIR}/pixmaps)

  install(FILES
    resources/application/FreeMajor.desktop
    DESTINATION ${CMAKE_INSTALL_DATADIR}/applications)

  install(FILES
    resources/mime/freemajor-realmajor.xml
    resources/mime/freemajor-realpatch.xml
    DESTINATION ${CMAKE_INSTALL_DATADIR}/mime/packages)
endif()

# ------------------------------------------------------------------------------
# Translations
# ------------------------------------------------------------------------------
if(ENABLE_GETTEXT)
  set(TRANSLATIONS fr)

  if(APPLE)
    set(MO_DESTINATION "FreeMajor.app/Contents/Resources/locale")
  else()
    set(MO_DESTINATION "${CMAKE_INSTALL_LOCALEDIR}")
  endif()

  foreach(lang ${TRANSLATIONS})
    gettext_process_po_files(
      ${lang}
      ALL
      INSTALL_DESTINATION ${MO_DESTINATION}
      PO_FILES po/${lang}/FreeMajor.po
    )
  endforeach()
endif()

# ------------------------------------------------------------------------------
# Packaging
# ------------------------------------------------------------------------------
include(CPackLists.txt)
