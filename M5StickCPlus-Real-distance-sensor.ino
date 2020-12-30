


// Import required l ibraries
#include <M5StickCPlus.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;


AsyncWebServer server(80);

// wifiアクセスポイントの名前・パスワードを設定
const char ssid[] = "M5_Phys002"; // SSID
const char pass[] = "11241124";   // password

const IPAddress ip(192, 168, 20, 2);      // IPアドレス
const IPAddress subnet(255, 255, 255, 0); // サブネットマスク

//距離の測定＆LCDの表示関数
String measure_distance() {
  float dist = sensor.readRangeContinuousMillimeters();
  M5.update();
  M5.Lcd.setCursor(20, 80);
  M5.Lcd.fillRect(20, 80, 60, 25, BLACK);
  M5.Lcd.print(dist / 10);
  Serial.print("distance ");  Serial.println(dist / 10);

  float dstCMs = dist / 10;
  return String(dstCMs);
}

void setup()
{
  // put your setup code here, to run once:
  Wire.begin(0, 26, 400000);// join i2c bus (address optional for master)
  Serial.begin(115200);  // start serial for output
  Serial.println("VLX53LOX test started.");

  //センサーのセットアップ
    Wire.begin(0, 26, 100000);
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }
  sensor.startContinuous();

  WiFi.softAP(ssid, pass);           // SSIDとパスの設定
  delay(100);                        // 追記：このdelayを入れないと失敗する場合がある
  WiFi.softAPConfig(ip, ip, subnet); // IPアドレス、ゲートウェイ、サブネットマスクの設定

  IPAddress myIP = WiFi.softAPIP(); // WiFi.softAPIP()でWiFi起動

  //シリアルにIPアドレスを表示
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  Serial.println("Server start!");

  // SPIFFSがうまく起動できているか確認
  if (!SPIFFS.begin())
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/home.html");
  });
  server.on("/xg.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/xg.html");
  });
  server.on("/vg.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/vg.html");
  });
  server.on("/ag.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/ag.html");
  });
  server.on("/x.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/x.html");
  });
  server.on("/v.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/v.html");
  });
  server.on("/xv.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/xv.html");
  });
  server.on("/a.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/a.html");
  });
  server.on("/ac.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/ac.html");
  });
  server.on("/vc.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/vc.html");
  });
  server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html");
  });
 server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request) {
   request->send_P(200, "text/plain", measure_distance().c_str());
  });
  server.on("/test.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/test.html");
  });
  server.on("/hello.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/hello.html");
  });

  // Start server
  server.begin();



  M5.begin();
  M5.Lcd.println("   ");  
  M5.Lcd.println("SSID -->");
  M5.Lcd.println(ssid);

  M5.Lcd.println("   ");  

  M5.Lcd.println("IP -->");
  M5.Lcd.println(myIP);

//  String urlqr = "http://" + myIP;
//    M5.Lcd.qrcode(urlqr,
//    0, 70, 80, 15);
 
  Serial.println("Connect:");
  Serial.println(ssid);
  Serial.println("Enter:");
  Serial.println(myIP);

  
}

void loop()
{
//   measure_distance();
//    delay(100);
}
