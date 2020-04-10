# GetCurrentMusic

此程序用于获取UWP程序当前的音乐播放信息

相关接口获取于twinui.dll的CTransportControlsManager类

## 项目

GetCurrentMusic - C++编写的DLL动态链接库

GetCurrentMusicGUI - C#编写的界面，运行时需要GetCurrentMusic.dll，因为我要用在OBS直播上所以背景是原谅色

Test - 测试用控制台项目，运行时需要GetCurrentMusic.dll

## 注意

我无法在我的64位系统上以32位模式（Wow64）成功运行这个程序，在执行到获取INowPlayingSession接口时会直接出错，即使我调用的是正确的函数，我个人猜测是程序必须要与系统统一版本才可正常获取接口，请大家编译时注意

## 展示图

![QQ截图20200410201651](https://user-images.githubusercontent.com/20377926/78990181-620c2600-7b68-11ea-8c7a-4faa6f6ea771.png)

因为不会写OBS插件所以用的窗口程序
