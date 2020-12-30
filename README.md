# M5StickCPlusで、リアルタイム測定
M5StickCをWifiのアクセスポイントにして、測定値をスマホで表示します。  

### 機材
M5StickCPlus 
ToF HAT  


### 作成方法Plus
- Arduion IDEエディタをインストールする。
- [こちらのサイト(英語)](https://randomnerdtutorials.com/esp32-esp8266-plot-chart-web-server/)を参考に、ライブラリをインストールする。
- Arduino IDEのライブラリマネージャから、M5stickC Plus用のライブラリをインポートする。
- Arduino IDEから、M5stickC Plusに書き込めるように、準備する。[こちらのサイト](https://deviceplus.jp/hobby/entry_069/)等を参考に。
- 書き込めば、使えるようになります！


### 使い方
必要なライブラリを読み込む。  
※非同期処理に関するライブラリは、マネージャからはインストールできないので要注意。  
.ino のファイルを、ESP32に書き込む  
spiffに、dataの中のデータを書き込む



wifiから、192.168.20.2にアクセス  
　→windowに、indexと入力  
　→windowにhtmlのファイル名を打てば、そのサイトに飛ぶ。  

### 参考にしたサイト
- [ESP32/ESP8266 Plot Sensor Readings in Real Time Charts – Web Server](https://randomnerdtutorials.com/esp32-esp8266-plot-chart-web-server/)  
　ネットワークまわりのコードで参考にしました。
- [プログラミング講座 第13回【テトリスを作る(1)/JavaScript】](https://www.youtube.com/watch?v=LJlKaTwtSdI)  
　htmlのCanvas機能の学習で使いました。グラフ描画のコードでは、かなり参考にしています。