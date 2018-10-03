HEADERS += \
    $$PWD/share.h
SOURCES += 

#3rdparty
include(../3rdparty/qmarkdowntextedit/qmarkdowntextedit.pri)
include(../3rdparty/hoedown.pri)

linux:!android {
    message("* Using settings for Unix/Linux.")
    contains(QMAKE_HOST.arch, x86_64){
        message("        arch: amd64")
    }
    contains(QMAKE_HOST.arch, x86){
        message("        arch: i386")
    }
}

android {
    message("* Using settings for Android.")
    contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
        message("        arch: armeabi-v7a")
        #LIBS += -lsome_lib
       #ANDROID_EXTRA_LIBS = \
       #    $${SOMEPATh}/libs/armeabi-v7a/libsomelib.so
    }
    contains(ANDROID_TARGET_ARCH,arm64-v8a) {
        message("        arch: arm64-v8a")
    }
    contains(ANDROID_TARGET_ARCH,x86) {
        message("        arch: x86")
    }
    contains(ANDROID_TARGET_ARCH,x86_84) {
        message("        arch: x86_64")
    }
}

ios {
    #LIBS += -F$${IOSPATH}
    #LIBS += -framework someframevork
    simulator {
        message("* OpenCV settings for iOS Simulator")
    }
    device{
        message("* OpenCV settings for iOS")
    }
}

macx{
    message("* Using settings for Mac OS X.")
    contains(QMAKE_HOST.arch, x86_64){
        message("        arch: amd64")
    }
    contains(QMAKE_HOST.arch, x86){
        message("        arch: i386")
    }    
}

win32{
    message("* Using settings for Windows.")
    contains(QMAKE_TARGET.arch, x86_64){
        message("        arch: amd64")
        win32-msvc* {
            MSVC_VER = $$(VisualStudioVersion)
            equals(MSVC_VER, 12.0){
                message("           msvc12 - 2013")
            }
            equals(MSVC_VER, 13.0){
                message("           msvc13 - 2014")
            }
            equals(MSVC_VER, 14.0){
                message("           msvc14 - 2015")
            }
            equals(MSVC_VER, 15.0){
                message("           msvc15 - 2017")
            }
        }
    }
    contains(QMAKE_TARGET.arch, x86){
        message("        arch: i386")
        win32-g++ {
            message("               compiler: mingw-32")
        }
    }
}
