cmake_minimum_required(VERSION 3.21)
project(TaikoSFML LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


add_executable(TaikoSFML src/main.cpp)
target_link_libraries(TaikoSFML PRIVATE sfml-graphics)
target_include_directories(TaikoSFML PUBLIC External/imgui)
target_compile_features(TaikoSFML PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET TaikoSFML POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:TaikoSFML> $<TARGET_FILE_DIR:TaikoSFML> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS TaikoSFML)