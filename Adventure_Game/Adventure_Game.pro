#-------------------------------------------------
#
# Project created by QtCreator 2017-09-10T16:49:35
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Adventure_Game
TEMPLATE = app

SOURCES += main.cpp\
    game_logic/inventory.cpp \
    game_logic/july5.cpp \
    game_logic/location.cpp \
    game_logic/locationmanager.cpp \
    game_logic/maploader.cpp \
    game_logic/verbmanager.cpp \
    objects/door.cpp \
    objects/inventoryobject.cpp \
    objects/key.cpp \
    objects/object.cpp \
    ui/objectbutton.cpp \
    utility/audiomanager.cpp \
    utility/eventmanager.cpp \
    utility/imageutilities.cpp \
    utility/updateable.cpp \
    objects/cookiejar.cpp \
    locationui.cpp \
    mainwindow.cpp \
    objects/porkers.cpp \
    objects/chicken.cpp \
    objects/basementblock.cpp

HEADERS  += \
    game_logic/inventory.h \
    game_logic/july5.h \
    game_logic/location.h \
    game_logic/locationmanager.h \
    game_logic/maploader.h \
    game_logic/verb.h \
    game_logic/verbmanager.h \
    objects/door.h \
    objects/inventoryobject.h \
    objects/key.h \
    objects/object.h \
    ui/objectbutton.h \
    utility/audiomanager.h \
    utility/event.h \
    utility/eventmanager.h \
    utility/imageutilities.h \
    utility/updateable.h \
    objects/cookiejar.h \
    locationui.h \
    mainwindow.h \
    objects/porkers.h \
    objects/chicken.h \
    objects/basementblock.h

FORMS    += \
    mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11

RESOURCES += \
    gfx.qrc

DISTFILES += \
    map/map.txt \
    gfx/backHallway.rtf \
    gfx/basement.rtf \
    gfx/frontHallway.rtf \
    gfx/garden.rtf \
    gfx/kitchen.rtf \
    gfx/livingroom.rtf \
    gfx/maze1.rtf \
    gfx/maze2.rtf \
    gfx/maze3.rtf \
    gfx/wickerman.rtf \
    jmh_horror/JMH HORROR.otf \
    jmh_horror/JMHHORROR-HORROR.ttf \
    sfx/music/kitchen.mp3 \
    sfx/lockedDoor.wav \
    sfx/openDoor.wav \
    sfx/unlockDoor.wav \
    sfx/whisper1.wav \
    sfx/whisper2.wav \
    sfx/whisper3.wav \
    sfx/whisper4.wav \
    sfx/whisper5.wav \
    sfx/whisper6.wav \
    sfx/whisper7.wav \
    gfx/backgrounds/backhallway.png \
    gfx/backgrounds/basement.png \
    gfx/backgrounds/bathroom.png \
    gfx/backgrounds/dollRoom.png \
    gfx/backgrounds/fronthallway.png \
    gfx/backgrounds/garden.png \
    gfx/backgrounds/grannysRoom.png \
    gfx/backgrounds/hallway.png \
    gfx/backgrounds/kitchen.png \
    gfx/backgrounds/livingroom.png \
    gfx/backgrounds/maze1.png \
    gfx/backgrounds/maze2.png \
    gfx/backgrounds/maze2copy.png \
    gfx/backgrounds/maze3.png \
    gfx/backgrounds/maze3copy.png \
    gfx/backgrounds/upstairsHallway.png \
    gfx/backgrounds/wickerman.png \
    gfx/basement/anvil.png \
    gfx/basement/barrels.png \
    gfx/basement/basementStairs.png \
    gfx/basement/boiler.png \
    gfx/basement/cage.png \
    gfx/basement/coal.png \
    gfx/basement/cog.png \
    gfx/basement/container.png \
    gfx/basement/crates.png \
    gfx/basement/generator.png \
    gfx/basement/kettle.png \
    gfx/basement/machine.png \
    gfx/basement/magma.png \
    gfx/basement/monsterPlate.png \
    gfx/basement/pick.png \
    gfx/basement/pipe.png \
    gfx/basement/pit.png \
    gfx/basement/rug.png \
    gfx/basement/skeleton.png \
    gfx/basement/tools.png \
    gfx/basement/wood.png \
    gfx/garden/barrelPlant.png \
    gfx/garden/branchLamps.png \
    gfx/garden/flower.png \
    gfx/garden/gravestones.png \
    gfx/garden/kitchenDoor.png \
    gfx/garden/lampost.png \
    gfx/garden/leafPile.png \
    gfx/garden/leaves.png \
    gfx/garden/log.png \
    gfx/garden/mazeDoor.png \
    gfx/garden/scarecrow.png \
    gfx/garden/sculpture.png \
    gfx/garden/washingLine.png \
    gfx/garden/well.png \
    gfx/interactables/alivePlant.png \
    gfx/interactables/anvil.png \
    gfx/interactables/barrel.png \
    gfx/interactables/barrelPlant.png \
    gfx/interactables/barrels.png \
    gfx/interactables/basementStairs.png \
    gfx/interactables/basementStairs1.png \
    gfx/interactables/blueBook.png \
    gfx/interactables/boiler.png \
    gfx/interactables/books.png \
    gfx/interactables/branchLamps.png \
    gfx/interactables/cage.png \
    gfx/interactables/candletable.png \
    gfx/interactables/catBlackPicture.png \
    gfx/interactables/catFullPicture.png \
    gfx/interactables/catPicture.png \
    gfx/interactables/chandelier.png \
    gfx/interactables/chicken.png \
    gfx/interactables/clawPicture.png \
    gfx/interactables/clock.png \
    gfx/interactables/coal.png \
    gfx/interactables/coffin.png \
    gfx/interactables/cog.png \
    gfx/interactables/container.png \
    gfx/interactables/cookieJar.png \
    gfx/interactables/crack.png \
    gfx/interactables/crates.png \
    gfx/interactables/darkTree.png \
    gfx/interactables/deadPlant.png \
    gfx/interactables/deadTree.png \
    gfx/interactables/door.png \
    gfx/interactables/drawers.png \
    gfx/interactables/eastDoor.png \
    gfx/interactables/eastRoad.png \
    gfx/interactables/fingers.png \
    gfx/interactables/fishPicture.png \
    gfx/interactables/flower.png \
    gfx/interactables/flowers.png \
    gfx/interactables/gargoyle.png \
    gfx/interactables/generator.png \
    gfx/interactables/glassFlowers.png \
    gfx/interactables/gravestones.png \
    gfx/interactables/greenBook.png \
    gfx/interactables/hoodedStatue.png \
    gfx/interactables/kettle.png \
    gfx/interactables/key.png \
    gfx/interactables/kitchenDoor.png \
    gfx/interactables/lampost.png \
    gfx/interactables/leafPile.png \
    gfx/interactables/leaves.png \
    gfx/interactables/log.png \
    gfx/interactables/machine.png \
    gfx/interactables/magma.png \
    gfx/interactables/marblePlant.png \
    gfx/interactables/mazeDoor.png \
    gfx/interactables/monsterPlate.png \
    gfx/interactables/musicSheet.png \
    gfx/interactables/nightWindow.png \
    gfx/interactables/northDoor.png \
    gfx/interactables/northRoad.png \
    gfx/interactables/notes.png \
    gfx/interactables/piano.png \
    gfx/interactables/pick.png \
    gfx/interactables/pigHead.png \
    gfx/interactables/pipe.png \
    gfx/interactables/pit.png \
    gfx/interactables/plate.png \
    gfx/interactables/platesCupboard.png \
    gfx/interactables/potions.png \
    gfx/interactables/potionsbooks.png \
    gfx/interactables/radishes.png \
    gfx/interactables/redFlowers.png \
    gfx/interactables/rockingChair.png \
    gfx/interactables/rubble.png \
    gfx/interactables/rug.png \
    gfx/interactables/scarecrow.png \
    gfx/interactables/scaredCatPicture.png \
    gfx/interactables/sculpture.png \
    gfx/interactables/sign.png \
    gfx/interactables/skeleton.png \
    gfx/interactables/smallDoor.png \
    gfx/interactables/smallLamp.png \
    gfx/interactables/southDoor.png \
    gfx/interactables/southRoad.png \
    gfx/interactables/spinach.png \
    gfx/interactables/splatter1.png \
    gfx/interactables/splatter2.png \
    gfx/interactables/stain.png \
    gfx/interactables/stairs.png \
    gfx/interactables/statue.png \
    gfx/interactables/stool.png \
    gfx/interactables/Stove.png \
    gfx/interactables/symbol.png \
    gfx/interactables/tallLamp.png \
    gfx/interactables/tea.png \
    gfx/interactables/timeTree.png \
    gfx/interactables/tools.png \
    gfx/interactables/troll.png \
    gfx/interactables/tv.png \
    gfx/interactables/vanityDrawers.png \
    gfx/interactables/vent.png \
    gfx/interactables/washingLine.png \
    gfx/interactables/well.png \
    gfx/interactables/westDoor.png \
    gfx/interactables/westRoad.png \
    gfx/interactables/window.png \
    gfx/interactables/wine.png \
    gfx/interactables/wood.png \
    gfx/interactables/yarnPicture.png \
    gfx/interactables/yellowPlant.png \
    gfx/maze1/deadTree.png \
    gfx/maze1/eastRoad.png \
    gfx/maze1/northRoad.png \
    gfx/maze1/southRoad.png \
    gfx/maze1/timeTree.png \
    gfx/maze1/westRoad.png \
    gfx/maze2/coffin.png \
    gfx/maze2/darkTree.png \
    gfx/maze2/rubble.png \
    gfx/maze2/symbol.png \
    gfx/maze2/yellowPlant.png \
    gfx/maze3/hoodedStatue.png \
    gfx/maze3/sign.png \
    gfx/wickerman/_0000_candle28.png \
    gfx/wickerman/_0001_candle27.png \
    gfx/wickerman/_0002_candle26.png \
    gfx/wickerman/_0003_candle25.png \
    gfx/wickerman/_0004_candle24.png \
    gfx/wickerman/_0005_candle23.png \
    gfx/wickerman/_0006_candle22.png \
    gfx/wickerman/_0007_candle21.png \
    gfx/wickerman/_0008_candle20.png \
    gfx/wickerman/_0009_candle19.png \
    gfx/wickerman/_0010_candle18.png \
    gfx/wickerman/_0011_candle17.png \
    gfx/wickerman/_0012_candle16.png \
    gfx/wickerman/_0013_candle15.png \
    gfx/wickerman/_0014_candle14.png \
    gfx/wickerman/_0015_candle13.png \
    gfx/wickerman/_0016_candle12.png \
    gfx/wickerman/_0017_candle11.png \
    gfx/wickerman/_0018_candle10.png \
    gfx/wickerman/_0019_candle9.png \
    gfx/wickerman/_0020_candle8.png \
    gfx/wickerman/_0021_candle7.png \
    gfx/wickerman/_0022_candle6.png \
    gfx/wickerman/_0023_candle5.png \
    gfx/wickerman/_0024_candle4.png \
    gfx/wickerman/_0025_candle3.png \
    gfx/wickerman/_0026_candle2.png \
    gfx/wickerman/_0027_candle1.png \
    gfx/wickerman/_0028_screen1.png \
    gfx/wickerman/_0029_screen2.png \
    gfx/wickerman/_0030_jibby.png \
    gfx/wickerman/_0031_wickerman.png \
    gfx/wickerman/_0032_wickerRoad.png \
    source/BackgroundAssets.psd \
    source/basement.psd \
    source/garden.psd \
    source/Kitchen.psd \
    source/LivingRoom.psd \
    source/maze.psd \
    source/maze2.psd \
    source/maze3.psd \
    source/upstairsHallway.psd \
    source/wickerScreen.psd \
    jmh_horror/Personal Use Only-User Terms Agreement.txt \
    map/map.txt

SUBDIRS += \
    Adventure_Game.pro
