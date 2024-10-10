PACKAGECONFIG:append = " journald"

# set QPA
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"


do_install:append() {
  install -d "${D}${sysconfdir}/profile.d"
  install -m 0644 "${WORKDIR}/qt-qpa.sh" "${D}${sysconfdir}/profile.d"
}
