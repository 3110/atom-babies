# UiFlow 版 ATOM Babies

※Arduino IDE や PlatformIO で実装する場合は[Arduino 版 ATOM Babies](https://github.com/3110/atom-babies-arduino/)を参照してください。

<div align="center">
<img src="https://i.gyazo.com/a451198da7ae3f5bf32a1002d3c13a27.png" alt="ATOM Babies" width="480"/>
</div>

## ATOM Babies とは

ATOM Babies は M5Stack 社の<a href="https://shop.m5stack.com/collections/atom-series/products/atom-matrix-esp32-development-kit">ATOM Matrix</a>を顔とし，<a href="https://shop.m5stack.com/products/atom-mate">ATOM Mate</a>を利用して M5StickC シリーズで使用する Hat を胴体にしたかわいいいきものです。Hat だけでなく，M5Stack 用に用意されているユニットも使用できるので，それらの機能を活用してさまざまな能力を持つ ATOM Babies をつくることができます。

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

[![M5Burnerの画面](https://i.gyazo.com/d3925e4e03ac1245d915d8533861a1fd.png)](https://gyazo.com/d3925e4e03ac1245d915d8533861a1fd)

ATOM Matrix に UiFlow のファームウェアを書き込むため，PC に M5Burner をインストールしてください。M5Burner のインストール方法や ATOM Babies に必要な ATOM Matrix 用の UiFlow ファームウェアの書き込み方については，「[M5Burner v3 の使いかた](https://zenn.dev/saitotetsuya/articles/m5stack_m5burner_v3)」を参照してください。

### ATOM Babies のカスタムブロックを UiFlow に読み込む

UiFlow のカスタムブロックは拡張子が`m5b`のファイルで，[UiFlow Block Maker](http://block-maker.m5stack.com/)や私が作った[UiFlow Custom Block Generator](https://github.com/3110/uiflow-custom-block-generator)で作成することができます。

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

### まばたきをする（`samples/blink.m5f`）

ATOM Babies の顔（ボタン）を押すたびに，まばたきを始めたり止めたりします。まばたきの設定はデフォルト（1 回のまばたき，目を開けている時間が 500 ミリ秒，目を閉じている時間が 100 ミリ秒，次のまばたきを始めるまでの間隔が 1000 ミリ秒）です。

[![samples/blink.m5f](https://i.gyazo.com/9ba20c8272b57e58b4e7d3c503239f06.png)](https://gyazo.com/9ba20c8272b57e58b4e7d3c503239f06)

### おじぎする（`samples/bow.m5f`）

[![samples/bow.m5f](https://i.gyazo.com/2f97b029257fe28b5b12c54dee7ba3e5.png)](https://gyazo.com/2f97b029257fe28b5b12c54dee7ba3e5)

### 数字を表示する（`samples/digits.m5f`）

[![samples/digits.m5f](https://i.gyazo.com/c372aa67a1a02dbc1abfe3a5bd818176.png)](https://gyazo.com/c372aa67a1a02dbc1abfe3a5bd818176)

ATOM Babies の顔（ボタン）を押すたびに 0 から順に数字が表示されます。2 桁以上の数字は各桁を順に表示します。

### 人が来たらあいさつする（`samples/greeting.m5f`）

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

[![samples/greeting.m5f](https://i.gyazo.com/222a273c32f6ba00ed579ac12638610b.png)](https://gyazo.com/222a273c32f6ba00ed579ac12638610b)

### 温度・湿度・気圧を表示する（`samples/env.m5f`）

<p align="center">
<a href="https://youtu.be/N_ciU3XL7x8"><img src="https://img.youtube.com/vi/N_ciU3XL7x8/0.jpg" width="480"/></a><br>
ATOM Babies: 温度・湿度・気圧を表示する（YouTube）
</p>

ATOM Babies の顔（ボタン）を押すと，気温・湿度・気圧がそれぞれ赤色・青色・白色の数値でスクロールして連続表示されます。

<p align="center">
<a href="https://gyazo.com/db8d656a80df7c2210d59da4e51a49e2"><img src="https://i.gyazo.com/db8d656a80df7c2210d59da4e51a49e2.jpg" alt="Image from Gyazo" width="480"/></a><br>
ATOM MatrixにATOM MateとENV III Hatを接続
</p>

[ATOM Mate](https://shop.m5stack.com/products/atom-mate)を使用して[ENV III Hat](https://shop.m5stack.com/products/m5stickc-env-hat-iii-sht30-qmp6988)を接続して利用します。USB-C の口を上にした状態が正しい向きになります。

ENV III Hat は本体の温度に影響を受けるため，補正値（`temperature_correction`）を引いて調整してください。

[![samples/env.m5f](https://i.gyazo.com/e7a70289ae78f8174c37e49907c2c167.png)](https://gyazo.com/e7a70289ae78f8174c37e49907c2c167)

## 付録：UiFlow Custom Block Generator の使い方

`pip`で UiFlow Custom Block Generator をインストールします。

```bash
pip install git+https://github.com/3110/uiflow-custom-block-generator
```

UiFlow Custom Generator を実行します。以下を実行するとカレントディレクトリに`atom_babies_ja.m5b`が生成されます。

```bash
python -m uiflow_custom_block_generator atom_babies/atom_babies_ja.json -t .
```

## 参考

- [ATOM Babies](https://youtube.com/playlist?list=PL5yIB9ecl31VxCF3HHRsOgXIgWvoJSiL5)（YouTube チャンネル）
- [UiFlow](https://flow.m5stack.com/)
- [UiFlow Block Maker](http://block-maker.m5stack.com/)
- [UiFlow Custom Block Generator](https://github.com/3110/uiflow-custom-block-generator)
