SUMMARY = "INSTRUMENT CLUSTER GUI"
DESCRIPTION = "INSTRUMENT CLUSTER GUI"
LICENSE = "CLOSED"

SRC_URI = "git://github.com/Team2-DES-Head-Unit/DES_Head-Unit.git;branch=waylandtest;protocol=https"
SRCREV ="1e7e572122ad70c8f86dab8b0a3102615a71de49"


S = "${WORKDIR}/git/TEST"

inherit cmake_qt5 

DEPENDS += "qtbase qtdeclarative qtquickcontrols2 qtwayland wayland weston"


do_install() {
    install -d ${D}/usr/bin/ic
    install -m 0755 ${B}/IC_TEST ${D}/usr/bin/ic
    install -m 0755 ${S}/main.qml ${D}/usr/bin/ic
}


FILES:${PN} += "/usr/bin/ic"




