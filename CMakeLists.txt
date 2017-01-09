cmake_minimum_required( VERSION 3.7 )

project( main )

find_package( Qt5Widgets REQUIRED )

set( main_SOURCES main.cpp card.cpp )

add_executable( main ${main_SOURCES} )

target_link_libraries( main Qt5::Widgets )

