// ============================================================
// PROJETO INTERDISCIPLINAR - CUBO DE LED 8x8x8
// Centro Universitário das Américas (FAM)
// 7º Congresso de Projetos Interdisciplinares
//
// Autores:
// Fabiano Ferreira de Lima
- Felipe Georgeto do Santos
- Gabriel Guardiano Lopes
- Luiz Gustavo Leite Soares
- Matheus de Oliveira Santos

//
// Professor orientador: Trevisan, F.
// Curso: Engenharia da Computação
// São Paulo, 2024
// ============================================================

// ------------------------------------------------------------
// Pinos de controle do Shift Register 74LS595
// ------------------------------------------------------------
#define dataPin  2   // Pino de dados (SER)
#define latchPin 3   // Pino de latch (RCLK)
#define clockPin 4   // Pino de clock (SRCLK)

// ------------------------------------------------------------
// Pinos das 8 camadas (anodos/cátodos das camadas do cubo)
// ------------------------------------------------------------
int camadas[8] = {5, 6, 7, 8, 9, 10, 11, 12};

// ------------------------------------------------------------
// Array que armazena os valores binários de cada camada
// Cada posição representa uma coluna (8 bits = 8 LEDs)
// ------------------------------------------------------------
byte pinVals[8][8];

// Coordenadas do LED atual para animação
int xc = 0;
int yc = 0;
int zLayer = 0;

// ------------------------------------------------------------
// Configuração inicial
// ------------------------------------------------------------
void setup() {
  // Configura pinos do shift register como saída
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  // Configura pinos das camadas como saída
  for (int i = 0; i < 8; i++) {
    pinMode(camadas[i], OUTPUT);
    digitalWrite(camadas[i], LOW); // Todas as camadas desligadas
  }

  // Apaga todos os LEDs no início
  limparCubo();

  // Acende o primeiro LED
  bitSet(pinVals[zLayer][xc], yc);
}

// ------------------------------------------------------------
// Loop principal - animação sequencial dos LEDs
// ------------------------------------------------------------
void loop() {
  // Exibe o estado atual do cubo
  exibirCubo();

  // Apaga o LED atual
  bitClear(pinVals[zLayer][xc], yc);

  // Avança para o próximo LED
  yc++;
  if (yc >= 8) {
    yc = 0;
    xc++;
  }
  if (xc >= 8) {
    xc = 0;
    zLayer++;
  }
  if (zLayer >= 8) {
    zLayer = 0;
  }

  // Acende o próximo LED
  bitSet(pinVals[zLayer][xc], yc);

  delay(50); // Ritmo visual suave
}

// ------------------------------------------------------------
// Função que exibe o estado atual do cubo via multiplexação
// ------------------------------------------------------------
void exibirCubo() {
  for (int z = 0; z < 8; z++) {
    // Ativa a camada atual
    for (int i = 0; i < 8; i++) {
      digitalWrite(camadas[i], i == z ? HIGH : LOW);
    }

    // Envia os dados da camada para o shift register
    digitalWrite(latchPin, LOW);
    for (int x = 0; x < 8; x++) {
      shiftOut(dataPin, clockPin, MSBFIRST, pinVals[z][x]);
    }
    digitalWrite(latchPin, HIGH);

    delayMicroseconds(500); // Pequeno delay para multiplexação
  }
}

// ------------------------------------------------------------
// Função que apaga todos os LEDs do cubo
// ------------------------------------------------------------
void limparCubo() {
  for (int z = 0; z < 8; z++) {
    for (int x = 0; x < 8; x++) {
      pinVals[z][x] = 0;
    }
  }
}

// ------------------------------------------------------------
// Função de efeito: acende todos os LEDs de uma camada
// ------------------------------------------------------------
void acenderCamada(int z) {
  for (int x = 0; x < 8; x++) {
    pinVals[z][x] = 0xFF; // Liga todos os 8 bits
  }
}

// ------------------------------------------------------------
// Função de efeito: apaga todos os LEDs de uma camada
// ------------------------------------------------------------
void apagarCamada(int z) {
  for (int x = 0; x < 8; x++) {
    pinVals[z][x] = 0x00; // Desliga todos os 8 bits
  }
}
