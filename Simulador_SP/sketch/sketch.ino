// Incluir bibliotecas
#include <WiFi.h> // Biblioteca Wi-Fi
#include <PubSubClient.h> // Biblioteca MQTT
#include <ArduinoJson.h> // Biblioteca para lidar com JSON (instale via Gerenciador de Bibliotecas do Arduino)

// Configurações do Wi-Fi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Configurações do Broker MQTT
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "irrigation/control";

// Configurações do ESP32
WiFiClient espClient;
PubSubClient client(espClient);

const int ledPin = 4;              // LED conectado ao GPIO 4

// Variáveis para simulação da umidade do solo
float soilMoisturePercentage = 0.0;

// Função para conectar ao Wi-Fi
void setup_wifi() {
  Serial.print("Conectando ao Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado ao Wi-Fi!");
}

// Função de callback para processar mensagens recebidas do MQTT
void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Comando recebido: ");
  Serial.println(message);

  StaticJsonDocument<256> doc;
  DeserializationError error = deserializeJson(doc, message);

  if (error) {
    Serial.print("Erro ao analisar JSON: ");
    Serial.println(error.c_str());
    return;
  }

  const char* command = doc["command"];
  if (String(command) == "ligar") {
    Serial.println("Dispositivo ligado!");
    digitalWrite(ledPin, HIGH);
  } else if (String(command) == "desligar") {
    Serial.println("Dispositivo desligado!");
    digitalWrite(ledPin, LOW);
  }
}

// Função para reconectar ao MQTT
void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao Broker MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("Conectado!");
      client.subscribe(mqtt_topic);
    } else {
      Serial.print("Falha ao conectar, tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  // Inicializar gerador de números aleatórios
  randomSeed(analogRead(0));
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Gerar valor aleatório de umidade entre 0 e 100%
  soilMoisturePercentage = random(0, 101);

  Serial.print("Umidade do Solo (%): ");
  Serial.println(soilMoisturePercentage);

  // Publicar valor aleatório de umidade do solo
  StaticJsonDocument<128> soilDoc;
  soilDoc["soilMoisture"] = soilMoisturePercentage;
  char buffer[128];
  serializeJson(soilDoc, buffer);
  client.publish("sensor/soil_moisture/sp", buffer);

  delay(10000); // Aguarda 10 segundos antes da próxima leitura
}