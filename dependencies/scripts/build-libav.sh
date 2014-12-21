#!/bin/bash

. $(dirname $0)/utils.sh

# http://libav.org/releases/libav-0.7.6.tar.gz

if [ ! -f $CACHEROOT/libav-$LIBAV_VERSION.tar.gz ]; then
  echo 'Downloading libav sources'
  try curl -L http://libav.org/releases/libav-$LIBAV_VERSION.tar.gz > $CACHEROOT/libav-$LIBAV_VERSION.tar.gz
fi
if [ ! -d $TMPROOT/libav-$LIBAV_VERSION ]; then
  try rm -rf $TMPROOT/libav-$LIBAV_VERSION
  try tar xvf $CACHEROOT/libav-$LIBAV_VERSION.tar.gz 2>&1 >/dev/null
  try mv libav-$LIBAV_VERSION $TMPROOT
  pushd $TMPROOT/libav-$LIBAV_VERSION
    try patch -p0 < $RENIOSDEPROOT/patches/libav.diff
  popd
fi

set -x

export PATH="$(dirname $0):$PATH"

echo "Configuring libav"
pushd $TMPROOT/libav-$LIBAV_VERSION
try ./configure --prefix=$DESTROOT \
  --cc="$ARM_CC" \
  --sysroot="$IOSSDKROOT" \
  --target-os=darwin \
  $LIBAV_CONFIGURE_ARCH_CPU \
  --extra-cflags="$ARM_CFLAGS" \
  --extra-ldflags="$ARM_LDFLAGS" \
  --enable-cross-compile \
  --enable-static \
  --disable-shared \
  --enable-memalign-hack \
  --enable-runtime-cpudetect \
  --disable-encoders \
  --disable-muxers \
  --disable-bzlib \
  --disable-demuxers \
  --enable-demuxer=au \
  --enable-demuxer=avi \
  --enable-demuxer=flac \
  --enable-demuxer=m4v \
  --enable-demuxer=matroska \
  --enable-demuxer=mov \
  --enable-demuxer=mp3 \
  --enable-demuxer=mpegps \
  --enable-demuxer=mpegts \
  --enable-demuxer=mpegtsraw \
  --enable-demuxer=mpegvideo \
  --enable-demuxer=ogg \
  --enable-demuxer=wav \
  --enable-demuxer=webm \
  --disable-decoders \
  --enable-decoder=flac \
  --enable-decoder=mp2 \
  --enable-decoder=mp3 \
  --enable-decoder=mp3on4 \
  --enable-decoder=mpeg1video \
  --enable-decoder=mpeg2video \
  --enable-decoder=mpegvideo \
  --enable-decoder=msmpeg4v1 \
  --enable-decoder=msmpeg4v2 \
  --enable-decoder=msmpeg4v3 \
  --enable-decoder=mpeg4 \
  --enable-decoder=pcm_dvd \
  --enable-decoder=pcm_s16be \
  --enable-decoder=pcm_s16le \
  --enable-decoder=pcm_s8 \
  --enable-decoder=pcm_u16be \
  --enable-decoder=pcm_u16le \
  --enable-decoder=pcm_u8 \
  --enable-decoder=theora \
  --enable-decoder=vorbis \
  --enable-decoder=vp3 \
  --enable-decoder=vp8 \
  --disable-parsers \
  --enable-parser=mpegaudio \
  --enable-parser=mpegvideo \
  --enable-parser=mpeg4video \
  --enable-parser=vp3 \
  --enable-parser=vp8 \
  --disable-protocols \
  --enable-protocol=file \
  --disable-devices \
  --disable-vdpau \
  --disable-filters \
  --disable-bsfs # 2>&1 >/dev/null
echo "Building libav"
try make clean # 2>&1 >/dev/null
try make # 2>&1 >/dev/null
try make install # 2>&1 >/dev/null

# Deduplicate shared symbols from libavcodec and libavutil.
#
# Manual instructions follow.
#
# Thanks to
#   http://atnan.com/blog/2012/01/12/avoiding-duplicate-symbol-errors-during-linking-by-removing-classes-from-static-libraries
# which also includes instructions for doing this for fat binaries.
#
# 1. List which .o files are in libavcodec.a and libavutil.a:
#    $ ar -t libavcodec.a > libavcodec.list
#    $ ar -t libavutil.a > libavutil.list
# 2. Find common .o files:
#    $ comm -12 libavcodec.list libavutil.list
# 3. Extract libavcodec.a:
#    $ mkdir libavcodec
#    $ cd libavcodec
#    $ ar -x ../libavcodec.a
# 4. Delete the duplicated .o files, e.g.:
#    $ rm log2_tab.o
#    $ rm utils.o
# 5. Repack the archive:
#    libtool -static *.o -o ../libavcodec.a
#
# Or instead of steps 3-5, just ar -d libavcodec.a log2_tab.o

echo "Deduplicating libav libraries"
try ar -d $DESTROOT/lib/libavcodec.a log2_tab.o

# copy to buildroot
echo "Moving libav build products into place"
try cp $DESTROOT/lib/libavcodec.a $BUILDROOT/lib
try cp $DESTROOT/lib/libavdevice.a $BUILDROOT/lib
try cp $DESTROOT/lib/libavfilter.a $BUILDROOT/lib
try cp $DESTROOT/lib/libavformat.a $BUILDROOT/lib
try cp $DESTROOT/lib/libavutil.a $BUILDROOT/lib
try cp $DESTROOT/lib/libswscale.a $BUILDROOT/lib
try cp $DESTROOT/lib/libavresample.a $BUILDROOT/lib

try rm -rdf $BUILDROOT/include/libavcodec
try cp -a $DESTROOT/include/libavcodec $BUILDROOT/include
try rm -rdf $BUILDROOT/include/libavdevice
try cp -a $DESTROOT/include/libavdevice $BUILDROOT/include
try rm -rdf $BUILDROOT/include/libavfilter
try cp -a $DESTROOT/include/libavfilter $BUILDROOT/include
try rm -rdf $BUILDROOT/include/libavformat
try cp -a $DESTROOT/include/libavformat $BUILDROOT/include
try rm -rdf $BUILDROOT/include/libavutil
try cp -a $DESTROOT/include/libavutil $BUILDROOT/include
try rm -rdf $BUILDROOT/include/libswscale
try cp -a $DESTROOT/include/libswscale $BUILDROOT/include
try rm -rdf $BUILDROOT/include/libavresample
try cp -a $DESTROOT/include/libavresample $BUILDROOT/include


popd
