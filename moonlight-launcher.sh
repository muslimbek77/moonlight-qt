#!/bin/bash
# Moonlight Qt Launcher Script
# Bu script snap paketlar bilan bog'liq muammolarni hal qiladi

cd "$(dirname "$0")"

# Barcha snap environment variables ni tozalash
unset SNAP
unset SNAP_COMMON
unset SNAP_USER_DATA
unset SNAP_USER_COMMON
unset SNAP_NAME
unset SNAP_INSTANCE_NAME
unset SNAP_REVISION
unset SNAP_VERSION

# PATH va LD_LIBRARY_PATH ni to'liq nazorat qilish
export PATH="/usr/local/bin:/usr/bin:/bin:/sbin:/usr/sbin"
export LD_LIBRARY_PATH="/lib/x86_64-linux-gnu:/usr/lib/x86_64-linux-gnu:/usr/local/lib"

# Snap mount'lardan qochish uchun
export LD_PRELOAD=""

# Agar GUI kerak bo'lsa
if [ "$1" = "--gui" ] || [ -z "$1" ]; then
    echo "Moonlight Qt GUI ishga tushirilmoqda..."
    # X11 yoki Wayland mavjudligini tekshirish
    if [ -n "$DISPLAY" ] || [ -n "$WAYLAND_DISPLAY" ]; then
        # System dynamic linker bilan to'g'ridan-to'g'ri ishga tushirish
        exec /lib64/ld-linux-x86-64.so.2 --library-path "/lib/x86_64-linux-gnu:/usr/lib/x86_64-linux-gnu:/usr/local/lib" ./app/moonlight "${@:2}"
    else
        echo "Xato: Display topilmadi. X11 yoki Wayland sessiyasida bo'lganingizga ishonch hosil qiling."
        exit 1
    fi
else
    # CLI rejimi
    QT_QPA_PLATFORM=offscreen exec /lib64/ld-linux-x86-64.so.2 --library-path "/lib/x86_64-linux-gnu:/usr/lib/x86_64-linux-gnu:/usr/local/lib" ./app/moonlight "$@"
fi