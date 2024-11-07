SUMMARY = "COMMUNICATION"
DESCRIPTION = "COMMUNICATION"
LICENSE = "CLOSED"

SRC_URI = "git://github.com/Team2-DES-Head-Unit/DES_Head-Unit.git;branch=main;protocol=https"
SRCREV ="6ea7085081839e56c8e368f9aad0f4ebf60876f6"

S = "${WORKDIR}/git/vsomeip_service/src"

inherit cmake 

DEPENDS += "cmake"


do_install() {
    install -d ${D}/home/root/vsomeip
    install -m 0755 ${B}/HelloWorldService ${D}/home/root/vsomeip
}


FILES:${PN} += "/home/root/vsomeip/HelloWorldService"


