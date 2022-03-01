# UiFlow 版 ATOM Babies

※現在開発中なので，しばらくはブロックの仕様がころころ変わると思います。つくったプログラムが開けなくなることもありますので，あらかじめご了承ください。

## 実装方法

[![UiFlowでの開発の様子](https://i.gyazo.com/f278afebd08736265ef63bd5ca6bfb16.png)](https://gyazo.com/f278afebd08736265ef63bd5ca6bfb16)

ATOM Babies は M5Stack 社が M5Stack シリーズ向けに提供しているブロックプログラミング環境である[UiFlow](https://flow.m5stack.com/)（[https://flow.m5stack.com/](https://flow.m5stack.com/)）を使って実装しています。ATOM Babies 用のカスタムブロックを使用することで，誰でも簡単に ATOM Babies をつくることができます。

UiFlow を使用するには，PC に M5Burner をインストールし，M5Burner を使って PC に接続した ATOM Matrix に UiFlow 用のファームウェアを書き込む必要があります。

### M5Burner のインストールと UiFlow ファームウェアの書き込み

ATOM Matrix に UiFlow のファームウェアを書き込むため，PC に M5Burner をインストールしてください。インストール方法やファームウェアの書き込み方については，「[M5Burner の使いかた](https://zenn.dev/saitotetsuya/articles/m5stack_m5burner)」を参照してください。

[![M5Burnerの画面](https://i.gyazo.com/502735c631de220e7fcac8b5088df9a9.png)](https://gyazo.com/502735c631de220e7fcac8b5088df9a9)

ATOM Babies に必要な ATOM Matrix 用の UiFlow ファームウェアは，M5Burner の画面左で ATOM を選択し，「UIFLOW(MATRIX)」にある「Download」ボタンを押すとダウンロードできます。

これ以降の手順は「[M5Burner の使いかた](https://zenn.dev/saitotetsuya/articles/m5stack_m5burner)」の「[8.2 ファームウェアのダウンロード](https://zenn.dev/saitotetsuya/articles/m5stack_m5burner#8.2-%E3%83%95%E3%82%A1%E3%83%BC%E3%83%A0%E3%82%A6%E3%82%A7%E3%82%A2%E3%81%AE%E3%83%80%E3%82%A6%E3%83%B3%E3%83%AD%E3%83%BC%E3%83%89)」を参照してください。

### ATOM Babies のカスタムブロックを UiFlow に読み込む

[![Customメニュー](https://i.gyazo.com/34bd1e3d9296cb60d0fe6e959e13490e.png)](https://gyazo.com/34bd1e3d9296cb60d0fe6e959e13490e)

カスタムメニューを選択し，「Open \*.m5b file」を押し，`uiflow/atom_babies_ja.m5b`を選択して読み込みます。

[![ATOM_Babiesメニュー](https://i.gyazo.com/d4cb5540307740aca6e03f29572a0bc8.png)](https://gyazo.com/d4cb5540307740aca6e03f29572a0bc8)

カスタムメニューの下に「ATOM_Babies」メニューが追加され，ATOM Babies を実装するのに使用するブロックが表示されます。

ATOM Babies のカスタムブロックを使って作ったプログラム（m5f ファイル）を読み込むときは，あらかじめ ATOM Babies のカスタムブロックを読み込ませておく必要があります。

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

- [UiFlow](https://flow.m5stack.com/)
- [UiFlow Block Maker](http://block-maker.m5stack.com/)（ベータ版）
- [M5Burner の使いかた](https://zenn.dev/saitotetsuya/articles/m5stack_m5burner)
