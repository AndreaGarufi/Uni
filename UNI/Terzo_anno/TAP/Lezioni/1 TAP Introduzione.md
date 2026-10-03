**Data Ingestion**
Prendere i dati da applicazione, logs, APIs e metterli nella pipeline di elaborazione, tramite batch o in streaming.
*Tecnologie:*
- apache flume
- apache NiFi
- logstash
- fluent
- n8n


*Utilizzi*
- Ruotare le informazioni ad altri soggetti.
- Prendere i dati dall'applicazione e immagazzinarli
- aggregare dati 
- automazione di certi eventi



**Data Streaming**
Prendere i dati e farli processare anche da più "attori" contemporaneamente 
*Tecnologie:*
- apache Kafka
- confluent
- redpanda
- apache pulsar
- NATS

*Utilizzi*
- trasferire i dati tra diversi sistemi
- trasformare i dati


**Data Processing**
Trasfomare, validare e analizzare i dati alla scala o latenza che il caso vuole (batch o streaming).

*Tecnologie:*
- apache Spark
- apache Flink
- ray
- duckDB

*Applicazioni*
- Arricchire i dati (completarli e dargli un senso)
- Analizzare e categorizzare i dati anche usando LLM


**Real-Time Analytics**
eseguire low-latency query direttamente su i dati "ingested" o "streamed" senza passare per uno step separato.

*Tecnologies:*
- HDFS
- minIO
- rustFS

*Applicazioni*
immagazzinare grandi datasets sui cluster


**Data Lake**
Gestisce le modifiche di grandi file e quindi di grandi quantità di dati.

*Tecnologies:*
- apache Iceberg
- delta Lake


**Search & Retrieval**
Capacità di fare ricerche sui dati processati attraverso keyword ad esempio.

*Tecnologie:*
- elasticsearch
- opensearch

*Applicazioni*
- indicizzare logs e documenti
- cercare dati


**Visualization & Monitoring**
Controllare come sta andando la pipeline e l'elaborazione dei dati

*Tecnologie:*
- kibana
- grafana

**Data Governance**
Catalogare i dataset, tracciare la lineage ed evidenziare la titolarità dei dati e gli indicatori di qualità lungo la pipeline.


**LLM Generative**
utilizzare LLM in locale

*Tecnologie:*
- hugging face
- vLLM
- ollama
- langChain

*Applicazioni*
- vari usi che possono offrire gli LLM (test, ricerche,lavori ripetitivi ecc...)

