# UiFlow 版 ATOM Babies

※Arduino IDE や PlatformIO で実装する場合は[Arduino 版 ATOM Babies](https://github.com/3110/atom-babies-arduino/)を参照してください。

<div align="center">
<img src="https://i.gyazo.com/e46dc64eac0adfe1591c9fb7c9dc737b.jpg" width="480"/>
</div>

## ATOM Babies とは

ATOM Babies は M5Stack 社の<a href="https://shop.m5stack.com/collections/atom-series/products/atom-matrix-esp32-development-kit">ATOM Matrix</a>を顔とし，<a href="https://shop.m5stack.com/products/atom-mate">ATOM Mate</a>を利用して M5Stick C シリーズで使用する Hat を胴体にしたかわいいいきものです。Hat だけでなく，M5Stack 用に用意されているユニットも使用できるので，それらの機能を活用してさまざまな能力を持つ ATOM Babies をつくることができます。

ちなみに，ATOM Babies の名付け親は M5Stack 社 CEO の Jimmy Lai さんです。

<p align="center">
<img src="https://i.gyazo.com/338db268a5e14a0bea83b9184c8a8043.png" width="480"/>
</p>

## 実装方法

※現在開発中なので，しばらくはブロックの仕様がころころ変わると思います。つくったプログラムが開けなくなることもありますので，あらかじめご了承ください。

[![UiFlowでの開発の様子](https://i.gyazo.com/f278afebd08736265ef63bd5ca6bfb16.png)](https://gyazo.com/f278afebd08736265ef63bd5ca6bfb16)

ATOM Babies は M5Stack 社が M5Stack シリーズ向けに提供しているブロックプログラミング環境である[UiFlow](https://flow.m5stack.com/)を使って実装しています。ATOM Babies 用のカスタムブロックを使用することで，誰でも簡単に ATOM Babies をつくることができます。

UiFlow を使用するには，PC に M5Burner をインストールし，M5Burner を使って PC に接続した ATOM Matrix に UiFlow 用のファームウェアを書き込む必要があります。

### M5Burner のインストールと UiFlow ファームウェアの書き込み

ATOM Matrix に UiFlow のファームウェアを書き込むため，PC に M5Burner をインストールしてください。インストール方法やファームウェアの書き込み方については，「[M5Burner の使いかた](https://zenn.dev/saitotetsuya/articles/m5stack_m5burner)」を参照してください。

[![M5Burnerの画面](https://i.gyazo.com/502735c631de220e7fcac8b5088df9a9.png)](https://gyazo.com/502735c631de220e7fcac8b5088df9a9)

ATOM Babies に必要な ATOM Matrix 用の UiFlow ファームウェアは，M5Burner の画面左で ATOM を選択し，「UIFLOW(MATRIX)」にある「Download」ボタンを押すとダウンロードできます。

これ以降の手順は「[M5Burner の使いかた](https://zenn.dev/saitotetsuya/articles/m5stack_m5burner)」の「[8.2 ファームウェアのダウンロード](https://zenn.dev/saitotetsuya/articles/m5stack_m5burner#8.2-%E3%83%95%E3%82%A1%E3%83%BC%E3%83%A0%E3%82%A6%E3%82%A7%E3%82%A2%E3%81%AE%E3%83%80%E3%82%A6%E3%83%B3%E3%83%AD%E3%83%BC%E3%83%89)」を参照してください。

### ATOM Babies のカスタムブロックを UiFlow に読み込む

UiFlow のカスタムブロックは拡張子が`m5b`のファイルで，[UiFlow Block Maker](http://block-maker.m5stack.com/)で作成することができます。

[![Customメニュー](https://i.gyazo.com/34bd1e3d9296cb60d0fe6e959e13490e.png)](https://gyazo.com/34bd1e3d9296cb60d0fe6e959e13490e)

カスタムメニューを選択し，「Open \*.m5b file」を押し，`atom_babies_ja.m5b`を選択して読み込みます。

[![ATOM_Babiesメニュー](https://i.gyazo.com/d4cb5540307740aca6e03f29572a0bc8.png)](https://gyazo.com/d4cb5540307740aca6e03f29572a0bc8)

カスタムメニューの下に「ATOM_Babies」メニューが追加され，ATOM Babies を実装するのに使用するブロックが表示されます。

ATOM Babies のカスタムブロックを使って作ったプログラム（m5f ファイル）を読み込むときは，あらかじめ ATOM Babies のカスタムブロックを読み込ませておく必要があります。

### 顔の向き・位置について

顔の向きは USB-C の口を下にした向きを基準として以下のように定義しています。

<a href="https://gyazo.com/a210b4d6c098baf76d47a5af3ea772fb"><img src="https://i.gyazo.com/a210b4d6c098baf76d47a5af3ea772fb.png" alt="顔の向き" width="480"/></a>

顔の位置は顔の向きがどの方向でも以下のように定義しています。

<a href="https://gyazo.com/b02a5dcf99ae07560e1e334809e2e069"><img src="https://i.gyazo.com/b02a5dcf99ae07560e1e334809e2e069.png" alt="顔の位置" width="480"/></a>

## サンプルの説明

### `samples/bow.m5f`

[![samples/bow.m5f](https://i.gyazo.com/51115ebf0233275e3ced754b50e8eebb.png)](https://gyazo.com/51115ebf0233275e3ced754b50e8eebb)

ATOM Babies の顔（ボタン）を押すとおじぎをします。押すごとにおじぎをする回数が増えます。

### `samples/greeting.m5f`

<p align="center">
<a href="https://youtu.be/hI7jYVK7nX0"><img src="https://img.youtube.com/vi/hI7jYVK7nX0/0.jpg" width="480"/></a><br>
ATOM Babies:人が来るとあいさつをする（YouTube）
</p>

人が目の前に来ると顔を出しておじぎをします。

<p align="center">
<a href="https://i.gyazo.com/4491f8348d1d45264d212cc0f971b629.jpg"><img src="https://i.gyazo.com/4491f8348d1d45264d212cc0f971b629.jpg" width="480"/></a><br>
ATOM MatrixにATOM MateとPIR Hatを接続
</p>

[ATOM Mate](https://shop.m5stack.com/products/atom-mate)を使用して[PIR Hat](https://shop.m5stack.com/products/m5stickccompatible-hat-pir-sensor)を接続して利用します。USB-C の口を上にした状態が正しい向きになります。

PIR は Passive pyroelectric infrared detector（受動焦電型赤外線検出器）の略で，人間が発する赤外線を検知し，目の前にいるかを判断します。
PIR Hat の仕様で，いったん検知した後，次に検知するまでに 2 秒間の遅れがあります。

[![samples/greetnig.m5b](https://i.gyazo.com/a1bf42998acf3b3b3bdb82d4d4d77913.png)](https://gyazo.com/a1bf42998acf3b3b3bdb82d4d4d77913)

### `samples/blink.m5f`

ATOM Babies の顔（ボタン）を押すたびに，まばたきを始めたり止めたりします。まばたきの設定はデフォルト（1 回のまばたき，目を開けている時間が 500 ミリ秒，目を閉じている時間が 100 ミリ秒，次のまばたきを始めるまでの間隔が 1000 ミリ秒）です。

[![samples/blink.m5f](https://i.gyazo.com/164b711efc9d2a0e0296c6bdf9694a44.png)](https://gyazo.com/164b711efc9d2a0e0296c6bdf9694a44)

## 参考

- [ATOM Babies](https://youtube.com/playlist?list=PL5yIB9ecl31VxCF3HHRsOgXIgWvoJSiL5)（YouTube チャンネル）
- [UiFlow](https://flow.m5stack.com/)
- [UiFlow Block Maker](http://block-maker.m5stack.com/)
