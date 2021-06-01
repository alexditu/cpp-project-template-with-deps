add_executable (main main.cpp)

install (TARGETS main DESTINATION "bin/")

# target_link_libraries (main PRIVATE libQt6Widgets.a libQt6Gui.a libQt6Core.a libQt6Concurrent.a -lfreetype -ldl -lpcre)
target_link_libraries (main PRIVATE -lQt6Widgets -lQt6Gui -lQt6Core)

configure_file ("resources/images/filesaveas.png" "resources/images/filesaveas.png" COPYONLY)