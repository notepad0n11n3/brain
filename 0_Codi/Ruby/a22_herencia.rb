class Object
  def i_have_superpowers
    puts "Este metodo esta en todos los objetos x89p :)   <3"
  end
end

[].i_have_superpowers
"".i_have_superpowers
10.i_have_superpowers
Video.new.i_have_superpowers
YouTubeVide0.i_have_superpowers

class VideoTest
  attr_accessor :title,:duration
end

class YoutubeVide0 < VideoTest
  attr_accessor :youtue_id
end

yt=YoutubeVide0.new

yt.title="Herencia en Ruby"
yt.youtue_id="1asdfj1asdkfl8adsf"

puts yt.title
puts yt.youtue_id


puts "--------------------------------------------"

class Video
  attr_accessor :title,:duration
  attr_accessor :description

  def embed_video_code
    "<video></video>"
  end

  def setup(title)
    @title = title
  end
end


class YoutubeVideo < Video
  attr_accessor :youtube_id

  def embed_video_code   #SOBRE ESCRIBIR EL METODO, SOBRE ESCRIBIR EL METODO
    "<iframe />"
  end

  def setup(title)
    super
    # YouTubeAPI.init()
  end
end
panda8hat = YoutubeVideo.new
panda8hat.setup("este es el fucking Titulo")
puts panda8hat.setup     #ERROR Y NO SE PORQUE :(
#puts YoutubeVideo.new().embed_video_code
