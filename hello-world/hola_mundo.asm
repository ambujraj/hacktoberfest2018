 
.model small
.stack
.data
   saludo   db "Hola mundo!!!", "$"
 
.code
 
main  proc              ;Inicia proceso
   mov   ax,seg saludo     ;hmm ¿seg?
   mov   ds,ax          ;ds = ax = saludo
 
   mov   ah,09          ;Function(print string)
   lea   dx,saludo         ;DX = String terminated by "$"
   int   21h               ;Interruptions DOS Functions
 
;mensaje en pantalla
 
   mov   ax,4c00h       ;Function (Quit with exit code (EXIT))
   int   21h            ;Interruption DOS Functions
 
main  endp              ;Termina proceso
end main
