#!/usr/bin/env bash

# this functionis for for ubuntu 12.04 from travis.ci, should be updated
install_cppcheck()
{
    git clone https://github.com/danmar/cppcheck.git
    cd cppcheck
    git checkout $(cat ../scripts/travis/cppcheck_version)
    make CFGDIR=/usr/share/cppcheck/cfg HAVE_RULES=no -j2
    sudo make CFGDIR=/usr/share/cppcheck/cfg install
    cd ..
    rm -rf ./cppcheck/
}

if [ $# -ne 1 ]; then
    echo "Error: expected OS type argument." >&2
    exit 1
fi

os=$1

#note: needs opengl / sdl / glut / xmu / xmi deps for osx!
case "$os" in
    osx)
        brew update
        brew unlink cmake
        brew install protobuf-c protobuf boost cppcheck cmake \
                     pstree
        ;;
    linux|"" )
        sudo echo 'deb http://llvm.org/apt/precise/ '\
            'llvm-toolchain-precise-3.4 main' >>/etc/apt/sources.list
        sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
        sudo add-apt-repository -y ppa:zoogie/sdl2-snapshots
        sudo apt-get -qq update
        sudo apt-get -qq install g++-4.8
        sudo apt-get install libprotobuf-dev protobuf-compiler \
            libboost-all-dev doxygen
        sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 50
        sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 50
        wget -O - http://llvm.org/apt/llvm-snapshot.gpg.key | sudo apt-key add -
        sudo apt-get -qq install clang-format-3.4
         # SDL2
        #curl -O http://www.libsdl.org/release/SDL2-2.0.0.tar.gz
        #tar -xzvf SDL2-2.0.0.tar.gz
        #(cd SDL2-2.0.0 && ./configure && make && sudo make install)
        sudo apt-add-repository --yes ppa:zoogie/sdl2-snapshots # for libsdl2
        sudo apt-get update -qq
        sudo apt-get -qq install libsdl2-dev libsdl2-image-dev
        sudo apt-get -qq install libsdl2-gfx-dev libsdl2-mixer-dev
        sudo apt-get -qq install libxmu-dev libxi-dev
        sudo apt-get -qq install freeglut3 freeglut3-dev
        install_cppcheck
        ;;
    *)
        echo "Error: unknown OS '$os'" >&2
        exit 1
        ;;
esac
