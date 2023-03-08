# key_LineNotice v1.1
M5Stackを使用して鍵の閉め忘れをLINEで通知するシステムです。

## what you need
* M5Stack or M5StickC Plus
* 磁気ドアスイッチx2
* LED
* [LINE Notify](https://notify-bot.line.me/ja/)のToken

## How to use
M5Stackでは"[stack_key.ino](https://github.com/11104/key_LineNotice/stack_key)"、M5StickC Plusでは"[stick_key.ino](https://github.com/11104/key_LineNotice/stick_key)"を使用します。

key_LineNotice.inoの5,6,8行目にwifiのIDとPassword、発行したLINE Notify tokenを入力して、M5Stackに書き込んで下さい。
13行目ではドアを閉じてから何秒後に通知を送るのかを変更できます。(デフォルトでは30秒)

M5Stackの16番pinに鍵用の磁気スイッチ、2番pinに鍵用の磁気スイッチ、5番pinにLEDを接続してください。
LINETokenの発行方法など少し詳しく書きましたので、下記の記事を参考にしてください。

解説記事-> "[【M5Stack】鍵の閉め忘れをLINEに通知するシステム](https://qiita.com/nih/items/6135769d6572f07a5789)"