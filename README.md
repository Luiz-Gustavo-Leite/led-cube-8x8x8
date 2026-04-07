# 💡 Cubo de LED 8x8x8 — Arduino

Projeto Interdisciplinar desenvolvido no **7º Congresso de Projetos Interdisciplinares do Centro Universitário das Américas (FAM)**.

---

## 👥 Autores

- Lima, F. F  
- Santos, G. F  
- Lopes, G. G  
- Soares, L. G. L  
- Santos, O. M  

**Professor orientador:** Trevisan, F.  
**Curso:** Engenharia da Computação — FAM, São Paulo, 2024

---

## 📋 Descrição

Cubo de LED RGB 8x8x8 composto por **512 LEDs** organizados em uma matriz tridimensional, controlado por um Arduino via **multiplexação** e **shift registers 74LS595**. O cubo é capaz de exibir animações e padrões visuais dinâmicos em três dimensões.

---

## 🔧 Componentes Utilizados

| Quantidade | Material / Componente | Função |
|---|---|---|
| 550 | LEDs RGB | Formação da matriz 8x8x8 |
| 10 | MOSFET IRF 9Z34N | Controle do fluxo de corrente nas camadas |
| 250 | Resistor 100Ω | Limitam corrente nos LEDs |
| 250 | Resistor 1KΩ | Controle de corrente em pontos específicos |
| 210 | Transistor 2N3904 | Alimentação das camadas de LEDs |
| 10 | Capacitor Eletrolítico 100µF 16V | Estabilização da alimentação |
| 25 | Capacitor Cerâmico 0.1µF | Suavização de flutuações de tensão |
| 30 | Resistor 10KΩ | Ajustes finos de sinal |
| 30 | CI 74LS595N | Registradores de deslocamento (shift register) |
| 1 | Arduino | Microcontrolador central |
| 250 | Fio RGB 22AWG | Conexões dos LEDs |
| 1 | Fonte 5A 5V/12V | Alimentação do sistema |
| 1 | Multímetro | Verificação de continuidade e tensão |
| - | Madeira | Estrutura física da base |

---

## ⚡ Pinagem — Arduino

| Pino | Função |
|---|---|
| 2 | Data (SER) — Shift Register |
| 3 | Latch (RCLK) — Shift Register |
| 4 | Clock (SRCLK) — Shift Register |
| 5 a 12 | Controle das 8 camadas do cubo |

---

## 🧠 Como funciona

O cubo utiliza a técnica de **multiplexação**: cada camada é ativada sequencialmente em intervalos muito curtos, criando a ilusão de que todos os 512 LEDs estão acesos ao mesmo tempo. O **shift register 74LS595** expande as saídas do Arduino, permitindo controlar as 64 colunas de cada camada com apenas 3 pinos.

---

## 🛠️ Como usar

### Pré-requisitos
- [Arduino IDE](https://www.arduino.cc/en/software) instalada
- Placa: **Arduino UNO** ou compatível

### Passos
1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/cubo-led-8x8x8.git
   ```
2. Abra o arquivo `cubo_led_8x8x8.ino` na Arduino IDE
3. Conecte o Arduino via USB
4. Selecione a placa e porta em **Ferramentas**
5. Clique em **Upload** (→)
6. Ligue o cubo e veja a animação!

---

## 📁 Estrutura do Repositório

```
cubo-led-8x8x8/
├── cubo_led_8x8x8.ino   # Código-fonte principal (Arduino C++)
└── README.md             # Documentação do projeto
```

---

`Arduino` · `LED` · `Cubo 8x8x8` · `Multiplexação` · `Shift Register` · `C++` · `FAM`
