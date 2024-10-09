IMG_BASE = " \
    python3 \
    python3-numpy \ 
    wpa-supplicant \
    openssh \
    i2c-tools \
    bash \
    git \
    can-utils \
    libsocketcan \
    bcm2835-dev \
    psplash \
"



GSTREAMER_PKGS = " \
    gstreamer1.0-plugins-base \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-libav \
    pulseaudio \
"

QT_BASE = " \
    qtbase \
    qtbase-dev \
    qtbase-mkspecs \
    qtbase-plugins \
    qtbase-tools \
"

QT_PKGS = " \
    qtwayland \
    qtwayland-dev \
    qtwayland-mkspecs \
    qtconnectivity-dev \
    qtconnectivity-mkspecs \
    qtquickcontrols \
    qtquickcontrols-qmlplugins \
    qtquickcontrols2 \
    qtquickcontrols2-dev \
    qtquickcontrols2-mkspecs \
    qtquickcontrols2-qmlplugins \
    qtdeclarative \
    qtdeclarative-dev \
    qtdeclarative-mkspecs \
    qtdeclarative-qmlplugins \
    qtgraphicaleffects \
    qtgraphicaleffects-dev \
    qtmultimedia \
    qtmultimedia-plugins \
    qtmultimedia-qmlplugins \
"
PIRACER = " \
    python3-pip \
    control \
    piracer \
    v4l-utils \
    python3-dev \
    python3-setuptools \
"

do_install:append() {
    pip3 install RPi.GPIO adafruit-circuitpython-pca9685 adafruit-circuitpython-ina219 adafruit-circuitpython-ssd1306 opencv-python pygame pyserial adafruit-blinka adafruit-circuitpython-busdevice piracer-py
}


IMAGE_INSTALL += " \
    ${GSTREAMER_PKGS} \
    ${IMG_BASE} \
    ${QT_BASE} \
    ${QT_PKGS} \
    ${PIRACER} \
"
