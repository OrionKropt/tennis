
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_COMPILER clang++)

set(PROJECT_NAME tennis)

project(${PROJECT_NAME})


file (GLOB_RECURSE _SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE _HEADERS CONFIGURE_DEPENDS "src/*.h")

add_executable(${PROJECT_NAME} ${_SOURCES} ${_HEADERS})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${_SOURCES} ${_HEADERS})

set(_INCLUDE_DIRS "")

foreach (_headerFile ${_HEADERS})
	get_filename_component(_dir ${_headerFile} PATH)
	list (APPEND _INCLUDE_DIRS ${_dir})
endforeach()

list(REMOVE_DUPLICATES _INCLUDE_DIRS)

target_include_directories(${PROJECT_NAME} PRIVATE ${_INCLUDE_DIRS})

#sdl2
set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/lib/SDL2-2.30.0/include")  
set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/SDL2-2.30.0/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/SDL2-2.30.0/lib/x64/SDL2main.lib")

set(SDL2_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/SDL2-2.30.0/cmake")
set(SDL2_PATH "${CMAKE_CURRENT_LIST_DIR}/lib/SDL2-2.30.0/lib/x64")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/SDL2-2.30.0/cmake")


include_directories(${SDL2_INCLUDE_DIRS})


target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
#sdl2



#sdl2_image and sdl2_ttf
set(SDL2_IMAGE_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/lib/sdl2_image/include")
set(SDL2_IMAGE_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/sdl2_image/SDL2_image.lib")

set(SDL2_TTF_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/lib/sdl2_ttf/include")
set(SDL2_TTF_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/sdl2_ttf/SDL2_ttf.lib")

include_directories(${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL2_TTF_LIBRARIES})


#sdl2_image and sdl2_ttf

# add dll
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy_directory
					${CMAKE_CURRENT_LIST_DIR}/dll $<TARGET_FILE_DIR:${PROJECT_NAME}>)


