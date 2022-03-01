# Arduino 版 ATOM Babies

## 動作環境

[PlatformIO](https://platformio.org/)環境に対応しています。動作確認は Windows 11 上で [PlatformIO IDE for VSCode](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) を使用して実施しています。

VS Code からコンパイル・ファームウェアの書き込みをする場合は，Switch PlatformIO Project Environment で環境（`env:atom-babies-all-faces`，`env:atom-babies-blink`，`env:atom-babies-bow`）を 1 つ選択し，PlatformIO:Upload ボタンを押します。

PlatformIO のターミナルからコンパイル・ファームウェアの書き込みをする場合は以下を実行します。

```bash
git clone https://github.com/3110/atom-babies
cd atom-babies
platformio run -e atom-babies-all-faces --target=upload # 例：all-faces の場合
platformio run -e atom-babies-blink --target=upload     # 例：blink の場合
platformio run -e atom-babies-bow --target=upload       # 例：bow の場合
```

## 実装方法

通常の顔の向きで顔を表示するための最低限の実装は以下のようになります。
`M5.begin()`と`M5.update()`はそれぞれ`babies.begin()`と`babies.update()`の中で呼んでいるので，改めて呼ぶ必要はありません。

```c++
#include "AtomBabies.h"

using namespace M5Stack_AtomBabies;

AtomBabies babies;

void setup(void) {
    babies.begin();
    babies.setFace(FaceNormal);
}

void loop(void) {
    babies.update();
}
```

## サンプルの説明

### `examples/bow`

PlatformIO で環境`atom-babies-bow`を選択します。

ATOM Babies の顔（ボタン）を押すとおじぎをします。押すごとにおじぎをする回数が増えます。

### `examples/greeting`

PlatformIO で環境`atom-babies-greeting`を選択します。

<p align="center">
<a href="https://youtu.be/hI7jYVK7nX0"><img src="https://img.youtube.com/vi/hI7jYVK7nX0/0.jpg" width="480"/></a><br>
ATOM Babies:人が来るとあいさつをする（YouTube）
</p>

人が目の前に来ると顔を出しておじぎをします。

<p align="center">
<a href="https://i.gyazo.com/4491f8348d1d45264d212cc0f971b629.jpg"><img src="https://i.gyazo.com/4491f8348d1d45264d212cc0f971b629.jpg" width="480"/></a><br>
ATOM MatrixにATOM MateとPIR Hatを接続
</p>

[ATOM Mate](https://shop.m5stack.com/products/atom-mate)を使用して[PIR Hat](https://shop.m5stack.com/products/m5stickccompatible-hat-pir-sensor)を接続して利用します。
PIR Hat が胴体となるため，顔の向きは`OrientationUpsideDown`にします。

PIR は Passive pyroelectric infrared detector（受動焦電型赤外線検出器）の略で，人間が発する赤外線を検知し，目の前にいるかを判断します。
PIR Hat の仕様で，いったん検知した後，次に検知するまでに 2 秒間の遅れがあります。

### `examples/blink`

PlatformIO で環境`atom-babies-blink`を選択します。

ATOM Babies の顔（ボタン）を押すたびに，まばたきを始めたり止めたりします。
まばたきの設定はデフォルト（`AtomBabies.cpp`の`DEFAULT_BLINK_PARAM`を参照，2 回以下のランダムな回数でのまばたき，目を開けている時間が 500 ミリ秒，目を閉じている時間が 100 ミリ秒，次のまばたきを始めるまでの間隔が 1000 ミリ秒）です。

### `examples/all-faces`

PlatformIO で環境`atom-babies-all-faces`を選択します。

ATOM Babies の顔の表示を一通り表示します。通常の向きから開始し，まばたきをした状態で始まります。ATOM Babies の顔（ボタン）を押すごとに右 → 逆さま → 左 → 通常と繰り返します。

## 参考

- [Visual Studio Code](https://azure.microsoft.com/ja-jp/products/visual-studio-code/)
- [PlatformIO](https://platformio.org/)
- [PlatformIO IDE for VSCode](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
- [Arduino IDE](https://www.arduino.cc/en/software)
