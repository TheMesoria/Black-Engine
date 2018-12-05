#!/usr/bin/env bash
# SFML Dependencies ( Only if building )

command apt > /dev/null
if [[ $? -eq 1 ]]; then echo -e "Apt found."; else echo -e "Apt not found.\n Run \`apt\`. It should return \`1\`. If returns something else, report to @TheMesoria!"; exit; fi;
if [[ "$USER" == "root" ]]; then echo -e "Root detected."; else echo -e "You have to be root to run this script!"; exit; fi


apt-get install cmake ${1}
apt-get install gcc ${1}
apt-get install g++ ${1}
apt-get install libx11-dev ${1}
apt-get install libxrandr-dev ${1}
apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev ${1}
apt-get install libudev-dev ${1}
apt-get install libfreetype6-dev ${1}
apt-get install libopenal-dev ${1}
apt-get install libvorbis-dev ${1}
apt-get install libflac-dev ${1}
