# Rev-eng-task 

Forsøker meg på litt enkel reverse-engineering av et c-program.  
Oppgaven går ut på å finne det hardkodede passordet i executablen i det kompilerte C-programmet.

## Verktøy  

gdb (Gnu debugger)


### Hvordan bruke gnu debugger  

```sh
gdb crackme 	# laster executable inn i gdb
```

```GDB
(gdb) set disassembly-function intel	# Setter syntaksen på assmbly til intel spesifikk syntax
(gdb) disas main	# Viser assemblykoden for main-funksjonen  
(gdb) break *main	# Setter breakpoint på main-funksjonen  
(gdb) run 		# Kjører executablen og stopper på første breakpoint  
(gdb) ni	# stepper gjennom programmet linje for linje
```

### strings

Henter ut alle ascii-verdier i en 

Det er mulig å finne passordet i crackme'en i programmet med denne.  

## Assembly  

### Registre  

Variabler lagret i registret kjøres som regel i register-file.
Programmer som bare bruker registry, kører fortere enn de som bruker stacken, som kjører i cachene eller i RAM.
Register-file er raskest, deretter L1-cache, deretter L2-cache og til slutt RAM.  

Man har 8-32 globale variabler kalt "registers".   
De har en satt størrelse.  

RIP / IP / EIP = viktig registeri/variabel.
Også kalt program counter. 
Sier noe om hvilken instruksjon som er den neste til å bli kalt i programmet.

ESP - stack-pointer  
Peker til toppen av stacken.  

zeroflag - 

### Funksjoner  

_cmp_ = compare  -  sammenligner noe, f.eks et tall i en int
_je_ = jump equal, - går til en minneadresse når noe er likt
_jne_ = jump not equals - går til en minneaddresse, hvis noe ikke er likt

_mov_ = move - betyr at man setter en verdi til en minneadresse eller til en variabel i registeret.  
_add_ og _sub_ er + og - i cpu-verden.  
F.eks. mov eax, 0x5  betyr at verdien i eax nå er verdi 5  
add eax, 0x2 - gjør at eax = 5+2 = 7  
sub eax, 0x3 - eax er nå 7 - 3 = 4  

_call_ = eksternt funksjonskall.   
_push_ = setter en verdi i stacken og inkrementerer stack pointer-verdien.  
_pop_ = Henter verdi fra toppen av stack og deinkrementerer pointer-verdien til stacken. 
_jump_ = Hopper til en minneadresse.  

 Man kan ofte bruke man-pages i linux for å finne ut av hva funksjonen gjør. F.eks call 0x5d0 <puts@plt> bruker puts-metoden. Som betyr å skrive til konsollet som printf.

