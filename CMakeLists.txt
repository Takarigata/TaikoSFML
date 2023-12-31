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
file(GLOB_RECURSE TJAPARSER RELATIVE ${CMAKE_SOURCE_DIR} "src/TJAParser/*.cpp")
find_package(OpenGL REQUIRED)

add_executable(TaikoSFML src/main.cpp ${GAMEFRAMEWORK} ${ENGINERAMEWORK} ${TAIKOFRAMEWORK} ${TJAPARSER} ${EXTERNALCPP} ${EXTERNALHPP})
target_link_libraries(TaikoSFML PRIVATE sfml-graphics)
target_link_libraries(TaikoSFML PRIVATE sfml-audio)
target_link_libraries(TaikoSFML PRIVATE OpenGL::GL)
target_include_directories(TaikoSFML PRIVATE
    External/imgui
    src/GameFramework/Public
    src/TJAParser/Public
    src/EngineFramework/Lib/Math/Public
    src/EngineFramework/Utility/Interface/Public
    src/EngineFramework/Utility/ImGUIDebug/Public
    src/EngineFramework/Utility/ImGUIDebug/SpritePosDebug/Public
    src/EngineFramework/Utility/Animation/SineWave/Public
    src/EngineFramework/Public
    src/EngineFramework/SubSystem/Public
    src/EngineFramework/Actor/Public
    src/EngineFramework/SubSystem/EventHandler/Public
    src/EngineFramework/SubSystem/WindowManager/Public
    src/EngineFramework/SubSystem/SceneManager/Public
    src/EngineFramework/SubSystem/DebugManager/Public
    src/EngineFramework/Components/AudioPlayer/Public
    src/EngineFramework/Components/TexturedSprite/Public
    src/EngineFramework/Components/AnimatedTexturedSprite/Public
    src/EngineFramework/Components/FadeComponent/Public
    src/EngineFramework/Components/BPMSignalComponent/Public
    src/EngineFramework/Components/Public
    src/TaikoFramework/Scene/MainMenu/Public
    src/TaikoFramework/Scene/GameScene/Public
    src/TaikoFramework/Actor/Notes/Public
    src/TaikoFramework/Actor/TaikoCharacter/Public
    src/TaikoFramework/Actor/PuchiChara/Public
    src/TaikoFramework/Components/DrumPart/Public
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

add_custom_command(
        TARGET ${PROJECT_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/Songs
                $<TARGET_FILE_DIR:TaikoSFML>/Songs)
install(TARGETS TaikoSFML)