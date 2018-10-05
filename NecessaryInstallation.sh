# SFML Dependencies ( Only if building )

command apt > /dev/null
if [ $? -eq 1 ]; then echo -e "Apt found."; else echo -e "Apt not found.\n Run \`apt\`. It should return \`1\`. If returns something else, report to @TheMesoria!"; exit; fi;
if [ "$USER" == "root" ]; then echo -e "Root detected."; else echo -e "You have to be root to run this script!"; exit; fi

apt-get install libx11-dev
apt install libxrandr-dev
apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
apt install libudev-dev
apt install libfreetype6-dev
apt install libopenal-dev
apt install libvorbis-dev
apt install libflac-dev
