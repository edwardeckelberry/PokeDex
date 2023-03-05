cmake_minimum_required(VERSION 3.22)
project(DropDownMenu)

set(CMAKE_CXX_STANDARD 14)

add_executable(DropDownMenu main.cpp Application.cpp Application.h DropDownMenu.cpp DropDownMenu.h Images.cpp Images.h ImageNames.h Tracks.cpp Tracks.h TracksEnum.h Music.cpp Music.h SoundEffects.cpp SoundEffects.h Tracker.cpp Tracker.h TrackerEnum.h History.cpp History.h App.cpp App.h TextBox.cpp TextBox.h KeyboardEvents.cpp KeyboardEvents.h MouseEvents.cpp MouseEvents.h InputRecord.cpp InputRecord.h States.cpp States.h SnapShot.h StatesEnum.h ImageClass.cpp ImageClass.h menuNames.h)

target_link_libraries(DropDownMenu sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)