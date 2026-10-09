# 📡 Leitor RFID / NFC com ESP32 e PN532 (I2C)

Este projeto demonstra como realizar a leitura de cartões e tags RFID/NFC padrão **ISO14443A** (como cartões Mifare Classic e tags NTAG) utilizando o microcontrolador **ESP32** conectado ao módulo **PN532** através do barramento de comunicação **I2C por hardware**.

---

## 🛠️ Componentes Utilizados

- **ESP32 DevKit** (30 ou 38 pinos)
- **Módulo NFC/RFID PN532** (placa vermelha ou azul)
- **Cabos Jumpers** (Macho-Fêmea)
- **Cartão / Tag RFID 13.56 MHz** (Mifare Classic, NTAG213/215, etc.)

---

## ⚙️ Configuração das Chaves (DIP Switch)

Para que o módulo PN532 se comunique via **I2C**, posicione as duas chaves seletoras da placa na seguinte configuração:

| Chave | Posição | Valor Lógico |
| :---: | :---: | :---: |
| **CH1** | **ON** | 1 |
| **CH2** | **OFF** | 0 |

---

## 🔌 Esquema de Ligação

| PN532 (Pino) | ESP32 (GPIO) | Descrição |
| :--- | :--- | :--- |
| **VCC** | **VIN / 5V** | Alimentação principal (recomendado 5V) |
| **GND** | **GND** | Aterramento comum |
| **SDA** | **GPIO 21** | Linha de Dados I2C |
| **SCL** | **GPIO 22** | Linha de Clock I2C |

> ⚠️ **Dica:** Muitos módulos PN532 apresentam instabilidade quando alimentados com 3.3V. Prefira alimentar pelo pino de 5V/VIN do ESP32.

---

## 📚 Bibliotecas Necessárias

Instale a seguinte biblioteca através do Gerenciador de Bibliotecas da Arduino IDE:

1. **Adafruit PN532** por *Adafruit* (versão mais recente)
2. Dependência automática: **Adafruit BusIO**

---

## 🚀 Como Executar

1. Abra a [Arduino IDE](https://www.arduino.cc/en/software).
2. Configure a placa selecionando **ESP32 Dev Module** (ou o modelo correspondente).
3. Conecte o ESP32 ao computador via cabo USB e selecione a porta COM correspondente.
4. Carregue o código no microcontrolador.
5. Abra o **Monitor Serial** com o baud rate ajustado para **115200 bps**.
6. Aproxime uma tag ou cartão do sensor para visualizar o UID lido.

---

## 📄 Licença

Este projeto é de código aberto e está licenciado sob a [Licença MIT](LICENSE).