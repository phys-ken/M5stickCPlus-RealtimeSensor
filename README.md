# M5StickCPlusで、リアルタイム測定
M5StickCをWifiのアクセスポイントにして、測定値をスマホで表示します。  
実際に使っている様子は、こちら(Youtubeに飛びます。)。  
[![](http://img.youtube.com/vi/dR3Dypq_xo0/0.jpg)](http://www.youtube.com/watch?v=dR3Dypq_xo0 "")

### 機材
[M5StickC Plus](https://www.switch-science.com/catalog/6470/) 
[ToF Hat(VL53L0X搭載)](https://www.switch-science.com/catalog/6059/)  


### 作成方法
- Arduion IDEエディタをインストールする。
- [こちらのサイト(英語)](https://randomnerdtutorials.com/esp32-esp8266-plot-chart-web-server/)を参考に、ライブラリをインストールする。
- Arduino IDEのライブラリマネージャから、M5stickC Plus用のライブラリをインポートする。
- Arduino IDEから、M5stickC Plusに書き込めるように、準備する。[こちらのサイト](https://deviceplus.jp/hobby/entry_069/)等を参考に。
- 書き込めば、使えるようになります！


### 使い方
- スマートフォンのwifi接続画面から、M5stickCに接続する。
- ブラウザから192.168.20.2にアクセス
    - インプットボックスに、indexと入力すると、管理者ページが開けます。
    - インプットボックスにxgなどと打つと、そのページに飛べます。  

### 参考にしたサイト
- [ESP32/ESP8266 Plot Sensor Readings in Real Time Charts – Web Server](https://randomnerdtutorials.com/esp32-esp8266-plot-chart-web-server/)  
　ネットワークまわりのコードで参考にしました。
- [プログラミング講座 第13回【テトリスを作る(1)/JavaScript】](https://www.youtube.com/watch?v=LJlKaTwtSdI)  
　htmlのCanvas機能の学習で使いました。グラフ描画のコードでは、かなり参考にしています。