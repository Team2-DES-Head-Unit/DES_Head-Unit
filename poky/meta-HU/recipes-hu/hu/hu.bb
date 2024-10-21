SUMMARY = "Head unit GUI"
DESCRIPTION = "Head unit GUI"
LICENSE = "CLOSED"

SRC_URI = "git://github.com/Team2-DES-Head-Unit/DES_Head-Unit.git;branch=waylandtest;protocol=https"
SRCREV ="d362008180a5028fc958f64fc4b0e4a1bd224f36"
SRC_URI[sha256sum] = "fe192784ee4a1900f9aa87a633484286657c49a7fe69bcf7663ba53d74122ac6"

S = "${WORKDIR}/git/HeadUnit_Project/HeadUnit"

inherit cmake_qt5 

DEPENDS += "qtbase qtdeclarative qtquickcontrols2 qtmultimedia qtwebengine qtconnectivity"


do_install() {
    install -d ${D}/usr/bin/hu
    install -m 0755 ${B}/HeadUnit ${D}/usr/bin/hu
    install -m 0755 ${S}/main.qml ${D}/usr/bin/hu
    install -m 0755 ${S}/bluetooth_page.qml ${D}/usr/bin/hu
    install -m 0755 ${S}/light_page.qml ${D}/usr/bin/hu
    install -m 0755 ${S}/media_page_youtube.qml ${D}/usr/bin/hu
    install -m 0755 ${S}/map_page.qml ${D}/usr/bin/hu
    install -m 0755 ${S}/media_page.qml ${D}/usr/bin/hu
    install -m 0755 ${S}/music_page.qml ${D}/usr/bin/hu
    install -m 0755 ${S}/setting_page.qml ${D}/usr/bin/hu
}




FILES:${PN} += "/usr/bin/hu"



