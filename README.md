# Coding Test backend
**Author** : Giorgio Raimondi

**Mailto** : <giorgio.raimondi.93@hotmail.com>

**Date**   : Gennaio 2018

-------------------------------------------------------
## Come installare il programma
-------------------------------------------------------
## CONTENUTO CARTELLA
- API.cpp	: Contiene le definizioni della classe API
- API.hpp	: Contiene le dichiarazioni della classe API
- main.cpp	: File di base per l'eseguibile
- Makefile	: Contiene le ruotine per la generazione dell'eseguibile
- runnable	: Eseguibile


## Instalazione ed Esecuzione

Il programma è stato scritto in linguaggio C++11, facendo largo delle sole standard libraries.

Si volesse ricompilare il programma è neccessario eseguire il comando 
``` 
$ make compile
``` 
per la generazione dell'eseguibile.
Qualora invece si volesse eseguire il programma è sufficiente eseguire il comando
``` 
$ make run 
``` 
od alternativamente
``` 
$ ./runnable
``` 
 

-------------------------------------------------------
#STRUTTURA DEL CODICE
-------------------------------------------------------

L'idea dietro a questo programma è quella di utilizzare le potenzialità di container già ottimizzato come lo è la classe map delle STANDARD LIBRARIES di C++, ed attorno a questa andare a generare delle routine utili per l'interfaccia utente. L'utilizzo delle standard libraries permette inoltre di semplificare le problematiche di costruzione e distruzione della classe.

Il valore di configurazione è stato salvato all'interno della map come un array di lunghezza 3 (CONF_VALUE), al quale è associato un valore chiave identico al valore ID salvato.

I metodi implementati per la semplificazione dell'interfaccia utente sono principalmente 4:

- GET: riceve in ingresso una string contenente il valore di ID preceduto dal backslash e ritorna, qualora esista una ID identico tra i valori chiave della map, il valore di configurazione. Qualora venga passato come ID il solo backslash, la funzione ritorna un vettore di tutti valori di configurazione presenti nella map  e li stampa a video.

- POST: riceve in ingresso 3 string contenenti i 3 dati per i valori di configurazione e se non esiste un ID uguale a quello passato nella map, salva all'interno di questa un nuovo elemento. Restituisce vero se l'operazione è andata a buon fine.

- PUT: riceve in ingresso 3 string contenenti i 3 dati per i valori di configarazione e se esiste un ID nella map uguale a quello passato, sostituisce i valori di configurazione riferiti al NAME ed al VALUE. Restituisce vero se l'operazione è andata a buon fine.

- DEL: riceve in ingresso 1 string contenente un valore ID e se presente un ID equivalente tra le key della map lo rimuove. Qualora sia passato come ID il solo backslash, rimuove tutti gli elementi nella map.
Restituisce vero se l'operazione è andata a buon fine.

A questi metodi sono stati aggiunte delle proprietà tipiche della programmazione ad oggetti come costruttori efficenti ed overload di operatori di copia. Quest'ultima parte in particolare risulta particolarmente utili all'interfaccia utente in quanto permette di importare degli API preesistenti (es: API google).

La distruzione dell'oggetto API non è stata implememtata in quanto si è deciso di utilizzare direttamente i distruttori della classe map.



##  DEV ENVIRONMENT
OS         : Ubuntu 14.04 LTS 64-bit

Processor  : Intel® Core™ i5-2410M CPU @ 2.30GHz × 4 

Compiler   : g++-4.8
