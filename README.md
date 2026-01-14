

# THE GAUNTLET 2

Consegna per esame **Unreal1**

---

## 🛠️ Requisiti Tecnici
Prima di iniziare, assicurati di avere installato:
* **Unreal Engine** (Versione 5.6 o superiore)
* **Visual Studio 2022** con il carico di lavoro "Game development with C++"
* **Windows SDK** compatibile con la versione di Unreal utilizzata

---

## 🚀 Installazione e Compilazione
Trattandosi di un progetto basato su C++, segui questi passaggi per generare i file necessari:

1. **Clona la repository:**
   ```bash
   git clone [https://github.com/doblex/Gauntlet2.git]

2. **Genera i file di Visual Studio:**
Fai click destro sul file `.uproject` nella cartella principale e seleziona **"Generate Visual Studio project files"**.
3. **Compilazione:**
Apri il file `.sln` generato e compila la soluzione in modalità **Development Editor** (Win64).
4. **Avvio:**
Apri il file `.uproject` per lanciare l'Unreal Editor.

---

## 📂 Struttura della Repository

L'architettura del progetto è suddivisa tra logica C++ e asset grafici, seguendo le best practice di Unreal Engine.

### 📁 Source (C++)

Contiene la logica core e le definizioni delle classi base.

* **`/Actors`**: Tutte le classi derivate da `AActor` o sottoclassi, organizzate per gerarchia di derivazione.
* **`/Characters`**: Classi specifiche per la gestione del giocatore.
* **`/Core`**: Il cuore del sistema. Include `GameInstance`, `GameMode`, `HUD`, `SubSystems` e la classe `devSettings` per la configurazione dei parametri di sistema.
* **`/Interfaces`**: Tutte le interfacce C++ utilizzate per il disaccoppiamento dei sistemi.
* **`/Lib`**: Librerie di funzioni globali (`Blueprint Function Library`).

### 📁 Content (Assets)

Contiene i Blueprint derivati dalle classi C++ e tutti gli asset multimediali.

| Cartella | Contenuto |
| --- | --- |
| **`/Blueprints`** | Implementazioni Blueprint non legate alla GameMode. |
| **`/Characters`** | Mesh, animazioni e Blueprint specifici dei personaggi. |
| **`/Core`** | Implementazioni Blueprint di GameInstance e GameMode. |
| **`/Data`** | Database di gioco, `DataAsset` e `DataTable`. |
| **`/Fab`** | Modelli e asset importati tramite il marketplace FAB. |
| **`/Input`** | Asset per l'Enhanced Input (Actions, Contexts). |
| **`/Levels`** | Mappe di gioco e file di scenario. |
| **`/Materials`** | Materiali, Master Materials e Texture. |
| **`/Niagara`** | Effetti particellari e sistemi VFX. |

---
