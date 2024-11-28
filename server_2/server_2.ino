#include <WiFi.h>
#define SensorA 34
#include <ESPAsyncWebServer.h>

// Defina seu SSID e senha Wi-Fi
const char* ssid = "SATC IOT";
const char* password = "IOT2024@#";

// Crie um servidor web na porta 80
AsyncWebServer server(80);

// pinos dos motores
const int motIn1 = 5;
const int motIn2 = 2;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(115200);
  pinMode(SensorA, INPUT);
  pinMode(motIn1, OUTPUT);
  pinMode(motIn2, OUTPUT);

  // Conecta-se à rede Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando-se ao Wi-Fi...");
  }

  Serial.println("Conectado ao Wi-Fi");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  // Serve um site HTML simples na rota "/"
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<html><body>"
                  "<h1>Controle do Varal Automatico</h1>"
                  "<p>Aperte no botao para abrir o varal.</p>"
                  "<button onclick=\"toggleVaral()\">Abrir Varal</button>"
                  "<p>Aperte no botao para Fechar o varal.</p>"
                  "<button onclick=\"toggleVaral()\">Fechar Varal</button>"
                  "<script>"
                  "function toggleLED() {"
                  "  fetch('/toggle');"
                  "}"
                  "</script>"
                  "</body></html>";
    request->send(200, "text/html", html);
  });

  server.on("/toggle", HTTP_GET, [](AsyncWebServerRequest *request){
    if (analogRead(SensorA) > 3400) {
      digitalWrite(motIn1, LOW);
      digitalWrite(motIn2, HIGH);
      Serial.println(analogRead(SensorA));
      delay(1000);
    }
    else {
      digitalWrite(motIn1, HIGH);
      digitalWrite(motIn2, LOW);
      delay(2000);
      Serial.println(analogRead(SensorA));
      delay(1000);

      // Verifica a URL da requisição
      String url = request->url();  // Obtém a URL da requisição

      if (url.indexOf("/H") >= 0) {  // Verifica se a URL contém "/H"
        digitalWrite(motIn2, HIGH);
        delay(2000);
        digitalWrite(motIn2, LOW);
        request->send(200, "text/plain", "Varal para fora.");
      }
      else if (url.indexOf("/L") >= 0) {  // Verifica se a URL contém "/L"
        digitalWrite(motIn1, HIGH);
        delay(2000);
        digitalWrite(motIn1, LOW);
        request->send(200, "text/plain", "Varal para dentro.");
      }
    }
  });

  // Inicia o servidor
  server.begin();
}

void loop() {
  // Não precisa fazer nada no loop, o servidor lida com as requisições automaticamente
}