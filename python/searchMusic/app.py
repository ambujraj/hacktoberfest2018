#encoding: utf8

from vagalume import lyrics

banda = raw_input(str("Por favor informe seu artista ou banda: "))
musica = raw_input(str("Por favor informe a música: "))

resultado = lyrics.find(banda, musica)

print(resultado.song.lyric)