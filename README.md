# YaNotes
Yet Another Notes - information manager and storage system


## Motivation:
- [MyTetra](https://github.com/xintrea/mytetra_dev) is a great tool for store and manage information. Also it have some issues, like a large amount of legacy code, mixed language comments and no mobile client (well, you can build MyTetra for Andoid, but it will be unusable due to UI issues and sync via git will not work on non-rooted devices).
- [QOwnNotes](https://gitgub.com/pbek/QOwnNotes) - perfect editor for markdown. While some issues with mobile build and git too.  

### Main goals:
 - usage of C++11/Qt 5.9 as a basis;
 - English only doc\comments in code;
 - QtQuick\QML UI for mobile devices additionally to QtWidget for desktops;
 - sync on mobile devices;
 - simplified UI;
 - database in MD format - to use directly from GitHub/GitLab;
 - tablet\phone UI;

### Prototype
 - QOwnNotes can be used as a main MD tool;
 - [HoeDown](https://github.com/hoedown/hoedown) can be used as MD parsed
 - [QMarkDownTextEdit](https://github.com/pbek/qmarkdowntextedit) can be used as MD editor
 - **QTextBrowser** can be used to view MD in HTML format for QtWidget/Desktop
 - **QtQuick.Text** can be used to view MD in HTML format for QtQuick/Mobile;

### Repository
repo use git-submodules, so
`git clone --recurse-submodules git@github.com:ayaromenok/YaNotes.git`