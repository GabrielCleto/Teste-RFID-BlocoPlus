
//chave 1 ON Direita 
//chave 2 off Esquerda 

#include <Wire.h>
#include <Adafruit_PN532.h>

// Definição dos pinos I2C para o ESP32
#define SDA_PIN 21
#define SCL_PIN 22

// Instancia o objeto PN532 via I2C
Adafruit_PN532 nfc(SDA_PIN, SCL_PIN);

void setup(void) {
  Serial.begin(115200);
  while (!Serial) delay(10); // Aguarda a serial estabilizar
  Serial.println("--- Teste de Leitura NFC/RFID ---");

  // Inicia a comunicação com o módulo
  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.println("ERRO: PN532 não encontrado!");
    Serial.println("DICA: Verifique se as chaves estão em OFF (0 0) e se o VCC está no 5V.");
    while (1); // Trava aqui se houver erro
  }

  // Exibe detalhes do chip encontrado
  Serial.print("Encontrado chip PN5"); 
  Serial.println((versiondata >> 24) & 0xFF, HEX);
  
  // Configura o sensor para ler tags
  nfc.SAMConfig();

  Serial.println("Aguardando cartão ou tag ISO14443A...");
}

void loop(void) {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer para armazenar o ID
  uint8_t uidLength;                        // Tamanho do ID (4 ou 7 bytes)

  // Tenta ler uma tag passiva
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (success) {
    // Se encontrar uma tag, exibe os detalhes no Monitor Serial
    Serial.println("Cartão Detectado!");
    Serial.print("Tamanho do UID: "); Serial.print(uidLength, DEC); Serial.println(" bytes");
    Serial.print("UID Valor: ");
    for (uint8_t i = 0; i < uidLength; i++) {
      Serial.print(" 0x"); Serial.print(uid[i], HEX);
    }
    Serial.println("\n");

    // Aguarda um pouco antes da próxima leitura
    delay(1000);
  }
}