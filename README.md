***INSTRUCTIONS***

* This instruction are made for Ubuntu

* First install some few dependences:
```
sudo apt-get install build-essential libx11-dev libxinerama-dev sharutils suckless-tools libxft-dev stterm

```
* Then clone my repo and compile it using:
```
sudo make clean install
```
* We need to do some extra stuff if we want to set it on our login screen:
```
sudo apt-get install dwm
sudo cp /usr/share/xsessions/dwm.desktop{,.bak}
sudo apt-get purge dwm
sudo mv /usr/share/xsessions/dwm.desktop{.bak,}
```
* To set background you will ned to install "feh" by using:
```
sudo apt install feh
```
* Then create a directory in your Desktop directory call backgrounds and put in there your background images
* Then restart your PC and select dwm on your session screen

*some apps are used for personal purpouses, so you dont have to install, as zoom or slack*
