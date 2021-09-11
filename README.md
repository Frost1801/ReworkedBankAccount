# ReworkedBankAccount

**PROGETTO SCELTO:**

> Classi che rappresentano transazioni finanziarie su un conto corrente (ingresso e uscita). Le classi devono essere in grado di leggere e salvare i dati su file.

## FUNZIONAMENTO DEL PROGRAMMA

Il programma è composto da 4 classi principali:

**Transaction:** Rappresenta una transazione sul conto, con valore, tipologia della transazione, data e ora in cui è avvenuta, causale e autore della transazione. 

**BankAccount:** Rappresenta un account bancario con un proprio nome, un bilancio che indica i fondi dell'account e una transaction history, che mantiene tutte le transazioni di ingresso e uscita avvenute nell'account. L'Account fornisce i metodi per depositare e ritirare denaro. 

**User:** Rappresenta un utente del servizio bancario con i propri dati (nome, data di nascita, indirizzo e lista degli account bancari che possiede). L'user ha la possibilità di gestire i propri account depositando e ritirando denaro e di visualizzare le transazioni effettuate. Al termine dell'utilizzo del servizio le operazioni effettuate dell'utente sono salvate in un file di testo insieme ai suoi dettagli anagrafici in un report generato automaticamente dal programma e che viene mostrato all'utente. 

**Interface:** Si occupa di rendere l'accesso alle operazioni più facile tramite una interfaccia naviabile utilizzando input della tastiera. 











