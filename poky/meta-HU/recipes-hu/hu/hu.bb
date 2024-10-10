SUMMARY = "Head unit GUI"
DESCRIPTION = "Head unit GUI"
LICENSE = "CLOSED"

SRC_URI = "git://github.com/Team2-DES-Head-Unit/DES_Head-Unit.git;branch=HU;protocol=https"
SRCREV ="56b4c70fae1786a5e3e1d446b5ab08d5e0a54e67"
SRC_URI[sha256sum] = "fe192784ee4a1900f9aa87a633484286657c49a7fe69bcf7663ba53d74122ac6"

S = "${WORKDIR}/git/HeadUnit_Project/HeadUnit"

inherit cmake_qt5 

DEPENDS += "qtbase qtdeclarative qtquickcontrols2 qtmultimedia"


do_install() {
    install -d ${D}${bindir}/HU/
    install -m 0755 ${B}/HeadUnit ${D}${bindir}/HU/
    install -m 0755 ${S}/main.qml ${D}${bindir}/HU/
    install -m 0755 ${S}/map_page.qml ${D}${bindir}/HU/
    install -m 0755 ${S}/media_page.qml ${D}${bindir}/HU/
    install -m 0755 ${S}/music_page.qml ${D}${bindir}/HU/
    install -m 0755 ${S}/setting_page.qml ${D}${bindir}/HU/
}


FILES:${PN} += "${bindir}/HU/"


