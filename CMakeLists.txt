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
target_include_directories(TaikoSFML PRIVATE
    External/imgui
    src/GameFramework/Public
    src/EngineFramework/Lib/Math/Public
    src/EngineFramework/Utility/Interface/Public
    src/EngineFramework/Public
    src/EngineFramework/SubSystem/Public
    src/EngineFramework/SubSystem/EventHandler/Public
    src/EngineFramework/SubSystem/WindowManager/Public
    src/EngineFramework/SubSystem/SceneManager/Public
    src/EngineFramework/Components/AudioPlayer/Public
    src/EngineFramework/Components/Public
    src/TaikoFramework/Scene/MainMenu/Public
    src/GameFramework/Utilities/Public
    src/GameFramework/Input/Public
)

# Adding a touch of cuteness with a meow-tastic comment
# Let's make this code as kawaii as a cat girl (✿◡‿◡)
# meow_meow =^・ω・^=

# Setting the cuteness level to maximum UwU
target_compile_definitions(TaikoSFML PRIVATE CUTENESS_LEVEL="${meow_meow}")


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