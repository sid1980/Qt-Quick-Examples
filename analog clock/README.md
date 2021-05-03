# analog clock

---

当プロジェクトはアナログ時計を表示するGUIアプリケーションのサンプルである。

| プロジェクト名 |     備考     |                   gifアニメ                   |
| :------------: | :----------: | :-------------------------------------------: |
|  analog clock  | アナログ時計 | <img src="../img/analog_ckock.gif" width=50%> |



# フォルダ構造

---

```cmd
analog clock
│  CMakeLists.txt #cmakeスクリプト
│  README.md #readme
│
├─img
│  │  img.qrc #画像用のリソースファイル
│  │
│  └─clock_img
│          base.svg #文字盤の画像
│          centor.svg #針の軸の画像
│          hour.svg #時針の画像
│          minute.svg #分針の画像 
│          second.svg #秒針の画像
│
├─include
│      clock_backend.hpp #時計エレメントのバックエンド処理(C++)用のヘッダファイル
│
├─qml
│      Clock.qml #アナログ時計エレメントの記されたqmlファイル
│      main.qml #基底ウィンドウの記されたqmlファイル
│      qml.qrc #qmlファイル用のリソースファイル
│
└─src
        clock_backend.cpp #時計エレメントのバックエンド処理(C++)用の実装ファイル
        main.cpp #エントリーポイントファイル
```

# ビルドと実行

---

```cmd or terminal
mkdir build
cd ./build
cmake ..
make run
```

#  登場するクラスやqmlエレメント

---

- clock_component::ClockBackend クラス (clock_backend.hppとclock_backend.cpp)
  - int get_hour() const メソッド
    - 時間を整数で出力
  - int get_minute() const メソッド
    - 分を整数で出力
  - int get_second() const メソッド
    - 秒を整数で出力

- Clockエレメント(Clock.qml)
  - アナログ時計を表示するエレメントであり、内部にTimerエレメントを保持し、100msに一回上記バックエンドc++クラスより現在時刻を取得し、画面に反映する。
