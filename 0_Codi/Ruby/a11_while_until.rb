

playlist=["First song", "Second song", "Third song"]

playing=true

index_song=0

while (index_song < playlist.length) && playing == true
  puts "Reproduciendo #{playlist[index_song]}"

  index_song+=1

  # Si nos manda 0 , hacemos stop, sino seguimos reproduciendo

  puts "Coloca 0 para detener la reproduccion..."
  respuesta=gets().chomp.to_i

#  if respuesta == 0
#    playing=False
#  end

  playing = false if respuesta == 0 
  playing = respuesta != 0  # si repuesta diferenteA 0 return false

end
