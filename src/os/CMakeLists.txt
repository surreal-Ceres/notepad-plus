include(FindSkia)

add_library(os-lib STATIC
skia/skia_surface.cpp
skia/skia_font_manager.cpp
skia/skia_typeface.cpp
win/system.cpp
win/native_dialogs.cpp
win/window.cpp
win/event_queue.cpp
win/keys.cpp
win/styles.cpp
font.cpp
style.cpp)

target_include_directories(os-lib PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_compile_definitions(os-lib PRIVATE -DUNICODE)
target_link_libraries(os-lib Comctl32 utils-lib skia)

add_executable(os-test main.cpp)
target_link_libraries(os-test os-lib)