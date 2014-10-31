NURBSurfer
==========

NURBSurfer is a C++11 / OpenGL NURBS-based CAD GUI. NURBSurfer can
load OpenNURBS .nrb_geom geometry files and display the models to the screen. NURBSurfer allows users to view, 
generate and alter models and meshes, view and alter finite-element model field data, load from and save to
OpenNURBS and industry-standard file formats, and generally access the features provided by the OpenNURBS
geometric modeling library.

Note: NURBSurfer is in development, not a fully-functional tool. Please help test and report any bugs, comments, 
or questions here on the github issues page.

==========

Prerequisites:

NURBSurfer uses OpenGL and the Simple DirectMedia Layer, or SDL, similar to the Valve platform. You need a 
graphics card that can support OpenGL, and the SDL libraries installed on your system.

==========

To install:

mkdir NURBSurfer

git clone https://github.com/OpenNURBS/NURBSurfer.git NURBSurfer

cd NURBSurfer

mkdir build

cd build

cmake ..

make

(this will place the executable in ./NURBSurfer/build/bin)


and optionally:

sudo make install

(this will place the executable in /usr/bin/, allowing all users to access NURBSurfer)





