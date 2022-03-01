# ATOM Babies: M5Stack の ATOM Matrix を使ったかわいいいきもの

<div align="center">
<img src="https://i.gyazo.com/17ba2e562ec676ad2b5e5da635c184e6.jpg" width="480">
</div>

## ATOM Babies とは

ATOM Babies は M5Stack 社の<a href="https://shop.m5stack.com/collections/atom-series/products/atom-matrix-esp32-development-kit">ATOM Matrix</a>を顔とし，<a href="https://shop.m5stack.com/products/atom-mate">ATOM Mate</a>を利用して M5Stick C シリーズで使用する Hat を胴体にしたかわいいいきものです。Hat だけでなく，M5Stack 用に用意されているユニットも使用できるので，それらの機能を活用してさまざまな能力を持つ ATOM Babies をつくることができます。

もともと VSCode + PlatformIO 環境で Arduino プログラミング言語を用いて開発していましたが，UiFlow のカスタムブロック（m5b ファイル）での実装を始めたのをきっかけに公開することにしました。

ちなみに，ATOM Babies の名付け親は M5Stack 社 CEO の Jimmy Lai さんです。

<p align="center">
<img src="https://i.gyazo.com/338db268a5e14a0bea83b9184c8a8043.png" width="480"/>
</p>

## ATOM Babies の実装

UiFlow 版と Arduino 版とがあります。詳細はそれぞれの`README.md`を参照してください。

- [UiFlow 版](uiflow)
- [Arduino 版](arduino)

顔の向きは USB-C の口を下にした向きを基準として以下のように定義しています。

<a href="https://gyazo.com/a210b4d6c098baf76d47a5af3ea772fb"><img src="https://i.gyazo.com/a210b4d6c098baf76d47a5af3ea772fb.png" alt="顔の向き" width="480"/></a>

顔の位置は顔の向きがどの方向でも以下のように定義しています。

<a href="https://gyazo.com/b02a5dcf99ae07560e1e334809e2e069"><img src="https://i.gyazo.com/b02a5dcf99ae07560e1e334809e2e069.png" alt="顔の位置" width="480"/></a>

## ATOM Babies の動作例

<p align="center">
<a href="https://youtu.be/lBxplz1Vmxc"><img src="https://img.youtube.com/vi/lBxplz1Vmxc/0.jpg" width="480"/></a><br>
ATOM Babies:あっちむいてほいで勝てない
</p>

<p align="center">
<a href="https://youtu.be/yEB1nSGFLgU"><img src="https://img.youtube.com/vi/yEB1nSGFLgU/0.jpg" width="480"/></a><br>
ATOM Babies: 自動手指消毒器「テッテ」とロボホンとの連携
</p>

## 参考

- [ATOM Babies](https://youtube.com/playlist?list=PL5yIB9ecl31VxCF3HHRsOgXIgWvoJSiL5)（YouTube チャンネル）
