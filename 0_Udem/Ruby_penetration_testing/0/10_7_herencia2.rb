
class Video
  attr_accessor :titulo, :duracion

  def embed_video_code
    "<video></video>"
  end

  def setup(titulo)
    @titulo = titulo
  end
end

class Youtube < Video
 attr_accessor :canal
  
 #overwrite - sobreescribir
  def embed_video_code
    "<iframe />"
  end 

  def setup(titulo)
    super   # llama el codigo de def setup de la clase padre
    puts "Hello"
  end
end

class Facebook < Video
  attr_accessor :usuario

end

yt = Youtube.new
yt.canal = "Go go men... fast"
yt.titulo = "youtube vFast"
puts yt.embed_video_code
puts yt.titulo
puts yt.setup("Parametro Setup")

video_1 = Video.new
puts video_1.embed_video_code
