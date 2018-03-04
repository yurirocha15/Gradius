project(gradius)

cmake_minimum_required(VERSION 2.8)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(SDL_mixer REQUIRED)

link_libraries(	${SDL_LIBRARY}
		${SDLIMAGE_LIBRARY}
		${SDLTTF_LIBRARY}
		${SDLMIXER_LIBRARY}
		SDLmain)

set(SOURCES
	../src/Background.cpp
	../src/Boss.cpp
	../src/Bullet.cpp
	../src/Button.cpp
	../src/Chunk.cpp
	../src/Controler.cpp
	../src/Double.cpp
	../src/Enemy.cpp
	../src/Entity.cpp
	../src/Event.cpp
	../src/GameOver.cpp
	../src/Gradius.cpp
	../src/GradiusShip.cpp
	../src/GradiusShield.cpp
	../src/Message.cpp
	../src/Music.cpp
	../src/Screen.cpp
	../src/SFX.cpp
	../src/Shoot.cpp
	../src/Simple.cpp
	../src/SimpleEnemy.cpp
	../src/Sprite.cpp
	../src/SquadEnemy.cpp
	../src/Stage.cpp
	../src/StringInput.cpp
	../src/TestEnemy.cpp
	../src/Timer.cpp
	../src/Title.cpp
	../src/Upgrade.cpp
	../src/WinScreen.cpp

)

add_executable(Gradius ${SOURCES})
