#include "stemWiFi.h"


stemWiFi w;
stemWiFi::stemWiFi() {}

void stemWiFi::init() {
    server = new AsyncWebServer(80);
    ws = new AsyncWebSocket("/ws");

    ws->onEvent(std::bind(&stemWiFi::onEvent, this
      , std::placeholders::_1
      , std::placeholders::_2
      , std::placeholders::_3
      , std::placeholders::_4
      , std::placeholders::_5
      , std::placeholders::_6));

    server->addHandler(ws);
    server->begin();
}

void stemWiFi::configureWiFiAP() {
  //RGBLED::configureLED();
  log_n("Definindo modo WiFi");
   WiFi.mode(WIFI_AP);
  log_n("Iniciando Acess Point");
  WiFi.softAP(ssid, password);



  log_n("Endereço IP");
  if(Serial) {
    Serial.println(WiFi.softAPIP());
  }
  w.init();
  delay(500);
  
  //loadingWiFi();
}

/*
void stemWiFi::loadingWiFi() {
  log_n("Aguardando cliente");
  while(()) {
    client = server.available();
    //RGBLED::CONFIGURE_WIFI();
  }
  log_n("Cliente conectado");
}
*/

/*
void stemWiFi::getGamepadValues() {
    if(client.connected()) {
      String data = webSocketServer.getData();

      if (data.length() > 0) {

        Gamepad::gamepad = handleReceivedMessage(data);

      }
   }
  delay(20);
}
*/

/*
bool stemWiFi::getClientConnected() {
  return client.connected();
}
*/

JsonDocument stemWiFi::handleReceivedMessage(String message) {
  JsonDocument jon;                
  deserializeJson(jon, message); 
  DeserializationError err = deserializeJson(jon, message);
  errorJson(err);

  return jon;
}


void stemWiFi::errorJson(DeserializationError err) {
  switch (err.code()) { 
      case DeserializationError::InvalidInput:
          Serial.println(F("Invalid input!"));
          break;
      case DeserializationError::NoMemory:
          Serial.println(F("Not enough memory"));
          break;
      case DeserializationError::Ok:
          break;
  }
}

/*
bool stemWiFi::waitForStart() {
  bool waitForStart = false;
  while(!waitForStart) {
    JsonDocument js = handleReceivedMessage(webSocketServer.getData());
    waitForStart = js["Estado"];
    Serial.println("Aguardando Init");
    delay(20);
  }
  return true;
}
*/
/*
String stemWiFi::getEnable() {
  JsonDocument js = handleReceivedMessage(handleWebSocketMessage());
  String status = js["Estado"];
  return status;
}
*/

void stemWiFi::onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
 void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.println("WebSocket client connected");
      break;
    case WS_EVT_DISCONNECT:
      Serial.println("WebSocket client disconnected");
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

void stemWiFi::cleanupClients() {
  ws->cleanupClients();
}

void stemWiFi::handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    JsonDocument jon;                
    DeserializationError err = deserializeJson(jon, data);
    errorJson(err);
    Gamepad::gamepad = jon;
  }
}
