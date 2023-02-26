# key_LineNotice
M5Stackを使用して鍵の閉め忘れをLINEに通知してくれるシステムです。

## what you need to use it
* M5Stack
* 磁気ドアスイッチx2
* LED
* [LINE NotifyのToken](https://notify-bot.line.me/ja/)

## How to use
key_LineNotice.inoの5,6,8行目にwifiのIDとPassword、発行したLINEtokenを入力して、M5Stackに書き込んで下さい。
13行目ではドアを閉じてから何秒後に通知を送るのかを変更できます。(デフォルトでは30秒)

M5Stackの16番pinに鍵用の磁気スイッチ、2番pinに鍵用の磁気スイッチ、5番pinにLEDを接続してください。
詳しくは下記の記事を参考にしてください。

解説記事-> ~"[【M5Stack】鍵の閉め忘れをLINEに通知するシステム]"~　_準備中_