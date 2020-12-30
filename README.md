# M5StickCで、リアルタイム測定
M5StickCをWifiのアクセスポイントにして、測定値をスマホで表示します。  

### 機材
M5StickC  
ToF HAT  


### Arduinoで作成
参考にしたサイト  
ESP32の処理　https://randomnerdtutorials.com/esp32-esp8266-plot-chart-web-server/  
グラフ描画機能の実装　https://www.youtube.com/watch?v=LJlKaTwtSdI&t=31s  

### 使い方
必要なライブラリを読み込む。  
※非同期処理に関するライブラリは、マネージャからはインストールできないので要注意。  
.ino のファイルを、ESP32に書き込む  
spiffに、dataの中のデータを書き込む



wifiから、192.168.20.2にアクセス  
　→windowに、indexと入力  
　→windowにhtmlのファイル名を打てば、そのサイトに飛ぶ。  