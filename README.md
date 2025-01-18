
# Projeto: Controle de LEDs e Buzzer com Teclado Matricial no Raspberry Pi Pico W

Este projeto implementa o controle de três LEDs e um buzzer utilizando um teclado matricial 4x4 conectado ao **Raspberry Pi Pico W**. Dependendo da tecla pressionada, LEDs específicos são ativados ou o buzzer é acionado.

## Funcionalidades
1. **Controle de LEDs:**
   - Tecla `1`: Liga o LED azul.
   - Tecla `2`: Liga o LED vermelho.
   - Tecla `3`: Liga o LED branco.

2. **Controle do Buzzer:**
   - Qualquer outra tecla aciona o buzzer por 200 ms.

## Hardware Necessário
- 1 Raspberry Pi Pico W.
- 1 Teclado matricial 4x4.
- 3 LEDs RGB (ou LEDs individuais nas cores azul, vermelho e branco).
- 1 Buzzer.
- Resistores (de 220Ω a 330Ω para os LEDs, e pull-up para o teclado, se necessário).
- Fios e uma protoboard.

## Esquema de Conexão
### Teclado Matricial
- **Linhas**:
  - ROW1 → GPIO2
  - ROW2 → GPIO3
  - ROW3 → GPIO4
  - ROW4 → GPIO5
- **Colunas**:
  - COL1 → GPIO6
  - COL2 → GPIO7
  - COL3 → GPIO8
  - COL4 → GPIO9

### LEDs
- LED azul → GPIO10
- LED vermelho → GPIO11
- LED branco → GPIO12

### Buzzer
- Buzzer → GPIO13

## Configuração do Ambiente
1. Instale o **Raspberry Pi Pico SDK** seguindo a [documentação oficial](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).
2. Configure o ambiente de desenvolvimento com CMake e uma IDE, como o Visual Studio Code.
3. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
   cd seu-repositorio

