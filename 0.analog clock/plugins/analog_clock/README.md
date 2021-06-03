# QML用 analog_clock プラグイン

---

本プラグインはQMLでアナログ時計を扱うためのAnalogClockエレメントを提供するプラグインである。

## インストール方法

---

```term
mkdir ./build
cd ./build
cmake -DCMAKE_INSTALL_PREFIX="path/to/plugin/directory" -DCMAKE_BUILD_TYPE=Release
ninja -j8
ninja install
```

[注意]

上記"path/to/plugin/directory"の内容は

プラグインのインストール先であり一般的には

"QTのインストール先/QTのバージョン番号/ビルドキット名/qml"となる

>  (例) cmake .. -DCMAKE_INSTALL_PREFIX="C:\Qt\5.15.2\mingw81_64\qml"

