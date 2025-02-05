# Dependencies for running this project
This document provides instructions for installing the necessary dependencies to run this project!
Before proceeding, ensure you have **Ubuntu 20.04 or later** installed.

--------------------------------------------------------------------------------------------------------
## 🚀 Quick Installation (Recommended)

Run the following command to install all required dependencies at once:

```bash
sudo apt install -y \
    qt5-default \
    qtbase5-dev \
    qtconnectivity5-dev \
    qtmultimedia5-dev \
    libqt5multimedia5-plugins \
    qml-module-qtmultimedia \
    qtwebengine5-dev \
    qtlocation5-dev \
    cmake \
    bluez \
    scrcpy \
    gstreamer1.0-libav \
    gstreamer1.0-plugins-base \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-plugins-ugly
    
--------------------------------------------------------------------------------------------------------
# CMake
cmake >= 3.14

# QMake
qtbase5-dev

# Qt dependencies
qt5-default
qtconnectivity5-dev
qtmultimedia5-dev
libqt5multimedia5-plugins
qml-module-qtmultimedia
qtwebengine5-dev
qtwebengine5-examples (not necessary)
qtwebengine5-doc (not necessary)
qtwebengine5-private-dev (not necessary)
qtlocation5-dev

# Bluetooth system
bluez

# Android phone mirroring
scrcpy

# GStreamer multimedia dependencies
gstreamer1.0-libav
gstreamer1.0-plugins-base
gstreamer1.0-plugins-good
gstreamer1.0-plugins-bad
gstreamer1.0-plugins-ugly


