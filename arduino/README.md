# Arduino 版 ATOM BAbies

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

## サンプルの説明

### `examples/bow`

PlatformIO で環境`env:atom-babies-bow`を選択してコンパイルします。

ATOM Babies の顔（ボタン）を押すとおじぎをします。押すごとにおじぎをする回数が増えます。

### `examples/all-faces`

PlatformIO で環境`env:atom-babies-all-faces`を選択してコンパイルします。

ATOM Babies の顔の表示を一通り表示します。通常の向きから開始し，まばたきをした状態で始まります。ATOM Babies の顔（ボタン）を押すごとに右 → 逆さま → 左 → 通常と繰り返します。

## 参考

- [Visual Studio Code](https://azure.microsoft.com/ja-jp/products/visual-studio-code/)
- [PlatformIO](https://platformio.org/)
- [PlatformIO IDE for VSCode](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
- [Arudino IDE](https://www.arduino.cc/en/software)
