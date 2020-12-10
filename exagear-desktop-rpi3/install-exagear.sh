#!/bin/bash

function retback {
	popd > /dev/null
}
trap retback EXIT

pushd `dirname $0` > /dev/null


UBT_PACKAGE_NAME_2G="exagear-mem2g_*-1_armhf.deb"
UBT_PACKAGE_NAME_3G="exagear_*-1_armhf.deb"
UBT_PACKAGE_NAME_LEGACY_2G="exagear-legacy-mem2g_*-1_armhf.deb"
UBT_PACKAGE_NAME_LEGACY_3G="exagear-legacy_*-1_armhf.deb"
UBT_PACKAGE_NAME_ARM7_8="exagear-armv8_*-1_arm64.deb"

GUEST_IMAGE_PACKAGE_NAME_DEBIAN_7="exagear-guest-debian-7_*_all.deb"
GUEST_IMAGE_PACKAGE_NAME_DEBIAN_7_WINE2G="exagear-guest-debian-7-wine2g_*_all.deb"
GUEST_IMAGE_PACKAGE_NAME_DEBIAN_8="exagear-guest-debian-8_*_all.deb"
GUEST_IMAGE_PACKAGE_NAME_UBUNTU_1204="exagear-guest-ubuntu-1204lts_*_all.deb"
GUEST_IMAGE_PACKAGE_NAME_UBUNTU_1404="exagear-guest-ubuntu-1404lts_*_all.deb"
GUEST_IMAGE_PACKAGE_NAME_UBUNTU_1504="exagear-guest-ubuntu-1504_*_all.deb"
GUEST_IMAGE_PACKAGE_NAME_UBUNTU_1604="exagear-guest-ubuntu-1604_*_all.deb"

PK_FILE_NAME="pk-*.key"

function file_exists {
    stat $1 &> /dev/null
}

function get_host_system_type {

    HOST_OS=`cat /etc/lsb-release 2>/dev/null | egrep "^DISTRIB_ID\=" | awk -F= '{print $2}' |  tr '[:upper:]' '[:lower:]'`
    if [ -n "$HOST_OS" ] ; then
        return
    fi

    HOST_OS=`cat /etc/os-release | egrep "^ID\=" | awk -F= '{print $2}' |  tr '[:upper:]' '[:lower:]'`
    if [ -n "$HOST_OS" ] ; then
        if [ "$HOST_OS" == "debian" -o "$HOST_OS" == "ubuntu" ] ; then
            return
        fi
    fi

    HOST_OS=`cat /etc/os-release | egrep "^ID_LIKE\=" | awk -F= '{print $2}' |  tr '[:upper:]' '[:lower:]'`
    if [ -n "$HOST_OS" ] ; then
        return
    fi

    HOST_OS="default"
}

function check_if_raspbian_23 {
    RASPBIAN=`cat /etc/issue | tr '[:upper:]' '[:lower:]' | grep 'raspbian'`
    if ! [ -z "$RASPBIAN" ] && [ "$ARCH" == 'armv7l' ]; then
	RASPBIAN23='y'
    fi
}

function get_host_system_version {
    if [ "$HOST_OS" == "debian"  ] ; then
        HOST_OS_VERSION=`cat /etc/*-release | egrep "^VERSION_ID\=" | awk -F= '{print $2}' | tr '[:upper:]' '[:lower:]' | tr -d "\"" `
        if [ -z "$HOST_OS_VERSION" ] ; then
    	    if grep "jessie" /etc/*-release; then
    		HOST_OS_VERSION="8"
    	    fi
    	fi

    elif [ "$HOST_OS" == "ubuntu" ] ; then
        HOST_OS_VERSION=`cat /etc/*-release | egrep "^DISTRIB_RELEASE\=" | awk -F= '{print $2}' |  awk -F. '{print $1}' | tr '[:upper:]' '[:lower:]'`
    fi

    if [ -z "$HOST_OS_VERSION" ] ; then
        HOST_OS_VERSION="default"
    fi
}

function get_arch {
    ARCH=`arch`
    echo "ARCH=$ARCH"
}

function check_guest_image_already_installed {
    INSTALLED_GUEST_IMAGE=`ls /opt/exagear/images/ 2>/dev/null | head -n 1`
    
    if [ ! -z "$INSTALLED_GUEST_IMAGE" ]; then
	echo "It is not possible to install guest image package as you already have guest image package installed."
	echo "Installed guest image package name is exagear-guest-$INSTALLED_GUEST_IMAGE. "
	echo "To uninstall current guest image package use ' sudo apt-get purge exagear-guest-$INSTALLED_GUEST_IMAGE '"
	echo "Note that all x86 applications installed inside the current guest image will be also deleted."
	exit 1
    fi
}

function check_free_space {
	FREE_SPACE_MB=`df -m /opt/ | awk 'NR==2 {print $4}'`
	INSTALL_BLOCKDEV=`df -m /opt/ | awk 'NR==2 {print $1}'`
	if [ $FREE_SPACE_MB -lt 1500 ]; then
		echo "No enough space on your $INSTALL_BLOCKDEV file system. 1500M is required for exagear. You got only ${FREE_SPACE_MB}M. Please perform some cleanup or resize partition and try again."
		exit 1
	fi
}

while test ${#} -gt 0
do
    if [ "$1" == "ubuntu-1404" ]
    then
	UBUNTU_14_FORCED='y'
    elif [ "$1" == "--without-opengl" ]
    then
	WITHOUT_GL_FORCED='y'
    else
	echo "Invalid arument: $1"
	exit 1
    fi
    shift
done

uid=$(id -u)
if [ "$uid" != "0" ] ; then
    echo "Must be root"
    exit 1
fi

test_binary=$(mktemp)
echo f0VMRgEBAQAAAAAAAAAAAAIAKAABAAAAVIAAADQAAADIAAAAAAIABTQAIAABACgABgADAAEAAAAAAAAAAIAAAACAAACAAAAAgAAAAAUAAAAAgAAACgKg4wEaoOMAIKDjMjCg48BwoOMAAADvCgJQ4wAAoAMBAKATAXCg4wAAAO9BEwAAAGFlYWJpAAEJAAAABgEIAQAuc3ltdGFiAC5zdHJ0YWIALnNoc3RydGFiAC50ZXh0AC5BUk0uYXR0cmlidXRlcwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAGwAAAAEAAAAGAAAAVIAAAFQAAAAsAAAAAAAAAAAAAAAEAAAAAAAAACEAAAADAABwAAAAAAAAAACAAAAAFAAAAAAAAAAAAAAAAQAAAAAAAAARAAAAAwAAAAAAAAAAAAAAlAAAADEAAAAAAAAAAAAAAAEAAAAAAAAAAQAAAAIAAAAAAAAAAAAAALgBAADgAAAABQAAAAYAAAAEAAAAEAAAAAkAAAADAAAAAAAAAAAAAACYAgAAWwAAAAAAAAAAAAAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAFSAAAAAAAAAAwABAAAAAAAAAAAAAAAAAAMAAgABAAAAAAAAAAAAAAAEAPH/DAAAAFSAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAQA8f8PAAAAgAABAAAAAAAQAAEAGgAAAIAAAQAAAAAAEAABACgAAACAAAEAAAAAABAAAQA0AAAAVIAAAAAAAAAQAAEAOwAAAIAAAQAAAAAAEAABAEcAAACAAAEAAAAAABAAAQBPAAAAgAABAAAAAAAQAAEAVgAAAIAAAQAAAAAAEAABAABtZW1fdGVzdC5vACRhAF9ic3NfZW5kX18AX19ic3Nfc3RhcnRfXwBfX2Jzc19lbmRfXwBfc3RhcnQAX19ic3Nfc3RhcnQAX19lbmRfXwBfZWRhdGEAX2VuZAA= | base64 --decode > $test_binary
chmod +x $test_binary
$test_binary
test_bin_ret=$?
rm -f $test_binary

if [ "$test_bin_ret" -eq  '0' ]; then
    is_3g="1"
    echo "System memory configuration is determined as 3g/1g"
else
    is_3g="0"
    echo "System memory configuration is determined as 2g/2g"
fi

get_host_system_type
get_host_system_version
get_arch
check_guest_image_already_installed
check_free_space
check_if_raspbian_23

if [ "$ARCH" == "armv7l" ]; then
    export USE_DSOUND_SERVER='y'
fi

if [ "$RASPBIAN23" == 'y' ]
then
    if ! [ "$WITHOUT_GL_FORCED" == 'y' ]
    then
	export USE_GL='y'
    fi
fi

if [ "$is_3g" == "1" ]; then
    if [ "$ARCH" ==  "armv6l" ] ; then
        UBT_PACKAGE_NAME=$UBT_PACKAGE_NAME_LEGACY_3G
    elif [ "$ARCH" == "armv7l" ] ; then
        UBT_PACKAGE_NAME=$UBT_PACKAGE_NAME_3G
    elif [ "$ARCH" == "aarch64" ] ; then
	UBT_PACKAGE_NAME=$UBT_PACKAGE_NAME_ARM7_8
    elif [ "$ARCH" == "armv8l" ] ; then
        UBT_PACKAGE_NAME=$UBT_PACKAGE_NAME_ARM7_8
    else
        echo "Only armv7, aarch64 and armv6 host arch are supported for 3g/1g memory split"
        exit 1
    fi
else
    if [ "$ARCH" ==  "armv6l" ] ; then
        UBT_PACKAGE_NAME=$UBT_PACKAGE_NAME_LEGACY_2G
    elif [ "$ARCH" == "armv7l" ] ; then
        UBT_PACKAGE_NAME=$UBT_PACKAGE_NAME_2G
    else
        echo "Only armv7 and armv6 arch are supported for 2g/2g memory split"
        exit 1
    fi    
fi

if [ "$UBUNTU_14_FORCED" == 'y' ] ; then
    # ubuntu-1404 is able to be forced to install via './install-exagear.sh ubuntu-1404'
    GUEST_IMAGE_PACKAGE_NAME=$GUEST_IMAGE_PACKAGE_NAME_UBUNTU_1404
else
    if [ "$HOST_OS" == "debian" ] ; then
        if [ "$HOST_OS_VERSION" == "7" ] ; then
            if [ "$is_3g" == "1" ]; then
                GUEST_IMAGE_PACKAGE_NAME=$GUEST_IMAGE_PACKAGE_NAME_DEBIAN_7
            else
                GUEST_IMAGE_PACKAGE_NAME=$GUEST_IMAGE_PACKAGE_NAME_DEBIAN_7_WINE2G
            fi
        else
            GUEST_IMAGE_PACKAGE_NAME=$GUEST_IMAGE_PACKAGE_NAME_DEBIAN_8
        fi
    elif [ "$HOST_OS" == "ubuntu" ] ; then
        if [ "$HOST_OS_VERSION" == "12" ] ; then
            GUEST_IMAGE_PACKAGE_NAME=$GUEST_IMAGE_PACKAGE_NAME_UBUNTU_1204
        elif [ "$HOST_OS_VERSION" == "14" ] ; then
            GUEST_IMAGE_PACKAGE_NAME=$GUEST_IMAGE_PACKAGE_NAME_UBUNTU_1404
        elif [ "$HOST_OS_VERSION" == "15" ] ; then
            GUEST_IMAGE_PACKAGE_NAME=$GUEST_IMAGE_PACKAGE_NAME_UBUNTU_1504
        else
            GUEST_IMAGE_PACKAGE_NAME=$GUEST_IMAGE_PACKAGE_NAME_UBUNTU_1604
        fi
    else
        GUEST_IMAGE_PACKAGE_NAME=$GUEST_IMAGE_PACKAGE_NAME_UBUNTU_1404
    fi
fi

echo "HOST OS: $HOST_OS"
echo "HOST OS VERSION: $HOST_OS_VERSION"
echo "EXAGEAR package: $UBT_PACKAGE_NAME"
echo "EXAGEAR guest image package: '$GUEST_IMAGE_PACKAGE_NAME'"

if ! file_exists "$UBT_PACKAGE_NAME" ; then
    echo "Put the translator package to the current directory."
    echo "The package is named ${UBT_PACKAGE_NAME/\*/NNNN}."
    exit 1
fi

if ! file_exists "$GUEST_IMAGE_PACKAGE_NAME" ; then
    echo "Put the guest image package to the current directory."
    echo "The package is named ${GUEST_IMAGE_PACKAGE_NAME/\*/N}."
    exit 1
fi

if ! file_exists "$PK_FILE_NAME" ; then
    echo "Put a primary key file to the current directory."
    echo "Primary key files are named ${PK_FILE_NAME/\*/NNNNNN}"
    exit 1
fi

echo "Installing prerequisites..."
apt-get update
for prereq in bash coreutils findutils realpath curl binfmt-support cron; do
    apt-get -y install $prereq || exit 1
done

echo "Installing the binary translator..."
dpkg -i $UBT_PACKAGE_NAME || exit 1

echo "Installing the guest image..."
dpkg -i $GUEST_IMAGE_PACKAGE_NAME || exit 1

if [ "$USE_DSOUND_SERVER" == "y" ]
then
    dpkg -i exagear-dsound-server_*_armhf.deb
fi

echo "Installing the primary key..."
mv $PK_FILE_NAME /opt/exagear/lic/ || exit 1

echo "Activating the copy of ExaGear..."
/opt/exagear/bin/actool || exit 1

echo "Done!"
