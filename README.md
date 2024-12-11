# Sistema Inteligente de Irrigação com IoT

Este repositório contém o código-fonte, configurações e documentações do projeto **Sistema Inteligente de Irrigação com IoT**, desenvolvido para promover a agricultura sustentável, utilizando tecnologias modernas como IoT, ESP32, MQTT, Node-RED, InfluxDB e Grafana. O projeto é alinhado aos **Objetivos de Desenvolvimento Sustentável (ODS)** da ONU, com foco no **ODS 2** (Fome Zero) e **ODS 12** (Consumo e Produção Sustentáveis).

## 🛠️ Objetivo do Projeto

Desenvolver um sistema de monitoramento e controle automatizado de irrigação, que:
- Otimize o uso de recursos hídricos.
- Aumente a eficiência da produção agrícola.
- Reduza desperdícios, integrando sensores e plataformas de análise de dados.
- Promova sustentabilidade no uso de recursos naturais.

---

## 🔑 Funcionalidades Principais

1. **Monitoramento em Tempo Real**:
   - Sensores medem a umidade do solo, temperatura e umidade relativa do ar.
   - Dados são enviados para a nuvem e integrados com a API do OpenWeather.

2. **Decisões Automatizadas**:
   - Regras predefinidas acionam comandos "ligar" e "desligar" com base nos dados coletados.
   - Previsões climáticas ajustam automaticamente as operações de irrigação.
- **Regras inteligentes** definem se o sistema de irrigação deve ser ligado ou desligado com base nos seguintes critérios:
  - Solo com umidade abaixo de **30%** ativa o sistema.
  - Previsão de chuva acima de **70%** ou solo com umidade acima de **60%** desativa o sistema.
  - Temperatura elevada e baixa umidade atmosférica também influenciam na decisão.


3. **Visualização e Análise**:
   - Dashboards no Grafana exibem os dados de forma interativa.
   - Gráficos detalham condições ambientais e frequência de comandos.

4. **Escalabilidade e Acessibilidade**:
   - Arquitetura modular para fácil ampliação.
   - Adequado para pequenos e grandes agricultores.

---

## 📦 Estrutura do Repositório

- **`SImulador_RJ/`**:
  Contém o código e as configurações simuladas para o estado do Rio de Janeiro.

- **`Simulador_SP/`**:
  Contém o código e as configurações simuladas para o estado de São Paulo.

- **`flows.json`**:
  Fluxo principal do sistema no Node-RED.

- **`README.md`**:
  Documentação detalhada do projeto.

- **`settings.js`**:
  Configurações do ambiente Node-RED.

---

## 🖥️ Tecnologias Utilizadas

### **Hardware**
- **ESP32**: Microcontrolador para coleta e transmissão de dados via MQTT.
- **DHT22**: Sensor de temperatura e umidade do ar.
- **Potenciômetro**: Simulação prática de valores de umidade do solo.

### **Software**
- **Wokwi**: Simulação de projetos com ESP32.
- **OpenWeather API**: Dados meteorológicos em tempo real.
- **Node-RED**: Fluxo visual para processamento de dados.
- **InfluxDB**: Banco de dados orientado a séries temporais.
- **Grafana**: Visualização interativa dos dados.

---

## 🌐 Fluxo de Funcionamento

1. **Coleta de Dados**:
   - Sensores enviam leituras para o ESP32.
   - Dados locais são comparados com informações da OpenWeather API.

2. **Processamento de Dados**:
   - Node-RED processa as informações, gerando comandos para irrigação.

3. **Decisões Inteligentes**:
   - Comandos "ligar" ou "desligar" baseados em regras de umidade do solo, temperatura e previsão de chuva.

4. **Armazenamento e Visualização**:
   - Dados armazenados no InfluxDB.
   - Dashboards no Grafana para análise em tempo real.

---

## 🚀 Resultados Alcançados

- Integração bem-sucedida entre sensores, Node-RED, InfluxDB e Grafana.
- Redução de desperdício de água ao ativar a irrigação apenas quando necessário.
- Dashboards detalhados para monitoramento e análise em tempo real.
- Sistema robusto e escalável, adequado para diferentes cenários agrícolas.

---

## 🗂️ Como Usar

1. **Simule o Código**:
   - Utilize a plataforma Wokwi para testar os códigos nas pastas `Simulador_SP` e `Simulador_RJ`.

2. **Implemente os Fluxos**:
   - Importe o arquivo `flows.json` no Node-RED.

3. **Configuração do Ambiente**:
   - Configure o InfluxDB para armazenar os dados e o Grafana para visualizá-los.

4. **Execute o Sistema**:
   - Certifique-se de que os sensores e o ESP32 estão conectados.
   - Monitore o comportamento no dashboard do Grafana.

---

## 🔗 Referências

- [OpenWeather API](https://openweathermap.org/api)
- [Node-RED](https://nodered.org/)
- [Grafana](https://grafana.com/)
- [InfluxDB](https://www.influxdata.com/)

---

Se precisar de mais detalhes ou modificações, é só avisar! 😊
