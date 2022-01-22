class Video
  attr_accessor :tiempo, :titulo

  def play
    puts "Se inicio el video #{titulo}..."
  end

  def pause
    puts "Se ha pausado el video..."
  end

  def stop
    puts "Se ha apagado el video..."
  end

end

video1 = Video.new
video1.titulo = "Clases de Ruby"
video1.tiempo = 10

video2 = Video.new
video2.titulo = "Clases de POO"
video2.tiempo = 15

puts video1.titulo
puts video1.tiempo

video1.play
