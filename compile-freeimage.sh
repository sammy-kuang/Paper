git clone https://github.com/WinMerge/freeimage
cd freeimage
make
cd ../
cp freeimage/Dist/libfreeimage.a lib/
rm -rf freeimage/