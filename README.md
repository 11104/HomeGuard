# 自宅警備員 Homeguard v1.1.2
M5Stackを使用して鍵の閉め忘れをLINEで通知するシステムです。

## what you need
* M5Stack or M5StickC Plus
* 磁気ドアスイッチx2
* LED
* [LINE Notify](https://notify-bot.line.me/ja/)のToken

## How to use
M5Stackでは"[stack_homeguard.ino](https://github.com/11104/key_LineNotice/blob/main/stack_homeguard/stack_homeguard.ino)"、M5StickC Plusでは"[stick_homeguard.ino](https://github.com/11104/key_LineNotice/blob/main/stick_homeguard/stick_homeguard.ino)"を使用します。

key_LineNotice.inoの5,6,8行目にwifiのIDとPassword、発行したLINE Notify tokenを入力して、M5Stackに書き込んで下さい。
13行目ではドアを閉じてから何秒後に通知を送るのかを変更できます。(デフォルトでは30秒)

M5Stackの16番pinに鍵用の磁気スイッチ、2番pinに鍵用の磁気スイッチ、5番pinにLEDを接続してください。
LINETokenの発行方法など少し詳しく書きましたので、下記の記事を参考にしてください。

解説記事-> "[【M5Stack】鍵の閉め忘れをLINEに通知するシステム](https://qiita.com/nih/items/6135769d6572f07a5789)"

## Attention
- M5StickCでは書き込み時にGND接続を外して下さい。
- M5Stickは、M5StackとLEDの電圧設定が逆です。

## Version history
- v1.0.0 - 23/2/25 release for M5Stack
- v1.1.0 - 23/3/8 release for M5StickC
- v1.1.1 - 23/3/9 Fix LED bug and add attention
- v1.1.2 - 23/3/13 Offical name decision