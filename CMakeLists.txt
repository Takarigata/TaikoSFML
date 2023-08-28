cmake_minimum_required(VERSION 3.21)
project(TaikoSFML LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE EXTERNALCPP "External/*.cpp")
file(GLOB_RECURSE EXTERNALHPP "External/*.hpp")
file(GLOB_RECURSE GAMEFRAMEWORK RELATIVE ${CMAKE_SOURCE_DIR} "src/GameFramework/*.cpp")
file(GLOB_RECURSE ENGINERAMEWORK RELATIVE ${CMAKE_SOURCE_DIR} "src/EngineFramework/*.cpp")
file(GLOB_RECURSE TAIKOFRAMEWORK RELATIVE ${CMAKE_SOURCE_DIR} "src/TaikoFramework/*.cpp")
find_package(OpenGL REQUIRED)

add_executable(TaikoSFML src/main.cpp ${GAMEFRAMEWORK} ${ENGINERAMEWORK} ${TAIKOFRAMEWORK} ${EXTERNALCPP} ${EXTERNALHPP})
target_link_libraries(TaikoSFML PRIVATE sfml-graphics)
target_link_libraries(TaikoSFML PRIVATE sfml-audio)
target_link_libraries(TaikoSFML PRIVATE OpenGL::GL)
target_include_directories(TaikoSFML PRIVATE External/imgui)
target_include_directories(TaikoSFML PRIVATE src/GameFramework/Public)
target_include_directories(TaikoSFML PRIVATE src/EngineFramework/Lib/Math/Public)
target_include_directories(TaikoSFML PRIVATE src/EngineFramework/Utility/Interface/Public)
target_include_directories(TaikoSFML PRIVATE src/EngineFramework/Public)
target_include_directories(TaikoSFML PRIVATE src/EngineFramework/SubSystem/Public)
target_include_directories(TaikoSFML PRIVATE src/EngineFramework/SubSystem/EventHandler/Public)
target_include_directories(TaikoSFML PRIVATE src/EngineFramework/SubSystem/WindowManager/Public)
target_include_directories(TaikoSFML PRIVATE src/EngineFramework/SubSystem/SceneManager/Public)
target_include_directories(TaikoSFML PRIVATE src/TaikoFramework/Scene/MainMenu/Public)
target_include_directories(TaikoSFML PRIVATE src/GameFramework/Utilities/Public)
target_include_directories(TaikoSFML PRIVATE src/GameFramework/Input/Public)
target_compile_features(TaikoSFML PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET TaikoSFML POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:TaikoSFML> $<TARGET_FILE_DIR:TaikoSFML> COMMAND_EXPAND_LISTS)
endif()
add_custom_command(
        TARGET ${PROJECT_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/Assets
                $<TARGET_FILE_DIR:TaikoSFML>/Assets)
install(TARGETS TaikoSFML)