
class Video
  @@de_clase = "Clase woo"
  @de_instancia = "Instancia yeei"

  def self.test
    p @@de_clase
    p @de_instancia
  end
end

class YouTube < Video
  def self.test
    @@de_clase = "Clase Cambiada :)" # CAMBIA EL VALOR DE 
    p @@de_clase
    p @de_instancia
  end
end

YouTube.test
Video.test
