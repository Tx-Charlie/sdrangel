project(audioinput)

set(audioinput_SOURCES
    audioinput.cpp
    audioinputplugin.cpp
    audioinputsettings.cpp
    audioinputwebapiadapter.cpp
    audioinputthread.cpp
)

set(audioinput_HEADERS
    audioinput.h
    audioinputplugin.h
    audioinputsettings.h
    audioinputwebapiadapter.h
    audioinputthread.h
)

include_directories(
    ${CMAKE_SOURCE_DIR}/swagger/sdrangel/code/qt5/client
)

if(NOT SERVER_MODE)
    set(audioinput_SOURCES
        ${audioinput_SOURCES}
        audioinputgui.cpp
        audioinputgui.ui
    )
    set(audioinput_HEADERS
        ${audioinput_HEADERS}
        audioinputgui.h
    )

    set(TARGET_NAME inputaudio)
    set(TARGET_LIB "Qt5::Widgets")
    set(TARGET_LIB_GUI "sdrgui")
    set(INSTALL_FOLDER ${INSTALL_PLUGINS_DIR})
else()
    set(TARGET_NAME inputaudiosrv)
    set(TARGET_LIB "")
    set(TARGET_LIB_GUI "")
    set(INSTALL_FOLDER ${INSTALL_PLUGINSSRV_DIR})
endif()

add_library(${TARGET_NAME} SHARED
    ${audioinput_SOURCES}
)

target_link_libraries(${TARGET_NAME}
    Qt5::Core
    ${TARGET_LIB}
    sdrbase
    ${TARGET_LIB_GUI}
    swagger
)

install(TARGETS ${TARGET_NAME} DESTINATION ${INSTALL_FOLDER})