# **Head Unit**

## **Introduction**

This project aims to develop a Head Unit Qt application running on a Raspberry Pi (RPi) alongside the previously developed PiRacer Instrument Cluster Qt application. The Head Unit application will provide additional features like ambient lighting, gear selection, and a media app. The project will use Yocto as the build system for the RPi. [Here is the detailed explanation of This Head Unit Project](https://github.com/SEA-ME/DES_Head-Unit)

## **Overview**
Basically, two Raspberry Pi (CAR Pi, IC/HU Pi) is used.
- **CAR Pi** oversees the movement of PiRacer and communicates directly with joy stick and PiRacer The Client1 of CAR Pi sends gear and battery information to the server in IC/HU Pi. 
- **IC/HU** Pi is used to print and manage the dashboard and infotainment system of the car, and for the server of car system.

Here are the divided technical requirements for composing the Head Unit:

- **[Head Unit Application](#head-unit-application):** A robust and scalable head unit application for automotive use on Raspberry Pi is developed using QT Quick Framework. The QT Quick Framework includes user-freindly and interactive features, and various infotainment functions. Here are the contents:
    - **[Dashboard](#dashboard):** The ]ashboard which shows the speed data and battery. The detailed information is described in Instrument Cluster Project.
    - **[Mirroring](#mirroring):** The screen of mobile device is shown when USB connection is conducted.
    - **[Youtube Player](#youtube-player):** Recent YouTube video is played.
    - **[Music Player](#music-player):** The infotainment system can play the music you saved in the USB flash memory.
    - **[bluetooth managing](#bluetooth-managing):** You can connect the bluetooth device with the infotainment system.
    - **[etc](#etc):** map, weather, calendar, theme light/dark mode change etc.
- **[SOME/IP Protocol Communication](#someip-protocol-communication):** The client/server or two Raspberry Pi send and receive the data by SOME/IP Protocol. The server exists in the IC Application of IC/HU Pi, which oversees the organic communication with client1 in the CAR Pi and client2 with HU application of IC/HU Pi.
- **[Embedded system using Yocto](#embedded-system-using-yocto):** Yocto is utilized for creating a stable and customizable embedded Linux operating system for the project. Wayland, whose compositor is Weston, is used as GUI environment of the custom linux OS.

## Project Description

### Head Unit Application

#### Dashboard

#### Mirroring
The device includes the function of mirroring the screen of mobile device, which is formally aimed to Android decive connected by USB port of RaspberryPi. (iPhone is functionally impossible.) The installed linux command `scrcpy` is automotically executed by methods of header `QProcess` whenever mirroring is turned on. Whenever processing, it checks the status of the process if the command successfully run or failed to find devices, and when the device is not found, the error window is shown.

#### Youtube Player

#### Music Player

#### Bluetooth Managing

#### etc

### SOME/IP Protocol Communication


### Embedded system using Yocto


## Tech Stack

<table align="center">
  <tr>
    <td align="center" width="140px">
      <a href="https://www.linux.org/">
        <img src="https://www.kernel.org/theme/images/logos/tux.png" width="48" height="48" alt="linux" />
      </a>
      <br />Linux
    </td>
    <td align="center" width="140px">
      <a href="https://isocpp.org/">
        <img src="https://isocpp.org/assets/images/cpp_logo.png" width="48" height="48" alt="c++" />
      </a>
      <br />C++
    </td>
    <td align="center" width="140px">
      <a href="https://www.yoctoproject.org/">
        <img src="https://www.yoctoproject.org/wp-content/uploads/sites/32/2023/09/YoctoProject_Logo_RGB_White_small.svg" width="48" height="48" alt="yokto" />
      </a>
      <br />Yocto Project
    </td>
    <td align="center" width="140px">
      <a href="https://www.raspberrypi.com/">
        <img src="https://upload.wikimedia.org/wikipedia/de/thumb/c/cb/Raspberry_Pi_Logo.svg/1200px-Raspberry_Pi_Logo.svg.png" width="40" height="48" alt="raspberrypi" />
      </a>
      <br />Raspberry Pi
    </td>
  </tr>
  <tr>
    <td align="center" width="140px">
      <a href="https://wayland.freedesktop.org/">
        <img src="https://wayland.freedesktop.org/wayland.png" width="48" height="48" alt="wayland" />
      </a>
      <br />Wayland
    </td>
    <td align="center" width="140px">
      <a href="https://www.qt.io/">
        <img src="https://www.qt.io/hubfs/Qt-logo-neon-small.png" width="60" height="40" alt="Grafana" />
      </a>
      <br />QT Quick
    </td>
    <td align="center" width="140px">
      <a href="https://github.com/COVESA/vsomeip">
        <img src="https://covesa.global/wp-content/uploads/2024/04/VSOMEIP-1.png" width="48" height="48" alt="Prometheus" />
      </a>
      <br />VSomeIP
    </td>
  </tr>
</table>


## Contributors

<center>
<table align="center">
  <tr>
    <td align="center">
      <a href="https://github.com/jo49973477>">
        <img src="https://github.com/jo49973477.png" width="150px;" alt="Yeongyoo Jo"/>
        <br />
        <sub><b>Yeongyoo Jo</b></sub>
      </a>
      <br />
      <a href="https://github.com/jo49973477"><img src="https://img.shields.io/badge/GitHub-jo49973477-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/iznue">
        <img src="https://github.com/iznue.png" width="150px;" alt="Eunji Lee"/>
        <br />
        <sub><b>Eunji Lee</b></sub>
      </a>
      <br />
      <a href="https://github.com/iznue"><img src="https://img.shields.io/badge/GitHub-iznue-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/johook">
        <img src="https://github.com/johook.png" width="150px;" alt="Seokhoon Jo"/>
        <br />
        <sub><b>Seokhoon Jo</b></sub>
      </a>
      <br />
      <a href="https://github.com/johook"><img src="https://img.shields.io/badge/GitHub-johook-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
  </tr>
  <tr>
    <td align="center">
      <a href="https://github.com/programerKim">
        <img src="https://github.com/programerKim.png" width="150px;" alt="Sunwung Kim"/>
        <br />
        <sub><b>Sunwung Kim</b></sub>
      </a>
      <br />
      <a href="https://github.com/programerKim"><img src="https://img.shields.io/badge/GitHub-programerKim-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/mechsoon">
        <img src="https://github.com/mechsoon.png" width="150px;" alt="Jisoo Kim"/>
        <br />
        <sub><b>Seungjoo Kim</b></sub>
      </a>
      <br />
      <a href="https://github.com/mechsoon"><img src="https://img.shields.io/badge/GitHub-mechsoon-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/atoepper">
        <img src="https://github.com/atoepper.png" width="150px;" alt="Alex"/>
        <br />
        <sub><b>Alex</b></sub>
      </a>
      <br />
      <a href="https://github.com/atoepper"><img src="https://img.shields.io/badge/GitHub-atoepper-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
  </tr>
</table>
</center>
