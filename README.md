# ATOM Babies: M5StackのATOM Matrixを使ったかわいいいきもの

※現在開発中なので，しばらくはブロックの仕様がころころ変わると思います。つくったプログラムが開けなくなることもありますので，あらかじめご了承ください。

<div align="center">
<img src="https://i.gyazo.com/17ba2e562ec676ad2b5e5da635c184e6.jpg" width="480">
</div>

## ATOM Babiesとは

ATOM BabiesはM5Stack社の<a href="https://shop.m5stack.com/collections/atom-series/products/atom-matrix-esp32-development-kit">ATOM  Matrix</a>を顔とし，<a href="https://shop.m5stack.com/products/atom-mate">ATOM Mate</a>を利用してM5Stick Cシリーズで使用するHatを胴体にしたかわいいいきものです。Hatだけでなく，M5Stack用に用意されているユニットも使用できるので，それらの機能を活用してさまざまな能力を持つATOM Babiesをつくることができます。

もともとVSCode + PlatformIO環境でArduinoプログラミング言語を用いて開発していましたが，UiFlowのカスタムブロック（m5bファイル）での実装を始めたのをきっかけに公開することにしました。

ちなみに，ATOM Babiesの名付け親はM5Stack社CEOのJimmy Laiさんです。

<p align="center">
<img src="https://i.gyazo.com/338db268a5e14a0bea83b9184c8a8043.png" width="480"/>
</p>

## ATOM Babiesの動作例

<p align="center">
<a href="https://youtu.be/lBxplz1Vmxc"><img src="https://img.youtube.com/vi/lBxplz1Vmxc/0.jpg" width="480"/></a><br>
ATOM Babies:あっちむいてほいで勝てない
</p>

<p align="center">
<a href="https://youtu.be/yEB1nSGFLgU"><img src="https://img.youtube.com/vi/yEB1nSGFLgU/0.jpg" width="480"/></a><br>
ATOM Babies: 自動手指消毒器「テッテ」とロボホンとの連携
</p>

## UiFlowでの実装方法

[![UiFlowでの開発の様子](https://i.gyazo.com/f278afebd08736265ef63bd5ca6bfb16.png)](https://gyazo.com/f278afebd08736265ef63bd5ca6bfb16)

ATOM BabiesはM5Stack社がM5Stackシリーズ向けに提供しているブロックプログラミング環境である[UiFlow](https://flow.m5stack.com/)（[https://flow.m5stack.com/](https://flow.m5stack.com/)）を使って実装しています。ATOM Babies用のカスタムブロックを使用することで，誰でも簡単にATOM Babiesをつくることができます。

UiFlowを使用するには，PCにM5Burnerをインストールし，M5Burnerを使ってPCに接続したATOM MatrixにUiFlow用のファームウェアを書き込む必要があります。

### M5BurnerのインストールとUiFlowファームウェアの書き込み

ATOM MatrixにUiFlowのファームウェアを書き込むため，PCにM5Burnerをインストールしてください。インストール方法やファームウェアの書き込み方については，「[M5Burnerの使いかた](https://zenn.dev/saitotetsuya/articles/m5stack_m5burner)」を参照してください。

[![M5Burnerの画面](https://i.gyazo.com/502735c631de220e7fcac8b5088df9a9.png)](https://gyazo.com/502735c631de220e7fcac8b5088df9a9)

ATOM Babiesに必要なATOM Matrix用のUiFlowファームウェアは，M5Burnerの画面左でATOMを選択し，「UIFLOW(MATRIX)」にある「Download」ボタンを押すとダウンロードできます。

これ以降の手順は「[M5Burnerの使いかた](https://zenn.dev/saitotetsuya/articles/m5stack_m5burner)」の「[8.2 ファームウェアのダウンロード](https://zenn.dev/saitotetsuya/articles/m5stack_m5burner#8.2-%E3%83%95%E3%82%A1%E3%83%BC%E3%83%A0%E3%82%A6%E3%82%A7%E3%82%A2%E3%81%AE%E3%83%80%E3%82%A6%E3%83%B3%E3%83%AD%E3%83%BC%E3%83%89)」を参照してください。

### ATOM BabiesのカスタムブロックをUiFlowに読み込む

[![Customメニュー](https://i.gyazo.com/34bd1e3d9296cb60d0fe6e959e13490e.png)](https://gyazo.com/34bd1e3d9296cb60d0fe6e959e13490e)

カスタムメニューを選択し，「Open *.m5b file」を押し，`atom_babies_ja.m5b`を選択して読み込みます。

[![ATOM_Babiesメニュー](https://i.gyazo.com/d4cb5540307740aca6e03f29572a0bc8.png)](https://gyazo.com/d4cb5540307740aca6e03f29572a0bc8)

カスタムメニューの下に「ATOM_Babies」メニューが追加され，ATOM Babiesを実装するのに使用するブロックが表示されます。

ATOM Babiesのカスタムブロックを使って作ったプログラム（m5fファイル）を読み込むときは，あらかじめATOM Babiesのカスタムブロックを読み込ませておく必要があります。

## サンプルの説明

### `samples/bow.m5f`

[![bow.m5f](https://i.gyazo.com/51115ebf0233275e3ced754b50e8eebb.png)](https://gyazo.com/51115ebf0233275e3ced754b50e8eebb)

ATOM Matrixの画面を押すと，押すごとにおじぎをする回数が増えます。

### `samples/greeting.m5f`

<p align="center">
<a href="https://youtu.be/hI7jYVK7nX0"><img src="https://img.youtube.com/vi/hI7jYVK7nX0/0.jpg" width="480"/></a><br>
ATOM Babies:人が来るとあいさつをする
</p>

ヒトが目の前に来ると顔を出しておじぎをします。

<p align="center">
<a href="https://i.gyazo.com/4491f8348d1d45264d212cc0f971b629.jpg"><img src="https://i.gyazo.com/4491f8348d1d45264d212cc0f971b629.jpg" width="480"/></a><br>

[ATOM Mate](https://shop.m5stack.com/products/atom-mate)を使用して[PIR Hat](https://shop.m5stack.com/products/m5stickccompatible-hat-pir-sensor)を接続して利用します。USB-Cの口を上にした状態が正しい向きになります。

PIRはPassive pyroelectric infrared detector（受動焦電型赤外線検出器）の略で，ヒトが発する赤外線を検知し，前にヒトがいるかを判断します。PIR Hatの仕様で，いったん検知した後，次に検知するまでに2秒間の遅れがあります。

[![greetnig.m5b](https://i.gyazo.com/a1bf42998acf3b3b3bdb82d4d4d77913.png)](https://gyazo.com/a1bf42998acf3b3b3bdb82d4d4d77913)

## 参考

* [ATOM Babies](https://youtube.com/playlist?list=PL5yIB9ecl31VxCF3HHRsOgXIgWvoJSiL5)（YouTubeチャンネル）
* [UiFlow](https://flow.m5stack.com/)
* [UiFlow Block Maker](http://block-maker.m5stack.com/)（ベータ版）
* [M5Burnerの使いかた](https://zenn.dev/saitotetsuya/articles/m5stack_m5burner)
