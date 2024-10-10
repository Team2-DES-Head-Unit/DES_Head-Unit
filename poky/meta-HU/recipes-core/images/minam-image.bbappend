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
    python3-typing-extensions \
    cmake \
"



GSTREAMER_PKGS = " \
    gstreamer1.0 \
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
    qtwayland-tools \
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
    qtlocation-dev \ 
    qtlocation-mkspecs \ 
    qtlocation-plugins \
    qtlocation \ 
"
PIRACER = " \
    python3-pip \
    control \
    piracer \
    v4l-utils \
    python3-dev \
    python3-setuptools \
    raspi-gpio \
    rpio \
    rpi-gpio \
    pi-blaster \
    python3-adafruit-circuitpython-register \
    platformdetect \
    python3-adafruit-pureio \
    blinka \
    busdevice \
    control \
    ina219 \
    pca9685 \
    pygame \
    pyserial \
    ssd \
    requests \
    framebuf \
    typing \
    connectionmanager \
"

Application =" \
    hu \
"



IMAGE_INSTALL += " \
    ${GSTREAMER_PKGS} \
    ${IMG_BASE} \
    ${QT_BASE} \
    ${QT_PKGS} \
    ${PIRACER} \
    ${Application} \
"
