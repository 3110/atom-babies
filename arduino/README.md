# Arduino 版 ATOM Babies

## 動作環境

[PlatformIO](https://platformio.org/)環境に対応しています。動作確認は Windows 11 上で [PlatformIO IDE for VSCode](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) を使用して実施しています。

VS Code からコンパイル・ファームウェアの書き込みをする場合は，Switch PlatformIO Project Environment で環境（今のところ`atom-babies-all-faces`，`atom-babies-bow`の 2 つ）を選択し，PlatformIO:Upload ボタンを押します。

PlatformIO のターミナルからコンパイル・ファームウェアの書き込みをする場合は以下を実行します。

```bash
git clone https://github.com/3110/atom-babies
cd atom-babies
platformio run -e atom-babies-all-faces --target=upload
もしくは
platformio run -e atom-babies-bow --target=upload
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

PlatformIO で環境`atom-babies-bow`を選択してコンパイルします。

ATOM Babies の顔（ボタン）を押すとおじぎをします。押すごとにおじぎをする回数が増えます。

## `examples/blink`

PlatformIO で環境`atom-babies-blink`を選択してコンパイルします。

ATOM Babies の顔（ボタン）を押すたびに，まばたきを始めたり止めたりします。
まばたきの設定はデフォルト（`AtomBabies.cpp`の`DEFAULT_BLINK_PARAM`を参照，2 回以下のランダムな回数でのまばたき，目を開けている時間が 500 ミリ秒，目を閉じている時間が 100 ミリ秒，次のまばたきを始めるまでの間隔が 1000 ミリ秒）です。

### `examples/all-faces`

PlatformIO で環境`atom-babies-all-faces`を選択してコンパイルします。

ATOM Babies の顔の表示を一通り表示します。通常の向きから開始し，まばたきをした状態で始まります。ATOM Babies の顔（ボタン）を押すごとに右 → 逆さま → 左 → 通常と繰り返します。

## 参考

- [Visual Studio Code](https://azure.microsoft.com/ja-jp/products/visual-studio-code/)
- [PlatformIO](https://platformio.org/)
- [PlatformIO IDE for VSCode](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
- [Arudino IDE](https://www.arduino.cc/en/software)
