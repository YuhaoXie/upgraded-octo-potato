#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char *WIFI_SSID = "***";
const char *WIFI_PASSWORD = "****";
 
const char *URL = "https://hooks.slack.com/services/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";
const char *FINGERPRINT = "82aefd933630da030a2f6353de2eb0438bf441f6";
 
WiFiClientSecure client;
HTTPClient httpsClient;
 
void setup()
{
    Serial.begin(9600);
 
    WiFi.mode(WIFI_STA);
 
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
 
    Serial.println("Connected");
 
    client.setFingerprint(FINGERPRINT);
}
 
void loop()
{
    String value = "Raspberry Beret Rocks!";
    String data = "{\"text\":\"" + String(value) + "\"}";
 
    httpsClient.begin(client, URL);
    httpsClient.addHeader("Content-Type", "application/json");
    httpsClient.POST(data);
    httpsClient.end();
 
    delay(5000);
}
