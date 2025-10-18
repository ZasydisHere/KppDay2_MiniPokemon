# KppDay2_MiniPokemon

Program ini  menjalankan permainan pokemon sederhana dimana mekanismenya turnbase sebagai berikut

di awal ada narasi singkat "Halo, selamat datang di region Hoenn sekarang pilihlah pokemonmu sebagai rekanmu"

Di awal permainan memilih 1 pokemon yang akan jadi rekan sampai akhir game dan hanya bisa memiliki 1 pokemon tersebut (tidak ada fitur menangkap pokemon)

pokemonnya = Torchic, Treecko, Mudkip

permainan diawali dengan memilih beberapa pilihan

1. Berjalan ke semak semak
2. Pergi ke Medical Center
3. Melawan Elite 

untuk pokemon yang ada pada game ini

Pokemon yang dapat dipilih player :
Torchic - Combusken - Blaziken (Fire)
Trecko - Grovyle - Sceptile (Grass)
Mudkip - Marshtomp - Swampert (Water)

tiap pokemon starter punya stat sama
Hp 50, Attack 20, speed 15

untuk level evolusi 
level 5 itu level awal pokemon skill only scratch
level 16 evolusi pertama skill bertambah jadi 2 yaitu scratch dan skill pertama tiap elemen
level 36 evolusi terakhir skill lengkap

tiap naik 1 level nambah base hp + 5 , attack + 1, speed +2

Pokemon yang ada di semak semak
base stat pokemon liar hp 45, attack 10, speed 10

Virogoth (Normal) - skill only scratch 
Zangoose (Normal) - skill only scratch 
Rattice (Normal) - skill only scratch

Pokemon para ELITE

Sidney Cacturne (Grass) 
Phoebe Chandelure (Fire) 
Drake Kingdra (Water) 

setiap pokemon elite base stat nya sama
hp 150, attack 35, speed 40


untuk pokemon water type: scratch (5 + base attack), Water Pump (20 + base attack) & Hydro Pump (25 + base attack) 
untuk pokemon grass type: scratch (5 + base attack), energy ball (20 + base attack) & Razor Leaf(25 + base base attack) 
untuk pokemon fire type:scratch (5 + base attack), ember (20 + base attack) & overheat (25 + base attack)


disini ada effetive (2x) , normal damage(1x), not effective (0,5)

untuk damage ke normal atau sebaliknya itu normal damage

disini hanya ada 3 elemn utama dan mereka saling counter

fire -> grass -> water -> fire

kalau searah panah itu effective kalau sebaliknya not effective 

ketika salah satu elite dikalahkan maka akan hilang dari list jika telah rata maka akan keluar "CONGRATS CHAMPIONS"

urutan elite berdasarkan pokemon awal yang dipilih

ketika pilih treecko urutan elitenya DRAKE, SIDNEY, PHOEBE
ketika pilih mudkip Phoebe, Drake, Sidney
ketika pilih torchic sidney, Phoebe, Drake

Hp terakhir pertarungan akan disimpan jika ingin pulih perlu ke medical center


| Konsep          | Implementasi                                                                                   |
| --------------- | ---------------------------------------------------------------------------------------------- |
| Class           | `Pokemon`, `Player`, `GameManager`, `ElitePokemon`, dll                                        |
| Object          | Instance tiap pokemon dan player                                                               |
| Attribute       | HP, Attack, Speed, Level, Name, Type                                                           |
| Method          | attack(), heal(), evolve(), showStatus(), dll                                                  |
| Constructor     | Menginisialisasi atribut tiap objek                                                            |
| Setter & Getter | getHp(), setHp(), getName(), setLevel()                                                        |
| Encapsulation   | Atribut dibuat private dan diakses lewat setter/getter                                         |
| Inheritance     | `StarterPokemon`, `WildPokemon`, `ElitePokemon` mewarisi `Pokemon`                             |
| Overriding      | attack() dan skill() di-override sesuai tipe                                                   |
| Access Modifier | Private, Protected, Public digunakan sesuai konteks                                            |
| Abstraction     | `Pokemon` dijadikan class abstrak dengan pure virtual method `attack()`                        |
| Polymorphism    | Pointer `Pokemon*` dipakai untuk battle antar tipe berbeda                                     |
| CRUD            | Create (new Pokémon), Read (lihat status), Update (level up), Delete (hapus elite dari daftar) |


Struktur Folder Proyek

main.cpp 

Types.h  
Effectiveness.h          

Pokemon.h        
StarterPokemon.h         
WildPokemon.h        
ElitePokemon.h         

Player.h              
BattleSystem.h          
GameManager.h            


