# **Head Unit**

## **Introduction**

This project aims to develop a Head Unit Qt application running on a Raspberry Pi (RPi) alongside the previously developed PiRacer Instrument Cluster Qt application. The Head Unit application will provide additional features like ambient lighting, gear selection, and a media app. The project will use Yocto as the build system for the RPi. [Here is the detailed explanation of This Head Unit Project](https://github.com/SEA-ME/DES_Head-Unit)

## **Overview**
Basically, two Raspberry Pi (CAR Pi, IC/HU Pi) is used.
- **CAR Pi** oversees the movement of PiRacer and communicates directly with joy stick and PiRacer The Client1 of CAR Pi sends gear and battery information to the server in IC/HU Pi. 
- **IC/HU** Pi is used to print and manage the dashboard and infotainment system of the car, and for the server of car system.

Here are the divided technical requirements for composing the Head Unit:

- **[Head Unit Application](#head-unit-application):** A robust and scalable head unit application for automotive use on Raspberry Pi is developed using QT Quick Framework. The QT Quick Framework includes user-freindly and interactive features, and various infotainment functions. Here are the contents:
    - **[Dashboard](#dashboard):** The dashboard shows the speed and battery data. The detailed information is described in Instrument Cluster Project.
    - **[Mirroring](#mirroring):** The screen of mobile device is shown when USB connection is conducted.
    - **[Youtube Player](#youtube-player):** Recent YouTube trending videos will be played.
    - **[Music Player](#music-player):** User can load their playlist and listen songs with their USB or extenal device.
    - **[bluetooth managing](#bluetooth-managing):** User can connect the bluetooth device with the infotainment system.
    - **[etc](#etc):** map, weather, calendar, change light/dark mode theme etc.
- **[SOME/IP Protocol Communication](#someip-protocol-communication):** The client/server or two Raspberry Pi send and receive the data by SOME/IP Protocol. The server exists in the IC Application of IC/HU Pi, which oversees the organic communication with client1 in the CAR Pi and client2 with HU application of IC/HU Pi.
- **[Embedded system using Yocto](#embedded-system-using-yocto):** Yocto is utilized for creating a stable and customizable embedded Linux operating system for the project. Wayland, whose compositor is Weston, is used as GUI environment of the custom linux OS.

## Project Description

### Head Unit Application
Considering IC & HU design is based on the user and system requirements. Those designs are made in [Figma](https://www.figma.com/design/4kdeuqjVnv2GWXMGwS88OF/Head-Unit?node-id=0-1&p=f&t=LxXl4KtK2MOydygM-0). You can click the link to view our demo. If there’s any questions or suggestions, feel free to contact us 🙂

#### Main Page
<p align="center">
  <img src="https://github.com/user-attachments/assets/ef49c2a8-2c63-4cc0-a498-770df32b759e" align="center" width="60%">
</p>
Main page is consists of 3 elements : Car status, Basic components, Main control bar. 

- **Car status** : User can see all the car’s information like speed, mileage, remaining time, gear selection
- **Basic components** : It is a basic background of main home. User can get some information about current climate, schedule, music player
- **Main control bar** : There’s 5 options to selecting page(function) : setting, map, home, music, video

#### Dashboard
<p align="center">
  <img src="https://github.com/user-attachments/assets/5689b0ea-1938-494d-8a3b-3da3200a0142" align="center" width="50%">
</p>
This image shows the UI of Instrument Cluster. It separated into 3 parts.

- **Left** : Gauge chart of Speed
- **Middle** : Status like date, current time, temperature
- **Right** : Gauge chart of RPM & Gear Information

#### Mirroring
The device includes the function of mirroring the screen of mobile device, which is formally aimed to Android decive connected by USB port of RaspberryPi. (iPhone is functionally impossible.) The installed linux command `scrcpy` is automotically executed by methods of header `QProcess` whenever mirroring is turned on. Whenever processing, it checks the status of the process if the command successfully run or failed to find devices, and when the device is not found, the error window is shown.

#### Youtube Player
<p align="center">
  <img src="https://github.com/user-attachments/assets/7ccbce24-d5aa-470a-94f5-7c5b3ec580f5" align="center" width="50%">
</p>
User can load and watch a list of videos that are trending on YouTube and can also be reflected in real time.

#### Music Player
<p align="center">
  <img src="https://github.com/user-attachments/assets/26442e50-22bb-4e1f-aa94-668d2c75f876" align="center" width="50%">
</p>
With user’s USB or external device, User can listen & check playlist. It provides options such as play, stop, and select previous or next song. (We planning to load playlists from bluetooth-connected devices or connect to external streaming sites such as Spotify.)

#### Bluetooth Managing
<p align="center">
  <img src="https://github.com/user-attachments/assets/84078924-424e-42b4-8991-8137bd06da35" align="center" width="50%">
</p>
In the setting page, service option offers the bluetooth function to connect devices such as phone, speaker and etc. If user connect device successfully, bluetooth icon will be displayed on the top bar (next to the mirroring icon)

#### Ambient Lighting
<p align="center">
  <img src="https://github.com/user-attachments/assets/ad8619a1-ea5d-4b26-85bc-690ef2659585" align="center" width="50%">
</p>
In the setting page, there’s a display option to choose mode like dark and light. The mode of entire Headunit & InstrumentCluster can be changed whenever the user wants. 

#### Map
<p align="center">
  <img src="https://github.com/user-attachments/assets/86740124-e6b2-4a40-adba-9bdfb8bba426" align="center" width="50%">
</p>
User can check current location in the map page. (We can’t use GPS, so now it is specified only at predefined places.)

## SOME/IP Protocol Communication

## Yocto Project

The **Yocto Project** is an open-source collaboration project that provides a flexible set of tools and a comprehensive framework for creating custom Linux-based systems. Designed to support embedded development, Yocto helps developers build, customize, and maintain lightweight, scalable Linux distributions tailored to specific hardware and software requirements.

### Key Features
- **Customizable Linux Systems**: Build minimal, optimized Linux distributions for embedded devices.
- **BitBake Build System**: A powerful tool to automate the build process for cross-compilation and package management.
- **Layered Architecture**: Use layers to modularize features, configurations, and machine-specific customizations.
- **Board Support Package (BSP)**: Simplifies hardware integration for a variety of platforms and architectures.
- **OpenEmbedded Core**: Provides a rich set of metadata and recipes to simplify development.

### Why Use Yocto?
- **Portability**: Works across a wide range of hardware architectures.
- **Scalability**: Ideal for small embedded systems and larger IoT devices.
- **Flexibility**: Offers full control over system configuration, software packages, and dependencies.


### Layer Architecture
In our project, we utilized two Raspberry Pi devices to develop two distinct versions of custom Linux OS: **CAR** and **IC/HU**. Each version features a unique layer architecture, tailored to optimize hardware resources by excluding unnecessary layers. 

#### IC/HU OS Layer Architecture
<p align="center">
  <img src="https://github.com/user-attachments/assets/0df2862a-31e9-4199-a166-0ff013947e56" align="center" width="40%">
  <img src="https://github.com/user-attachments/assets/2497a167-6610-4252-aef1-1fdc75e7e69e" align="center" width="29%">
</p>
To function as IC/HU OS, these OS has Instrument Cluster and Head Unit application recipe file. And As Instrument cluster and Head Unit process exchange data like gear, ambient light each other using internal vsomeip, there are recipe files for vsomeip communication.

#### CAR OS Layer Architecture
<p align="center">
  <img src="https://github.com/user-attachments/assets/91d22cd6-08a9-4c35-afff-47f1fe6fb46a" align="center" width="50%">
  <img src="https://github.com/user-attachments/assets/8855e7f6-082b-4d7c-908f-d3623948d254" align="center" width="33%">
</p>

To function as CAR OS, these OS has recipe files which includes piracer control code and python dependencies in  **meta-control layer**. And As RaspberryPi with this OS should send attributes like gear, Indicator by using external vsomeip, it had recipe files that enable this OS to use vsomeip communication.      



- And both OS has common layer(**meta-minam**, **meta-env**)

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
