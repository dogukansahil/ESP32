# ESP32 OTA (Over-the-air update)

## Wi-Fi Bağlantısı
- ESP32, **STA modunda** Wi-Fi'ye bağlanır.
- **Statik IP**: 192.168.1.66 (atanamazsa DHCP devreye girer).
- ESP32 kablosuz uzaktan programlanabilir.

## OTA (Over-The-Air) Güncelleme
- **ArduinoOTA** kütüphanesi ile OTA desteği.
- Güncelleme durumları seri monitöre yazdırılır.
- Hata kodları yakalanır ve görüntülenir.

## LED Blink
- **GPIO 12**'deki LED **(100ms HIGH - 100ms LOW)** yanıp söner.
- ESP32'nin çalıştığını gösterir.

🔗 [ESP32OTA](https://github.com/dogukansahil/ESP32/blob/main/esp32ota.ino)
