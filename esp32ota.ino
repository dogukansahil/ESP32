#include <WiFi.h>
#include <ArduinoOTA.h>

const char* ssid = "Wi-FiAdiniz";       // Wi-Fi Ağ Adı
const char* password = "Sifreniz"; // Wi-Fi Şifresi

// Statik IP Ayarları
IPAddress local_IP(192, 168, 1, 66);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);
IPAddress secondaryDNS(8, 8, 4, 4);

// Blink için LED Pin
const int ledPin = 12;  // GPIO 12

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);

    // Wi-Fi Bağlantısı
    WiFi.mode(WIFI_STA);
    if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
        Serial.println("⚠ Statik IP atanamadı! DHCP kullanılacak.");
    }
    WiFi.begin(ssid, password);

    Serial.print("🔌 Wi-Fi Bağlanıyor...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\n✅ Wi-Fi Bağlandı!");
    Serial.print("📡 IP Adresi: ");
    Serial.println(WiFi.localIP());

    // OTA Ayarları
    ArduinoOTA.setHostname("esp32ota");

    ArduinoOTA.onStart([]() {
        Serial.println("🚀 OTA Güncelleme Başlıyor!");
    });

    ArduinoOTA.onEnd([]() {
        Serial.println("\n✅ OTA Güncelleme Tamamlandı!");
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("📶 Güncelleme: %u%%\r", (progress / (total / 100)));
    });

    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("❌ OTA Hatası [%u]\n", error);
    });

    ArduinoOTA.begin();
    Serial.println("✅ OTA Hazır!");
}

void loop() {
    ArduinoOTA.handle();  // OTA Güncellemelerini Dinle

    // Blink İşlevi
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
}

