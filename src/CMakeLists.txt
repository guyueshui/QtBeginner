find_package(
        Qt6
        CONFIG
        REQUIRED
        Core
        Gui
        Widgets
        Network
        Svg
#        DBus
#        LinguistTools
)

if (USE_WAYLAND_CLIPBOARD)
    find_package(KF5GuiAddons)
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(demo)
target_sources(
        demo
        PRIVATE
        # ${CMAKE_CURRENT_SOURCE_DIR}/../external/Qt-Color-Widgets/src/QtColorWidgets/color_utils.cpp
        # ${CMAKE_CURRENT_SOURCE_DIR}/../external/Qt-Color-Widgets/src/QtColorWidgets/color_wheel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/mainwidget.cpp
        main.cpp)


target_link_libraries(
        demo
        Qt6::Svg
#        Qt6::DBus
        Qt6::Network
        Qt6::Widgets
)
