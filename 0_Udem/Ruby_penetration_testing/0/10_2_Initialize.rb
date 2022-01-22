class Video
  attr_accessor :tiempo, :titulo

  def initialize(tituloInitialize)
    self.titulo = tituloInitialize
    puts "Gracias por iniciar... <3 U.U"
  end

  def play
    puts "Se esta iniciando el video #{titulo}"
  end

  def stop
    puts "Se esta deteniendo el video #{titulo}"
  end
end

# video1.titulo = "Curso de Ruby"
# puts video1.titulo

video1 = Video.new("Curso de Ruby")

puts video1.titulo
video1.play
